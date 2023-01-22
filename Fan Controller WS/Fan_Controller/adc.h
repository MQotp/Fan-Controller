 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
	AREF, AVCC, RESERVED, INTERNAL
}ADC_ReferenceVoltage;

typedef enum{
	F_CPU_2, F_CPU_2_, F_CPU_4, F_CPU_8, F_CPU_16, F_CPU_32, F_CPU_64, F_CPU_128
}ADC_Prescaler;

/*
 * [Structure Type Name]: ADC_ConfigType
 * [Structure Description]: This structure is responsible of assigning configuration parameters
 * 							of the ADC that is required for dynamic initialization of the ADC.
 *
 * [Structure Members]: 	Variable of type ADC_ReferenceVoltage.
 * 							Variable of type ADC_Prescaler.
 * */
typedef struct{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 * Inputs: pointer to structure of type ADC_ConfigType
 * ADC_ConfigType is a structure of Initializing parameters to dynamically initialize the ADC peripheral.
 * Outputs: No Outputs.
 */

void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 * Inputs: variable of uint8 type contains the Analog channel number.
 * Outputs: variable of uint16 type contains the digital value after converting.
 */

uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
