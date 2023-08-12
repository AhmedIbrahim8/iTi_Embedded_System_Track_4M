#include"..\..\..\LIB\Std_Types.h"
#include"..\..\..\LIB\common_macros.h"
#include"..\..\..\HAL\Keypad\Keypad.h"
#include"..\..\..\HAL\LCD\Lcd.h"
#include"..\..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
#include <util/delay.h>
void Calculator(void);
void Convert();
void Decimal_To_Binary(void);
void Decimal_To_Hexa(void);
int main(){
	uint8 keypad_state=KEYPAD_NOT_PRESSED;
	DIO_Init();
	LCD_voidInit();
	KPD_voidInit(KEYPAD1_INDEX);
	while(1){
		LCD_voidClrScr(LCD1_INDEX_NUMBER);
		LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,0,"Cal(1):Convert(2)");
		LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,1,0,"Enter mode : ");
		keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
		while(keypad_state == KEYPAD_NOT_PRESSED){
			keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
		}
		while(keypad_state != '1' && keypad_state != '2' && keypad_state != 'c'){
			LCD_voidClrScr(LCD1_INDEX_NUMBER);
			LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,0,"Not Valid Mode....");
			LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,1,0,"Please Try Again..");
			_delay_ms(500);
			LCD_voidClrScr(LCD1_INDEX_NUMBER);
			LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,0,"Cal(1):Convert(2)");
			LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,1,0,"Enter mode : ");
			keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
			while(keypad_state == KEYPAD_NOT_PRESSED){
				keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
			}
		}
		switch(keypad_state){
		case '1':
			LCD_voidClrScr(LCD1_INDEX_NUMBER);
			Calculator();
			while(keypad_state != KEYPAD_NOT_PRESSED){
				keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
			}
			while(keypad_state != 'c'){
				keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
			}

			break;
		case '2':
			LCD_voidClrScr(LCD1_INDEX_NUMBER);
			Convert();
			while(keypad_state != KEYPAD_NOT_PRESSED){
				keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
			}
			while(keypad_state != 'c'){
				keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
			}
			break;
		case 'c':
			LCD_voidClrScr(LCD1_INDEX_NUMBER);
			LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,0,"Clear Screen...");
			_delay_ms(500);
			LCD_voidClrScr(LCD1_INDEX_NUMBER);
			keypad_state = KEYPAD_NOT_PRESSED;
			break;
		}

	}

}







void Calculator(void){
	uint32 number1=0;
	uint32 number2=0;
	uint32 result=0;
	uint8 keypad_state=KEYPAD_NOT_PRESSED;
	uint8 KeypadOperation;
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
			while(keypad_state != KEYPAD_NOT_PRESSED){
				keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
			}
			while(keypad_state != 'c'){
				keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
			}
			number1=0;
			number2=0;
			result=0;
	}
	}
}

void Convert(){
	uint8 keypad_state=KEYPAD_NOT_PRESSED;
	LCD_voidClrScr(LCD1_INDEX_NUMBER);
	LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,0,"DTB(1):DTH(2)");
	LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,1,0,"Enter mode : ");
	keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
	while(keypad_state == KEYPAD_NOT_PRESSED){
		keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
	}
	while(keypad_state != '1' && keypad_state != '2' && keypad_state != 'c'){
		LCD_voidClrScr(LCD1_INDEX_NUMBER);
		LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,0,"Not Valid Mode....");
		LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,1,0,"Please Try Again..");
		_delay_ms(500);
		LCD_voidClrScr(LCD1_INDEX_NUMBER);
		LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,0,"DTB(1):DTH(2)");
		LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,1,0,"Enter mode : ");
		keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
		while(keypad_state == KEYPAD_NOT_PRESSED){
			keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
		}
	}
	switch(keypad_state){
	case '1':
		LCD_voidClrScr(LCD1_INDEX_NUMBER);
		Decimal_To_Binary();
		break;
	case '2':
		LCD_voidClrScr(LCD1_INDEX_NUMBER);
		Decimal_To_Hexa();
		break;
	case 'c':
		LCD_voidClrScr(LCD1_INDEX_NUMBER);
		LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,0,"Clear Screen...");
		_delay_ms(500);
		LCD_voidClrScr(LCD1_INDEX_NUMBER);
		break;
	}
}

void Decimal_To_Binary(void){
	uint8 counter;
	uint8 number1=0;
	uint8 keypad_state=KEYPAD_NOT_PRESSED;
	/* Get the key from the user */
	keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
	while(keypad_state == KEYPAD_NOT_PRESSED){
		keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
	}
	while(keypad_state!='=' && keypad_state!='c'){
		LCD_voidSendChar(LCD1_INDEX_NUMBER,keypad_state);
		number1=(number1*10)+(keypad_state-48);
		keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
		while(keypad_state == KEYPAD_NOT_PRESSED){
			keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
		}
	}
	if(keypad_state == '=' || keypad_state == 'c'){
		/* '=' indicates start converting */
		switch(keypad_state){
		case '=':
			LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,0);
			LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,1,0,"0b");
			for(counter=8;counter>=1;counter--){
				LCD_voidSendNumber(LCD1_INDEX_NUMBER,GET_BIT(number1,counter-1));
			}
			while(keypad_state != KEYPAD_NOT_PRESSED){
				keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
			}
			while(keypad_state != 'c'){
				keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
			}
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
}

void Decimal_To_Hexa(void){
	uint8 counter;
	uint8 number1=0;
	uint8 number2=0;
	uint8 keypad_state=KEYPAD_NOT_PRESSED;
	/* Get the key from the user */
	keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
	while(keypad_state == KEYPAD_NOT_PRESSED){
		keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
	}
	while(keypad_state!='=' && keypad_state!='c'){
		LCD_voidSendChar(LCD1_INDEX_NUMBER,keypad_state);
		number1=(number1*10)+(keypad_state-48);
		keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
		while(keypad_state == KEYPAD_NOT_PRESSED){
			keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
		}
	}
	switch(keypad_state){
	case '=':
		LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,0);
		LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,1,0,"0x");
		number2=(number1&0xF0)>>4;
		for(counter=0;counter<2;counter++){
			if(number2<=9){
				LCD_voidSendNumber(LCD1_INDEX_NUMBER,number2);
			}
			else{
				switch(number2){
				case 10:
					LCD_voidSendChar(LCD1_INDEX_NUMBER,'A');
				break;
				case 11:
					LCD_voidSendChar(LCD1_INDEX_NUMBER,'B');
				break;
				case 12:
					LCD_voidSendChar(LCD1_INDEX_NUMBER,'C');
				break;
				case 13:
					LCD_voidSendChar(LCD1_INDEX_NUMBER,'D');
				break;
				case 14:
					LCD_voidSendChar(LCD1_INDEX_NUMBER,'E');
				break;
				case 15:
					LCD_voidSendChar(LCD1_INDEX_NUMBER,'F');
				break;
				}
			}
			number2=(number1&0x0F);
		}
		while(keypad_state != KEYPAD_NOT_PRESSED){
			keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
		}
		while(keypad_state != 'c'){
			keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
		}
		break;
	case 'c':
		LCD_voidClrScr(LCD1_INDEX_NUMBER);
		LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,0,"Clear Screen...");
		_delay_ms(500);
		LCD_voidClrScr(LCD1_INDEX_NUMBER);
		break;
	}

}
