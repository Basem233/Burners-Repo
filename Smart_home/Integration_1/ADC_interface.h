/*
 * ADC_interface.h
 *
 *  Created on: 1 Nov 2023
 *      Author: DELL
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef enum
{
	ADC0_SINGLE_ENDED = 0 	,
	ADC1_SINGLE_ENDED		,
	ADC2_SINGLE_ENDED		,
	ADC3_SINGLE_ENDED		,
	ADC4_SINGLE_ENDED		,
	ADC5_SINGLE_ENDED		,
	ADC6_SINGLE_ENDED		,
	ADC7_SINGLE_ENDED		,

}ADC_Channel_SingleEnded_t  ;
void ADC_voidInit (void) ;

uint16 ADC_u16GetChannelReading (ADC_Channel_SingleEnded_t Copy_u8Channel ) ;
#endif /* ADC_INTERFACE_H_ */
