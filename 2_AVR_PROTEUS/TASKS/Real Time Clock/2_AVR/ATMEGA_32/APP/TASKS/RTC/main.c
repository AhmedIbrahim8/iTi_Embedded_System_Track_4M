#include"..\..\..\LIB\Std_Types.h"
#include"..\..\..\LIB\common_macros.h"
#include"..\..\..\HAL\Keypad\Keypad.h"
#include"..\..\..\HAL\LCD\Lcd.h"
#include"..\..\..\HAL\Seven_Segment\SevenSegment.h"
#include"..\..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
#include"..\..\..\MCAL\Timer2\Timer2.h"
#include"..\..\..\MCAL\Global_Interrupt_Enable_Driver\GIE.h"
#include <util/delay.h>
#define   HOUR_1_CURSOR_POSITION  5
#define   HOUR_0_CURSOR_POSITION  6
#define   MINUTE_1_CURSOR_POSITION  8
#define   MINUTE_0_CURSOR_POSITION  9
#define   SECOND_1_CURSOR_POSITION  11
#define   SECOND_0_CURSOR_POSITION  12
/* Three global Variables that get changed by the call back function of TIMER2*/
uint8 global_hours=0;
uint8 global_minutes=0;
uint8 global_seconds=0;
/* Function responsible for displaying the clock on the seven segments */
void App_Display_Sev_Segment();

/* This Function will be called back by the Timer2 compare match ISR
 * called every 1 second to increment the seconds
 * */
