/*******************************************************************************************/
/*  Module       :   LCD                                                                   */
/*  File Name    :   Lcd.c                                                                 */
/*  Description  :   Source File of the LCD Driver                                         */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   06/08/2023                                                            */
/*******************************************************************************************/
#include "Lcd.h"
#include "DIO_Interface.h"
#include "common_macros.h"
#include <util/delay.h>

static void LCD_help(uint8 u8IndexCpy,uint8 u8CommandCpy);

void LCD_voidWriteCommand(uint8 u8IndexCpy,uint8 u8CommandCpy){

	/* RS pin to 0 to write command */
	DIO_enuWritePin(pinsConfiguration[u8IndexCpy].registerSelectPin ,LEVEL_LOW);
	/* LCD_help() is responsible of writing the cmd in case of the both cases  */
	/*              command or data                                           */
	LCD_help(u8IndexCpy,u8CommandCpy);

}

void LCD_voidInit(void){
	uint8 counter;
	uint8 command=0;
	for(counter=0;counter<LCD_NUMBERS;counter++){
		if(configuration[counter].mode==LCD_8_BIT_MODE)
		{
			/* Wait after VDD rises to 4.5 v */
			_delay_ms(30);
			/* Function Set Command */
			command=FUNCTION_SET_COMMAND|(1<<LCD_DB4_BIT)|\
					(configuration[counter].line<<LCD_DB3_BIT)|\
					(configuration[counter].font<<LCD_DB2_BIT);
			LCD_voidWriteCommand(counter,command);
			_delay_ms(1);
			/* Display On Off Control command*/
			command=DISPLAY_ON_OFF_COMMAND|(configuration[counter].display<<LCD_DB2_BIT)|\
					(configuration[counter].cursor<<LCD_DB1_BIT)|\
					(configuration[counter].blink<<LCD_DB0_BIT);
			LCD_voidWriteCommand(counter,command);
			_delay_ms(1);
			/* Clear Screen command */
			command=CLEAR_DISPLAY_COMMAND;
			LCD_voidWriteCommand(counter,command);
			_delay_ms(3);
			/* Entry mode command */
			command=ENTRY_MODE_COMMAND|(configuration[counter].cursorMove<<LCD_DB1_BIT)|\
					(configuration[counter].shift<<LCD_DB0_BIT);
			LCD_voidWriteCommand(counter,command);
			_delay_ms(3);
		}
		else
		{
			/* Wait after VDD rises to 4.5 v */
			_delay_ms(30);
			/* Function Set Command */
			LCD_voidWriteCommand(counter,FUNCTION_SET_COMMAND);
			LCD_voidWriteCommand(counter,FUNCTION_SET_COMMAND);
			command=FUNCTION_SET_COMMAND|(configuration[counter].line<<LCD_DB3_BIT)|\
					(configuration[counter].font<<LCD_DB2_BIT);
			command=command<<4;
			LCD_voidWriteCommand(counter,command);
			_delay_ms(1);
			/* Display On Off Control command */
			LCD_voidWriteCommand(counter,0x00);
			command=DISPLAY_ON_OFF_COMMAND|(configuration[counter].display<<LCD_DB2_BIT)|\
					(configuration[counter].cursor<<LCD_DB1_BIT)|\
					(configuration[counter].blink<<LCD_DB0_BIT);
			command=command<<4;
			LCD_voidWriteCommand(counter,command);
			/* Clear Screen command */
			LCD_voidWriteCommand(counter,0x00);
			LCD_voidWriteCommand(counter,CLEAR_DISPLAY_COMMAND);
			_delay_ms(3);
			/* Entry mode command */
			LCD_voidWriteCommand(counter,0x00);
			command=ENTRY_MODE_COMMAND|(configuration[counter].cursorMove<<LCD_DB1_BIT)|\
					(configuration[counter].shift<<LCD_DB0_BIT);
			command=command<<4;
			LCD_voidWriteCommand(counter,command);
			_delay_ms(3);
		}
	}
}


