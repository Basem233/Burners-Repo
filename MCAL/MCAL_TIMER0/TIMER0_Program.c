/*=================================================================================*/
/*  File        : TIMER0_Program.c
/*  Description : This file includes TIMER0 Driver implementations for Atmega32    */
/*  Author      : Burners team . Embedded SW Engineers                      */
/*  Date        : 10/24/2023                                                         */
/*=================================================================================*/

/* Include Header Files From LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Include My own Header Files*/
#include "TIMER0_Register.h"
#include "TIMER0_Interface.h"
#include "TIMER0_Private.h"
#include "TIMER0_STD.h"

void (*Global_PointerToFunction_OVF_T0) (void) = NULL ; 
void (*Global_PointerToFunction_CTC_T0) (void) = NULL ; 
u16 Global_u8PreloadValue = 0 ;
u16 Global_u8CompareMatchValue = 0 ;
u32 Global_u32Time_ms = 0 ;
Timer0Confg_t * GlobalTimer0ConfigStruct ;

/*============================================================================================================*/
/*==============================     Burners TIMER0 Functions Implementation      ============================*/
/*============================================================================================================*/
/***************************  [1]  TIMER0_voidInit                                     ************************/
/***************************  [2]  TIMER0_voidSetCallBack_OVF                          ************************/
/***************************  [3]  TIMER0_voidSetCallBack_CTC                          ************************/
/***************************  [4]  TIMER0_voidSetPreloadValue                          ************************/
/***************************  [5]  TIMER0_voidSetCompareMatchValue                     ************************/
/***************************  [6]  void __vector_11 (void)   __attribute__((signal));  ************************/
/***************************  [7]  void __vector_10 (void)   __attribute__((signal)); ************************/
/*============================================================================================================*/

/************************************************************************************************/
/* Function Name : TIMER0_voidInit                                                              */
/* Description : Initilization of TIMER0 with Specific Specks accordig to Gonfigration File.h   */                                          
/* Fun. Return : void                                                                           */
/************************************************************************************************/
STD TIMER0_voidInit (Timer0Confg_t * Timer0 )
{
	u8 Local_Error_State = E_OK;

	/*======================================*/
	/*======================================*/
	/*    MAke the passed struct as        */
	/*    global to serve another function */
	/*--------------------------------------*/
	GlobalTimer0ConfigStruct= &Timer0;
	/*======================================*/
	/*======================================*/
	/*     TIMER0 Prescaller Selection      */
	/*--------------------------------------*/

	TCCR0_REG &= ~(PRESCALER_MASK<<0); /*to clear the prescler bits*/
	TCCR0_REG |= ((Timer0->PRESCALER) << 0);  //put the value of prescaller directly

	/*======================================*/
	/*         TIMER0 Mode Selection        */
	/*--------------------------------------*/
	switch(Timer0->MODE)
	{
	case NORMAL_OVF : // OVF Normal Mode of Timer/Counter0
		CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_WGM00);
		CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_WGM01);
		SET_BIT(TIMSK_REG,TIMER0_TIMSK_TOIE0);          // Enable T0 OVF Interrupt [PIE].
		break;

	case CTC :		// CTC Mode of Timer/Counter0
		CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_WGM00);
		SET_BIT(TCCR0_REG,TIMER0_TCCR0_WGM01);
		SET_BIT(TIMSK_REG,TIMER0_TIMSK_OCIE0);          // Enable T0 CTC Interrupt [PIE].
		break;
	default :
		Local_Error_State = E_NOT_OK;
		break;
	}
	/*======================================*/
	/*          OC0 Mode Selection          */
	/*--------------------------------------*/
	switch(Timer0->OC0_MODE)
	{
	case DISCONNECTED :
		CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_COM00);
		CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_COM01);
		break;
	case SETonTOP_CLEARonCOMPARE :
		CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_COM00);
		SET_BIT(TCCR0_REG,TIMER0_TCCR0_COM01);
		break;
	case SETonCOMPARE_CLEARonTOP :
		SET_BIT(TCCR0_REG,TIMER0_TCCR0_COM00);
		SET_BIT(TCCR0_REG,TIMER0_TCCR0_COM01);
		break;
	default :
		Local_Error_State = E_NOT_OK;
		break;

	}

	return Local_Error_State;
}


/************************************************************************************************/
/* Function Name : TIMER0_voidSetCallBack_OVF                                                   */
/* Description : Call Back Function To Assign the address of OVF APP. Fun. at Global Pointer    */                                          
/* Fun. Argument1: (*Local_PointerToFunction_OVF) { Address of OVF Application Function }       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
STD TIMER0_voidSetCallBack_OVF (void (*Local_PointerToFunction_OVF) (void))
{
	u8 Local_Error_State = E_OK ;

	if(Local_PointerToFunction_OVF !=  NULL)
	{
		Global_PointerToFunction_OVF_T0 = Local_PointerToFunction_OVF ;
	}
	else
	{
		Local_Error_State = E_NOT_OK;
	}
	return Local_Error_State;
}

/************************************************************************************************/
/* Function Name : TIMER0_voidSetPreloadValue                                                   */
/* Description : Set Preload Value in a Timer Register to Start Count From this Preload Value   */
/* Fun. Argument1: Copy_u8PreloadValue  { from  0  To  255 }                                    */
/* Fun. Return : void                                                                           */
/************************************************************************************************/

