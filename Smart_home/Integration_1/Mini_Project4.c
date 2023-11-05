/******************************************************************************
 *
 * Module: Main
 *
 * File Name: Ultrasonic_Project.c
 *
 * Description: main file for the Ultrasonic_sensor driver
 *
 * Author: Ahmed_Salah
 *
 *******************************************************************************/
#include <avr/io.h>
#include <util/delay.h>
#include"gpio.h"
#include "lcd.h"
#include "ultrasonic.h"
#include"ADC_interface.h"
#include"LM35_interface.h"


int main(void)
{
	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);
	uint16 Distance;
	uint8 temp;
	uint8 x;
	/*Initialize LCD*/
	LCD_init();
	/*Initialize Ultarsonic_Module */
	Ultrasonic_init();
	/*Initialize ADC_Module*/
	ADC_voidInit ();


	GPIO_setupPinDirection(PORTA_ID, PIN1_ID, PIN_INPUT);
	LCD_moveCursor(0,0);
	LCD_displayString("   'SmartLink'   ");
	_delay_ms(2000);
	LCD_clearScreen();
	LCD_displayString("    'Burners'    ");
	_delay_ms(2000);
	LCD_clearScreen();
	LCD_moveCursor(0,0);
	LCD_displayString("WaterLevel:    %");
	LCD_moveCursor(1,0);
	LCD_displayString("Temp:   C");

	while(1)
	{
		Distance = Ultrasonic_readDistance();
		LCD_moveCursor(0, 11);
         x=(uint8)ADC_u16GetChannelReading ( ADC1_SINGLE_ENDED);
		temp=LM35_u8GetTemp(x);
		/*Display water level*/
		if( Distance >= 100 )
		{
			LCD_intgerToString(Distance);
		}
		else
		{
			LCD_intgerToString(Distance);

			/* In case the distance is two, or one number
			 * Print a space after the value to overwrite the previous digit in this location if existed
			 */

			LCD_displayCharacter(' ');
		}

		LCD_moveCursor(1, 5);
		LCD_intgerToString(temp);

	}
}

