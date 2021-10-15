/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: Source file for the ATmega16 PWM driver
 *
 * Author: Hady Emad
 *
 *******************************************************************************/

#include "pwm.h"
#include "common_macros.h"
#include <avr/io.h>

void PWM_Timer0_Start(uint8 duty_cycle){
	SET_BIT(DDRB,PB3); /* Setting OC0 pin as output */
	TCNT0 = 0; /* Setting the initial value of timer */
	OCR0 = (duty_cycle*255)/100; /* Setting the compare value according to required duty cycle */

	/*
	 * WGM 1:0 used to specify timer0 mode
	 * COM 1:0 used to specify pwm mode
	 * CS0 1:0 used to set the prescaler
	 * FOC0 is cleared in pwm mode
	 */
	TCCR0 = (1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS01);
}
