#include"..\..\..\LIB\Std_Types.h"
#include"..\..\..\LIB\common_macros.h"
#include"..\..\..\HAL\Keypad\Keypad.h"
#include"..\..\..\HAL\LCD\Lcd.h"
#include"..\..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
#include <util/delay.h>
#define   HOUR_1_CURSOR_POSITION  5
#define   HOUR_0_CURSOR_POSITION  6
#define   MINUTE_1_CURSOR_POSITION  8
#define   MINUTE_0_CURSOR_POSITION  9
#define   SECOND_1_CURSOR_POSITION  11
#define   SECOND_0_CURSOR_POSITION  12

int main(){
	uint8 second;
	uint8 minute;
	uint8 hour;
	uint8 counter=0;
	/* Seconds variable */
	uint8 seconds[2]={0,0};
	/* Minutes variable */
	uint8 minutes[2]={0,0};
	/* Hours variable */
	uint8 hours[2]={0,0};
	/* Initial Value of keypad state*/
	uint8 keypad_state=KEYPAD_NOT_PRESSED;
	uint8 u8cursorPosition=5;
	DIO_Init();
	LCD_voidInit();
	KPD_voidInit(KEYPAD1_INDEX);
	/* Initial Value of the stop watch */
	LCD_voidMoveCursor(LCD1_INDEX_NUMBER,0,u8cursorPosition);
	LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,4,"Stop Watch");
	/* Cursor Position : 0   1   2   3   4     5         6          7            8         9          10            11         12   */
	/*                                      hours[1]  hours[0]              minutes[1]  minutes[0]              seconds[1]  seconds[0]
	/*                                         0         0          :            0         0           :            0          0   */
	LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,1,5,"00:00:00");
	/* Cursor to the first of the hours */
	LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
	while(1){
		/* Get the key from the user */
		keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
		/* If key not equal KEYPAD_NOT_PRESSED , the user pressed the key and will enter the if condition */
		if(keypad_state !=KEYPAD_NOT_PRESSED){
			switch(keypad_state){
			/* In case User wants to clear the stop watch */
			case 'c':
				/* Setting zeros to all seconds, minutes and hours */
				seconds[0]=0;
				seconds[1]=0;
				minutes[0]=0;
				minutes[1]=0;
				hours[0]=0;
				hours[1]=0;
				LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,1,5,"00");
				LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,1,8,"00");
				LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,1,11,"00");
				u8cursorPosition=5;
				LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
				break;
				/* '6' means user move right */
			case '6':
				/* In case user reach the last of Right limit, it will go the last of the left limits*/
				if(u8cursorPosition==SECOND_0_CURSOR_POSITION){
					u8cursorPosition=HOUR_1_CURSOR_POSITION;
				}
				else{
					u8cursorPosition++;
				}
				/* Move the cursor based on the u8cursorPosition value */
				LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
				break;
				/* '4' means user move Left */
			case '4':
				/* In case user reach the last of left limit, it will go the last of the right limits*/
				if(u8cursorPosition==HOUR_1_CURSOR_POSITION){
					u8cursorPosition=SECOND_0_CURSOR_POSITION;
				}
				else{
					u8cursorPosition--;
				}
				/* Move the cursor based on the u8cursorPosition value */
				LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
				break;
				/* '8' means Increment the the element which the cursor points at */
			case '2':
				/* Here, we want to check the cursor position of the cursor */
				switch(u8cursorPosition){
				case HOUR_1_CURSOR_POSITION:
					if(hours[1]==2){
						hours[1]=0;
					}
					else{
						hours[1]++;
					}
					counter=hours[1];
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,counter);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case HOUR_0_CURSOR_POSITION:
					if(hours[0]==4){
						hours[0]=0;
					}
					else{
						hours[0]++;
					}
					counter=hours[0];
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,counter);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case MINUTE_1_CURSOR_POSITION:
					if(minutes[1]==6){
						minutes[1]=0;
					}
					else{
						minutes[1]++;
					}
					counter=minutes[1];
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,counter);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case MINUTE_0_CURSOR_POSITION:
					if(minutes[0]==9){
						minutes[0]=0;
					}
					else{
						minutes[0]++;
					}
					counter=minutes[0];
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,counter);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case SECOND_1_CURSOR_POSITION:
					if(seconds[1]==6){
						seconds[1]=0;
					}
					else{
						seconds[1]++;
					}
					counter=seconds[1];
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,counter);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case SECOND_0_CURSOR_POSITION:
					if(seconds[0]==9){
						seconds[0]=0;
					}
					else{
						seconds[0]++;
					}
					counter=seconds[0];
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,counter);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				}

				break;
				/* '2' means Decrement the increment the element which the cursor points at */
			case '8':
				/* Here, we want to check the cursor position of the cursor */
				switch(u8cursorPosition){
				case HOUR_1_CURSOR_POSITION:
					if(hours[1]==0){
						hours[1]=2;
					}
					else{
						hours[1]--;
					}
					counter=hours[1];
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,counter);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case HOUR_0_CURSOR_POSITION:
					if(hours[0]==0){
						hours[0]=4;
					}
					else{
						hours[0]--;
					}
					counter=hours[0];
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,counter);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case MINUTE_1_CURSOR_POSITION:
					if(minutes[1]==0){
						minutes[1]=6;
					}
					else{
						minutes[1]--;
					}
					counter=minutes[1];
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,counter);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case MINUTE_0_CURSOR_POSITION:
					if(minutes[0]==0){
						minutes[0]=9;
					}
					else{
						minutes[0]--;
					}
					counter=minutes[0];
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,counter);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case SECOND_1_CURSOR_POSITION:
					if(seconds[1]==0){
						seconds[1]=6;
					}
					else{
						seconds[1]--;
					}
					counter=seconds[1];
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,counter);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case SECOND_0_CURSOR_POSITION:
					if(seconds[0]==0){
						seconds[0]=9;
					}
					else{
						seconds[0]--;
					}
					counter=seconds[0];
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,counter);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				}
				break;
				/* Stop watch begin*/
				case '3':
					second=seconds[1]*10+seconds[0];
					minute=minutes[1]*10+minutes[0];
					hour=hours[1]*10+hours[0];
					while(second!=0 || minute!=0 || hour!=0){
						_delay_ms(1000);
						second--;
						LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,SECOND_0_CURSOR_POSITION);
						LCD_voidSendNumber(LCD1_INDEX_NUMBER,second%10);
						LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,SECOND_1_CURSOR_POSITION);
						LCD_voidSendNumber(LCD1_INDEX_NUMBER,second/10);
						if(second==0){
							if(minute>0){
								minute--;
								second=59;
							}
							LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,SECOND_0_CURSOR_POSITION);
							LCD_voidSendNumber(LCD1_INDEX_NUMBER,second%10);
							LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,SECOND_1_CURSOR_POSITION);
							LCD_voidSendNumber(LCD1_INDEX_NUMBER,second/10);
							LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,MINUTE_0_CURSOR_POSITION);
							LCD_voidSendNumber(LCD1_INDEX_NUMBER,minute%10);
							LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,MINUTE_1_CURSOR_POSITION);
							LCD_voidSendNumber(LCD1_INDEX_NUMBER,minute/10);
						if(minute==0 && second==0){
							if(hour==0){
								break;
							}
							hour--;
							minute=59;
							second=59;
							LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,MINUTE_0_CURSOR_POSITION);
							LCD_voidSendNumber(LCD1_INDEX_NUMBER,minute%10);
							LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,MINUTE_1_CURSOR_POSITION);
							LCD_voidSendNumber(LCD1_INDEX_NUMBER,minute/10);
							LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,HOUR_0_CURSOR_POSITION);
							LCD_voidSendNumber(LCD1_INDEX_NUMBER,hour%10);
							LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,HOUR_1_CURSOR_POSITION);
							LCD_voidSendNumber(LCD1_INDEX_NUMBER,hour/10);
						}
						}
					}

					break;
			}
		}
	}

	return 0;
}
