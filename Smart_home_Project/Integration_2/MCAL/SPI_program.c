#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_register.h"
#include "SPI_config.h"
#include "SPI_private.h"





void SPI_voidInitMaster(void)
{
	/*Master intilization*/
	SET_BIT(SPCR,SPCR_MSTR);

	/*Clock prescaller:divide by 8*/
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);

	/*SPI enable*/
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidInitSlave(void)
{
	/*Slave intilization*/
	CLR_BIT(SPCR,SPCR_MSTR);

	/*SPI enable*/
	SET_BIT(SPCR,SPCR_SPE);
}

u8 SPI_u8Transceive(u8 Copy_u8Data)
{
	/*Send the data*/
	SPDR=Copy_u8Data;

	/*Wait (busy waiting) until transfer complete*/
	while ((GET_BIT(SPSR,SPSR_SPIF))==0);

	return SPDR;
}
