//#include "..\..\HAL\LCD\Lcd.h"
//#include "..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
//#include "..\..\LIB\Std_Types.h"
//#include "..\..\LIB\common_macros.h"
//#include "..\..\MCAL\Timer0\Timer0.h"
//#include "..\..\MCAL\Timer1\Timer1.h"
//#include "..\..\MCAL\External_Interrupt_Driver\EXT_INT.h"
//#include "..\..\MCAL\Global_Interrupt_Enable_Driver\GIE.h"
//
//
//
//
//int main(){
//	uint32 Local_u32TotalPeriod;
//	uint8  Local_u8DutyCycle;
//
//	/* Initialize the Dio */
//	DIO_Init();
//	/* Set the global interrupt enable */
//	GI_voidEnable();
//    /* Turn on Timer 1 to measure the time */
//	TIMER1_voidSetTCNT1Value(0);
//	TIMER1_voidTimer1_Init();
//	TIMER1_voidEnable(TIMER1_CLK_8);
//
//	/* Initialize the Timer0 to give PWM Signal */
//	/* Duty Cycle = 50 %                        */
//	/* Frequency  = 3906.25                     */
//	TIMER0_voidSetTCNTValue(0);
//	TIMER0_voidSetOCRValue(50);
//	TIMER0_voidTimer0_Init();
//	TIMER0_voidEnable(TIMER0_CLK_8);
//
//	/* Initialize the LCD */
//	LCD_voidInit();
//
//
//	while(1)
//	{
//		uint8 period[]="Period=";
//		uint8 duty[]="Duty = ";
//		Local_u32TotalPeriod=App_u16OffPeriod+App_u16OnPeriod;
//		Local_u8DutyCycle = (uint8)((App_u16OnPeriod*100UL)/(Local_u32TotalPeriod));
//		LCD_displayStringRowColumn(0,0,0,period);
//		LCD_voidSendNumber(0,Local_u32TotalPeriod);
//		LCD_voidSendChar(0,'u');
//		LCD_voidSendChar(0,'s');
//		LCD_displayStringRowColumn(0,1,0,duty);
//		LCD_voidSendNumber(0,Local_u8DutyCycle);
//		LCD_voidSendChar(0,'%');
//	}
//
//
//	return 0;
//}
//
//
//