void App_Increment(void);
/* Function to display new clock adjustment */
void App_DisplayNewClock(void);
int main(){
	/* Seconds variable */
	uint8 seconds[2]={0,0};
	/* Minutes variable */
	uint8 minutes[2]={0,0};
	/* Hours variable */
	uint8 hours[2]={0,0};
	/* Initial Value of keypad state*/
	uint8 keypad_state=KEYPAD_NOT_PRESSED;
	/* Variable indicating the first position of the clock on the screen*/
	uint8 u8cursorPosition=HOUR_1_CURSOR_POSITION;
	/* Initialize the Dio Driver */
	DIO_Init();
	/* Initialize the LCD */
	LCD_voidInit();
	/* Initialize the keypad, here we have only one keypad */
	KPD_voidInit(KEYPAD1_INDEX);

	/* Set the I bit in the SREG Register (Global interrupt enable bit)*/
	GI_voidEnable();
	/* Adjust the mode and clock source of Timer 2 to make 1 second */
	TIMER2_voidTimer2_Init();
	/* Set the call back of the compare match interrupt
	 * Timer2 should be independent of the application */
	TIMER2_voidTimer2CMPSetCallBack(App_Increment);
	/* Zero to the counter register TCNT2 */
	TIMER2_voidSetTCNTValue(0);
	/* Adjust the compare value */
	TIMER2_voidSetOCRValue(250);
	/* Enable the compare interrupt */
	TIMER2_voidEnableCompareINT();
	/* Ask the user to adjust the clock */
	LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,LCD_COL_0_INDEX,"Please Adjust ");
	LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,1,LCD_COL_0_INDEX,"Your Clock..... ");
	_delay_ms(1000);
	App_DisplayNewClock();
	while(1){
		/* Get the key from the user */
		keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
		/* If key not equal KEYPAD_NOT_PRESSED , the user pressed the key and will enter the if condition */
		if(keypad_state !=KEYPAD_NOT_PRESSED){
			switch(keypad_state){
			/* In case User wants to clear the stop watch */
			case 'c':
				/* Setting zeros to all seconds, minutes and hours */
				global_hours=0;
				global_minutes=0;
				global_seconds=0;
				seconds[0]=0;
				seconds[1]=0;
				minutes[0]=0;
				minutes[1]=0;
				hours[0]=0;
				hours[1]=0;
				/* Display zeros on the Lcd */
				LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,1,5,"00:00:00");
				/* Adjust the cursor to the first position of the clock */
				u8cursorPosition=5;
				/* ROW 1 : COL : 5 */
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
			case '8':
				/* Here, we want to check the cursor position of the cursor */
				switch(u8cursorPosition){
				case HOUR_1_CURSOR_POSITION:
					if(hours[1]==2){
						hours[1]=0;
					}
					else{
						hours[1]++;
					}

					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,hours[1]);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case HOUR_0_CURSOR_POSITION:
					if(hours[0]==9){
						hours[0]=0;
					}
					else{
						hours[0]++;
					}

					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,hours[0]);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case MINUTE_1_CURSOR_POSITION:
					if(minutes[1]==5){
						minutes[1]=0;
					}
					else{
						minutes[1]++;
					}

					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,minutes[1]);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case MINUTE_0_CURSOR_POSITION:
					if(minutes[0]==9){
						minutes[0]=0;
					}
					else{
						minutes[0]++;
					}

					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,minutes[0]);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case SECOND_1_CURSOR_POSITION:
					if(seconds[1]==5){
						seconds[1]=0;
					}
					else{
						seconds[1]++;
					}

					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,seconds[1]);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case SECOND_0_CURSOR_POSITION:
					if(seconds[0]==9){
						seconds[0]=0;
					}
					else{
						seconds[0]++;
					}

					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,seconds[0]);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				}

				break;
				/* '2' means Decrement the increment the element which the cursor points at */
			case '2':
				/* Here, we want to check the cursor position of the cursor */
				switch(u8cursorPosition){
				case HOUR_1_CURSOR_POSITION:
					if(hours[1]==0){
						hours[1]=1;
					}
					else{
						hours[1]--;
					}

					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,hours[1]);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case HOUR_0_CURSOR_POSITION:
					if(hours[0]==0){
						hours[0]=9;
					}
					else{
						hours[0]--;
					}

					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,hours[0]);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case MINUTE_1_CURSOR_POSITION:
					if(minutes[1]==0){
						minutes[1]=5;
					}
					else{
						minutes[1]--;
					}

					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,minutes[1]);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case MINUTE_0_CURSOR_POSITION:
					if(minutes[0]==0){
						minutes[0]=9;
					}
					else{
						minutes[0]--;
					}

					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,minutes[0]);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case SECOND_1_CURSOR_POSITION:
					if(seconds[1]==0){
						seconds[1]=5;
					}
					else{
						seconds[1]--;
					}

					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,seconds[1]);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				case SECOND_0_CURSOR_POSITION:
					if(seconds[0]==0){
						seconds[0]=9;
					}
					else{
						seconds[0]--;
					}

					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					LCD_voidSendNumber(LCD1_INDEX_NUMBER,seconds[0]);
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					break;
				}

				break;
				/* Real time clock begin*/
				case '9':
					LCD_voidClrScr(LCD1_INDEX_NUMBER);
					LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,0,"7:Pause 3:Resume");
					LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,1,0,"1 : New Clock");
					global_seconds=seconds[1]*10+seconds[0];
					global_minutes=minutes[1]*10+minutes[0];
					global_hours=hours[1]*10+hours[0];
					/* Set the pre-scaler to give 1 second  */
					TIMER2_voidEnable(TIMER2_CLK_128);
					while((global_minutes>=0 || global_seconds>=0 || global_hours>=0) && keypad_state!='1'){
						App_Display_Sev_Segment();

						/* Get the key from the user */
						keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
						if(keypad_state=='7'){
							TIMER2_voidDisableCompareINT();
							TIMER2_voidEnable(TIMER2_NO_CLOCK_SOURCE);
							while(keypad_state !='3' && keypad_state!='1'){
								/* Get the key from the user */
								keypad_state=KPD_u8GetPressedKey(KEYPAD1_INDEX);
								App_Display_Sev_Segment();
							}

							TIMER2_voidEnableCompareINT();
							TIMER2_voidEnable(TIMER2_CLK_128);
						}
					}
					App_DisplayNewClock();
					/* Cursor to the first of the hours */
					LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
					/* Setting zeros to all seconds, minutes and hours */
					global_hours=0;
					global_minutes=0;
					global_seconds=0;
					seconds[0]=0;
					seconds[1]=0;
					minutes[0]=0;
					minutes[1]=0;
					hours[0]=0;
					hours[1]=0;

					break;
			}
		}
	}

	return 0;
}



void App_Display_Sev_Segment(){
	/* Sequence of displaying on a multiplexed 6 seven segment :
	 *    1- Write the data (number) on the Data pins of the seven segment
	 *    2- Enable the specified Seven segment, the responsible for that data
	 *    3- Delay 1us so, data can be displayed on the seven segment
	 *    4- Disable the specified seven segment and move to the next seven segment    */

	/* Display the hours on the seven segment */
	SEV_Write(SEV1_INDEX_NUMBER,global_hours/10);
	SEV_Enable(SEV1_INDEX_NUMBER);
	_delay_us(1);
	SEV_Disable(SEV1_INDEX_NUMBER);

	SEV_Write(SEV2_INDEX_NUMBER,global_hours%10);
	SEV_Enable(SEV2_INDEX_NUMBER);
	_delay_us(1);
	SEV_Disable(SEV2_INDEX_NUMBER);

	/* Display the minutes on the seven segment */
	SEV_Write(SEV3_INDEX_NUMBER,global_minutes/10);
	SEV_Enable(SEV3_INDEX_NUMBER);
	_delay_us(1);
	SEV_Disable(SEV3_INDEX_NUMBER);

	SEV_Write(SEV4_INDEX_NUMBER,global_minutes%10);
	SEV_Enable(SEV4_INDEX_NUMBER);
	_delay_us(1);
	SEV_Disable(SEV4_INDEX_NUMBER);

	/* Display the seconds on the seven segment */
	SEV_Write(SEV5_INDEX_NUMBER,global_seconds/10);
	SEV_Enable(SEV5_INDEX_NUMBER);
	_delay_us(1);
	SEV_Disable(SEV5_INDEX_NUMBER);

	SEV_Write(SEV6_INDEX_NUMBER,global_seconds%10);
	SEV_Enable(SEV6_INDEX_NUMBER);
	_delay_us(1);
	SEV_Disable(SEV6_INDEX_NUMBER);

}



