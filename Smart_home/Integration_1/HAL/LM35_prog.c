#include "std_types.h"
#include "ADC_interface.h"
#include "LM35_cfg.h"
#include "LM35_interface.h"


uint8 LM35_u8GetTemp(uint8 copy_u8ChannelReading)
{
	uint8 Local_u8Temp;

	Local_u8Temp = ((uint32)copy_u8ChannelReading* (MAXVOLT/10L)) / LM35_RESOLUTION;
	//Local_u8Temp/=10;
	
	return Local_u8Temp;
}
