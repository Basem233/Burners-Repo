/******************************************************/
/******************************************************/
/**************		Author:Basem Moufreh 	***********/
/**************		Layer:MCAL    			***********/
/**************		SWC:SPI					***********/
/**************		Version:1.00			***********/

/*Preprocessor file guard*/
#ifndef SPI_RIGSTER_H_
#define SPI_RIGSTER_H_

#define SPCR	*((volatile u8*)0x2d)		//SPI Control register 
#define SPCR_SPR0		0					//SPI clock rate
#define SPCR_SPR1		1                   //SPI clock rate
#define SPCR_CPHA		2                   //Clock phase (0->send then recive,1->recive then send)
#define SPCR_CPOL		3                   //Clock polarity (elclock htbd2 blow wla b high)
#define SPCR_MSTR		4                   //Master / Slave select
#define SPCR_DORD		5                   //Data sending order(LSB or MSB)
#define SPCR_SPE		6                   //SPI Enable
#define SPCR_SPIE		7                   //SPI interupt enable


#define SPSR	*((volatile u8*)0x2e)
#define SPSR_SPI2X		0					//SPI Double SPI Speed Bit
#define SPSR_SPIF		7					//SPI interrupt flag
#define SPSR_WCOL		6					//SPI write collision flag

#define SPDR	*((volatile u8*)0x2f)			//Data register


#endif
