

#ifndef SERVO_MOTOR_H_
#define SERVO_MOTOR_H_

#include "STD_TYPES.h"
#include "DIO_interface.h"
/******************************************************************************************
 *                                    Macros Definitions                                  *
 ******************************************************************************************/

#define SERVO_MOTOR_DIR_ID                  DDRB
#define SERVO_MOTOR_PORT_ID                 DIO_PORTB
#define SERVO_MOTOR_PIN_ID                  DIO_PIN3



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
u8 ServoMotor_Init(PIN_CONFIG * ptr);

/*
 * DESCRIPTION:
 * The function responsible for set the angle of the Servo Motor  based on the state
 * input state value.
 */
void ServoMotor_Rotate(PIN_CONFIG * ptr,ServoMotor_State state);

#endif
