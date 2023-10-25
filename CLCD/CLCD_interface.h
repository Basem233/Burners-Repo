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

typedef struct 
{
	u8* Copy_u8Arr;
	u8 Copy_u8BlockNumber;
	u8 Copy_u8XPos;
	u8 Copy_u8YPos;
}Write_SPEC;

void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidInit(void);

/*Ay haga hthsel askii value yb2a lazm tkon char*/
void CLCD_voidSendString(const char* Copy_pcString);

void CLCD_voidGoToXY(CURSOR_LOC * ptr);

void CLCD_voidWriteSpecialCharacter(Write_SPEC * ptr);

void CLCD_voidWriteNumber(u32 Copy_u32Number);








#endif