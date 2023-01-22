/*
 * timer0_pwm.c
 *
 *  Created on: Oct 8, 2022
 *      Author: Mahmoud Qotp
 */


#include "timer0_pwm.h"
#include <avr/io.h>
#include "std_types.h"

/*
 * [Function Name]: PWM_Timer0_Start
 * [Function Description]: This Function will start the timer PWM mode with certain duty cycle given in percentage.
 *
 * Inputs: variable of type uint8 represents the percentage of duty_cycle required.
 * Outputs: No Outputs.
*/

void PWM_Timer0_Start(uint8 duty_cycle)
{
	uint8 tempDutyCycle;
	/* Check if duty Cycle is equal to 100 so Set PWM Compare value to 255,
	 * the equation below is going to result 256 In case of 100% duty cycle ( 256 )
	 * which means overflow occurs and we will get 0 motor speed.
	*/
	if(duty_cycle == 100)
	{
		tempDutyCycle = TIMER0_MAX;
	}
	else
	{
		tempDutyCycle = (uint8)(((uint32)(duty_cycle * TIMER0_MAX_COUNTS)/ 100));
	}

	TCNT0 = 0; /* Set Timer Initial Value to 0*/

	OCR0  = tempDutyCycle; /* Set Compare Value*/

	DDRB  = DDRB | (1<<PB3); /* Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC*/

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
