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


void main(void) {
    
    
    D_PORT_Init();
    
    D_GLCD_Init(false);
    D_GLCD_ClearScreen(GLCD_BLACK);
    // D_GLCD_DrawBitmap(SmallPanda,0,0,GLCD_BLACK);
    D_GLCD_DrawRoundRect(0,0,191,63,8,GLCD_WHITE);
    
    // Brightness
    D_PWM_Init(PWM_MODULE_1);
    D_PWM_Enabele(PWM_MODULE_1, true);
    D_PWM_SetDuty(PWM_MODULE_1, (0xAD + (0xFF-0xAD)*5/8));
    
    int i;
    int j = 0;
    for(i=0; i < 192; i++){
        j++;
        if(j == 63){
            j = 0;
        }
        D_GLCD_DrawDot(i,j,GLCD_WHITE);
    }
    
    while(1) {
        
        //PORTAbits.RA1 = !PORTAbits.RA1;
    }
    return;
}
