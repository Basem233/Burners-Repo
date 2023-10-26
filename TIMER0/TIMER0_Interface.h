/*====================================================================================================*/
/*  File        : TIMER0_Interface.h                                                                  */
/*  Description : This interface file includes TIMER0 Driver prototypes and declarations for Atmega32 */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                                         */
/*  Date        : 7/4/2023                                                                            */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                                           */
/*  Git account : https://github.com/ahmedbahaa11                                                     */
/*  mail        : ahmedbahaataha7@gmil.com                                                            */
/*====================================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

/*============================================================================================================*/
/*===============================     Burners TIMER0 Functions Prototypes       ==============================*/
/*============================================================================================================*/
/***************************  [1]  TIMER0_voidInit                                     ************************/
/***************************  [2]  TIMER0_voidSetCallBack_OVF                          ************************/
/***************************  [3]  TIMER0_voidSetCallBack_CTC                          ************************/
/***************************  [4]  TIMER0_voidSetPreloadValue                          ************************/
/***************************  [5]  TIMER0_voidSetCompareMatchValue                     ************************/
/***************************  [6]  void __vector_11 (void)   __attribute__((signal));  ************************/
/***************************  [7]  void __vector_10 (void)   __attribute__((signal)); ************************/
/*============================================================================================================*/
/*===============================================*/
/*              TIMER0 Mode Selection            */
/*-----------------------------------------------*/
/****************   NORMAL_OVF         **********************/
/****************   PWM_PHASECORRECT   **********************/
/****************   CTC                **********************/
/****************   FAST_PWM           **********************/

/*==========================================================*/
/*               OC0 Mode Selection                         */
/*----------------------------------------------------------*/
/****************   DISCONNECTED                                  **********************/
/****************   SETonTOP_CLEARonCOMPARE                       **********************/
/****************   SETonCOMPARE_CLEARonTOP                       **********************/
/****************   SETonCOMPdownCounting_CLEARonCOMPupCounting   **********************/
/****************   SETonCOMPupCounting_CLEARonCOMPdownCounting   **********************/

/*===============================================*/
/*          TIMER0 Prescaller Selection          */
/*-----------------------------------------------*/
/****************   NO_CLK_SOURCE_TIMER_STOPED        **********************/
/****************   NOT_USE_PRESCALER                 **********************/
/****************   PRESCALER_DIVISION_BY_8           **********************/
/****************   PRESCALER_DIVISION_BY_64          **********************/
/****************   PRESCALER_DIVISION_BY_256         **********************/
/****************   PRESCALER_DIVISION_BY_1024        **********************/
/****************   EXTERNAL_CLK_SOURCE_FALLING_EDGE  **********************/
/****************   EXTERNAL_CLK_SOURCE_RAISING_EDGE  **********************/
/************************************************************************************************/
/* Function Name : TIMER0_voidInit                                                              */
/* Description : Initilization of TIMER0 with Specific Specification according to configuration File.h   */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
STD TIMER0_voidInit (void);

/************************************************************************************************/
/* Function Name : TIMER0_voidSetCallBack_OVF                                                   */
/* Description : Call Back Function To Assign the address of OVF APP. Fun. at Global Pointer    */                                          
/* Fun. Argument1: (*Local_PointerToFunction_OVF) { Address of OVF Application Function }       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
/************************************************************************************************/
STD TIMER0_voidSetCallBack_OVF (void (*Local_PointerToFunction_OVF) (void));
/* Function Name : TIMER0_setPreloadValue                                                      */
/* Description : Set the Preload Value for Timer/Counter 0 (TCNT0) Register                    */
/* Function Argument1: preloadValue (u8) - The value to set as the preload for TCNT0       */
/* Function Return : void                                                                     */
/************************************************************************************************/
STD TIMER0_voidSetPreloadValue(u8 preloadValue);


/************************************************************************************************/
/* Function Name : TIMER0_voidSetCallBack_CTC                                                   */
/* Description : Call Back Function To Assign the address of CTC APP. Fun. at Global Pointer    */                                          
/* Fun. Argument1: (*Local_PointerToFunction_CTC) { Address of CTC Application Function }       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
STD TIMER0_voidSetCallBack_CTC (void (*Local_PointerToFunction_CTC) (void));



/************************************************************************************************/
/* Function Name : TIMER0_voidSetCompareMatchValue                                              */
/* Description : Set Compare Match Value in OCR0 Register To make Timer Over Flow at This Value */                                          
/* Fun. Argument1: Copy_u8CompareMatchValue  { from  0  To  255 }                               */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
STD TIMER0_voidSetCompareMatchValue ( u8 Copy_u8CompareMatchValue );

/**************************************************************************************************/
/* Function Name : TIMER0_voidSetBusyWait_ms                                                      */
/* Description : Set Busy Wait Function work as Delay by make Processor Stuck in Fun. during Time */                                          
/* Fun. Argument1: Copy_u32Time_ms  { any Time in Milliseconds }                                  */
/* Fun. Return : void                                                                             */
/**************************************************************************************************/


#endif
