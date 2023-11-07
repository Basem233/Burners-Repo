/******************************************************/
/******************************************************/
/**************		Author:Basem Moufreh 	***********/
/**************		Layer:MCAL    			***********/
/**************		SWC:PORT				***********/
/**************		Version:1.00			***********/

/*Preprocessor file guard*/
#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define	 KPD_COL_PORT				DIO_PORTD
#define	 KPD_ROW_PORT				DIO_PORTC

#define KPD_COLUMN0_PIN			DIO_PIN7
#define KPD_COLUMN1_PIN			DIO_PIN6
#define KPD_COLUMN2_PIN			DIO_PIN5
#define KPD_COLUMN3_PIN			DIO_PIN3

#define KPD_ROW0_PIN			DIO_PIN5
#define KPD_ROW1_PIN			DIO_PIN4
#define KPD_ROW2_PIN			DIO_PIN3
#define KPD_ROW3_PIN			DIO_PIN2

#define	 KPD_NO_PRESSED_KEY		0xff


#define KPD_ARR_VAL		{{7,8,9,'/'},{4,5,6,'*'},{1,2,3,'-'},{'_',0,'=','+'}}


#endif
