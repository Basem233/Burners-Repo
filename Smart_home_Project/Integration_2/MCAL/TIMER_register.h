/******************************************************/
/******************************************************/
/**************		Author:Basem Moufreh 	***********/
/**************		Layer:MCAL    			***********/
/**************		SWC:Timer			***********/
/**************		Version:1.00			***********/

/*Preprocessor file guard*/
#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define 	TCCR0			*((volatile u8*)0x53)		//Timer0 Control register 
#define 	TCCR0_WGM00		6						    //Waveform generation Mode bit0
#define 	TCCR0_WGM01		3                           //waveform generation mode bit1
#define 	TCCR0_CS02		2                           //prescaller bit2
#define 	TCCR0_CS01		1                           //prescaller bit1
#define 	TCCR0_CS00		0                           //presaller bit0

#define 	OCSR0			*((volatile u8*)0x5c)		//Output compare register 0
#define 	TCNT0			*((volatile u8*)0x52)		//Output compare register 0

#define 	TIMSK			*((volatile u8*)0x59)		//Timer mask
#define 	TIMSK_OCIE0		1							//Output compare 0 interrupt enable
#define 	TIMSK_TOIE0		0							//Normal over flow enable

#define 	SREG 		*((volatile u8*)0x5f)
#define 	SREG_I		7
#endif
