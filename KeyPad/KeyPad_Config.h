/*
 * KeyPad_Config.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Mohamed Safwat
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

#include <StdTypes.h>
#include "Dio_Interface.h"
typedef enum
{
	E_NOT_OK,             //configure the error state
	E_OK            //configure the correct state

}KeyPad_Error;
#define KEYPAD_DEBOUNCING_TIME 50
#define KEYPAD_PRESSED 0
typedef struct{
PIN_CONFIG row_0;
PIN_CONFIG row_1;
PIN_CONFIG row_2;
PIN_CONFIG row_3;
PIN_CONFIG col_0;
PIN_CONFIG col_1;
PIN_CONFIG col_2;
PIN_CONFIG col_3;
}keypad_init_config;

#define KEYPAD_RELEASED 0



#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