STD TIMER0_voidSetPreloadValue(u8 preloadValue)
{
	u8 Local_Error_State = E_OK ;
	if(preloadValue<=MAX_PRELOAD_VALUE)
	{
		// Set the preload value (TCNT0) to the specified value
		TCNT0_REG = preloadValue;
	}
	else
	{
		Local_Error_State = E_NOT_OK;
	}

	return Local_Error_State;
}


/************************************************************************************************/
/* Function Name : TIMER0_voidSetCallBack_CTC                                                   */
/* Description : Call Back Function To Assign the address of CTC APP. Fun. at Global Pointer    */                                          
/* Fun. Argument1: (*Local_PointerToFunction_CTC) { Address of CTC Application Function }       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
STD TIMER0_voidSetCallBack_CTC (void (*Local_PointerToFunction_CTC) (void))
{

	u8 Local_Error_State = E_OK ;

	if(Local_PointerToFunction_CTC !=  NULL)
	{
		Global_PointerToFunction_CTC_T0 = Local_PointerToFunction_CTC ;
	}
	else
	{
		Local_Error_State = E_NOT_OK;
	}
	return Local_Error_State;
}


/************************************************************************************************/
/* Function Name : TIMER0_voidSetCompareMatchValue                                              */
/* Description : Set Compare Match Value in OCR0 Register To make Timer Over Flow at This Value */                                          
/* Fun. Argument1: Copy_u8CompareMatchValue  { from  0  To  255 }                               */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
STD TIMER0_voidSetCompareMatchValue (u8 Local_u8CompareMatchValue)
{
	u8 Local_Error_State = E_OK ;
	switch(GlobalTimer0ConfigStruct->MODE)
	{
	case CTC :
		OCR0_REG = Local_u8CompareMatchValue ;
		Global_u8CompareMatchValue = Local_u8CompareMatchValue ;
		break;
	default:
		Local_Error_State = E_NOT_OK ;
		break;
	}
	return Local_Error_State ;
}



/**************************************************************************************************/
/* Function Name : TIMER0_voidSetBusyWait_ms                                                      */
/* Description : Set Busy Wait Function work as Delay by make Processor Stuck in Fun. during Time */                                          
/* Fun. Argument1: Copy_u32Time_ms  { any Time in Milliseconds }                                  */
/* Fun. Return : void                                                                             */
/**************************************************************************************************/
void TIMER0_voidSetBusyWait_ms ( u32 Copy_u32Time_ms )
{
	CLEAR_BIT(TIMSK_REG,TIMER0_TIMSK_OCIE0);              // Disable T0 CTC Interrupt [PIE].
	u32 Counter_CTC = 0 ;
	TIMER0_voidSetCompareMatchValue (200);
	Counter_CTC = ( Copy_u32Time_ms * 1000UL ) /200 ;     // Counter_CTC = (Required Time(ms) * 1000) / (Compare Match Value)
	u32 iter = 0 ;
	for ( iter =0 ; iter < Counter_CTC ; iter++)
	{
		u8 Local_u8Flag ;
		Local_u8Flag = GET_BIT(TIFR_REG,TIMER0_TIFR_OCF0);
		while ( Local_u8Flag == 0 )
		{
			Local_u8Flag = GET_BIT(TIFR_REG,TIMER0_TIFR_OCF0);      // Polling in the CTC Flag
		}
		SET_BIT(TIFR_REG,TIMER0_TIFR_OCF0);						    // Clear Flag
	}
	SET_BIT(TIMSK_REG,TIMER0_TIMSK_OCIE0);          // Enable T0 CTC Interrupt [PIE].
}




/*=============================================================================================================*/
/* ==========================================         ISR Functions          ==================================*/
/*=============================================================================================================*/

/*****************************************************************************/
/* Function Name : void __vector_11 (void) [ISR Function]                    */
/* Description : ISR Prototype (position 11 on vector table OVF TIMER0 )     */ 
/* Fun. Return : void                                                        */
/*****************************************************************************/
/**************     [ISR] to OVF     *************/
void __vector_11 (void)   __attribute__((signal));
void __vector_11 (void)
{
	if(Global_PointerToFunction_OVF_T0 != NULL)
	{
		Global_PointerToFunction_OVF_T0();
	}
	else
	{
		/*do nothing*/
	}
}

/*****************************************************************************/
/* Function Name : void __vector_10 (void) [ISR Function]                    */
/* Description : ISR Prototype (position 10 on vector table CTC TIMER0 )     */ 
/* Fun. Return : void                                                        */
/*****************************************************************************/
/**************     [ISR] to CTC     *************/
void __vector_10 (void)   __attribute__((signal));
void __vector_10 (void)
{
	if(Global_PointerToFunction_OVF_T0 != NULL)
	{
		Global_PointerToFunction_CTC_T0();
	}
	else
	{
		/*do nothing*/
	}



}

