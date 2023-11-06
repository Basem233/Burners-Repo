#include "STD_TYPES.h"
#include <avr/interrupt.h>
#include "Common_Macros.h"
#include "Servo_Motor.h"
#include "TIMER0_Register.h"



volatile uint8_t counter =0;



/*
 * DESCRIPTION:
 * The Function responsible for setup the direction for the SERVO motor pin through the DIO driver.
 * Initialization of Timer0.
 */
u8 ServoMotor_Init(PIN_CONFIG * ptr)
{
	u8 Local_Error_State = 0;
	u8 Local_Error_State1 = 0;
	u8 Local_Error_State2 = 0;
	Timer0Confg_t * Timer0;
	Timer0->PRESCALER = PRESCALER_DIVISION_BY_64;
	Timer0->MODE = CTC;
	Timer0->OC0_MODE = DISCONNECTED;
	Local_Error_State1 = TIMER0_voidInit (Timer0 );
	Local_Error_State2 = DIO_u8SetPinDirection(ptr);
	Local_Error_State = Local_Error_State1 | Local_Error_State2;
	return Local_Error_State;
}

/*
 * DESCRIPTION:
 * The function responsible for set the angle of the Servo Motor  based on the state
 * input state value.
 */
void ServoMotor_Rotate(PIN_CONFIG * ptr,ServoMotor_State state)
{



	if(state == OPEN){
		OCR0_REG = 195;
	}
	else if(state==CLOSE){
		OCR0_REG=30;
	}


	while(BIT_IS_CLEAR(TIFR,OCF0));
	counter++;
	if(counter==3){
		ptr->Copy_u8Value = DIO_PIN_LOW;
		DIO_u8SetPinValue(ptr);
	}
	if(counter==40){
		ptr->Copy_u8Value = DIO_PIN_HIGH;
		DIO_u8SetPinValue(ptr);
		counter = 0;


	}



	TCNT0_REG = 0;
	SET_BIT(TIFR,OCF0);





}

