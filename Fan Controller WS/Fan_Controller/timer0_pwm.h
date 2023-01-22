/*
 * timer0_pwm.h
 *
 *  Created on: Oct 8, 2022
 *      Author: Mahmoud Qotp
 */

#ifndef TIMER0_PWM_H_
#define TIMER0_PWM_H_
#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define TIMER0_MAX 255
#define TIMER0_MAX_COUNTS 256


/*******************************************************************************
 *                             Functions Prototypes                            *
 *******************************************************************************/

/*
 * [Function Name]: PWM_Timer0_Start
 * [Function Description]: This Function will start the timer PWM mode with certain duty cycle given in percentage.
 *
 * Inputs: variable of type uint8 represents the percentage of duty_cycle required.
 * Outputs: No Outputs.
*/

void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* TIMER0_PWM_H_ */
