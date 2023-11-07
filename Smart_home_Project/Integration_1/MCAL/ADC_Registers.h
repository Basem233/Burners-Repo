/*===================================================================================================*/
/*  File        : ADC_Register.h                                                                    */
/*  Description : This ADC_Register file include  ADC registers for Atmega32   */
/*  Author      : Hassan Elgabas.  Embedded SW Engineer                                        */
/*  Date        : 9/10/2022                                                                           */
/*  Linkedin    : /                                          */
/*  Git account :                                                     */
/*  mail        : has.elgbas@gmail.com                                                           */
/*===================================================================================================*/


#ifndef ADC_REGISTERS_H_
#define ADC_REGISTERS_H_

#define ADMUX     *((volatile uint8 *)0x27)   /*ADC Multiplexer Selection Register   */
#define ADMUX_REFS1    7                  /*Reference Selection Bit1             */
#define ADMUX_REFS0    6                 /*Reference Selection Bit0             */
#define ADMUX_ADLAR    5                /*Left Adjust Result bit               */

/*****************************************************************************/
/****************************************************************************/

#define ADCSRA *((volatile uint8 *)0x26)    /*ADC control and status register*/
#define ADCSRA_ADEN        7            /*ADC enable                     */
#define ADCSRA_ADSC        6           /*ADC start conversion           */
#define ADCSRA_ADATE       5          /*ADC auto trigger enable        */
#define ADCSRA_ADIF        4         /*ADC interrupt flag             */
#define ADCSRA_ADIE        3        /*ADC interrupt enable           */

/*******************************************************************/
/******************************************************************/

#define ADCH  *((volatile uint8 *)0x25)    /*ADC data register high*/
#define ADCL  *((volatile uint8 *)0x24)    /*ADC data register low*/
#define ADC   *((volatile uint16 *)0x24)      /*ADC data register*/

/************************************************************/
/***********************************************************/

#define SFIOR  *((volatile uint16 *)0x50)/*ADC data register*/

/*******************************************************/
/******************************************************/
#endif /* ADC_REGISTERS_H_ */
