#include "STD_TYPES.h"
#include "util/delay.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"

PIN_CONFIG RS_LOW = {CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW};
PIN_CONFIG RS_HIGH = {CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH};

PIN_CONFIG RW_LOW = {CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW};
PIN_CONFIG RW_HIGH = {CLCD_CONTROL_PORT,CLCD_RW_PIN,DIO_u8PIN_HIGH};

PIN_CONFIG EN_LOW = {CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW};
PIN_CONFIG EN_HIGH = {CLCD_CONTROL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH};



u8 HAL_CLCD_u8Init(void)
{
	u8 Local_u8ErrorState=OK;

	#if CLCD_MODE == CLCD_8BIT_MODE
	/*1-Wait more than 30 ms*/
	_delay_ms(40);

	/*Function set Command : 2 Lines (1), 5*8 Font size (0)*/
	HAL_CLCD_u8SendCommand(0b00111000);

	/*Display on/off control:Enable display(1),Disable cursor(0),no Blink cursur(0)*/
	HAL_CLCD_u8SendCommand(0b00001100);

	/*Clear display*/
	HAL_CLCD_u8SendCommand(1);//0b00000001

#elif CLCD_MODE == CLCD_4BIT_MODE
	_delay_ms(40);
	/*Set 4 bit mode*/
	HAL_CLCD_u8SendCommand(0b0010);
	/*Function Set*/
	HAL_CLCD_u8SendCommand(0b00101000);
	_delay_us(45);
	//set display on/off control
	HAL_CLCD_u8SendCommand(0b00001111);

	_delay_us(45);
	//set display clear
	HAL_CLCD_u8SendCommand(0b00000001);
	_delay_ms(2);
	//set entry mode
	HAL_CLCD_u8SendCommand(0b00000110);

#endif

	return Local_u8ErrorState;
}


u8 HAL_CLCD_u8SendCommand(u8 Copy_u8Command)
{
	u8 Local_u8ErrorState=OK;

	#if CLCD_MODE == CLCD_8BIT_MODE
	/*SET RS Pin to LOW For command*/
	DIO_u8SetPinValue(&RS_LOW);

	/*SET RW Pin to LOW To Write*/
	DIO_u8SetPinValue(&RW_LOW);


	PORT_CONFIG PORT_COM = {CLCD_DATA_PORT,Copy_u8Command};
	/*Set Command to Data Pins*/
	DIO_u8SetPortValue(&PORT_COM);

	/*Send Enable Pulse*/
	DIO_u8SetPinValue(&EN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(&EN_LOW);

#elif CLCD_MODE == CLCD_4BIT_MODE

	/*SET RS Pin to LOW For command*/
	DIO_u8SetPinValue(&RS_LOW);

	/*Send Higher data*/
	DIO_u8SetPinValue(&EN_HIGH);
	_delay_ms(9);
	u8 datah=((Copy_u8Command >>4)&0x07) | (((Copy_u8Command >>4)&(0x08))<<1);
	PORT_CONFIG Send_datah ={CLCD_DATA_PORT,datah};
	DIO_u8SetPortValue(&Send_datah);
	/*Send Enable Pulse*/

	DIO_u8SetPinValue(&EN_LOW);
	_delay_ms(9);

	/*Send Lower data*/
	DIO_u8SetPinValue(&EN_HIGH);
	_delay_ms(9);
	u8 datal=(Copy_u8Command & 0x07) | (((Copy_u8Command)&(0x08))<<1);
	PORT_CONFIG Send_datal ={CLCD_DATA_PORT,datal};
	DIO_u8SetPortValue(&Send_datal);
	/*Send Enable Pulse*/

	DIO_u8SetPinValue(&EN_LOW);
	_delay_ms(9);

#endif

	return Local_u8ErrorState;
}

u8 HAL_CLCD_u8SendData(u8 Copy_u8Data)
{
	u8 Local_u8ErrorState = OK;
	#if CLCD_MODE == CLCD_8BIT_MODE
	/*SET RS Pin to HIGH For Data*/
	DIO_u8SetPinValue(&RS_HIGH);

	/*SET RW Pin to LOW To Write*/
	DIO_u8SetPinValue(&RW_LOW);


	PORT_CONFIG PORT_DATA = {CLCD_DATA_PORT,Copy_u8Data};
	/*Set Data to Data Pins*/
	DIO_u8SetPortValue(&PORT_DATA);

	/*Send Enable Pulse*/
	DIO_u8SetPinValue(EN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(EN_LOW);

#elif CLCD_MODE == CLCD_4BIT_MODE


	/*SET RS Pin to HIGH For Data*/
	DIO_u8SetPinValue(&RS_HIGH);

	/*Send Higher data*/
	DIO_u8SetPinValue(&EN_HIGH);
	_delay_ms(9);
	u8 datah=((Copy_u8Data >>4)&0x07) | (((Copy_u8Data >>4)&(0x08))<<1);
	PORT_CONFIG Send_datah ={CLCD_DATA_PORT,datah};
	DIO_u8SetPortValue(&Send_datah);
	/*Send Enable Pulse*/

	DIO_u8SetPinValue(&EN_LOW);
	_delay_ms(9);

	/*Send Lower data*/
	DIO_u8SetPinValue(&EN_HIGH);
	_delay_ms(9);
	u8 datal=(Copy_u8Data & 0x07) | (((Copy_u8Data)&(0x08))<<1);
	PORT_CONFIG Send_datal ={CLCD_DATA_PORT,datal};
	DIO_u8SetPortValue(&Send_datal);
	/*Send Enable Pulse*/

	DIO_u8SetPinValue(&EN_LOW);
	_delay_ms(9);

#endif

	return Local_u8ErrorState;
}


/*Ay haga hthsel askii value yb2a lazm tkon char*/
u8 HAL_CLCD_u8SendString(const char* Copy_pcString)
{
	u8 Local_u8ErrorState=OK;

	#if CLCD_MODE == CLCD_8BIT_MODE
	u8 Local_u8Counter = 0;
	while (Copy_pcString[Local_u8Counter] !='\0')
	{
		HAL_CLCD_u8SendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}

#elif CLCD_MODE == CLCD_4BIT_MODE
	u8 Local_u8Counter = 0;
	while (Copy_pcString[Local_u8Counter] !='\0')
	{
		HAL_CLCD_u8SendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
#endif

	return Local_u8ErrorState;
}

void HAL_CLCD_u8WriteNumber(u32 Copy_u32Number)
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
		HAL_CLCD_u8SendData(arr[(number /i)%10]);
		i=i/10;
	}
}

u8 HAL_CLCD_u8_ClearDisplay(void)
{
	u8 Local_u8ErrorState =OK;

	HAL_CLCD_u8SendCommand(1);

	return Local_u8ErrorState;
}

