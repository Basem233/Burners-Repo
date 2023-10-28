/*
 * KeyPad_Program.c
 *
 *  Created on: Oct 26, 2023
 *      Author: Mohamed Safwat
 */

#include "KeyPad_Interface.h"
#define F_CPU 16000000UL
#include <util/delay.h>

KeyPad_Error HAL_Keypad_init(keypad_init_config* ptr)
{
	KeyPad_Error Error_Check=E_NOT_OK;
	ptr->row_0.Copy_u8Direction=DIO_PIN_OUTPUT;
	ptr->row_0.Copy_u8PIN=DIO_PIN5;
	ptr->row_0.Copy_u8PORT=DIO_PORTC;
	ptr->row_0.Copy_u8Value=DIO_PIN_HIGH;
	DIO_u8SetPortDirection(&ptr->row_0);
	DIO_u8SetPinValue(&ptr->row_0);
	////////////////////////
	ptr->row_1.Copy_u8Direction=DIO_PIN_OUTPUT;
	ptr->row_1.Copy_u8PIN=DIO_PIN4;
	ptr->row_1.Copy_u8PORT=DIO_PORTC;
	ptr->row_1.Copy_u8Value=DIO_PIN_HIGH;
	DIO_u8SetPortDirection(&ptr->row_1);
	DIO_u8SetPinValue(&ptr->row_1);
	/////////////////////////
	ptr->row_2.Copy_u8Direction=DIO_PIN_OUTPUT;
	ptr->row_2.Copy_u8PIN=DIO_PIN3;
	ptr->row_2.Copy_u8PORT=DIO_PORTC;
	ptr->row_2.Copy_u8Value=DIO_PIN_HIGH;
	DIO_u8SetPortDirection(&ptr->row_2);
	DIO_u8SetPinValue(&ptr->row_2);
	//////////////////
	ptr->row_3.Copy_u8Direction=DIO_PIN_OUTPUT;
	ptr->row_3.Copy_u8PIN=DIO_PIN2;
	ptr->row_3.Copy_u8PORT=DIO_PORTC;
	ptr->row_3.Copy_u8Value=DIO_PIN_HIGH;
	DIO_u8SetPortDirection(&ptr->row_3);
	DIO_u8SetPinValue(&ptr->row_3);
	//////////////////////
	ptr->col_0.Copy_u8Direction=DIO_PIN_INPUT;
	ptr->col_0.Copy_u8PIN=DIO_PIN7;
	ptr->col_0.Copy_u8PORT=DIO_PORTD;
	DIO_u8SetPortDirection(&ptr->col_0);
	DIO_u8SetPinValue(&ptr->col_0);
	//////////////////////
	ptr->col_1.Copy_u8Direction=DIO_PIN_INPUT;
	ptr->col_1.Copy_u8PIN=DIO_PIN6;
	ptr->col_1.Copy_u8PORT=DIO_PORTD;
	DIO_u8SetPortDirection(&ptr->col_1);
	DIO_u8SetPinValue(&ptr->col_1);
	//////////////////////
	ptr->col_2.Copy_u8Direction=DIO_PIN_INPUT;
	ptr->col_2.Copy_u8PIN=DIO_PIN5;
	ptr->col_2.Copy_u8PORT=DIO_PORTD;
	DIO_u8SetPortDirection(&ptr->col_2);
	DIO_u8SetPinValue(&ptr->col_2);
	//////////////////////
	ptr->col_3.Copy_u8Direction=DIO_PIN_INPUT;
	ptr->col_3.Copy_u8PIN=DIO_PIN3;
	ptr->col_3.Copy_u8PORT=DIO_PORTD;
	DIO_u8SetPortDirection(&ptr->col_3);
	DIO_u8SetPinValue(&ptr->col_3);
	//////////////////////

	Error_Check=E_OK;
	return Error_Check;
}
static KeyPad_Error HAL_keypad_WaitForKeyRelease(void)
{
	KeyPad_Error Error_Check=E_NOT_OK;

	Error_Check=E_OK;
	return Error_Check;
}
static KeyPad_Error HAL_Keypad_WaitForKeyPress(void)
{
	KeyPad_Error Error_Check=E_NOT_OK;

	Error_Check=E_OK;
	return Error_Check;
}

uint8_t HAL_Kepad_GetKey(keypad_init_config* ptr)
{
	keypad_init_config *p=&ptr;
	uint8_t Local_u8_Arr[4][5] =
	{{ '7' , '8' , '9' ,'0', '/' },
			{ '4' , '5' , '6' ,'0', '*' },
			{ '1' , '2' , '3' ,'0', '-' },
			{ 'C' , '0' , '=' , '0','+' }};
	uint8_t Local_u8_Reading = KEYPAD_RELEASED;
	uint8_t Local_u8_Value   = 0;
	uint8_t Local_u8_Row = ptr->row_0.Copy_u8PIN;
	uint8_t Local_u8_Col = ptr->col_0.Copy_u8PIN;
	for (;Local_u8_Row>=ptr->row_3.Copy_u8PIN;Local_u8_Row--)
	{
		ptr->row_0.Copy_u8Value=DIO_PIN_LOW;
	    DIO_u8SetPinValue(&ptr->row_0);
		for (;Local_u8_Col >= ptr->col_3.Copy_u8PIN;Local_u8_Col--)
		{

			if(Local_u8_Col == 4)
			{
				continue;
			}
			else
			{
				DIO_GetPinValue(&ptr->col_0,&Local_u8_Reading);
				if(Local_u8_Reading == KEYPAD_PRESSED)
				{
					_delay_ms(KEYPAD_DEBOUNCING_TIME);
					if(Local_u8_Reading== KEYPAD_PRESSED)
					{
						while(Local_u8_Reading == KEYPAD_PRESSED);
						Local_u8_Value =  Local_u8_Arr[5 - Local_u8_Row][7-Local_u8_Col];
					}
				}
			}
		}
		ptr->row_0.Copy_u8Value=DIO_PIN_HIGH;
	    DIO_u8SetPinValue(&ptr->row_0);
	}
	return Local_u8_Value;
}
