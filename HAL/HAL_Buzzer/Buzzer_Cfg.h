/*
 * Buzzer_Cfg.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Mohamed Safwat
 */

#ifndef HAL_BUZZER_BUZZER_CFG_H_
#define HAL_BUZZER_BUZZER_CFG_H_
#include "Dio_Interface.h"
#include "Reg.h"


typedef struct{
PIN_CONFIG P;
}Buzzer_CONFIG;

typedef enum{
	E_Not_OK,
	E_Ok
}Buzzer_Error;
#endif /* HAL_BUZZER_BUZZER_CFG_H_ */
