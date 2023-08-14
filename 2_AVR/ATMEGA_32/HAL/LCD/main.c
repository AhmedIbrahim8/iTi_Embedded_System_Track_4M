#include "..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
#include "Lcd.h"
#include "util/delay.h"
//
//int main(){
//	uint8 counter=0;
//	DIO_Init();
//	LCD_voidInit();

//	/* Address Counter points to first location of CGRAM */
//	/* Pattern of char[0]*/
//	LCD_sendSpecialCharacter(0,0,0,0b00000111);
//	LCD_sendSpecialCharacter(0,0,1,0b00000100);
//	LCD_sendSpecialCharacter(0,0,2,0b00011111);
//	LCD_sendSpecialCharacter(0,0,3,0b00000000);
//	LCD_sendSpecialCharacter(0,0,4,0b00000100);
//	LCD_sendSpecialCharacter(0,0,5,0b00000100);
//	LCD_sendSpecialCharacter(0,0,6,0b00000100);
//	LCD_sendSpecialCharacter(0,0,7,0b00000100);
//	/* Pattern of char[1] */
//	LCD_sendSpecialCharacter(0,1,0,0b00000000);
//	LCD_sendSpecialCharacter(0,1,1,0b00000000);
//	LCD_sendSpecialCharacter(0,1,2,0b00000000);
//	LCD_sendSpecialCharacter(0,1,3,0b00001000);
//	LCD_sendSpecialCharacter(0,1,4,0b00000010);
//	LCD_sendSpecialCharacter(0,1,5,0b00011111);
//	LCD_sendSpecialCharacter(0,1,6,0b00000000);
//	LCD_sendSpecialCharacter(0,1,7,0b00000000);
//	LCD_voidMoveCursor(0,0,0);
//	LCD_voidSendChar(0,0);
//	LCD_voidSendChar(0,1);
//	LCD_voidSendChar(0,'a');
//	while(1){
//		/* Shifting display to right */
//		for(counter=0;counter<16;counter++){
//			LCD_voidSendCommand(0,LCD_SHIFT_DISPLAY_RIGHT);
//			_delay_ms(50);
//		}
//		for(counter=0;counter<16;counter++){
//			LCD_voidSendCommand(0,LCD_SHIFT_DISPLAY_LEFT);
//			_delay_ms(50);
//		}
//
//
//	}
//
//}

