/*
 * Buzzer_Program.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Mohamed Safwat
 */
#include "Buzzer_Interface.h"
//GPIO_Pin_Configuration Pin={PORTA,4};

Buzzer_Error HAL_Buzzer_init(Buzzer_CONFIG * ptr)
{
	Buzzer_Error Error_Check =E_NOT_OK;
	ptr->P.Copy_u8Direction=DIO_PIN_OUTPUT;
	ptr->P.Copy_u8PIN=DIO_PIN6;
	ptr->P.Copy_u8PORT=DIO_PORTC;
	Error_Check=E_OK;
	return Error_Check;
}
Buzzer_Error HAL_Buzzer_TurnOn (Buzzer_CONFIG * ptr)
{

	Buzzer_Error Error_Check=E_NOT_OK;
	ptr->P.Copy_u8Value=DIO_PIN_HIGH;
	DIO_u8SetPinValue(&ptr->P);
	Error_Check=E_OK;
	return Error_Check;


	return Error_Check;
}
Buzzer_Error HAL_Buzzer_TurnOff (Buzzer_CONFIG * ptr)
{
	Buzzer_Error Error_Check=E_NOT_OK;
	ptr->P.Copy_u8Value=DIO_PIN_LOW;
	DIO_u8SetPinValue(&ptr->P);Error_Check=E_OK;
	return Error_Check;
}
Buzzer_Error HAL_Buzzer_Toggle (Buzzer_CONFIG * ptr)
{

	Buzzer_Error Error_Check=E_NOT_OK;
	DIO_u8TogglePinValue(@ptr->P);
	Error_Check=E_OK;
	return Error_Check;
}


