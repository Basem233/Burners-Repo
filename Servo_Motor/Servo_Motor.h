/****************************************************************************************************************
 * File Name: DC_Motor.h
 * Date: 4/8/2023
 * Driver: DC Motor Driver Header File
 * Author: Youssef Zaki
 ****************************************************************************************************************/



#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_

#include "STD_TYPES.h"

/******************************************************************************************
 *                                    Macros Definitions                                  *
 ******************************************************************************************/

#define SERVO_MOTOR_DIR_ID                  DDRD
#define SERVO_MOTOR_PORT_ID                 PORTD
#define SERVO_MOTOR_PIN_ID                  5



/******************************************************************************************
 *                                     Types Declaration                                  *
 ******************************************************************************************/

typedef enum {
	CLOSE,OPEN
}ServoMotor_State;

/******************************************************************************************
 *                                      Functions Prototypes                              *
 ******************************************************************************************/

/*
 * DESCRIPTION:
 * The Function responsible for setup the direction for the SERVO motor pin through the DIO driver.
 * Initialization of Timer0.
 */
void ServoMotor_Init(void);

/*
 * DESCRIPTION:
 * The function responsible for set the angle of the Servo Motor  based on the state
 * input state value.
 */
void ServoMotor_Rotate(ServoMotor_State state);


#endif
