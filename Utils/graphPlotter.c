#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>
#include <string.h>

#include "graphPlotter.h"
#include "../Drivers/GLCD_Driver.h"

/*******************************************************************************
 *          DEFINES
 ******************************************************************************/


/*******************************************************************************
 *          MACRO FUNCTIONS
 ******************************************************************************/

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
