/******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: dc_motor.h
 *
 * Description: Header file for the dc motor driver
 *
 * Author: Hady Emad
 *
 *******************************************************************************/


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define DC_MOTOR_PORT PORTB_ID
#define DC_MOTOR_IN1_PIN PIN0_ID
#define DC_MOTOR_IN2_PIN PIN1_ID

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum{
	FAN_OFF,FAN_ACW,FAN_CW
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* Function to initialise DC motor pins */

void DcMotor_init(void);

/* Function to set speed and direction of the DC motor */

void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
