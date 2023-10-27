/*
 * TIMER0_STD.h
 *
 *  Created on: 26 Oct 2023
 *      Author: DELL
 */

#ifndef TIMER0_STD_H_
#define TIMER0_STD_H_

typedef enum
{
	NORMAL_OVF=0,
	PWM_PHASECORRECT,
	CTC,
	FAST_PWM
}MODE_t;

typedef enum
{
	DISCONNECTED=0,
	SETonTOP_CLEARonCOMPARE,
	SETonCOMPARE_CLEARonTOP,
	SETonCOMPdownCounting_CLEARonCOMPupCounting,
	SETonCOMPupCounting_CLEARonCOMPdownCounting,
}OC0_MODE_t;
typedef enum
{
	NO_CLK_SOURCE_TIMER_STOPED        =  0u   ,
	NOT_USE_PRESCALER                 =  1u   ,
	PRESCALER_DIVISION_BY_8           =  8u   ,
	PRESCALER_DIVISION_BY_64          =  64u  ,
	PRESCALER_DIVISION_BY_256         =  256u ,
	PRESCALER_DIVISION_BY_1024        =  1024u,
	EXTERNAL_CLK_SOURCE_FALLING_EDGE  =  6u  ,
	EXTERNAL_CLK_SOURCE_RAISING_EDGE  =  7u   ,
}PRESCALER_t;
typedef struct
{
	 MODE_t MODE;
	 OC0_MODE_t OC0_MODE ;
	 PRESCALER_t PRESCALER;

}Timer0Confg_t;

#endif /* TIMER0_STD_H_ */
