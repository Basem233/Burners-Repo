#include "STD_TYPES.h"
#include "GIE_register.h"
#include "GIE_Interface.h"

void GIE_EN(void)
{
	SREG|=(1<<7);
}

void GIE_DISABLE(void)
{
	SREG &= ~(1<<7);
}
