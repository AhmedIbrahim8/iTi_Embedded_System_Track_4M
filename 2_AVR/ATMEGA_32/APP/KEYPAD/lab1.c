#include "..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
#include "..\..\HAL\LCD\Lcd.h"
#include "..\..\HAL\Keypad\Keypad.h"

int main(){
	uint8 keypad_state=KEYPAD_NOT_PRESSED;
	DIO_Init();
	LCD_voidInit();
	KPD_voidInit(KEYPAD1_INDEX);
	while(1){
		keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
		if(keypad_state!=KEYPAD_NOT_PRESSED){
			LCD_voidSendChar(0,keypad_state);
		}
	}

}
