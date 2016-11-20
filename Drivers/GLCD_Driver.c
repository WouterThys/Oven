#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <xc.h>
#include <p18f4550.h>

#include "GLCD_Driver.h"
#include "GLCD_Bitmaps.h"
#include "GLCD_Font.h"
#include "PORT_Driver.h"

/*******************************************************************************
 *          DEFINES
 ******************************************************************************/
// KS0108 DEFINES
#define GLCD_CHIP_WIDTH     64      // Pixels per chip
    
#define GLCD_ON             0x3F
#define GLCD_OFF            0x3E
#define GLCD_DISP_START     0xC0

#define GLCD_SET_ADDRESS    0x40
#define GLCD_SET_PAGE       0xB8
#define GLCD_BUSY_FLAG      0x80
    
#define GLCD_OUT        0x00
#define GLCD_IN         0xFF

// Font 
typedef uint8_t (*FontCallBack)(const uint8_t*);
typedef uint8_t byte;
#define FONT_LENGTH         0
#define FONT_FIXED_WIDTH	2
#define FONT_HEIGHT         3
#define FONT_FIRST_CHAR		4
#define FONT_CHAR_COUNT		5
#define FONT_WIDTH_TABLE	6
#define GLCD_SelectFont(font) GLCD_SelectFontEx(font, GLCD_WHITE, readPgmData)

/*******************************************************************************
 *          MACRO FUNCTIONS
 ******************************************************************************/
#define _BV(i)      (1 << (i))
#define IsFixedWidthFont(font)  (GLCD_FontRead(font+FONT_LENGTH) == 0 && GLCD_FontRead(font+FONT_LENGTH+1) == 0)

#define GLCD_SelectChip(chip)\
    switch(chip){\
        case 0: GLCD_CS1=0; GLCD_CS2=1; GLCD_CS3=1;break;\
        case 1: GLCD_CS1=1; GLCD_CS2=0; GLCD_CS3=1;break;\
        case 2: GLCD_CS1=1; GLCD_CS2=1; GLCD_CS3=0;break;\
    }
    
#define GLCD_EnablePulse()\
    __delay_us(5);\
    GLCD_EN = 1;\
    __delay_us(5);\
    GLCD_EN = 0;\
    __delay_us(5)

#define GLCD_WaitWhileBusy(chip)\
    GLCD_SelectChip(chip);\
    GLCD_DATA_Dir = GLCD_IN;\
    GLCD_RS = 0;\
    GLCD_RW = 1;\
    GLCD_EN = 1;\
    __delay_us(5);\
    while(GLCD_DATA & GLCD_BUSY_FLAG);\
    GLCD_EN = 0;\
    __delay_us(5)

#define GLCD_ReadData(data)\
    GLCD_ReadSingle(true);\
    data = GLCD_ReadSingle(false)
    
#define GLCD_WriteCommand(cmd,chip)\
    GLCD_WaitWhileBusy(chip);\
    GLCD_RS = 0;\
    GLCD_RW = 0;\
    GLCD_DATA_Dir = GLCD_OUT;\
    __delay_us(5);\
    GLCD_DATA = cmd;\
    GLCD_EnablePulse();\
    __delay_us(5);\
    __delay_us(5);\
    GLCD_DATA = 0x00

/*******************************************************************************
 *          VARIABLES
 ******************************************************************************/
//void GLCD_DisplayOn(void);
//void GLCD_GotoRow(uint8_t y);
//void GLCD_GotoCol(uint8_t x);
//void GLCD_GotoXY(uint8_t x, uint8_t y);
void GLCD_ClearPage(uint8_t page, uint8_t color);
uint8_t GLCD_ReadSingle(bool firstTime);
void GLCD_WriteData(uint8_t data);
uint8_t readPgmData(const uint8_t* ptr);

void GLCD_SelectFontEx(const uint8_t* font, uint8_t color, FontCallBack callback);
int16_t  GLCD_PutChar(char c);
uint8_t  GLCD_CharWidth(char c);
uint16_t GLCD_StringWidth(const char *str);

// Coordinate struct
typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t page;
} GLCD_Coordinates;

static GLCD_Coordinates GLCD_Coord;
static bool GLCD_Inverted;
static FontCallBack GLCD_FontRead;
static uint8_t GLCD_FontColor;
static const uint8_t* GLCD_Font;

/*******************************************************************************
 *          BASIC FUNCTIONS
 ******************************************************************************/
