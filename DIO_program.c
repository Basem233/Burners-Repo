#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_config.h"
#include "DIO_private.h"



u8 DIO_u8SetPinDirection(PIN_CONFIG * ptr)
{
	u8 Local_u8ErrorState=0;  //This indicate that there is no error
	if(ptr->Copy_u8PIN<=DIO_PIN7)
	{
		if (ptr->Copy_u8Direction ==DIO_PIN_INPUT)//input
		{
			switch(ptr->Copy_u8PORT)
			{
			case DIO_PORTA:CLR_BIT(DDRA,ptr->Copy_u8PIN);break;
			case DIO_PORTB:CLR_BIT(DDRB,ptr->Copy_u8PIN);break;
			case DIO_PORTC:CLR_BIT(DDRC,ptr->Copy_u8PIN);break;
			case DIO_PORTD:CLR_BIT(DDRD,ptr->Copy_u8PIN);break;
			default:Local_u8ErrorState=1;
			}
		}
		else if (ptr->Copy_u8Direction ==DIO_PIN_OUTPUT)//OUTPUT
		{
			switch(ptr->Copy_u8PORT)
			{
			case DIO_PORTA : SET_BIT(DDRA,ptr->Copy_u8PIN);break;
			case DIO_PORTB : SET_BIT(DDRB,ptr->Copy_u8PIN);break;
			case DIO_PORTC : SET_BIT(DDRC,ptr->Copy_u8PIN);break;
			case DIO_PORTD : SET_BIT(DDRD,ptr->Copy_u8PIN);break;
			default:Local_u8ErrorState=1;
			}
		}
		else
		{
			Local_u8ErrorState=1;//ERROR

		}
	}
	else
	{
		Local_u8ErrorState=1;
	}

	return Local_u8ErrorState;

}

u8 DIO_u8SetPortDirection(PORT_CONFIG * ptr)
{
	u8 Local_u8ErrorState=0;  //This indicate that there is no error
	switch(ptr->Copy_u8PORT)
	{
	case DIO_PORTA : DDRA = ptr->Copy_u8Direction;break;
	case DIO_PORTB : DDRB = ptr->Copy_u8Direction;break;
	case DIO_PORTC : DDRC = ptr->Copy_u8Direction;break;
	case DIO_PORTD : DDRD = ptr->Copy_u8Direction;break;
	default:Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue(PIN_CONFIG * ptr)
{
	u8 Local_u8ErrorState=0;  //This indicate that there is no error
	if (ptr->Copy_u8Value ==DIO_PIN_LOW)//LOW
	{
		switch(ptr->Copy_u8PORT)
		{
		case DIO_PORTA : CLR_BIT(PORTA,ptr->Copy_u8PIN);break;
		case DIO_PORTB : CLR_BIT(PORTB,ptr->Copy_u8PIN);break;
		case DIO_PORTC : CLR_BIT(PORTC,ptr->Copy_u8PIN);break;
		case DIO_PORTD : CLR_BIT(PORTD,ptr->Copy_u8PIN);break;
		default:Local_u8ErrorState=1;
		}
	}
	else if (ptr->Copy_u8Value ==DIO_PIN_HIGH)//HIGH
	{
		switch(ptr->Copy_u8PORT)
		{
		case DIO_PORTA:SET_BIT(PORTA,ptr->Copy_u8PIN);break;
		case DIO_PORTB:SET_BIT(PORTB,ptr->Copy_u8PIN);break;
		case DIO_PORTC:SET_BIT(PORTC,ptr->Copy_u8PIN);break;
		case DIO_PORTD:SET_BIT(PORTD,ptr->Copy_u8PIN);break;
		default:Local_u8ErrorState=1;
		}
	}
	else
	{
		Local_u8ErrorState=1; //ERROR

	}
	return Local_u8ErrorState;

}

u8 DIO_u8SetPortValue(PORT_CONFIG * ptr)
{
	u8 Local_u8ErrorState=0;  //This indicate that there is no error
	switch(ptr->Copy_u8PORT)
	{
	case DIO_PORTA : PORTA =ptr->Copy_u8Value;break;
	case DIO_PORTB : PORTB =ptr->Copy_u8Value;break;
	case DIO_PORTC : PORTC =ptr->Copy_u8Value;break;
	case DIO_PORTD : PORTD =ptr->Copy_u8Value;break;
	default:Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}

u8 DIO_GetPinValue(PIN_CONFIG * ptr,u8 *Copy_pu8Value)
{
	u8 Local_u8ErrorState=0;  //This indicate that there is no error
	if ((Copy_pu8Value!=NULL) && (ptr->Copy_u8PIN<=DIO_PIN7))// Check if the pointer equals to null
	{
		switch(ptr->Copy_u8PORT)
		{
		case DIO_PORTA : *Copy_pu8Value=GET_BIT(PINA,ptr->Copy_u8PIN);break;
		case DIO_PORTB : *Copy_pu8Value=GET_BIT(PINB,ptr->Copy_u8PIN);break;
		case DIO_PORTC : *Copy_pu8Value=GET_BIT(PINC,ptr->Copy_u8PIN);break;
		case DIO_PORTD : *Copy_pu8Value=GET_BIT(PIND,ptr->Copy_u8PIN);break;
		default:Local_u8ErrorState=1;
		}
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;

}

u8 DIO_u8TogglePinValue(PIN_CONFIG * ptr)
{
	u8 Local_u8ErrorState=0;  //This indicate that there is no error
	if(ptr->Copy_u8PIN<=DIO_PIN7)
	{
		switch(ptr->Copy_u8PORT)
		{
		case DIO_PORTA : TOGGLE_BIT(PORTA,ptr->Copy_u8PIN);break;
		case DIO_PORTB : TOGGLE_BIT(PORTB,ptr->Copy_u8PIN);break;
		case DIO_PORTC : TOGGLE_BIT(PORTC,ptr->Copy_u8PIN);break;
		case DIO_PORTD : TOGGLE_BIT(PORTD,ptr->Copy_u8PIN);break;
		default:Local_u8ErrorState=1;
		}
	}
	else
	{
		Local_u8ErrorState=1; //ERROR

	}
	return Local_u8ErrorState;
}
