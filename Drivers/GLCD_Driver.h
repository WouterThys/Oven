#ifndef GLCD_DRIVER_H
#define	GLCD_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdint.h>
#include <stdbool.h>
    
#define GLCD_WHITE      0xFF
#define GLCD_BLACK      0x00
    
#define GLCD_DISP_WIDTH     192
#define GLCD_DISP_HEIGHT    64
    
// FUNCTIONS
void GLCD_GotoXY(uint8_t x, uint8_t y);    
/**
 * Initializes all the parameters to the default setting, as well as writing the
 * tri-state registers. Resets all chips and clears (fills) the screen
 * @param invert: Black or White pixel clearing
 */
void D_GLCD_Init(bool invert);
/**
 * Clear the full screen
 * @param color: Black or White pixel clearing
 */
void D_GLCD_ClearScreen(uint8_t color);
/**
 * Place one pixel on the specified location on the screen. Select the color
 * Black or White to fill or clear a pixel.
 * @param x: Horizontal location
 * @param y: Vertical location
 * @param color: Black or White pixel
 */
void D_GLCD_DrawDot(uint8_t x, uint8_t y, uint8_t color);
/**
 * Draw a bitmap on the screen. Select the color
 * Black or White to fill the bitmap.
 * @param bitmap: Pointer to the bitmap
 * @param x: Horizontal start position
 * @param y: Vertical start position
 * @param color: Black or White
 */
void D_GLCD_DrawBitmap(const uint8_t *bitmap, uint8_t x, uint8_t y, uint8_t color);
/**
 * Writes a string on the screen in the selected font. The start positions are
 * given in x and y, be sure not to fall of the screen! The newline character \n
 * is recognized to jump to a new line. 
 */
void D_GLCD_WriteStringAt(const char *str, uint8_t x, uint8_t y);
void D_GLCD_WriteString(const char *str);
/**
 * Draw a line (one pixel thickness) from 2 specified points inside the screen.
 * @param x1: first horizontal position
 * @param y1: first vertical position
 * @param x2: second horizontal position
 * @param y2: second vertical position
 * @param color: BLACK or WHITE
 */
void D_GLCD_DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t color);
/**
 * Draw a rectangle (one pixel lines) with a start position on the screen.
 * @param x: Horizontal start position
 * @param y: Vertical start position
 * @param width: Width of the rectangle (in the x direction)
 * @param height: Height of the rectangle (in the y direction)
 * @param color: BLACK or WHITE
 */
void D_GLCD_DrawRect(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t color);
/**
 * Draw a rectangle (one pixel lines) with a start position on the screen. The 
 * corners of the rectangle can be rounded with the radius parameter.
 * @param x: Horizontal start position
 * @param y: Vertical start position
 * @param width: Width of the rectangle (in the x direction)
 * @param height: Height of the rectangle (in the y direction)
 * @param radius: The radius of the rounded corner in pixels
 * @param color: BLACK or WHITE
 */
void D_GLCD_DrawRoundRect(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t radius, uint8_t color);
/**
 * Draw a rectangle filled in the specified color,  with a start position on the screen.
 * @param x: Horizontal start position
 * @param y: Vertical start position
 * @param width: Width of the rectangle (in the x direction)
 * @param height: Height of the rectangle (in the y direction)
 * @param color: BLACK or WHITE
 */
void D_GLCD_FillRect(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint8_t color);
/**
 * Takes a rectangular portion of the screen, and inverts it.
 * @param x: Horizontal start position
 * @param y: Vertical start position
 * @param width: Width of the rectangle (in the x direction)
 * @param height: Height of the rectangle (in the y direction)
 * @param color: BLACK or WHITE
 */
void D_GLCD_InvertRect(uint8_t x, uint8_t y, uint8_t width, uint8_t height);
/**
 * Draw a vertical line (one pixel thick) on the screen.
 * @param x: Horizontal start position
 * @param y: Vertical start position
 * @param length: Length of the line
 * @param height: Height of the rectangle (in the y direction)
 * @param color: BLACK or WHITE
 */
void D_GLCD_DrawVertLine(uint8_t x, uint8_t y, uint8_t length, uint8_t color);
/**
 * Draw a horizontal line (one pixel thick) on the screen.
 * @param x: Horizontal start position
 * @param y: Vertical start position
 * @param length: Length of the line
 * @param height: Height of the rectangle (in the y direction)
 * @param color: BLACK or WHITE
 */
void D_GLCD_DrawHoriLine(uint8_t x, uint8_t y, uint8_t length, uint8_t color);
/**
 * Draw a circle on the screen.
 * @param xCenter: Horizontal position of the center
 * @param yCenter: Vertical position of the center
 * @param radius: Radius of the circle, in pixels
 * @param color: BLACK or WHITE
 */
void D_GLCD_DrawCircle(uint8_t xCenter, uint8_t yCenter, uint8_t radius, uint8_t color);
/**
 * Invert the screen
 * @param invert: INVERTED or NON_INVERTED
 */
void D_GLCD_SetInverted(bool invert);
/**
 * Print a positive number up to 10 digits on the screen.
 * @param n: number
 */
void D_GLCD_PrintNumber(long n);
void D_GLCD_PrintNumberAt(long n, uint8_t x, uint8_t y);
/**
 * Print the hexadecimal presentation of a positive number on the screen.
 * @param n: number
 */
void D_GLCD_PrintHexNumber(uint16_t n);
/**
 * Print a real number on the screen up to 10 digits.
 * @param n: the number
 */
void D_GLCD_PrintRealNumber(double n);

    
    
#ifdef	__cplusplus
}
#endif

#endif	/* GLCD_DRIVER_H */