void GLCD_GotoXY(uint8_t x, uint8_t y) {
    uint8_t chip, cmd;
    
    if ((x > GLCD_DISP_WIDTH - 1)){
        x = 0;
        y = y+8;
    }
    if(y > GLCD_DISP_HEIGHT - 1) {
        return;
    }
    
    // Save the new coordinates
    GLCD_Coord.x = x;
    GLCD_Coord.y = y;

    if (y / 8 != GLCD_Coord.page) {
        GLCD_Coord.page = y / 8;
        // Set y address on all chips
        cmd = GLCD_SET_PAGE | GLCD_Coord.page;
        for (chip = 0; chip < (GLCD_DISP_WIDTH/GLCD_CHIP_WIDTH); chip++) {
            GLCD_WriteCommand(cmd, chip);
        }
    }

    chip = GLCD_Coord.x / GLCD_CHIP_WIDTH;
    x = x % GLCD_CHIP_WIDTH;
    cmd = GLCD_SET_ADDRESS | x;
    GLCD_WriteCommand(cmd, chip); // Set x address on active chip
}

void GLCD_ClearPage(uint8_t page, uint8_t color){
    for(uint8_t x = 0; x < GLCD_DISP_WIDTH; x++) {
        GLCD_GotoXY(x, page*8);
        GLCD_WriteData(color);
    }
}

uint8_t GLCD_ReadSingle(bool firstTime){
    uint8_t chip, data;
    
    chip = GLCD_Coord.x/GLCD_CHIP_WIDTH;
    GLCD_WaitWhileBusy(chip);
    if(firstTime){
        if(GLCD_Coord.x % GLCD_CHIP_WIDTH == 0 && chip > 0) {
            GLCD_GotoXY(GLCD_Coord.x, GLCD_Coord.y);
            GLCD_WaitWhileBusy(chip);
        }
    }
    
    GLCD_DATA_Dir = GLCD_IN;
    GLCD_RS = 1;
    GLCD_RW = 1;
    GLCD_EN = 1;
   __delay_us(5);
   
   data = GLCD_DATA;
   
   GLCD_EN = 0;
   __delay_us(5);
   if(!firstTime) {
       GLCD_GotoXY(GLCD_Coord.x, GLCD_Coord.y);
   }
   if(GLCD_Inverted) {
       data = ~data;
   }
   return data;
}

void GLCD_WriteData(uint8_t data){
    uint8_t displayData, yOffset, chip;
    
    if(GLCD_Coord.x >= GLCD_DISP_WIDTH) return;
    chip = GLCD_Coord.x / GLCD_CHIP_WIDTH;
    GLCD_WaitWhileBusy(chip);
    
    GLCD_DATA_Dir = GLCD_OUT;
    GLCD_RS = 1;
    GLCD_RW = 0;
    
    yOffset = GLCD_Coord.y % 8;
    
    if(yOffset != 0) {
        // First page
        GLCD_ReadData(data);
        GLCD_DATA_Dir = GLCD_OUT;
        GLCD_RS = 1;
        GLCD_RW = 0;
        GLCD_SelectChip(chip);
        displayData |= data << yOffset;
        if(GLCD_Inverted) {
            displayData = ~displayData;
        }
        GLCD_DATA = displayData;
        GLCD_EnablePulse();
        
        // Second page
        GLCD_GotoXY(GLCD_Coord.x, GLCD_Coord.y + 8);
        GLCD_ReadData(displayData);
        GLCD_DATA_Dir = GLCD_OUT;
        GLCD_RS = 1;
        GLCD_RW = 0;
        GLCD_SelectChip(chip);
        displayData |= data >> (8 - yOffset);
        if(GLCD_Inverted) {
            displayData = ~displayData;
        }
        GLCD_DATA = displayData;
        GLCD_EnablePulse();
        
        GLCD_GotoXY(GLCD_Coord.x + 1, GLCD_Coord.y - 8);
    } else {
        if(GLCD_Inverted) {
            data = ~data;
        }
        __delay_us(5);
        GLCD_DATA = data;
        GLCD_EnablePulse();
        GLCD_Coord.x++;
    }
}



/*******************************************************************************
 *          DRIVER FUNCTIONS
 ******************************************************************************/
