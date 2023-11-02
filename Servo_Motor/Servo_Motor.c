#include "STD_TYPES.h"
#include <avr\io.h>
#include <avr/interrupt.h>
#include "Common_Macros.h"
#include "Servo_Motor.h"



volatile uint8_t counter =0;



/*
 * DESCRIPTION:
 * The Function responsible for setup the direction for the SERVO motor pin through the DIO driver.
 * Initialization of Timer0.
 */
void ServoMotor_Init(void)
{
	SET_BIT(SERVO_MOTOR_DIR_ID,SERVO_MOTOR_PIN_ID) ;
	TCCR0 = (1<<WGM01)| (1<<CS01);
	TCNT0 = 0;
}

/*
 * DESCRIPTION:
 * The function responsible for set the angle of the Servo Motor  based on the state
 * input state value.
 */
void ServoMotor_Rotate(ServoMotor_State state)
{



	if(state == OPEN){
		OCR0 = 80;
	}
	else if(state==CLOSE){
		OCR0=0;
	}


	while(BIT_IS_CLEAR(TIFR,OCF0));
	counter++;
	if(counter==3){
		CLEAR_BIT(SERVO_MOTOR_PORT_ID,SERVO_MOTOR_PIN_ID);
	}
	if(counter==40){
		SET_BIT(SERVO_MOTOR_PORT_ID,SERVO_MOTOR_PIN_ID);
		counter = 0;


	}



	TCNT0 = 0;
	SET_BIT(TIFR,OCF0);





}

