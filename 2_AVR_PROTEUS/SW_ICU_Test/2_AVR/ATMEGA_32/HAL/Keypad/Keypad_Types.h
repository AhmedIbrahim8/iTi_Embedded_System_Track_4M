

#ifndef HAL_KEYPAD_KEYPAD_TYPES_H_
#define HAL_KEYPAD_KEYPAD_TYPES_H_
#include "Keypad_Cfg.h"
typedef struct {
	uint8 keypad_rows[KEYPAD_ROW_NUM];
	uint8 keypad_cols[KEYPAD_COL_NUM];
	uint8 keypad_content[KEYPAD_ROW_NUM][KEYPAD_ROW_NUM];
}KEYPAD_Configuration;

typedef enum{
	KEYPAD_NOT_PRESSED=0,KEYPAD_PRESSED=1
}KEYPAD_State;


#endif /* HAL_KEYPAD_KEYPAD_TYPES_H_ */
