/*
 * Buzzer_Interface.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Mohamed Safwat
 */
#include "Buzzer_Cfg.h"
//GPIO_Pin_Configuration Pin={PORTA,4};
Buzzer_Error HAL_Buzzer_init(Buzzer_CONFIG * ptr);
Buzzer_Error HAL_Buzzer_TurnOn (Buzzer_CONFIG * ptr);
Buzzer_Error HAL_Buzzer_TurnOff (Buzzer_CONFIG * ptr);
Buzzer_Error HAL_Buzzer_Toggle (Buzzer_CONFIG * ptr);
