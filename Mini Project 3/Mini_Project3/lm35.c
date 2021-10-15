/******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: Source file for the LM35 Temperature Sensor driver
 *
 * Author: Hady Emad
 *
 *******************************************************************************/

#include"ADC.h"
#include "lm35.h"

uint8 LM35_getTemperature(void){
	uint16 ADC_reading = 0;
	uint8 Temperature = 0;
	ADC_reading= ADC_readChannel(SENSOR_CHANNEL_ID);
	Temperature= (uint8)(SENSOR_MIN_VALUE+(((uint32)ADC_reading*SENSOR_RANGE*ADC_REF_VOLT)/(SENSOR_RANGE*SENSOR_RESOLUTION*ADC_MAX_VALUE)));
	return Temperature;
}
