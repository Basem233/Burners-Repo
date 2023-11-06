/**********************************************************/
/**************** Auther: Basem Moufreh *******************/ 
/**************** Layer: MCAL		 	*****************/
/****************  SWC: USART       	******************/
/****************  Version:1.00         *****************/
/****************  Date:28/8/2022       *****************/
/**********************************************************/
/**********************************************************/
	
#ifndef 		USART_INTERFACE_H_
#define 		USART_INTERFACE_H_

#define USART_u32TIMEOUT 	5000

void USART_voidInit(void);

u8 USART_voidSend(u8 Copy_u8Data);

u8 USART_u8Recieve(u8 * Copy_u8Data);

void USART_voidSendString(const char* Copy_pcString);

#endif
