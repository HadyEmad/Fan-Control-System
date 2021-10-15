 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: Header file for the LM35 Temperature Sensor driver
 *
 * Author: Hady Emad
 *
 *******************************************************************************/

#ifndef LM35_H_
#define LM35_H_

#include "std_types.h"

#define SENSOR_CHANNEL_ID 2
#define SENSOR_RANGE 150
#define SENSOR_MIN_VALUE 0
#define SENSOR_RESOLUTION 0.01

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculating the temperature from the ADC digital value.
 */

uint8 LM35_getTemperature(void);


#endif /* LM35_H_ */
