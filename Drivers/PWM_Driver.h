/*
 * Name:        PWM driver functions
 * Created by:  Vonny & Waldo
 * date:        21/06/2016
 */
#ifndef PWM_DRIVER_H
#define	PWM_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdbool.h>
#include <stdint.h>
    
#define PWM_MODULE_1    0x00
#define PWM_MODULE_2    0x01
    
/*******************************************************************************
 *          Driver functions
 ******************************************************************************/
 /**
 * Initializes all the parameters to the default setting, as well as writing the
 * tri-state registers. 
 * @param which: PWM_MODULE_1 or PWM_MODULE_2 
 */
 void D_PWM_Init(uint8_t which);  

 /**
  * Set the PWM duty cycle
  * @param duty: percentage from 0 to 100
  * @param which: PWM_MODULE_1 or PWM_MODULE_2 
  */
 void D_PWM_SetDuty(uint8_t which, uint8_t duty); 
 /**
  * Enable or disable the PWM.
  * @param enable: true or false
  */
 void D_PWM_Enabele(uint8_t which, bool enable);
 

#ifdef	__cplusplus
}
#endif

#endif	