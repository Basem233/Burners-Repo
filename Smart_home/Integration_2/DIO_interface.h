#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


typedef struct 
{
	u8 Copy_u8PORT;
	u8 Copy_u8PIN;
	u8 Copy_u8Value;
	
}PIN_CONFIG;

typedef struct
{
	u8 Copy_u8PORT;
	u8 Copy_u8Value;

}PORT_CONFIG;


typedef enum
{
	DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD
}PORT_ID;

typedef enum
{
	DIO_PIN0,DIO_PIN1,DIO_PIN2,DIO_PIN3,DIO_PIN4,DIO_PIN5,DIO_PIN6,DIO_PIN7
}PIN_ID;


#define DIO_PORT_HIGH		0xFF
#define DIO_PORT_LOW		0

#define DIO_PORT_OUTPUT		0xff
#define DIO_PORT_INPUT		0

typedef enum
{
	DIO_PIN_INPUT,DIO_PIN_OUTPUT
}PIN_DIR;

typedef enum
{
	DIO_PIN_LOW,DIO_PIN_HIGH
}PIN_VALU;


u8 DIO_u8SetPinDirection(PIN_CONFIG * ptr);

u8 DIO_u8SetPortDirection(PORT_CONFIG * ptr);

u8 DIO_u8SetPinValue(PIN_CONFIG * ptr);

u8 DIO_u8SetPortValue(PORT_CONFIG * ptr);

u8 DIO_GetPinValue(PIN_CONFIG * ptr,u8 *Copy_pu8Value);

u8 DIO_u8TogglePinValue(PIN_CONFIG * ptr);


#endif
