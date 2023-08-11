

#include "..\..\LIB\Std_Types.h"
#include "Keypad.h"
KEYPAD_Configuration keypad_config[KEYPAD_MAX_NUMBER]=
{
		{
				{KEYPAD1_ROW_0_PIN_INDEX,KEYPAD1_ROW_1_PIN_INDEX,KEYPAD1_ROW_2_PIN_INDEX,KEYPAD1_ROW_3_PIN_INDEX },
				{KEYPAD1_COL_0_PIN_INDEX,KEYPAD1_COL_1_PIN_INDEX,KEYPAD1_COL_2_PIN_INDEX,KEYPAD1_COL_3_PIN_INDEX},
				{{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'}}
		}
};