void D_GLCD_Init(bool invert) {
    __delay_ms(10);
    // Directions
    GLCD_DATA_Dir = GLCD_OUT;
    
    // Deactivate chips
    GLCD_CS1 = 1;
    GLCD_CS2 = 1;
    GLCD_CS3 = 1;
    
    GLCD_RS = 0;
    GLCD_RW = 0;
    GLCD_EN = 0;
    
    // Reset the chip
    GLCD_RST = 0;
    __delay_ms(10);
    GLCD_RST = 1;
    __delay_ms(10);
    
    // Set coordinates
    GLCD_Coord.x = 0;
    GLCD_Coord.y = 0;
    GLCD_Coord.page = 0;
    
    GLCD_Inverted = invert;
    
    uint8_t chip;
    for(chip = 0; chip < (GLCD_DISP_WIDTH/GLCD_CHIP_WIDTH); chip++) {
        GLCD_WriteCommand(GLCD_ON, chip); // Display ON
        GLCD_WriteCommand(GLCD_DISP_START, chip); // Set Display start line at 0
    }
    
    // Display on
    D_GLCD_ClearScreen(invert ? GLCD_WHITE : GLCD_BLACK);
    GLCD_GotoXY(0,0);
    GLCD_SelectFont(System5x7);
}

void D_GLCD_ClearScreen(uint8_t color){
    uint8_t page;
    for(page = 0; page < 8; page++) {
        GLCD_GotoXY(0, page*8);
        GLCD_ClearPage(page,color);
    }
}

void D_GLCD_DrawDot(uint8_t x, uint8_t y, uint8_t color) {
    uint8_t data;
    
    GLCD_GotoXY(x, y - y % 8);
    GLCD_ReadData(data);
    
    if(color == GLCD_WHITE) {
        data |= 0x01 << (y % 8);
    } else {
        data &= ~(0x01 << (y % 8));
    }
    GLCD_WriteData(data);
}

uint8_t readPgmData(const uint8_t* ptr) {
    return *ptr;
}

void D_GLCD_DrawBitmap(const uint8_t* bitmap, uint8_t x, uint8_t y, uint8_t color) {
    uint8_t width, height;
    uint8_t i,j;
    
    width = readPgmData(bitmap++);
    height = readPgmData(bitmap++);
    
    for(j = 0; j < height/8; j++) {
        GLCD_GotoXY(x, y + (j*8));
        for(i = 0; i < width; i++) {
            uint8_t displayData = readPgmData(bitmap++);
            if(color == GLCD_WHITE) {
                GLCD_WriteData(displayData);
            } else {
                GLCD_WriteData(~displayData);
            }
        }
    }
}

void GLCD_SelectFontEx(const uint8_t* font, uint8_t color, FontCallBack callback) {
    GLCD_Font = font;
    GLCD_FontRead = callback;
    GLCD_FontColor = color;
}

