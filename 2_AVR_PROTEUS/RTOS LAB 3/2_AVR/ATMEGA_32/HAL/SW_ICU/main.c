//#include "..\..\HAL\LCD\Lcd.h"
//#include "..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
//#include "..\..\LIB\Std_Types.h"
//#include "..\..\LIB\common_macros.h"
//#include "..\..\MCAL\Timer0\Timer0.h"
//#include "..\..\MCAL\Timer1\Timer1.h"
//#include "..\..\MCAL\Global_Interrupt_Enable_Driver\GIE.h"
//
//#include <util/delay.h>
//#include "SWICU.h"
//
//
//
//int main(){
//	uint32 Local_u32TotalPeriod;
//	uint8  Local_u8DutyCycle;
//	uint16  Local_u16Freq;
//	/* Initialize the Dio */
//	DIO_Init();
//	/* Set the global interrupt enable */
//	GI_voidEnable();
//    /* Turn on Timer 1 to measure the time */
//	TIMER1_voidSetTCNT1Value(0);
//	TIMER1_voidTimer1_Init();
//	TIMER1_voidEnable(TIMER1_CLK_8);
//
//	/* Initialize the software icu */
//	//SWICU_voidEnable();
//
//	/* Initialize hw ICU */
//	TIMER1_voidHWICUEnable();
//	/* Initialize the Timer0 to give PWM Signal */
//	/* Duty Cycle = 50 %                        */
//	/* Frequency  = 3906.25                     */
//	TIMER0_voidSetTCNTValue(0);
//	TIMER0_voidSetOCRValue(127);
//	TIMER0_voidTimer0_Init();
//	TIMER0_voidEnable(TIMER0_CLK_8);
//
//	/* Initialize the LCD */
//	LCD_voidInit();
//
//
//	while(1)
//	{
//		uint8 period[]="Freq =";
//		uint8 duty[]="Duty = ";
//		TIMER1_voidGetPWMTotalPeriod(&Local_u32TotalPeriod);
//		Local_u16Freq= 1000000/Local_u32TotalPeriod;
//		TIMER1_voidGetPWMDutyCycle(&Local_u8DutyCycle);
//		LCD_displayStringRowColumn(0,0,0,period);
//		LCD_voidSendNumber(0,Local_u16Freq);
//		LCD_voidSendChar(0,' H');
//		LCD_voidSendChar(0,'z');
//		LCD_displayStringRowColumn(0,1,0,duty);
//		LCD_voidSendNumber(0,Local_u8DutyCycle);
//		LCD_voidSendChar(0,' %');
//		_delay_ms(2000);
//		TIMER0_voidSetOCRValue(250);
//		TIMER0_voidEnable(TIMER0_CLK_1024);
//
//		TIMER1_voidGetPWMTotalPeriod(&Local_u32TotalPeriod);
//		Local_u16Freq= 1000000/Local_u32TotalPeriod;
//		TIMER1_voidGetPWMDutyCycle(&Local_u8DutyCycle);
//		LCD_displayStringRowColumn(0,0,0,period);
//		LCD_voidSendNumber(0,Local_u16Freq);
//		LCD_voidSendChar(0,' H');
//		LCD_voidSendChar(0,'z');
//		LCD_displayStringRowColumn(0,1,0,duty);
//		LCD_voidSendNumber(0,Local_u8DutyCycle);
//		LCD_voidSendChar(0,' %');
//		_delay_ms(2000);
//		TIMER0_voidSetOCRValue(250);
//		TIMER0_voidEnable(TIMER0_CLK_64);
//
//
//	}
//
//
//	return 0;
//}
//
//
//
