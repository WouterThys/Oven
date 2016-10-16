#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>
#include <p18f4550.h>

#include "PWM_Driver.h"
#include "TIMER_Driver.h"
#include "PORT_Driver.h"

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
 *          BASIC FUNCTIONS
 ******************************************************************************/
void initPwm_1(void);
void initPwm_2(void);

void initPwm_1() {
    // CCP1CON register settings
    CCP1CONbits.DC1B = 0b00;
    CCP1CONbits.CCP1M = 0b1111;
    
    // Initialize Timer 2
    D_TIMER_Init(TIMER_2);
    CCPR1L = 0x00;
    PWM1_PIN_Dir = 0;
}

void initPwm_2() {
    
}

/*******************************************************************************
 *          DRIVER FUNCTIONS
 ******************************************************************************/
 void D_PWM_Init(uint8_t which) {
     if(which == PWM_MODULE_1) {
         initPwm_1();
     } else if(which == PWM_MODULE_2) {
         initPwm_2();
     } else {
         return;
     }
 }

 void D_PWM_SetDuty(uint8_t which, uint8_t duty) {
     if(which == PWM_MODULE_1) {
        CCPR1L = duty;
        
     } else if(which == PWM_MODULE_2) {
         
     } else {
         return;
     }   
 }
 
 void D_PWM_Enabele(uint8_t which, bool enable) {
     if(which == PWM_MODULE_1) {
        D_TIMER_Enable(TIMER_2, enable);
        
     } else if(which == PWM_MODULE_2) {
         
     } else {
         return;
     }   
 }