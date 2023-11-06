/*********************************************************************************************/
/*********************************************************************************************/
/*******************************	Smart Home Project		**********************************/
/*******************************	Authour:Burners Team		******************************/
/*******************************	Date:4/11/2023				******************************/

#include "STD_TYPES.h"
#include "util/delay.h"
#include <avr/interrupt.h>
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "TIMER_interface.h"

#include "USART_interface.h"
#include "IIC.h"
#include "SPI_interface.h"
#include "eeprom.h"

/***************************Safwat Defines************************/
#define Door_close	215
#define Door_open 230
u8 UART_Recived_Data = 0;			//Equals to null at first

u32 GetNumber(void);
u32 MakeNewPassword(void);
void login(void);

/*Global Variable To get the EEPROM Data*/
u32 EEPROM_Value=0;
int OverFlow_Counter=0; ///////////////////////////////



PIN_CONFIG ServoPinLOW={DIO_PORTD,DIO_PIN4,DIO_PIN_LOW};
PIN_CONFIG ServoPinHIGH={DIO_PORTD,DIO_PIN4,DIO_PIN_HIGH};

PIN_CONFIG Test={DIO_PORTB,DIO_PIN7,DIO_PIN_HIGH};
PIN_CONFIG Test1={DIO_PORTB,DIO_PIN7,DIO_PIN_LOW};
int main (void)
{

	u8 Temp,flag=0,counter=0;
	int state=Door_close;

	u32 Local_u32Key;

	PIN_CONFIG buzzer={DIO_PORTC,DIO_PIN6,DIO_PIN_HIGH};
	PIN_CONFIG buzzer1={DIO_PORTC,DIO_PIN6,DIO_PIN_LOW};
	PIN_CONFIG LedCheckHIGH={DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH};
	PIN_CONFIG LedCheckLOW={DIO_PORTA,DIO_PIN4,DIO_PIN_LOW};

	PIN_CONFIG MotorCCW={DIO_PORTB,DIO_PIN5,DIO_PIN_LOW};
	PIN_CONFIG MotorCCWG={DIO_PORTB,DIO_PIN6,DIO_PIN_LOW};

	PIN_CONFIG MotorCW={DIO_PORTB,DIO_PIN6,DIO_PIN_HIGH};
	PIN_CONFIG MotorCWG={DIO_PORTB,DIO_PIN5,DIO_PIN_LOW};

	PIN_CONFIG PWMOff={DIO_PORTB,DIO_PIN3,DIO_PIN_LOW};
	PIN_CONFIG PWMOn={DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH};

	PIN_CONFIG LED_ON={DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH};
	PIN_CONFIG LED_OFF={DIO_PORTC,DIO_PIN7,DIO_PIN_LOW};



	PORT_voidInit();
	HAL_CLCD_u8Init();
	USART_voidInit();
	TIMER0_voidInit();
	/*********************************************************************/
	DIO_u8SetPinValue(&ServoPinHIGH);


	/*********************************************************************/

	I2C_Init();
	//SPI_voidInitMaster();



	/*Welcoming the user*/
	HAL_CLCD_u8GoToXY(4,0);
	HAL_CLCD_u8SendString("Hi,Welcome!");
	HAL_CLCD_u8GoToXY(4,1);
	HAL_CLCD_u8SendString("Smart Link");
	HAL_CLCD_u8GoToXY(2,3);
	HAL_CLCD_u8SendString("By Burners Team");
	_delay_ms(2000);
	/**********************************************************************************/
	login();


	HAL_CLCD_u8_ClearDisplay();
	HAL_CLCD_u8SendString("Enter Your Password :");

	while(1)
	{
		while(counter<=3)
		{
			do
			{
				Temp=KPD_u8GetPressedKey();
			}while(Temp == 0xff);



			if(Temp =='=')
			{
				if(Local_u32Key==EEPROM_Value)
				{
					HAL_CLCD_u8_ClearDisplay();
					HAL_CLCD_u8SendString("Welcome Burners To");
					HAL_CLCD_u8GoToXY(4,2);
					HAL_CLCD_u8SendString("Smart Link");
					counter=0;
					flag=0;


					/*Safwat implmentation*/


					while(1)
					{

						//HAL_CLCD_u8_ClearDisplay();
						//u8 x= UART_Recived_Data;
						//HAL_CLCD_u8WriteNumber(x);
						//HAL_CLCD_u8GoToXY(0,1);
						//HAL_CLCD_u8WriteNumber(TCNT0);
						switch(UART_Recived_Data)
						{
						case 'C':
							state =Door_close;
							DIO_u8SetPinValue(&LedCheckHIGH);
							break;
						case 'c':
							state =Door_open;
							DIO_u8SetPinValue(&LedCheckLOW);
							break;
						case 'b':		//Open Door by the DC Motor
							DIO_u8SetPinValue(&Test);
							DIO_u8SetPinValue(&PWMOn);
							DIO_u8SetPinValue(&MotorCCW);
							DIO_u8SetPinValue(&MotorCCWG);

							//DIO_u8SetPinValue(&Disable);
							break;
						case 'B':		//close Door by the DC Motor
							DIO_u8SetPinValue(&Test1);
							DIO_u8SetPinValue(&PWMOn);
							DIO_u8SetPinValue(&MotorCW);
							DIO_u8SetPinValue(&MotorCWG);


							//DIO_u8SetPinValue(&Disable);
							break;


						case 'A':		//Open LED by the Relay
							DIO_u8SetPinValue(&LED_ON);
							break;

						case 'a':		//Close LED by the Relay
							DIO_u8SetPinValue(&LED_OFF);
							break;
						default:
							//Do nothing
							break;

						}


						if ((TCNT0 == state) && OverFlow_Counter==0)
						{
							DIO_u8SetPinValue(&ServoPinLOW);

						}
					}

				}
				else
				{
					if (counter ==3)
					{
						HAL_CLCD_u8_ClearDisplay();
						HAL_CLCD_u8SendString("Block mode");
						HAL_CLCD_u8GoToXY(0,1);
						HAL_CLCD_u8SendString("Wait 3 Seconds");
						DIO_u8SetPinValue(&buzzer);
						//DIO_u8SetPinValue(&buzzer1);
						_delay_ms(3000);
						DIO_u8SetPinValue(&buzzer1);
						HAL_CLCD_u8GoToXY(0,2);
						HAL_CLCD_u8SendString("Try again:");
						counter=0;
						flag=0;
					}
					else
					{
						HAL_CLCD_u8_ClearDisplay();
						HAL_CLCD_u8SendString("Wrong password");
						HAL_CLCD_u8GoToXY(0,1);
						HAL_CLCD_u8SendString("Try again:");
						counter++;
						flag=0;
					}

				}
			}
			else
			{
				flag++;
				if (flag==1)
				{
					Local_u32Key=Temp;
					HAL_CLCD_u8SendData(Local_u32Key+'0');
				}
				else if(flag==2)
				{
					Local_u32Key=(Local_u32Key*10)+Temp;
					HAL_CLCD_u8SendData(Temp+'0');
				}
				else if(flag==3)
				{
					Local_u32Key=((Local_u32Key*10))+Temp;
					HAL_CLCD_u8SendData(Temp+'0');
				}
				else if(flag==4)
				{
					Local_u32Key=(Local_u32Key*10)+Temp;
					HAL_CLCD_u8SendData(Temp+'0');
				}
				else if(flag==5)
				{
					Local_u32Key=(Local_u32Key*10)+Temp;
					HAL_CLCD_u8SendData(Temp+'0');
				}
			}
		}
	}
}

