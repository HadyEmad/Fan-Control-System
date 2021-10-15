/******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: dc_motor.c
 *
 * Description: Source file for the dc motor driver
 *
 * Author: Hady Emad
 *
 *******************************************************************************/

#include "gpio.h"
#include "pwm.h"
#include "common_macros.h"
#include "dc_motor.h"

/*
 * Setting the DC motor direction pins as output and initialising them by 0
 */

void DcMotor_init(void){
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);
	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	uint8 port_value = 0;
	PWM_Timer0_Start(speed); /* Setting motor speed */
	port_value = GPIO_readPort(DC_MOTOR_PORT); /* Setting motor state by writing state value to their port position*/
	port_value = (port_value & 0xFC) | state;
	GPIO_writePort (DC_MOTOR_PORT,port_value);
}


