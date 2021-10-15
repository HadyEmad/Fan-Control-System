/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the ATmega16 ADC driver
 *
 * Author: Hady Emad
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ADC_MAX_VALUE 1023
#define ADC_REF_VOLT 2.56

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum{
	AREF,AVCC,V_INTERNAL=3
}ADC_ReferenceVolatge;

typedef enum{
	FCPU_2=1,FCPU_4,FCPU_8,FCPU_16,FCPU_32,FCPU_64,FCPU_128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge ref_vol;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialise the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