int16_t GLCD_PutChar(char c){
    if (GLCD_Font == 0) return 0;
    
    uint8_t width = 0;
    uint8_t height = GLCD_FontRead(GLCD_Font + FONT_HEIGHT);
    uint8_t bytes = (height + 7) / 8; /* calculates height in rounded up bytes */

    uint8_t firstChar = GLCD_FontRead(GLCD_Font + FONT_FIRST_CHAR);
    uint8_t charCount = GLCD_FontRead(GLCD_Font + FONT_CHAR_COUNT);

    uint16_t index = 0;
    uint8_t x = GLCD_Coord.x, y = GLCD_Coord.y;
    uint8_t thielefont;

    if (c < firstChar || c >= (firstChar + charCount)) {
        return 0; // invalid char
    }
    c -= firstChar;

    if (IsFixedWidthFont(GLCD_Font)) {
        thielefont = 0;
        width = GLCD_FontRead(GLCD_Font + FONT_FIXED_WIDTH);
        index = c * bytes * width + FONT_WIDTH_TABLE;
    } else {
        // variable width font, read width data, to get the index
        thielefont = 1;
        for (uint8_t i = 0; i < c; i++) {
            index += GLCD_FontRead(GLCD_Font + FONT_WIDTH_TABLE + i);
        }
        index = index * bytes + charCount + FONT_WIDTH_TABLE;
        width = GLCD_FontRead(GLCD_Font + FONT_WIDTH_TABLE + c);
    }
    
    uint8_t pixels = height + 1; /* 1 for gap below character*/
    uint8_t p;
    uint8_t dy;
    uint8_t tfp;
    uint8_t dp;
    uint8_t dbyte;
    uint8_t fdata;

    for (p = 0; p < pixels;) {
        dy = y + p;
        GLCD_GotoXY(x, (dy & ~7));
        uint16_t page = p / 8 * width; // page must be 16 bit to prevent overflow
        for (uint8_t j = 0; j < width; j++) /* each column of font data */ {
            if (p >= height) {
                fdata = 0;
            } else {
                fdata = GLCD_FontRead(GLCD_Font + index + page + j);
                if (thielefont && (height - (p&~7)) < 8) {
                    fdata >>= 8 - (height & 7);
                }
            }

            if (GLCD_FontColor == GLCD_BLACK)
                fdata ^= 0xff; /* inverted data for "white" font color	*/

            if (!(dy & 7) && !(p & 7) && ((pixels - p) >= 8)) {
                GLCD_WriteData(fdata);
                continue;
            } else {
                GLCD_ReadData(dbyte);
            }

            tfp = p; /* font pixel bit position 		*/
            dp = dy & 7; /* data byte pixel bit position */

            while ((dp <= 7) && (tfp) < pixels) {
                if (fdata & _BV(tfp & 7)) {
                    dbyte |= _BV(dp);
                } else {
                    dbyte &= ~_BV(dp);
                }

                if ((tfp & 7) == 7) {
                    fdata = GLCD_FontRead(GLCD_Font + index + page + j + width);

                    if ((thielefont) && ((height - tfp) < 8)) {
                        fdata >>= (8 - (height & 7));
                    }

                    if (GLCD_FontColor == GLCD_BLACK)
                        fdata ^= 0xff; /* inverted data for "white" color	*/
                }
                tfp++;
                dp++;
            }
            GLCD_WriteData(dbyte);
        }

        if ((dy & 7) || (pixels - p < 8)) {
            uint8_t mask = 0;

            GLCD_ReadData(dbyte);

            if (dy & 7)
                mask |= _BV(dy & 7) - 1;

            if ((pixels - p) < 8)
                mask |= ~(_BV(pixels - p) - 1);


            if (GLCD_FontColor == GLCD_BLACK)
                dbyte |= ~mask;
            else
                dbyte &= mask;

        } else {
            if (GLCD_FontColor == GLCD_BLACK)
                dbyte = 0xff;
            else
                dbyte = 0;
        }

        GLCD_WriteData(dbyte);
        p += 8 - (dy & 7);
    }

    GLCD_GotoXY(x + width + 1, y);
    
    return 1; // valid char
}

void D_GLCD_WriteStringAt(const char *str, uint8_t x, uint8_t y) {
    GLCD_GotoXY(x, y);
    int h = GLCD_Coord.x;
    while (*str != 0) {
        if (*str == '\n') {
            GLCD_GotoXY(h, GLCD_Coord.y + GLCD_FontRead(GLCD_Font + FONT_HEIGHT));
        } else {
            GLCD_PutChar(*str);
        }
        str++;
    }
}

void D_GLCD_WriteString(const char *str) {
    int h = GLCD_Coord.x;
    while (*str != 0) {
        if (*str == '\n') {
            GLCD_GotoXY(h, GLCD_Coord.y + GLCD_FontRead(GLCD_Font + FONT_HEIGHT));
        } else {
            GLCD_PutChar(*str);
        }
        str++;
    }
}

void D_GLCD_PrintNumber(long n) {
    byte buf[10]; // prints up to 10 digits
    byte i = 0;
    if (n == 0)
        GLCD_PutChar('0');
    else {
        if (n < 0) {
            GLCD_PutChar('-');
            n = -n;
        }
        while (n > 0 && i <= 10) {
            buf[i++] = n % 10; // n % base
            n /= 10; // n/= base
        }
        for (; i > 0; i--)
            GLCD_PutChar((char) (buf[i - 1] < 10 ? '0' + buf[i - 1] : 'A' + buf[i - 1] - 10));
    }
}

void D_GLCD_PrintNumberAt(long n, uint8_t x, uint8_t y) {
    GLCD_GotoXY(x, y);
    byte buf[10]; // prints up to 10 digits
    byte i = 0;
    if (n == 0)
        GLCD_PutChar('0');
    else {
        if (n < 0) {
            GLCD_PutChar('-');
            n = -n;
        }
        while (n > 0 && i <= 10) {
            buf[i++] = n % 10; // n % base
            n /= 10; // n/= base
        }
        for (; i > 0; i--)
            GLCD_PutChar((char) (buf[i - 1] < 10 ? '0' + buf[i - 1] : 'A' + buf[i - 1] - 10));
    }
}

