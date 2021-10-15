/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Hady Emad
 *
 *******************************************************************************/


#include "adc.h"
#include "common_macros.h"
#include <avr/io.h>

void ADC_init(const ADC_ConfigType * Config_Ptr){
	/* REFS1:0 = ref_vol in config struct to choose the reference voltage
	 * MUX4:0 =0 to make initial channel ,channel 0
	 * ADLAR = 0 right adjust ADC reg
	 */
	ADMUX = 0;
	ADMUX = ((Config_Ptr->ref_vol)<<6);

	/*
	 * ADEN = 1 to enable ADC module
	 * ADCS will be enabled at the start of the conv
	 * ADPS 2:0 will have the value of the prescaler in config struct
	 */

	ADCSRA = (1<<ADEN);
	ADCSRA = (ADCSRA & 0xE0) | Config_Ptr->prescaler;
}

uint16 ADC_readChannel(uint8 channel_num){
	ADMUX = (ADMUX & 0xE0) | (channel_num & 0x07); /* putting channel number in ADMUX */
	SET_BIT(ADCSRA,ADSC); /* Starting conversion */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* waiting for conversion to be complete */
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}
