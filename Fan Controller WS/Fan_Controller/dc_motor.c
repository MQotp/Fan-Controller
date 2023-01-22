/*
 * dc_motor.c
 *
 *  Created on: Oct 8, 2022
 *      Author: Mahmoud Qotp
 */

/*******************************************************************************
 *                                   Includes                                  *
 *******************************************************************************/

#include "dc_motor.h"
#include "gpio.h"
#include "std_types.h"
#include "common_macros.h"
#include "timer0_pwm.h"

/*******************************************************************************
 *                             Functions definitions                           *
 *******************************************************************************/
/*
 * [Function Name]: DcMotor_Init
 * [Function Description]: This Function should initialize the DC Motor peripheral by setting the direction
 * 						   for the two input pins of the DC motor, using GPIO Driver
 *
 * Inputs: No inputs.
 * Outputs: No Outputs.
 */
void DcMotor_Init(void){
	/*setup the direction for the two motor pins through the GPIO driver.*/
	GPIO_setupPinDirection(DC_MOTOR_PORT,DC_MOTOR_PIN0,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT,DC_MOTOR_PIN1,PIN_OUTPUT);
	/*Stop at the DC-Motor at the beginning through the GPIO driver.*/
	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN0,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN1,LOGIC_LOW);
}


/*
 * [Function Name]: DcMotor_Init
 * [Function Description]: This Function should take the state and the speed of the motor, based on the state
 * 						   the motor can take one of these states: Stop, Clock-wise rotating, Anti Clock-wise.
 * 						   Based on the given speed, the motor should use the PWM Timer driver to apply the
 * 						   change.
 * [Depends on Drivers]: GPIO driver - PWM Timer driver.
 *
 * Inputs: variable of DcMotor_State type represents the state of the motor.
 * 		   variable of uint8 type represents the speed of the motor.
 * Outputs: No Outputs.
 */

void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	switch (state) {
	case CW:
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN0,LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN1,LOGIC_LOW);
		break;
	case ACW:
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN0,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN1,LOGIC_HIGH);
		break;
		/* Default made to be 00 ( STOP ). */
	default:
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN0,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_PIN1,LOGIC_LOW);
	}

	PWM_Timer0_Start(speed);
}
