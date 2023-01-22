/*
 * dc_motor.h
 *
 *  Created on: Oct 8, 2022
 *      Author: Mahmoud Qotp
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "gpio.h"
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DC_MOTOR_PORT PORTB_ID

#define DC_MOTOR_PIN0 PIN0_ID
#define DC_MOTOR_PIN1 PIN1_ID

#define DC_MOTOR_OFF 0
#define DC_MOTOR_QUARTER_SPEED 25
#define DC_MOTOR_HALF_SPEED 50
#define DC_MOTOR_THREE_QUARTERS_SPEED 75
#define DC_MOTOR_FULL_SPEED 100

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum{
	STOP, CW, ACW
}DcMotor_State;


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * [Function Name]: DcMotor_Init
 * [Function Description]: This Function should initialize the DC Motor peripheral by setting the direction
 * 						   for the two input pins of the DC motor, using GPIO Driver
 *
 * Inputs: No inputs.
 * Outputs: No Outputs.
*/
void DcMotor_Init(void);

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
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
