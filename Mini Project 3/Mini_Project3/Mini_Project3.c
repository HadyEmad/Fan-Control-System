/******************************************************************************
 *
 * Project: Mini Project 3
 *
 * File Name: Mini_Project3.c
 *
 * Description: Main file of the project
 *
 * Author: Hady Emad
 *
 *******************************************************************************/

#include "adc.h"
#include "lcd.h"
#include "lm35.h"
#include "dc_motor.h"


int main(){
	ADC_ConfigType adc_config ={V_INTERNAL,FCPU_8}; /* Configuring V reference to be 2.56 and ADC prescaler to be FCPU/8 */
	LCD_init(); /* Initialising LCD module */
	ADC_init(&adc_config); /* Initialising ADC module by passing configuration struct by address */
	DcMotor_init(); /* Initialising DC motor module */
	uint8 Temperature;
	DcMotor_State Fan_state ;
	DcMotor_State Fan_direction =FAN_CW ;

	/*
	 * Get the temperature using LM35 module and evaluate it, and according to each
	 * temperature the DC motor will operate at specified speed, then display the temperature and fan state
	 */

	while(1){

		Temperature = LM35_getTemperature();
		 if(Temperature<30){
			 Fan_state = FAN_OFF;
			 DcMotor_Rotate(Fan_state,0);
		 }else if((Temperature>=30) && (Temperature<60)){
			 Fan_state = Fan_direction;
			 DcMotor_Rotate(Fan_state,25);
		 }else if((Temperature>=60)&& (Temperature<90)){
			 Fan_state = Fan_direction;
			 DcMotor_Rotate(Fan_state,50);
		 }else if((Temperature>=90)&& (Temperature<120)){
			 Fan_state = Fan_direction;
			 DcMotor_Rotate(Fan_state,75);
		 }else if(Temperature>=120){
			 Fan_state = Fan_direction;
			 DcMotor_Rotate(Fan_state,100);
		 }

		 LCD_displayStringRowColumn(0,3,"FAN is ");
		 if(Fan_state == FAN_OFF){
			 LCD_displayString("OFF");
		 }else {
			 LCD_displayString("ON ");
		 }
		 LCD_displayStringRowColumn(1,2,"Temp = ");
		 LCD_intgerToString(Temperature);
		 LCD_displayString(" C ");
	}
}
