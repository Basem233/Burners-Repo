/******************************************************/
/******************************************************/
/**************		Author:Basem Moufreh 	***********/
/**************		Layer:MCAL    			***********/
/**************		SWC:PORT				***********/
/**************		Version:1.00			***********/

/*Preprocessor file guard*/
#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

/*Choose : 0 for INPUT
		   1 for OUTPUT*/

#define 	PORTA_PIN0_DIR				1
#define 	PORTA_PIN1_DIR				1
#define 	PORTA_PIN2_DIR				1
#define 	PORTA_PIN3_DIR				1
#define 	PORTA_PIN4_DIR				1
#define 	PORTA_PIN5_DIR				1
#define 	PORTA_PIN6_DIR				1
#define 	PORTA_PIN7_DIR				1
		
#define 	PORTB_PIN0_DIR				1
#define 	PORTB_PIN1_DIR				1
#define 	PORTB_PIN2_DIR				1
#define 	PORTB_PIN3_DIR				1		//PWM
#define 	PORTB_PIN4_DIR				1
#define 	PORTB_PIN5_DIR				1		//DIR
#define 	PORTB_PIN6_DIR				1		//enable
#define 	PORTB_PIN7_DIR				1
		
#define 	PORTC_PIN0_DIR				0
#define 	PORTC_PIN1_DIR				0
#define 	PORTC_PIN2_DIR				0
#define 	PORTC_PIN3_DIR				0
#define 	PORTC_PIN4_DIR				0
#define 	PORTC_PIN5_DIR				0
#define 	PORTC_PIN6_DIR				1
#define 	PORTC_PIN7_DIR				1

#define 	PORTD_PIN0_DIR				0
#define 	PORTD_PIN1_DIR				1
#define 	PORTD_PIN2_DIR				0
#define 	PORTD_PIN3_DIR				1
#define 	PORTD_PIN4_DIR				1
#define 	PORTD_PIN5_DIR				1
#define 	PORTD_PIN6_DIR				1
#define 	PORTD_PIN7_DIR				1


/*Choose 	0 for Floating if input,LOW if output
			1 for pulledup if input,High if output*/

#define 	PORTA_PIN0_INTIAL_VALUE		0
#define 	PORTA_PIN1_INTIAL_VALUE		0
#define 	PORTA_PIN2_INTIAL_VALUE		0
#define 	PORTA_PIN3_INTIAL_VALUE		0
#define 	PORTA_PIN4_INTIAL_VALUE		0
#define 	PORTA_PIN5_INTIAL_VALUE		0
#define 	PORTA_PIN6_INTIAL_VALUE		0
#define 	PORTA_PIN7_INTIAL_VALUE		0

#define 	PORTB_PIN0_INTIAL_VALUE		0
#define 	PORTB_PIN1_INTIAL_VALUE		0
#define 	PORTB_PIN2_INTIAL_VALUE		0
#define 	PORTB_PIN3_INTIAL_VALUE		0
#define 	PORTB_PIN4_INTIAL_VALUE		0
#define 	PORTB_PIN5_INTIAL_VALUE		0
#define 	PORTB_PIN6_INTIAL_VALUE		0
#define 	PORTB_PIN7_INTIAL_VALUE		0

#define 	PORTC_PIN0_INTIAL_VALUE		1
#define 	PORTC_PIN1_INTIAL_VALUE		1
#define 	PORTC_PIN2_INTIAL_VALUE		1
#define 	PORTC_PIN3_INTIAL_VALUE		1
#define 	PORTC_PIN4_INTIAL_VALUE		1
#define 	PORTC_PIN5_INTIAL_VALUE		1
#define 	PORTC_PIN6_INTIAL_VALUE		0
#define 	PORTC_PIN7_INTIAL_VALUE		0

#define 	PORTD_PIN0_INTIAL_VALUE		0
#define 	PORTD_PIN1_INTIAL_VALUE		0
#define 	PORTD_PIN2_INTIAL_VALUE		0
#define 	PORTD_PIN3_INTIAL_VALUE		1
#define 	PORTD_PIN4_INTIAL_VALUE		0
#define 	PORTD_PIN5_INTIAL_VALUE		1
#define 	PORTD_PIN6_INTIAL_VALUE		1
#define 	PORTD_PIN7_INTIAL_VALUE		1

#endif
