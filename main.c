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
#include "Drivers/UART_Driver.h"
#include "Utils/graphPlotter.h"

// To test
int8_t points[] = {
    0,0,1,1,2,3,4,5,6,7,
    7,6,6,5,6,7,8,8,9,9,
    10,10,11,13,14,16,17,18,19,20,
    23,25,26,26,26,27,27,27,28,28,
    29,30,30,31,31,30,31,30,29,31,
    32,33,35,36,37,39,41,50,50,50,
    50,50,50,49,49,50,49,48,47,47,
    46,46,46,45,45,44,43,42,41,40,
    39,38,37,36,35,42,32,29,25,20,
    19,18,15,13,10,9,8,6,3,1
};

void main(void) {
    // Basic initializes
    D_PORT_Init();
    
//    D_GLCD_Init(false);
//    D_GLCD_ClearScreen(GLCD_BLACK);
//    
//    // Brightness
//    D_PWM_Init(PWM_MODULE_1);
//    D_PWM_Enabele(PWM_MODULE_1, true);
//    D_PWM_SetDuty(PWM_MODULE_1, (0xAD + (0xFF-0xAD)*5/8));
//    
//    drawAxis("t(s)", "T(C)");
//    drawGraph(points, SizeOfArray(points), false);
    
    D_UART_Init("Panda", 9600, true);
    D_UART_Enable(true);
   
    while(1) {
        if (readReady) {
            D_UART_Write("C", "Got it");
            readReady = false;
        }
        __delay_ms(10);
    }
    return;
}
