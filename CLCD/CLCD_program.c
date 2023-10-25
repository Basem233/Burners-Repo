#include "STD_TYPES.h"
#include "util/delay.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"


void CLCD_voidInit(void)
{
	#if CLCD_MODE == CLCD_8BIT_MODE
	/*1-Wait more than 30 ms*/
	_delay_ms(40);

	/*Function set Command : 2 Lines (1), 5*8 Font size (0)*/
	CLCD_voidSendCommand(0b00111000);

	/*Display on/off control:Enable display(1),Disable cursor(0),no Blink cursur(0)*/
	CLCD_voidSendCommand(0b00001100);

	/*Clear display*/
	CLCD_voidSendCommand(1);//0b00000001

#elif CLCD_MODE == CLCD_4BIT_MODE
	_delay_ms(40);
	/*Set 4 bit mode*/
	CLCD_voidSendCommand(0b0010);
	/*Function Set*/
	CLCD_voidSendCommand(0b00101000);
	_delay_us(45);
	//set display on/off control
	CLCD_voidSendCommand(0b00001111);

	_delay_us(45);
	//set display clear
	CLCD_voidSendCommand(0b00000001);
	_delay_ms(2);
	//set entry mode
	CLCD_voidSendCommand(0b00000110);

#endif
}


void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	#if CLCD_MODE == CLCD_8BIT_MODE
	/*SET RS Pin to LOW For command*/
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/*SET RW Pin to LOW To Write*/
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*Set Command to Data Pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*Send Enable Pulse*/
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

#elif CLCD_MODE == CLCD_4BIT_MODE

	/*SET RS Pin to LOW For command*/
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/*Send Higher data*/
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(4);
	u8 datah=((Copy_u8Command >>4)&0x07) | (((Copy_u8Command >>4)&(0x08))<<1);
	DIO_u8SetPortValue(CLCD_DATA_PORT,datah);
	/*Send Enable Pulse*/

	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(4);

	/*Send Lower data*/
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(4);
	u8 datal=(Copy_u8Command & 0x07) | (((Copy_u8Command)&(0x08))<<1);
	DIO_u8SetPortValue(CLCD_DATA_PORT,datal);
	/*Send Enable Pulse*/

	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(4);

#endif
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	#if CLCD_MODE == CLCD_8BIT_MODE
	/*SET RS Pin to HIGH For Data*/
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/*SET RW Pin to LOW To Write*/
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*Set Data to Data Pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*Send Enable Pulse*/
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

#elif CLCD_MODE == CLCD_4BIT_MODE

	/*SET RS Pin to HIGH For Data*/
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/*Send Higher data*/
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(4);
	u8 datah=((Copy_u8Data >>4)&0x07) | (((Copy_u8Data >>4)&(0x08))<<1);
	DIO_u8SetPortValue(CLCD_DATA_PORT,datah);
	/*Send Enable Pulse*/

	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(4);

	/*Send Lower data*/
	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(4);
	u8 datal=(Copy_u8Data & 0x07) | (((Copy_u8Data)&(0x08))<<1);
	DIO_u8SetPortValue(CLCD_DATA_PORT,datal);
	/*Send Enable Pulse*/

	DIO_u8SetPinValue(CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	_delay_ms(4);

#endif
}


/*Ay haga hthsel askii value yb2a lazm tkon char*/
void CLCD_voidSendString(const char* Copy_pcString)
{
	#if CLCD_MODE == CLCD_8BIT_MODE
	u8 Local_u8Counter = 0;
	while (Copy_pcString[Local_u8Counter] !='\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}

#elif CLCD_MODE == CLCD_4BIT_MODE
	u8 Local_u8Counter = 0;
	while (Copy_pcString[Local_u8Counter] !='\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD_voidWriteNumber(u32 Copy_u32Number)
{
	u8 arr[10]="0123456789";//To get the askii value
	u8 LoopCounter;
	u32 i = 1;
	u8 counter=0;//value carry the length of the number
	u32 number = Copy_u32Number;//To save the number before counting its element
	/*To count the number required to be displayed*/
	while (Copy_u32Number>0)
	{
		counter++;
		Copy_u32Number =Copy_u32Number/10;
	}
	/*To calculate the number to divide */
	for (LoopCounter=counter-1;LoopCounter>0;LoopCounter--)
	{
		i = i*10;
	}

	/*b2sm el rkm w bb3t l askii bta3o*/
	for (LoopCounter=counter;LoopCounter>0;LoopCounter--)
	{
		CLCD_voidSendData(arr[(number /i)%10]);
		i=i/10;
	}
}

