/******************************************************/
/******************************************************/
/**************		Author:Basem Moufreh 	***********/
/**************		Layer:HAL    			***********/
/**************		SWC:KEYPAD				***********/
/**************		Version:1.00			***********/

#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"



u8 KPD_u8GetPressedKey(void)
{

	u8 Local_u8PressedKey=KPD_NO_PRESSED_KEY;
	u8 Local_u8ColumnIdx,Local_u8RowIdx,Local_u8PinState;
	static u8 Local_u8KPDArr[ROW_NUM][COLUMN_NUM]=KPD_ARR_VAL;

	static u8 Local_u8KPDColumnArr[COLUMN_NUM]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	static u8 Local_u8KPDRowArr[ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
///////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
	for(Local_u8ColumnIdx=0; Local_u8ColumnIdx<COLUMN_NUM ;Local_u8ColumnIdx++)
	{
		PIN_CONFIG Current_column_Activ={KPD_COL_PORT,Local_u8KPDColumnArr[Local_u8ColumnIdx],DIO_PIN_LOW};

		/*Activate Current column*/
		DIO_u8SetPinValue(&Current_column_Activ);

		for(Local_u8RowIdx=0;Local_u8RowIdx<ROW_NUM;Local_u8RowIdx++)
		{
			PIN_CONFIG Read_row;
			Read_row.Copy_u8PORT = KPD_ROW_PORT;
			Read_row.Copy_u8PIN = Local_u8KPDRowArr[Local_u8RowIdx];
			/*Read the current ROW*/
			DIO_GetPinValue(&Read_row,&Local_u8PinState);

			/*Check if the switch is pressed */
			if (DIO_PIN_LOW==Local_u8PinState)
			{
				Local_u8PressedKey=Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];

				/*Polling (busy waiting)until the key is released*/
				while(DIO_PIN_LOW==Local_u8PinState)
				{
					DIO_GetPinValue(&Read_row,&Local_u8PinState);
				}

				return Local_u8PressedKey;
			}
		}
		PIN_CONFIG Current_column_Deactiv={KPD_COL_PORT,Local_u8KPDColumnArr[Local_u8ColumnIdx],DIO_PIN_HIGH};

		/*Deactivate current column*/
		DIO_u8SetPinValue(&Current_column_Deactiv);

	}

	return Local_u8PressedKey;
}



