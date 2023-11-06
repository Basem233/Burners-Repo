/******************************************************/
/******************************************************/
/**************		Author:Basem Moufreh 	***********/
/**************		Layer:HAL    			***********/
/**************		SWC:CLCD				***********/
/**************		Version:1.00			***********/

/*Preprocessor file guard*/
#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

#define 	CLCD_DATA_PORT			DIO_PORTB

#define CLCD_8BIT_MODE		0
#define CLCD_4BIT_MODE		1

/*Choose the desired mode:
 	 	 	 	 	 	 	 1-CLCD_8BIT_MODE
 	 	 	 	 	 	 	 2-CLCD_4BIT_MODE*/
#define 	CLCD_MODE		CLCD_4BIT_MODE


#define		CLCD_CONTROL_PORT		DIO_PORTA
#define 	CLCD_RS_PIN				DIO_PIN3
#define 	CLCD_RW_PIN				DIO_PIN1
#define 	CLCD_E_PIN				DIO_PIN2


#endif
