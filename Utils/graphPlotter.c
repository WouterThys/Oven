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
    D_GLCD_DrawHoriLine(0, GLCD_DISP_HEIGHT-3, GLCD_DISP_WIDTH, GLCD_WHITE);
    D_GLCD_DrawDot(GLCD_DISP_WIDTH-2, GLCD_DISP_HEIGHT-4, GLCD_WHITE);
    D_GLCD_DrawDot(GLCD_DISP_WIDTH-2, GLCD_DISP_HEIGHT-2, GLCD_WHITE);
    D_GLCD_DrawDot(GLCD_DISP_WIDTH-3, GLCD_DISP_HEIGHT-5, GLCD_WHITE);
    D_GLCD_DrawDot(GLCD_DISP_WIDTH-3, GLCD_DISP_HEIGHT-1, GLCD_WHITE);
    
    D_GLCD_WriteStringAt(xUnits, GLCD_DISP_WIDTH-sizeof(xUnits)-7, GLCD_DISP_HEIGHT-12);

    // y-axis
    D_GLCD_DrawVertLine(1, 0, GLCD_DISP_HEIGHT, GLCD_WHITE);
}
