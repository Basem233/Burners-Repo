/**********************************************************/
/**************** Auther: Basem Moufreh *******************/ 
/**************** Layer: MCAL		 	*****************/
/****************  SWC: USART        	******************/
/****************  Version:1.00         *****************/
/****************  Date:28/8/2022       *****************/
/**********************************************************/
/**********************************************************/
	
#ifndef 		USART_REGISTER_H_
#define 		USART_REGISTER_H_

#define		UDR				*((volatile u8*)0x2C)
#define		UCSRA			*((volatile u8*)0x2B)
#define     UCSRA_MPCM		0
#define     UCSRA_U2X		1
#define     UCSRA_PE		2
#define     UCSRA_DOR		3
#define     UCSRA_FE		4
#define     UCSRA_UDRE		5							//Data Register empty
#define     UCSRA_TXC		6							//Transmission complete flag
#define     UCSRA_RXC		7							//Reciving complete flag

#define		UCSRB			*((volatile u8*)0x2A)
#define     UCSRB_TXB8		0
#define     UCSRB_RXB8		1
#define     UCSRB_UCSZ2		2
#define     UCSRB_TXEN		3							//Transimter enable
#define     UCSRB_RXEN		4							//Reciver enable
#define     UCSRB_UDRIE		5
#define     UCSRB_TXCIE		6
#define     UCSRB_RXCIE		7

#define		UCSRC			*((volatile u8*)0x40)
#define     UCSRC_URSEL		7
#define     UCSRC_UMSEL		6
#define     UCSRC_UPM1		5
#define     UCSRC_UPM0		4
#define     UCSRC_USBS		3
#define     UCSRC_UCSZ1		2
#define     UCSRC_UCSZ0		1
#define     UCSRC_UCPOL		0

#define 	SREG 		*((volatile u8*)0x5f)
#define 	SREG_I		7


#define		UBRRL			*((volatile u8*)0x29)		//UBRRL which is USART Baud Rate Register Low Byte

#endif
