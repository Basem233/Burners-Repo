/*
 * ADC_cfg.h
 *
 *  Created on: 1 Nov 2023
 *      Author: DELL
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_
/**************************************************************************************************************/
/**************************************************************************************************************/

/*
 * @details select the voltage reference for the ADC options are : 1- AREF
 * 													               2- AVCC
 * 													               3- INTERNAL_2560mv_VOLTAGE_REFERENCE
 * */

#define ADC_u8REFERENCE_SELECTION   AVCC


/**************************************************************************************************************/
/**************************************************************************************************************/

/*@details Configure the the interrupt enable configuration, options are   1- ENABLED
 * 							                                               2- DISABLED */

#define ADC_u8INTERRUPT_ENABLE  DISABLED

/**************************************************************************************************************/
/**************************************************************************************************************/

/*
 * @details configure ADC Auto Trigger Enable options are : 1- ENABLED
 * 															2- DISABLED
 * */

#define ADC_u8AUTO_TRIGGER_MODE   DISABLED

/*
 *@details   configure Auto Trigger Source Selection options are : 1- FREE_RUNNING_MODE
 *                                                                 2- ANALOG_COMPARATOR
 *                                                                 3- EXTERNAL_INTERRUPT_REQUEST_0
 *                                                                 4- TIMER_COUNTER0_COMPARE_MATCH
 *                                                                 5- TIMER_COUNTER0_OVERFLOW
 *                                                                 6- TIMER_COUNTER1_COMPARE_MATCH_B
 *                                                                 7- TIMER_COUNTER1_OVERFLOW
 *                                                                 8- TIMER_COUNTER1_CAPTURE_EVENT
 * */

#define ADC_AUTO_TRIGGER_SOURECE_SELECTION    FREE_RUNNING_MODE

/**************************************************************************************************************/
/**************************************************************************************************************/

/*@details configure ADC resolution, options are : 1- EIGHT_BITS
 * 									               2- TEN_BITS   */
#define ADC_u8RESOLUTION  EIGHT_BITS

/**************************************************************************************************************/
/**************************************************************************************************************/

/*@details configure ADC prescaler value, options : 1-  ADC_PRESCALER_DIVISIO_FACTOR_BY_2
 *                                                  2-  ADC_PRESCALER_DIVISIO_FACTOR_BY_4
 *                                                  3-  ADC_PRESCALER_DIVISIO_FACTOR_BY_8
 *                                                  4-  ADC_PRESCALER_DIVISIO_FACTOR_BY_16
 *                                                  5-  ADC_PRESCALER_DIVISIO_FACTOR_BY_32
 *                                                  6-  ADC_PRESCALER_DIVISIO_FACTOR_BY_64
 *                                                  7-  ADC_PRESCALER_DIVISIO_FACTOR_BY_128
 * */

#define ADC_u8PRESCALER_VALUE  ADC_PRESCALER_DIVISIO_FACTOR_BY_128

/**************************************************************************************************************/
/**************************************************************************************************************/

#endif /* ADC_CFG_H_ */
