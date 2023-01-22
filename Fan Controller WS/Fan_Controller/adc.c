 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/


/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */


/*******************************************************************************
 *                           Functions Definitions                             *
 *******************************************************************************/


/*
 * Description :
 * Function responsible for initialize the ADC driver.
 * Inputs: pointer to structure of type ADC_ConfigType
 * ADC_ConfigType is a structure of Initializing parameters to dynamically initialize the ADC peripheral.
 * Outputs: No Outputs.
 */

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 00 to choose to connect external reference voltage by input this voltage through AREF pin
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = 0;
	ADMUX = (ADMUX & (0x3f)) | (((Config_Ptr->ref_volt) & (0x03)) << REFS0);

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADC must operate in range 50-200Khz
	 */
	ADCSRA = (1<<ADEN);
	ADCSRA = ((ADCSRA & (0xf1)) | ((Config_Ptr->prescaler) & (0x07)));
}


/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 * Inputs: variable of uint8 type contains the Analog channel number.
 * Outputs: variable of uint16 type contains the digital value after converting.
 */

uint16 ADC_readChannel(uint8 channel_num)
{
	/* Input channel number must be from 0 --> 7 */
	/* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	/* Choose the correct channel by setting the channel number in MUX4:0 bits */
	ADMUX = ((ADMUX & (0xE0)) | (channel_num & (0x07)));
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}