/*******************************************************************************************/
/*********************************Function name: login*************************************/
/****Description: Handle the startup of the system password Authentication***************/
/*****************		Void in inputs and outputs			*****************************/

void login(void)
{
	/*flag: To Loop and continue asking for the admin password*/
	u8 Temp,flag=0;
	/**/
	u32 Admin_Pass,Password;
	HAL_CLCD_u8_ClearDisplay();
	HAL_CLCD_u8SendString("New Password: 1");
	HAL_CLCD_u8GoToXY(0,1);
	HAL_CLCD_u8SendString("Enter Password: 2");
	HAL_CLCD_u8GoToXY(0,2);
	HAL_CLCD_u8SendString("Your Choice:");
	do
	{
		Temp=KPD_u8GetPressedKey();
	}while(Temp == 0xff);
	/*Display your choice*/
	HAL_CLCD_u8WriteNumber(Temp);

	while(flag==0)
	{
		if (Temp == 1)
		{
			HAL_CLCD_u8_ClearDisplay();
			HAL_CLCD_u8SendString("Enter Admin Password:");
			Admin_Pass=GetNumber();
			if(Admin_Pass==123)
			{
				flag=1;
				HAL_CLCD_u8_ClearDisplay();
				HAL_CLCD_u8SendString("Welcome Admin..");
				HAL_CLCD_u8GoToXY(0,1);
				HAL_CLCD_u8SendString("Enter User New");
				HAL_CLCD_u8GoToXY(0,2);
				HAL_CLCD_u8SendString("Password: ");
				Password =MakeNewPassword();
			}
			else
			{
				HAL_CLCD_u8_ClearDisplay();
				HAL_CLCD_u8SendString("Wrong Password");
				HAL_CLCD_u8GoToXY(0,1);
				HAL_CLCD_u8SendString("Please Contact Your Admin");
				_delay_ms(1000);
			}
		}

		else
		{
			flag=1;
			EEPROM_ReadByte(0x0311,&EEPROM_Value);
		}
	}
}

