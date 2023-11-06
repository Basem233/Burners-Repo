/**********************************************************/
/**************** Auther: Basem Moufreh *******************/
/**************** Layer: MCAL		 	*****************/
/****************  SWC: USART        	******************/
/****************  Version:1.00         *****************/
/****************  Date:28/8/2022       *****************/
/**********************************************************/
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_register.h"
#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"

void USART_voidInit(void)
{
	/*Make u8 variable to Set the bit no 7 to write on USCRC*/
	u8 Local_u8UCSRCVal = 0 ;
	SET_BIT(Local_u8UCSRCVal,7);
	/*8 Bit Data*/
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	SET_BIT(Local_u8UCSRCVal,UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRCVal,UCSRC_UCSZ0);
	UCSRC=Local_u8UCSRCVal;

	/*Use 1 Stop Bit*/
	CLR_BIT(UCSRC,UCSRC_USBS);

	/*No parity bit*/
	CLR_BIT(UCSRC,UCSRC_UPM0);
	CLR_BIT(UCSRC,UCSRC_UPM1);


	/*Set Receive Enable*/
	SET_BIT(UCSRB,UCSRB_RXEN);

	/*Set Transmit Enable*/
	SET_BIT(UCSRB,UCSRB_TXEN);

	/*Set the Baud rate 9600 BPS*/
	UBRRL = 103;			//103 can be assigned to lower register only for 16 MHZ

	/*Set Receive interrupt enable*/
	SET_BIT(UCSRB,UCSRB_RXCIE);


	/*Enable global interrupt*/
	SET_BIT(SREG,SREG_I);

}

u8 USART_u8Recieve(u8 * Copy_u8Data)
{
	u8 Local_u8ErrorState=OK;
	u32 Local_u8Counter=0;
	//Wait until the transmit data register is empty
	while((GET_BIT(UCSRA,UCSRA_UDRE))==0	&&  (Local_u8Counter != USART_u32TIMEOUT))
	{
		Local_u8Counter++;
	}
	if (Local_u8Counter == 0)
	{
		/*Time out reached*/
		Local_u8ErrorState = NOK;
	}
	else
	{
		*Copy_u8Data=UDR;
	}
	return Local_u8ErrorState;
}

u8 USART_voidSend(u8 Copy_u8Data)
{
	u8 Local_u8ErrorState=OK;
	u32 Local_u8Counter=0;
	//Wait until the transmit data register is empty
	while((GET_BIT(UCSRA,UCSRA_UDRE))==0	&&  (Local_u8Counter != USART_u32TIMEOUT))
	{
		Local_u8Counter++;
	}
	if (Local_u8Counter == 0)
	{
		/*Time out reached*/
		Local_u8ErrorState = NOK;
	}
	else
	{
		UDR=Copy_u8Data;
	}
	return Local_u8ErrorState;
}

void USART_voidSendString(const char* Copy_pcString)
{
	u8 Local_u8Counter = 0;
	while (Copy_pcString[Local_u8Counter] !='\0')
	{
		USART_voidSend(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}