void LCD_help(uint8 u8IndexCpy,uint8 u8CommandCpy){
	uint8 binary_command[8];
	uint8 counter;
	for(counter=0;counter<8;counter++){
		binary_command[counter]=GET_BIT(u8CommandCpy,counter);

	}
	/* 0 For  Writing */
	DIO_enuWritePin(pinsConfiguration[u8IndexCpy].readWritePin,LEVEL_LOW);


	if(configuration[u8IndexCpy].mode == LCD_8_BIT_MODE){
		/* Sending the command of the 8-bits */

		DIO_enuWriteGroup(pinsConfiguration[u8IndexCpy].dataPins,binary_command,8);
		/*
		DIO_enuWritePin(16,0);
		*/
	}
	else
	{
		for(counter=4;counter<8;counter++){
			/* Sending the last 4 bits only */
			DIO_enuWritePin(pinsConfiguration[u8IndexCpy].dataPins[counter],binary_command[counter]);
		}
	}
	/* 1 For  Enable */
	DIO_enuWritePin(pinsConfiguration[u8IndexCpy].enablePin,LEVEL_HIGH);
	_delay_ms(10);
	DIO_enuWritePin(pinsConfiguration[u8IndexCpy].enablePin,LEVEL_LOW);
	_delay_ms(10);

}

void LCD_voidSendChar(uint8 u8IndexCpy,uint8 u8CommandCpy){
	/* RS pin to 1 to write command */
	DIO_enuWritePin(pinsConfiguration[u8IndexCpy].registerSelectPin ,LEVEL_HIGH);
	if(configuration[u8IndexCpy].mode == LCD_8_BIT_MODE){
		LCD_help(u8IndexCpy,u8CommandCpy);
		_delay_ms(1);

	}
	else
	{
		LCD_help(u8IndexCpy,u8CommandCpy);
		_delay_ms(1);
		LCD_help(u8IndexCpy,u8CommandCpy<<4);
		_delay_ms(1);
	}
}

void LCD_voidSendCommand(uint8 u8IndexCpy,uint8 u8CommandCpy){

	if(configuration[u8IndexCpy].mode == LCD_8_BIT_MODE){
		LCD_voidWriteCommand(u8IndexCpy,u8CommandCpy);
		_delay_ms(1);
	}
	else
	{
		LCD_voidWriteCommand(u8IndexCpy,u8CommandCpy);
		_delay_ms(1);
		LCD_voidWriteCommand(u8IndexCpy,u8CommandCpy<<4);
		_delay_ms(1);
	}
}

void LCD_voidSendString(uint8 u8IndexCpy,uint8 *pau8CharCpy){
	uint8 counter=0;
	while(pau8CharCpy[counter]!='\0'){
		LCD_voidSendChar(u8IndexCpy,pau8CharCpy[counter]);
		counter++;
	}
}

void LCD_voidClrScr(uint8 u8IndexCpy){
	LCD_voidSendCommand(u8IndexCpy,CLEAR_DISPLAY_COMMAND);
}

void LCD_voidMoveCursor(uint8 u8IndexCpy,uint8 u8RowCpy,uint8 u8ColCpy){
	uint8 cursorPosition;
	if(u8RowCpy==0){
		cursorPosition=LCD_LINE_0_BASE_ADDRESS+u8ColCpy;
	}
	else{
		cursorPosition=LCD_LINE_1_BASE_ADDRESS+u8ColCpy;
	}
	cursorPosition=cursorPosition|0x80;
	LCD_voidSendCommand(u8IndexCpy,cursorPosition);
}

//void LCD_voidSendNumber(uint8 u8IndexCpy,uint16 u16NumberCpy){
//	uint16 buff[16];
//	itoa(u16NumberCpy,buff,10);
//	LCD_voidSendString(u8IndexCpy,buff);
//}
//
//void LCD_displayStringRowColumn(uint8 u8IndexCpy,uint8 u8RowCpy,uint8 u8ColCpy,uint8 *pau8CharCpy){
//	uint8 counter=0;
//	LCD_voidMoveCursor(u8IndexCpy,u8RowCpy,u8ColCpy);
//	while(pau8CharCpy[counter]!='\0'){
//		LCD_voidSendChar(0,pau8CharCpy[counter]);
//		counter++;
//	}
//}
//
//
//void LCD_sendSpecialCharacter(uint8 u8IndexCpy,uint8 u8CharacterIndex,uint8 u8CharacterLocation,uint8 pattern){
//	/* Adjust address counter to the CGRAM */
//	uint8 location_command=0b01000000;
//	location_command = location_command | ((u8CharacterIndex*8)+u8CharacterLocation);
//	LCD_voidSendCommand(u8IndexCpy,location_command);
//	LCD_voidSendChar(u8IndexCpy,pattern);
//
//}
