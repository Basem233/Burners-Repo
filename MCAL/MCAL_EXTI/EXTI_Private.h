/*=================================================================================*/
/*  File        : EXTI_Private.h                                                   */
/*  Description : This Private file includes EXTI Driver macros for Atmega32       */
//*  Author      : Hassan Elgabas. Embedded SW Engineer                            */
/*  Date        : 6/11/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/hassan-elgabas-63104419b/            */                                                 */
/*  mail        : has.elgabas@gmail.com                                            */
/*=================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* Private Macros */

#define  GICR_REG            *((volatile u8*)0x5B)
#define  MCUCR_REG           *((volatile u8*)0x55)
#define  MCUCSR_REG          *((volatile u8*)0x54)

/* Private Macros to BIT Numbers */
#define  PIN0                    0
#define  PIN1                    1
#define  PIN2                    2
#define  PIN3                    3
#define  PIN4                    4
#define  PIN5                    5
#define  PIN6                    6
#define  PIN7                    7

#define  NULL                     (void*)(0)

#endif