void D_GLCD_PrintHexNumber(uint16_t n) {
    int8_t i;
    uint8_t d, previous_write = 0;

    if (n == 0) {
        GLCD_PutChar('0');
        return;
    }

    for (i=3; i>=0; i--) {
        d = ((0x0F << i*4) & n) >> i*4;

        if (d < 0xA)
            d += '0';
        else
            d = (d - 0xA) + 'A';

        if (d != '0' || previous_write) {
            GLCD_PutChar((char) d);
            previous_write = 1;
        }
    }
}

void D_GLCD_PrintRealNumber(double n) {
    long int_part, frac_part;
    uint8_t sign = 0;

    if (n < 0) {
        sign = 1;
        n *= -1;
    }

    int_part = (long)n;
    frac_part = (long)((n - (double)int_part)*1000000);
    if (sign) GLCD_PutChar('-');
    D_GLCD_PrintNumber(int_part);
    GLCD_PutChar('.');

    while ((frac_part != 0) && (frac_part % 10 == 0)) {
        frac_part /= 10;
    }

    D_GLCD_PrintNumber(frac_part);
}


uint8_t GLCD_CharWidth(char c) {
    uint8_t width = 0;
    uint8_t firstChar = GLCD_FontRead(GLCD_Font + FONT_FIRST_CHAR);
    uint8_t charCount = GLCD_FontRead(GLCD_Font + FONT_CHAR_COUNT);

    // read width data
    if (c >= firstChar && c < (firstChar + charCount)) {
        c -= firstChar;
        width = GLCD_FontRead(GLCD_Font + FONT_WIDTH_TABLE + c) + 1;
    }

    return width;
}

uint16_t GLCD_StringWidth(const char *str) {
    uint16_t width = 0;

    while (*str != 0) {
        width += GLCD_CharWidth(*str++);
    }

    return width;
}

void GLCD_CursorTo(uint8_t x, uint8_t y) { // 0 based coordinates for fixed width fonts (i.e. systemFont5x7)
    GLCD_GotoXY(x * (GLCD_FontRead(GLCD_Font + FONT_FIXED_WIDTH) + 1),
            y * (GLCD_FontRead(GLCD_Font + FONT_HEIGHT) + 1));
}

// Extra draw line macros:
#define _GLCD_AbsDiff(a,b)  ((a>b) ? (x-y):(y-x))
#define _GLCD_Swap(a,b) uint8_t t; t=a; a=b; b=t

void D_GLCD_DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color) {
    uint8_t dx, dy, x, y, steep;
    int8_t error, ystep;

    steep = _GLCD_AbsDiff(y1,y2) > _GLCD_AbsDiff(x1,x2);
    if(steep) {
        _GLCD_Swap(x1,y1);
        _GLCD_Swap(x2,y2);
    }
    if(x1 > x2) {
        _GLCD_Swap(x1, x2);
        _GLCD_Swap(y1, y2);
    }

    dx = x2 - x1;
    dy = _GLCD_AbsDiff(y2,y1);
    error = dx/2;
    y = y1;
    if(y1 < y2) ystep = 1;
    else ystep = -1;

    for(x = x1; x<= x2; x++) {
        if(steep) D_GLCD_DrawDot(y,x,color);
        else D_GLCD_DrawDot(x,y,color);
        error = error - dy;
        if(error < 0){
            y = y + ystep;
            error = error + dx;
        }
    }
}

void D_GLCD_DrawRect(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t color) {
    D_GLCD_DrawHoriLine(x, y, width, color); // top
    D_GLCD_DrawHoriLine(x, y + height, width, color); // bottom
    D_GLCD_DrawVertLine(x, y, height, color); // left
    D_GLCD_DrawVertLine(x + width, y, height, color); // right
}

