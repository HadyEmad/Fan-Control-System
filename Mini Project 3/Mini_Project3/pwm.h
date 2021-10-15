/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for the ATmega16 PWM driver
 *
 * Author: Hady Emad
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"

/* function to start PWM on pin OC0 with specified duty cycle */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
