/*
 *   ADC_registers.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Burners Team
 *      Layer: MCAL
 */

#ifndef ADC_REGISTERS_H_
#define ADC_REGISTERS_H_
/**************************************************************************************/
/********************************** Register File *************************************/
/**************************************************************************************/
//ADC multiplexer selection register
#define ADMUX_REG	    	*((volatile u8 *)0x27)

#define ADMUX_REFS1			7               //Reference selection bit1

#define ADMUX_REFS0			6			    //Reference selection bit0

#define ADMUX_ADLAR         5				//ADC Left adjust result


/*ADC control and status register A*/
#define ADCSRA_REG		    *((volatile u8 *)0x26)
#define ADCSRA_ADEN			7							//ADC enable
#define ADCSRA_ADSC			6							//Start conversion (Single conversion mode)
#define ADCSRA_ADATE		5							//Auto trigger enable ( Auto trigger mode )
#define ADCSRA_ADIF			4							//Interrupt flag (Auto clear when the ADC finished conversion will Set the Flag )
#define ADCSRA_ADIE			3							//Interrupt enable (PIE from ADC enable)
#define ADCSRA_ADPS2		2							//Pre_Scaler Bit2
#define ADCSRA_ADPS1		1							//Pre_Scaler Bit1
#define ADCSRA_ADPS0		0							//Pre_Scaler Bit0

/*ADC RIGHT register (Right Adjust 10 Bits )*/
#define ADC_REG				*((volatile u16 *)0x24)
/*ADC high register	(Left Adjust 8 Bits)*/
#define ADCH_REG			*((volatile u8 *)0x25)
/*ADC low register*/
#define ADCL_REG			*((volatile u8 *)0x24)

/*ADC Special Function I/O Register*/
#define SFIOR_REG			*((volatile u8 *)0x50)
#define SFIOR_ADTS2			7                         	//Trigger Source bit2
#define SFIOR_ADTS1	     	6                         	//Trigger Source bit1
#define SFIOR_ADTS0		    5                         	//Trigger Source bit0



#endif /* ADC_REGISTERS_H_ */
