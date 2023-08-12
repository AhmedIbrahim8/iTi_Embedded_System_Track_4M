#include"..\..\..\LIB\Std_Types.h"
#include"..\..\..\HAL\Keypad\Keypad.h"
#include"..\..\..\HAL\LCD\Lcd.h"
#include"..\..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
#include <util/delay.h>

int main(){
	uint32 number1=0;
	uint32 number2=0;
	uint32 result=0;
	uint8 keypad_state=KEYPAD_NOT_PRESSED;
	uint8 KeypadOperation;
	DIO_Init();
	LCD_voidInit();
	KPD_voidInit(KEYPAD1_INDEX);
	while(1){
		/* Get the key from the user */
		keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
		while(keypad_state == KEYPAD_NOT_PRESSED){
			keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
		}
		while(keypad_state!='+' && keypad_state!='-' && keypad_state!='*' && keypad_state!='/' && keypad_state!='=' && keypad_state!='c'){
			LCD_voidSendChar(LCD1_INDEX_NUMBER,keypad_state);
			number1=(number1*10)+(keypad_state-48);
			keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
			while(keypad_state == KEYPAD_NOT_PRESSED){
				keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
			}
		}
		if(keypad_state == '=' || keypad_state == 'c'){
			/* You didn't enter number2*/
			switch(keypad_state){
			case '=':
				LCD_voidClrScr(LCD1_INDEX_NUMBER);
				LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,0,"Not valid");
				_delay_ms(500);
				LCD_voidClrScr(LCD1_INDEX_NUMBER);
				number1=0;
				break;
			case 'c':
				LCD_voidClrScr(LCD1_INDEX_NUMBER);
				LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,0,"Clear Screen...");
				_delay_ms(500);
				LCD_voidClrScr(LCD1_INDEX_NUMBER);
				number1=0;
				break;
			}
		}
		/* Incase of '+' or '-' or '*' or '/' */
		else{
			LCD_voidSendChar(LCD1_INDEX_NUMBER,keypad_state);
			KeypadOperation=keypad_state;
			keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
			while(keypad_state == KEYPAD_NOT_PRESSED){
				keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
			}
			while(keypad_state!='+' && keypad_state!='-' && keypad_state!='*' && keypad_state!='/' && keypad_state!='=' && keypad_state!='c'){
				LCD_voidSendChar(LCD1_INDEX_NUMBER,keypad_state);
				number2=(number2*10)+(keypad_state-48);
				keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
				while(keypad_state == KEYPAD_NOT_PRESSED){
					keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
				}
			}
			if(keypad_state == '=' || keypad_state == 'c'){
				if(keypad_state=='c'){
					LCD_voidClrScr(LCD1_INDEX_NUMBER);
					LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,0,"Clear Screen...");
					_delay_ms(500);
					LCD_voidClrScr(LCD1_INDEX_NUMBER);
					number1=0;
					number2=0;
				}
				else{
					LCD_voidSendChar(LCD1_INDEX_NUMBER,keypad_state);
					/* 2-cases '=' or 'c' */
					switch(KeypadOperation){
					case '+':
						result=number1+number2;
						break;
					case '-':
						result=number1-number2;
						break;
					case '*':
						result=number1*number2;
						break;
					case '/':
						result=number1/number2;
						break;
					}
				}
				LCD_voidSendNumber( LCD1_INDEX_NUMBER,result);
				number1=0;
				number2=0;
				result=0;
		}
		}
	}
}
