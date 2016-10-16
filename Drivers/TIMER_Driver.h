/*
 * Name:        TIMER driver functions
 * Created by:  Vonny & Waldo
 * date:        21/06/2016
 */
#ifndef TIMER_DRIVER_H
#define	TIMER_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdbool.h>
#include <stdint.h>
    
#define TIMER_1    0x00
#define TIMER_2    0x01
#define TIMER_3    0x02
#define TIMER_4    0x03
    
/*******************************************************************************
 *          Driver functions
 *******************************************************************************/
/**
 * Initialize the timer modules.
 * @param which: TIMER_1, TIMER_2, TIMER_3, TIMER_4
 */    
void D_TIMER_Init(uint8_t which);
/**
 * Enable or disable the timer modules.
 * @param which: TIMER_1, TIMER_2, TIMER_3, TIMER_4
 * @param enable: true - false
 */
void D_TIMER_Enable(uint8_t which, bool enable);
 

#ifdef	__cplusplus
}
#endif

#endif	