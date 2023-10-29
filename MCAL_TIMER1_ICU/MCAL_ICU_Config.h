/******************************************************************************
 *
 * Module: ICU
 *
 * File Name: MCAL_ICU_config.h
 *
 * Description: Header file for the AVR ICU driver (Configurations)
 *
 *******************************************************************************/

#ifndef MCAL_ICU_CONFIG_H_
#define MCAL_ICU_CONFIG_H_
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Icu_Clock;

typedef enum
{
	FALLING,RISING
}Icu_EdgeType;

typedef struct
{
	Icu_Clock clock;
	Icu_EdgeType edge;
}Icu_ConfigType;



#endif /* MCAL_ICU_CONFIG_H_ */
