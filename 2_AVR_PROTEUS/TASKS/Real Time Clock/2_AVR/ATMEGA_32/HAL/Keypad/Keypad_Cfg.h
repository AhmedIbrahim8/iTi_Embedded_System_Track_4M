/*******************************************************************************************/
/*  Module       :   Keypad                                                                */
/*  File Name    :   Keypad_Cfg.h                                                          */
/*  Description  :   Header File of the configuration Keypad Driver                        */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   10/08/2023                                                            */
/*******************************************************************************************/
#ifndef HAL_KEYPAD_KEYPAD_CFG_H_
#define HAL_KEYPAD_KEYPAD_CFG_H_

#define KEYPAD_MAX_NUMBER            1
#define KEYPAD_ROW_NUM               4
#define KEYPAD_COL_NUM               4

#define KEYPAD1_INDEX                0


#define KEYPAD1_ROW_0_PIN_INDEX      (uint8)16
#define KEYPAD1_ROW_1_PIN_INDEX      (uint8)17
#define KEYPAD1_ROW_2_PIN_INDEX      (uint8)18
#define KEYPAD1_ROW_3_PIN_INDEX      (uint8)19
#define KEYPAD1_ROW_PINS             {16,17,18,19}

#define KEYPAD1_COL_0_PIN_INDEX      (uint8)20
#define KEYPAD1_COL_1_PIN_INDEX      (uint8)21
#define KEYPAD1_COL_2_PIN_INDEX      (uint8)30
#define KEYPAD1_COL_3_PIN_INDEX      (uint8)31
#define KEYPAD1_COL_PINS             {20,21,30,31}

#define KEYPAD1_CONTENTS {{'7','8','9','/'},\
	                      {'4','5','6','*'},\
						  {'1','2','3','-'},\
						  {'c','0','=','+'}}



#endif /* HAL_KEYPAD_KEYPAD_CFG_H_ */
