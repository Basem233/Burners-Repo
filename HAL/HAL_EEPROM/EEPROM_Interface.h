/*====================================================================================================*/
/*  File        : EEPROM_Interface.h                                                                  */
/*  Description : This interface file includes EEPROM Driver prototypes and declarations for Atmega32 */
/*  Author      : Hassan Elgabas. Embedded SW Engineer                             */
/*  Date        : 6/11/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/hassan-elgabas-63104419b/            */                                               
/*  mail        : has.elgabas@gmail.com                                            */
/*=================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

void EEPROM_voidSendDataByte ( u16 Copy_u16LocationAddress , u8 Copy_u8DataByte );
u8 EEPROM_voidReadDataByte ( u16 Copy_u16LocationAddress );


#endif