void D_GLCD_DrawRoundRect(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t radius, uint8_t color) {
    int16_t tSwitch, x1 = 0, y1 = radius;
    tSwitch = 3 - 2 * radius;

    while (x1 <= y1) {
        D_GLCD_DrawDot(x + radius - x1, y + radius - y1, color);
        D_GLCD_DrawDot(x + radius - y1, y + radius - x1, color);

        D_GLCD_DrawDot(x + width - radius + x1, y + radius - y1, color);
        D_GLCD_DrawDot(x + width - radius + y1, y + radius - x1, color);

        D_GLCD_DrawDot(x + width - radius + x1, y + height - radius + y1, color);
        D_GLCD_DrawDot(x + width - radius + y1, y + height - radius + x1, color);

        D_GLCD_DrawDot(x + radius - x1, y + height - radius + y1, color);
        D_GLCD_DrawDot(x + radius - y1, y + height - radius + x1, color);

        if (tSwitch < 0) {
            tSwitch += (4 * x1 + 6);
        } else {
            tSwitch += (4 * (x1 - y1) + 10);
            y1--;
        }
        x1++;
    }

     D_GLCD_DrawHoriLine(x + radius, y, width - (2 * radius), color); // top
     D_GLCD_DrawHoriLine(x + radius, y + height, width - (2 * radius), color); // bottom
     D_GLCD_DrawVertLine(x, y + radius, height - (2 * radius), color); // left
     D_GLCD_DrawVertLine(x + width, y + radius, height - (2 * radius), color); // right
}

void D_GLCD_FillRect(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t color) {
    uint8_t mask, pageOffset, h, i, data;
    height++;

    pageOffset = y % 8;
    y -= pageOffset;
    mask = 0xFF;
    if (height < 8 - pageOffset) {
        mask >>= (8 - height);
        h = height;
    } else {
        h = 8 - pageOffset;
    }
    mask <<= pageOffset;

    GLCD_GotoXY(x, y);
    for (i = 0; i <= width; i++) {
        GLCD_ReadData(data);

        if (color == GLCD_WHITE) {
            data |= mask;
        } else {
            data &= ~mask;
        }

        GLCD_WriteData(data);
    }

    while (h + 8 <= height) {
        h += 8;
        y += 8;
        GLCD_GotoXY(x, y);

        for (i = 0; i <= width; i++) {
            GLCD_WriteData(color);
        }
    }

    if (h < height) {
        mask = ~(0xFF << (height - h));
        GLCD_GotoXY(x, y + 8);

        for (i = 0; i <= width; i++) {
            GLCD_ReadData(data);

            if (color == GLCD_WHITE) {
                data |= mask;
            } else {
                data &= ~mask;
            }

            GLCD_WriteData(data);
        }
    }
}

void D_GLCD_InvertRect(uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
    uint8_t mask, pageOffset, h, i, data, tmpData;
    height++;

    pageOffset = y % 8;
    y -= pageOffset;
    mask = 0xFF;
    if (height < 8 - pageOffset) {
        mask >>= (8 - height);
        h = height;
    } else {
        h = 8 - pageOffset;
    }
    mask <<= pageOffset;

    GLCD_GotoXY(x, y);
    for (i = 0; i <= width; i++) {
        GLCD_ReadData(data);
        tmpData = ~data;
        data = (tmpData & mask) | (data & ~mask);
        GLCD_WriteData(data);
    }

    while (h + 8 <= height) {
        h += 8;
        y += 8;
        GLCD_GotoXY(x, y);

        for (i = 0; i <= width; i++) {
            GLCD_ReadData(data);
            GLCD_WriteData(~data);
        }
    }

    if (h < height) {
        mask = ~(0xFF << (height - h));
        GLCD_GotoXY(x, y + 8);

        for (i = 0; i <= width; i++) {
            GLCD_ReadData(data);
            tmpData = ~data;
            data = (tmpData & mask) | (data & ~mask);
            GLCD_WriteData(data);
        }
    }
}

void D_GLCD_DrawVertLine(uint8_t x, uint8_t y, uint8_t length, uint8_t color) {
    D_GLCD_FillRect(x, y, 0, length, color);
}

void D_GLCD_DrawHoriLine(uint8_t x, uint8_t y, uint8_t length, uint8_t color) {
    D_GLCD_FillRect(x, y, length, 0, color);
}

void D_GLCD_DrawCircle(uint8_t xCenter, uint8_t yCenter, uint8_t radius, uint8_t color) {
    D_GLCD_DrawRoundRect(xCenter-radius, yCenter-radius, 2*radius, 2*radius, radius, color);
}

void D_GLCD_SetInverted(bool invert) {
    if (GLCD_Inverted != invert) {
        D_GLCD_InvertRect(0, 0, GLCD_DISP_WIDTH - 1, GLCD_DISP_HEIGHT - 1);
        GLCD_Inverted = invert;
    }    
}