void App_Increment(void){
	/* In case seconds < 59 , we will increment the seconds by 1 */
	if(global_seconds<59){
		global_seconds++;
	}
	/* In case seconds equal 59, we will make seconds equal zero for the next minute
	 * */
	else if(global_seconds==59){
		global_seconds=0;
		/* the next we should increment the minutes by 1 only if minutes < 59 */
		if(global_minutes<59){
			global_minutes++;
		}
		/* In case minutes equal 59, we will make minutes equal zero */
		else if(global_minutes==59){
			global_minutes=0;
			/* If hours < 23 , we will increment hours by 1 */
			if(global_hours<23)
			{
				global_hours++;
			}
			/* If hours= 23, make hourse equal zero */
			else if(global_hours==23)
			{
				global_hours=0;
			}

		}

	}

}



void App_DisplayNewClock(void)
{
	uint8 u8cursorPosition=HOUR_1_CURSOR_POSITION;
	LCD_voidClrScr(LCD1_INDEX_NUMBER);
	/* Initial Value of the stop watch */
	LCD_voidMoveCursor(LCD1_INDEX_NUMBER,0,u8cursorPosition);
	LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,0,0,"Real Time Clock");
	/* Cursor Position : 0   1   2   3   4     5         6          7            8         9          10            11         12   */
	/*                                      hours[1]  hours[0]              minutes[1]  minutes[0]              seconds[1]  seconds[0]
	/*                                         0         0          :            0         0           :            0          0   */
	LCD_displayStringRowColumn(LCD1_INDEX_NUMBER,1,5,"00:00:00");
	u8cursorPosition=HOUR_1_CURSOR_POSITION;
	/* Cursor to the first of the hours */
	LCD_voidMoveCursor(LCD1_INDEX_NUMBER,1,u8cursorPosition);
}

//int main(){
//	uint8 User_Choice=KEYPAD_NOT_PRESSED;
//	DIO_Init();
//	LCD_voidInit();
//	KPD_voidInit(KEYPAD1_INDEX);
//	/* Set the I bit in the SREG Register */
//	GI_voidEnable();
//	/* Adjust the mode and clock source of Timer 2 */
//	TIMER2_voidTimer2_Init();
//	/* Set the call back of the compare match interrupt*/
//	TIMER2_voidTimer2CMPSetCallBack();
//	/* Zero to the counter register TCNT2 */
//	TIMER2_voidSetTCNTValue(0);
//	/* Adjust the compare value */
//	TIMER2_voidSetOCRValue(250);
//	/* Enable the compare interrupt */
//	TIMER2_voidEnableCompareINT();
//	/* Set the pre-scaler to give 1 second  */
//	TIMER2_voidEnable(TIMER2_CLK_128);
//	while(1){
//		LCD_displayStringRowColumn(LCD1_INDEX_NUMBER, 0, LCD_COL_0_INDEX, "Press 1 to set  ");
//		LCD_displayStringRowColumn(LCD1_INDEX_NUMBER, 1, LCD_COL_0_INDEX, "clock : ");
//		User_Choice=KPD_u8GetPressedKey(KEYPAD1_INDEX);
//		if(KEYPAD_NOT_PRESSED!=User_Choice){
//			LCD_voidClrScr(LCD1_INDEX_NUMBER);
//			LCD_displayStringRowColumn(LCD1_INDEX_NUMBER, 0, LCD_COL_0_INDEX, "Hours =  ");
//			global_hours=KPD_u8GetPressedKey(KEYPAD1_INDEX);
//			while(global_hours>=24){
//				LCD_voidClrScr(LCD1_INDEX_NUMBER);
//				LCD_displayStringRowColumn(LCD1_INDEX_NUMBER, 0, LCD_COL_0_INDEX, "Invalid Value ");
//				LCD_voidClrScr(LCD1_INDEX_NUMBER);
//				LCD_displayStringRowColumn(LCD1_INDEX_NUMBER, 0, LCD_COL_0_INDEX, "Hours =  ");
//				global_hours=KPD_u8GetPressedKey(KEYPAD1_INDEX);
//			}
//
//		}
//		else{
//			/*Do No thing */
//		}
//
//	}
//}
