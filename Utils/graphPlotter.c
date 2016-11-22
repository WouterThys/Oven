#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <xc.h>
#include <string.h>

#include "graphPlotter.h"
#include "../Drivers/GLCD_Driver.h"

/*******************************************************************************
 *          DEFINES
 ******************************************************************************/

/*******************************************************************************
 *          LOCAL FUNCTIONS
 ******************************************************************************/
void plot(int8_t *p, uint8_t length);
uint8_t* fitPoints(int8_t *p, uint8_t length);
bool isPointTouching(int8_t x1, int8_t y1, int8_t x2, int8_t y2);

/*******************************************************************************
 *          VARIABLES
 ******************************************************************************/

/*******************************************************************************
 *          FUNCTIONS
 ******************************************************************************/
void drawAxis(const char *xUnits, const char *yUnits) {
    // x-axis
    uint8_t lengthToShift = sizeof(xUnits)*7 + 10;
    D_GLCD_WriteStringAt(xUnits, GLCD_DISP_WIDTH-lengthToShift, GLCD_DISP_HEIGHT-12);
    D_GLCD_DrawHoriLine(0, GLCD_DISP_HEIGHT-3, GLCD_DISP_WIDTH, GLCD_WHITE);
    D_GLCD_DrawDot(GLCD_DISP_WIDTH-2, GLCD_DISP_HEIGHT-4, GLCD_WHITE);
    D_GLCD_DrawDot(GLCD_DISP_WIDTH-2, GLCD_DISP_HEIGHT-2, GLCD_WHITE);
    D_GLCD_DrawDot(GLCD_DISP_WIDTH-3, GLCD_DISP_HEIGHT-5, GLCD_WHITE);
    D_GLCD_DrawDot(GLCD_DISP_WIDTH-3, GLCD_DISP_HEIGHT-1, GLCD_WHITE);

    // y-axis
    D_GLCD_WriteStringAt(yUnits, 5, 3);
    D_GLCD_DrawVertLine(2, 0, GLCD_DISP_HEIGHT, GLCD_WHITE);
    D_GLCD_DrawDot(1, 1, GLCD_WHITE);
    D_GLCD_DrawDot(3, 1, GLCD_WHITE);
    D_GLCD_DrawDot(0, 2, GLCD_WHITE);
    D_GLCD_DrawDot(4, 2, GLCD_WHITE);
}

void drawGraph(int8_t *p, uint8_t length, bool fit) {
    if (fit) {
        plot(fitPoints(p, length), PLOT_MAX_X_POINTS);
    } else {
        plot(p, length);
    }
}

/*******************************************************************************
 *          LOCAL FUNCTIONS
 ******************************************************************************/

void plot(int8_t *p, uint8_t length) {
    uint8_t i;
    for (i = 0; i < length; i++) {
        if (p[i] > 0) {
            int8_t x = PLOT_ORIGIN_X + i;
            int8_t y = PLOT_ORIGIN_Y - p[i];

            D_GLCD_DrawDot(x, y, GLCD_WHITE);
        }
    }
}

uint8_t* fitPoints(int8_t *p, uint8_t length) {
    int8_t fitted[PLOT_MAX_X_POINTS];
    uint8_t i = 0;
    uint8_t cnt = 0;
    uint8_t xFactor = 0;
    int8_t maxVal = 0;
    double max = 0;
    double len = 0;
    double fac = 0;
    
//    for (i = 0; i < length; i++) {
//        if (i > maxVal) maxVal = i;
//    }
//    double max = PLOT_MAX_Y_POINTS;
//    double len = maxVal;
//    int8_t yFitted[];
//    for (i = 0; i < length; i++) {
//        double pa = (double)p[i];
//        double pb = (pa/len)*max;
//        yFitted[i] = (int8_t)pb;
//    }
    
    max = PLOT_MAX_X_POINTS;
    len = length;
    fac = (max / len) + 0.5;
    xFactor = (uint8_t)fac;

    for (i = 0; i < PLOT_MAX_X_POINTS; i++) {
        if ((i % xFactor) == 0) {
            fitted[i] = p[cnt];//yFitted[cnt];
            cnt++;
        } else {
            fitted[i] = -1;
        }
    }
    
    return fitted;
}

bool isPointTouching(int8_t x1, int8_t y1, int8_t x2, int8_t y2) {
    if (x1+1 == x2 && y1 == y2) return true; 
    if (x1-1 == x2 && y1 == y2) return true;  
    if (y1+1 == y2 && x1 == x2) return true;  
    if (y1-1 == y2 && x1 == x2) return true; 
    
    // Diagonals
    if (x1+1 == x2 && y1+1 == y2) return true;
    if (x1+1 == x2 && y1-1 == y2) return true;
    if (x1-1 == x2 && y1+1 == y2) return true;
    if (x1-1 == x2 && y1-1 == y2) return true;
    
    return false;
}