u32 GetNumber(void)
{
	u8 temp,Flag=0,Loop=0;
	u32 key=0;
	while(Loop != 1)
	{
		do
		{
			temp=KPD_u8GetPressedKey();
		}while(temp == 0xff);

		if (temp=='=')
		{
			Loop =1;
		}
		else
		{
			Flag++;
			if (Flag==1)
			{
				key=temp;
				HAL_CLCD_u8SendData(key+'0');
			}
			else if(Flag==2)
			{
				key=(key*10)+temp;
				HAL_CLCD_u8SendData(temp+'0');
			}
			else if(Flag==3)
			{
				key=((key*10))+temp;
				HAL_CLCD_u8SendData(temp+'0');
			}
			else if(Flag==4)
			{
				key=(key*10)+temp;
				HAL_CLCD_u8SendData(temp+'0');
			}
			else if(Flag==5)
			{
				key=(key*10)+temp;
				HAL_CLCD_u8SendData(temp+'0');
			}
		}
	}
	return key;
}

u32 MakeNewPassword(void)
{
	u32 passcode =GetNumber();

	EEPROM_WriteByte(0x0311,passcode);
	_delay_ms(10);
	EEPROM_ReadByte(0x0311,&EEPROM_Value);
	HAL_CLCD_u8_ClearDisplay();
	HAL_CLCD_u8SendString("Succesfully Added");
	HAL_CLCD_u8GoToXY(0,1);
	HAL_CLCD_u8SendString("Your New Password");
	HAL_CLCD_u8GoToXY(8,2);
	HAL_CLCD_u8WriteNumber(EEPROM_Value);
	HAL_CLCD_u8GoToXY(0,3);
	HAL_CLCD_u8SendString("Thank You");
	_delay_ms(2000);

	return passcode;
}

ISR(USART_RXC_vect)
{

	UART_Recived_Data=UDR;
}

ISR(TIMER0_OVF_vect)
{

	OverFlow_Counter++;
	if(OverFlow_Counter == 2)
	{


		DIO_u8SetPinValue(&ServoPinHIGH);
		OverFlow_Counter=0;
		TCNT0=200;


	}
}
