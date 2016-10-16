#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>
#include <p18f4550.h>

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
void initTimer_1(void);
void initTimer_2(void);
void initTimer_3(void);
void initTimer_4(void);

void initTimer_1() {
    
}

void initTimer_2() {
    //T2CON register settings
    T2CONbits.TMR2ON = 0;
    T2CONbits.T2OUTPS0 = 0;
    T2CONbits.T2OUTPS1 = 0;
    T2CONbits.T2OUTPS2 = 0;
    T2CONbits.T2OUTPS3 = 0;
    T2CONbits.T2CKPS = 0b01;
    PR2 = 0XFF;
    
}

void initTimer_3() {
    
}

void initTimer_4() {
    
}

/*******************************************************************************
 *          DRIVER FUNCTIONS
 ******************************************************************************/
void D_TIMER_Init(uint8_t which) {
    switch(which) {
        case TIMER_1:
            initTimer_1();
            break;
        case TIMER_2:
            initTimer_2();
            break;
        case TIMER_3:
            initTimer_3(); 
           break;
        case TIMER_4:
            initTimer_4();
            break;
        default:
            return;
    }
}

void D_TIMER_Enable(uint8_t which, bool enable) {
    switch(which) {
        case TIMER_1:
            break;
        case TIMER_2:
            T2CONbits.TMR2ON = enable;
            break;
        case TIMER_3:
            break;
        case TIMER_4:
            break;
        default:
            return;
    }    
}
