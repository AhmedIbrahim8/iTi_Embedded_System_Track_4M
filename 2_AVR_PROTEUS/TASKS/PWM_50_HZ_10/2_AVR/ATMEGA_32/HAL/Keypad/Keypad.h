/*******************************************************************************************/
/*  Module       :   Keypad                                                                */
/*  File Name    :   Keypad.h                                                              */
/*  Description  :   Header File of the Keypad Driver                                      */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   10/08/2023                                                            */
/*******************************************************************************************/
#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_
#include "Keypad_Types.h"
#include "Keypad_Cfg.h"



/* Function Responsible of initializing the Keypad */
void KPD_voidInit(uint8 u8keyPadIndex);
/* Function Responsible of get the pressed key */
uint8 KPD_u8GetPressedKey(uint8 u8keyPadIndex);
extern KEYPAD_Configuration keypad_config[KEYPAD_MAX_NUMBER];

#endif /* HAL_KEYPAD_KEYPAD_H_ */
