/**********************************************************/
/**************** Auther: Basem Moufreh *******************/ 
/**************** Layer: MCAL		 	*****************/
/****************  SWC: Timer        	******************/
/****************  Version:1.00         *****************/
/****************  Date:19/10/2023       *****************/
/**********************************************************/
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"
#include "TIMER_register.h"

static void (*TIMER0_pvCallBackFunc)(void)=NULL;

void TIMER0_voidInit(void)
{
	/*Choose CTC (clear timer on compare match)Mode
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);*/

	//Choose FastPWM MODE
	//SET_BIT(TCCR0,TCCR0_WGM00);
	//SET_BIT(TCCR0,TCCR0_WGM01);

	/*Choose normal mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	/*overflow interrupt enable enable*/
	SET_BIT(TIMSK,TIMSK_TOIE0);

	/*Global interrupt enable*/
	SET_BIT(SREG,SREG_I);

	/*Set compare match value to 125*/
	//OCSR0= 125;
	TCNT0=200;

	/*Clear on compare match,Set on top*/
	//SET_BIT(TCCR0,5);
	//CLR_BIT(TCCR0,4);

	/*Presscaler :Division by 1024*/
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
}


void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value)
{
	OCSR0=Copy_u8Value;
}

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorStatus=OK;
	
	/*check if the pointer to function equals to null*/
	if (Copy_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}


	return Local_u8ErrorStatus;
}

