
#include "STD_TYPES.h"
#include <util/delay.h>
#include <avr\io.h>
#include "Common_Macros.h"

volatile uint8_t counter =0;
volatile uint16_t counter1 =0;
volatile uint8_t state;

#define Servo PD5
int main()
{
	DDRD |= (1<<Servo) ;
	TCCR0 = (1<<WGM01)| (1<<CS01);
    state = 0;
	TCNT0 = 0;
	while(1)
	{

		if(state == 1){
			OCR0 = 80;
		}
		else if(state==0){
			OCR0=0;
		}


		while(BIT_IS_CLEAR(TIFR,OCF0));
		counter++;
		counter1++;
		if(counter==3){
			CLEAR_BIT(PORTD,5);
		}
		if(counter==40){
			SET_BIT(PORTD,5);
			counter = 0;


		}
		if(counter1==50000 && state==0){
			state=1;
			counter1=0;
		}
		if(counter1==5000 && state==1){
			state=0;
			counter1=0;
		}



		TCNT0 = 0;
		SET_BIT(TIFR,OCF0);






	}
}

