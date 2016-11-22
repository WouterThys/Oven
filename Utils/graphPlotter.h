#ifndef GRAPHPLOTTER_H
#define	GRAPHPLOTTER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdint.h>
#include <stdbool.h>
    
#include "../Drivers/GLCD_Driver.h"
    
// DEFINES
#define PLOT_ORIGIN_X 2
#define PLOT_ORIGIN_Y (GLCD_DISP_HEIGHT-3)
    
#define PLOT_MAX_X_POINTS   (GLCD_DISP_WIDTH -3)
#define PLOT_MAX_Y_POINTS   (GLCD_DISP_HEIGHT-3)    
    
// MACRO
#define SizeOfArray(a) (int)(sizeof(a) / sizeof(a[0]))    
    
// FUNCTIONS
/**
 * Draws the x and y axis, with units.
 * @param xUnits string with x units.
 * @param yUnits string with y units.
 */
void drawAxis(const char *xUnits, const char *yUnits);

void drawGraph(int8_t *p, uint8_t length, bool fit);
    
#ifdef	__cplusplus
}
#endif

#endif	