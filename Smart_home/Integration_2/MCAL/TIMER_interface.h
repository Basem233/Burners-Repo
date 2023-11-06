/******************************************************/
/******************************************************/
/**************		Author:Basem Moufreh 	***********/
/**************		Layer:MCAL    			***********/
/**************		SWC:Timer				***********/
/**************		Version:1.00			***********/

/*Preprocessor file guard*/
#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER0_voidInit(void);

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));

void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value);

#endif
