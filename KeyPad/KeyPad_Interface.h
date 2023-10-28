/*
 * KeyPad_Interface.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Mohamed Safwat
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_
#include "KeyPad_Config.h"
/*******_Function Prototypes_*************/


KeyPad_Error HAL_Keypad_init(keypad_init_config* ptr);
static KeyPad_Error HAL_keypad_WaitForKeyRelease(void);
static KeyPad_Error HAL_Keypad_WaitForKeyPress(void);
uint8_t HAL_Kepad_GetKey (keypad_init_config* ptr);





#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
