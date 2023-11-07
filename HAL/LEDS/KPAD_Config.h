/*=================================================================================*/
/*  File        : KPAD_Config.h                                                    */
/*  Description : This file includes KPAD Driver Configrations for Atmega32        */
/*  Author      : Hassan Elgabas. Embedded SW Engineer                             */
/*  Date        : 6/11/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/hassan-elgabas-63104419b/            */                                               
/*  mail        : has.elgabas@gmail.com                                            */
/*=================================================================================*/

/* File Gaurd by ifndef & endif */
#ifndef KPAD_CONFIG_H
#define KPAD_CONFIG_H

#define  KPAD_PORT             PORTA
 
#define  KPAD_C0_PIN           PIN4
#define  KPAD_C1_PIN           PIN5
#define  KPAD_C2_PIN           PIN6
#define  KPAD_C3_PIN           PIN7

#define  KPAD_R0_PIN           PIN0
#define  KPAD_R1_PIN           PIN1
#define  KPAD_R2_PIN           PIN2
#define  KPAD_R3_PIN           PIN3

#define  KPAD_COLUMNS_NUM         4
#define  KPAD_ROWS_NUM            4

#define KPAD_KEYS {{'7','8','9','/'} , {'4','5','6','*'} , {'1','2','3','-'} , {'#','0','=','+'}} 


#endif 