#include "std_types.h"
#include"common_macros.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"
#include "ADC_Registers.h"
#include "ADC_interface.h"
//#include<avr/io.h>
void ADC_voidInit (void)
{
	/*configure the reference volt to ADC */

#if ADC_u8REFERENCE_SELECTION ==   AREF
	CLEAR_BIT(ADMUX,ADMUX_REFS0);
	CLEAR_BIT(ADMUX,ADMUX_REFS1);

#elif ADC_u8REFERENCE_SELECTION == AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLEAR_BIT(ADMUX,ADMUX_REFS1);
#elif	ADC_u8REFERENCE_SELECTION == INTERNAL_2560mv_VOLTAGE_REFERENCE
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#else
	#error wrong ADC_u8REFERENCE_SELECTION configuration option
#endif

	/*configure the resolution to ADC */

#if ADC_u8RESOLUTION == EIGHT_BITS
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif ADC_u8RESOLUTION == TEN_BITS
	CLEAR_BIT(ADMUX,ADMUX_ADLAR);

#else
	#error wrong ADC_u8RESOLUTION configuration option

#endif
	/*configure the interrupt status of ADC */

#if ADC_u8INTERRUPT_ENABLE == ENABLED
	SET_BIT(ADCSRA,ADCSRA_ADIE);

#elif    ADC_u8INTERRUPT_ENABLE == DISABLED
	CLEAR_BIT(ADCSRA,ADCSRA_ADIE);
//#else #error wrong ADC_u8INTERRUPT_ENABLE configuration option

#endif

	/*configure auto trigger mode */
#if ADC_u8AUTO_TRIGGER_MODE == ENABLED
	SET_BIT(ADCSRA,ADCSRA_ADATE);

	/*set the auto trigger source*/
	SFIOR &= ~(AUTO_TRIGGER_MASK << 5 );
	SFIOR |=  (ADC_AUTO_TRIGGER_SOURECE_SELECTION << 5 );
#elif ADC_u8AUTO_TRIGGER_MODE == DISABLED
	CLEAR_BIT(ADCSRA,ADCSRA_ADATE);

//#else #error wrong ADC_u8AUTO_TRIGGER_MODE configuration option

#endif
	/*configure the prescaler bits*/
	ADCSRA &= ~(PRESCALER_MASK);
	ADCSRA |= ADC_u8PRESCALER_VALUE ;

	/*ADC Enable*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);

}
uint16 ADC_u16GetChannelReading (ADC_Channel_SingleEnded_t Copy_u8Channel )
{
	ADMUX &=  ~ (CHANNEL_MASK) ;
	ADMUX |= Copy_u8Channel ;

	/*START CONVERSION*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*BUSY WAIT FOR CONVERSION COMPLTETE*/
	while( GET_BIT(ADCSRA,ADCSRA_ADIF )==0);

	/*CLEAR THE CONVERION COMPLETE FLAG*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

#if ADC_u8RESOLUTION == EIGHT_BITS
	return ADCH ;

#elif 	ADC_u8RESOLUTION == TEN_BITS
	return ADC ;

#endif




}

