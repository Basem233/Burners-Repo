

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_register.h"



u8 HAL_LED_init (PIN_CONFIG * ptr){
	u8 Local_u8ErrorState=0;
	if(ptr->Copy_u8Direction ==DIO_PIN_OUTPUT){
		Local_u8ErrorState =  DIO_u8SetPinDirection(PIN_CONFIG * ptr);
	}
	else{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}

u8 HAL_LED_TurnOn (PIN_CONFIG * ptr){
	u8 Local_u8ErrorState=0;
	if(ptr->Copy_u8Value==DIO_PIN_HIGH){
		Local_u8ErrorState =  DIO_u8SetPinValue(PIN_CONFIG * ptr);
	}
	else{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;

}

u8 HAL_LED_TurnOff (PIN_CONFIG * ptr){
	u8 Local_u8ErrorState=0;
	if(ptr->Copy_u8Value==DIO_PIN_LOW){
		Local_u8ErrorState =  DIO_u8SetPinValue(PIN_CONFIG * ptr);
	}
	else{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;

}

u8 HAL_LED_Toggle (PIN_CONFIG * ptr){
	u8 Local_u8ErrorState=0;
	Local_u8ErrorState =  DIO_u8TogglePinValue(PIN_CONFIG * ptr);

	return Local_u8ErrorState;

}

