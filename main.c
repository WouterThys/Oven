/*
 * File:   main.c
 * Author: wouter
 *
 * Created on October 16, 2016, 1:55 PM
 */

#include <xc.h>
#include <stdbool.h>
#include "Drivers/GLCD_Driver.h"
#include "Drivers/PORT_Driver.h"
#include "Drivers/GLCD_Bitmaps.h"
#include "Drivers/PWM_Driver.h"

#include "Utils/graphPlotter.h"

void main(void) {
    // Basic initializes
    D_PORT_Init();
    
    D_GLCD_Init(false);
    D_GLCD_ClearScreen(GLCD_BLACK);
    
    // Brightness
    D_PWM_Init(PWM_MODULE_1);
    D_PWM_Enabele(PWM_MODULE_1, true);
    D_PWM_SetDuty(PWM_MODULE_1, (0xAD + (0xFF-0xAD)*5/8));
    
    drawAxis("t(s)", "T(C)");
   
    while(1) {
        
    }
    return;
}
