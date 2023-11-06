/******************************************************/
/******************************************************/
/**************		Author:Basem Moufreh 	***********/
/**************		Layer:HAL    			***********/
/**************		SWC:NTI_CLCD				***********/
/**************		Version:1.00			***********/

/*Preprocessor file guard*/
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

typedef struct 
{
	u8 Copy_u8XPos;
	u8 Copy_u8YPos;
}CURSOR_LOC;


u8 HAL_CLCD_u8SendCommand(u8 Copy_u8Command);

u8 HAL_CLCD_u8SendData(u8 Copy_u8Data);

u8 HAL_CLCD_u8Init(void);

/*Ay haga hthsel askii value yb2a lazm tkon char*/
u8 HAL_CLCD_u8SendString(const char* Copy_pcString);

u8 HAL_CLCD_u8GoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos);

void HAL_CLCD_u8WriteNumber(u32 Copy_u32Number);

u8 HAL_CLCD_u8_ClearDisplay(void);








#endif
