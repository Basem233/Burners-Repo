/******************************************************************************
 *
 * Module: Main
 *
 * File Name: Ultrasonic_Project.c
 *
 * Description: main file for the Ultrasonic_sensor driver
 * LM35,LDR,PIR
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
	uint8 x;       /*LM35 reading*/
	uint8 reading;  /*LDR reading*/
	uint8 reading_1=0;/*PIR reading*/
	/*Initialize LCD*/
	LCD_init();
	/*Initialize Ultarsonic_Module */
	Ultrasonic_init();
	/*Initialize ADC_Module*/
	ADC_voidInit ();
	/******************************************************/
	/*LDR initialization*/
	/*configure DIO pin as input*/
	GPIO_setupPinDirection(PORTA_ID, PIN0_ID, PIN_INPUT);
	/*configure DIO pin (LEDs) as output*/
	/*Red+Green*/
	GPIO_setupPinDirection(PORTB_ID, PIN7_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTA_ID, PIN4_ID, PIN_OUTPUT);
	/******************************************************/
	/*configure DIO pin (LEDs) as output*/
	/*Blue+Yellow*/
	GPIO_setupPinDirection(PORTA_ID, PIN5_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTA_ID, PIN6_ID, PIN_OUTPUT);
	/******************************************************/
	/*PIR_PIN*/
	GPIO_setupPinDirection(PORTC_ID, PIN1_ID, PIN_INPUT);
	/******************************************************/

	/*ADC1 -> input for LM35*/
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
		/*Checking LDR reading*/
		/********************************************************/
		reading=(uint8)ADC_u16GetChannelReading ( ADC0_SINGLE_ENDED);
		if(reading<100)
		{
			/*LED OFF*/
			GPIO_writePin(PORTB_ID, PIN7_ID,LOGIC_LOW);
			GPIO_writePin(PORTA_ID, PIN4_ID,LOGIC_LOW);

		}
		else
		{
			/*LED ON*/

			GPIO_writePin(PORTB_ID, PIN7_ID,LOGIC_HIGH);
			GPIO_writePin(PORTA_ID, PIN4_ID,LOGIC_HIGH);


		}
		/********************************************************/
		reading_1=GPIO_readPin(PORTC_ID, PIN1_ID);
		if(reading_1)
		{
			/*LED ON*/

			GPIO_writePin(PORTA_ID, PIN5_ID,LOGIC_HIGH);
			GPIO_writePin(PORTA_ID, PIN6_ID,LOGIC_HIGH);
		}
		else
		{
			/*LED OFF*/
			GPIO_writePin(PORTA_ID, PIN5_ID,LOGIC_LOW);
			GPIO_writePin(PORTA_ID, PIN6_ID,LOGIC_LOW);
		}
		/********************************************************/
		/*Read water level*/
		Distance = Ultrasonic_readDistance();
		LCD_moveCursor(0, 11);
		/*Read temperature*/
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

