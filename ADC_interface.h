/*
 *   ADC_interface.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Burners Team
 *      Layer: MCAL
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


/*ADC Channel PORTA */
#define CHANNEL_A0		0
#define CHANNEL_A1		1
#define CHANNEL_A2		2
#define CHANNEL_A3		3
#define CHANNEL_A4		4
#define CHANNEL_A5		5
#define CHANNEL_A6		6
#define CHANNEL_A7		7


typedef struct
{
	u8  * Channel;
	u16 * Result;
	u8    Size;
	void (*NotificationFunction)(void);

}Chain_T;



/*Initialization function of ADC*/
void ADC_voidInit(void);

/*Start conversion synch*/
u8 ADC_u16StartConversionSynch(u8 Copy_u8Channel , u16 *Copy_pu16Reading );


/*if you call function pleased enable GIE :)*/

u8 ADC_u16StartConversionAsynch(u8 Copy_u8Channel , u16 *Copy_pu16Reading  , void (*Copy_PvNotificationFunction)(void) );
/*start chain conversion*/
u8 ADC_u8StartChainAsynch(Chain_T *Copy_Chain);


#endif /* ADC_INTERFACE_H_ */
