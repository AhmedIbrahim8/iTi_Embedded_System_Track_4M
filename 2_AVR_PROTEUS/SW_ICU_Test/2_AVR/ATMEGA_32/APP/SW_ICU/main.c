#include "..\..\HAL\LCD\Lcd.h"
#include "..\..\MCAL\DIO_DRIVER\DIO_Interface.h"
#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\common_macros.h"
#include "..\..\MCAL\Timer0\Timer0.h"
#include "..\..\MCAL\Timer1\Timer1.h"
#include "..\..\MCAL\External_Interrupt_Driver\EXT_INT.h"
#include "..\..\MCAL\Global_Interrupt_Enable_Driver\GIE.h"
/* */
volatile uint16 App_u16OnPeriod=0;
volatile uint16 App_u16OffPeriod=0;
void App_voidEXTICallBack(void);

int main(){
	uint32 Local_u32TotalPeriod;
	uint8  Local_u8DutyCycle;

	/* Initialize the Dio */
	DIO_Init();
	/* Set the global interrupt enable */
	GI_voidEnable();
    /* Turn on Timer 1 to measure the time */
	TIMER1_voidSetTCNT1Value(0);
	TIMER1_voidTimer1_Init();
	TIMER1_voidEnable(TIMER1_CLK_8);

	/* Set call back function of the Interrupt 0 */
	EXT_INT_SetCallBack(&App_voidEXTICallBack,EXTERNAL_INT_0_INDEX);
	/* Enable External Interrupt 0 */
	EXT_INT_Enable(EXTERNAL_INT_0_INDEX,RISING_EDGE);

	/* Initialize the Timer0 to give PWM Signal */
	/* Duty Cycle = 50 %                        */
	/* Frequency  = 3906.25                     */
	TIMER0_voidSetTCNTValue(0);
	TIMER0_voidSetOCRValue(50);
	TIMER0_voidTimer0_Init();
	TIMER0_voidEnable(TIMER0_CLK_8);

	/* Initialize the LCD */
	LCD_voidInit();


	while(1)
	{
		uint8 period[]="Period=";
		uint8 duty[]="Duty = ";
		Local_u32TotalPeriod=App_u16OffPeriod+App_u16OnPeriod;
		Local_u8DutyCycle = (uint8)((App_u16OnPeriod*100UL)/(Local_u32TotalPeriod));
		LCD_displayStringRowColumn(0,0,0,period);
		LCD_voidSendNumber(0,Local_u32TotalPeriod);
		LCD_voidSendChar(0,'u');
		LCD_voidSendChar(0,'s');
		LCD_displayStringRowColumn(0,1,0,duty);
		LCD_voidSendNumber(0,Local_u8DutyCycle);
		LCD_voidSendChar(0,'%');
	}


	return 0;
}



void App_voidEXTICallBack(void){
	uint16 Local_u16TimerValue;
	static uint8 Local_u8Flag=0;
	/* We must save the previous value of the timer counter */
	static uint16 Local_u16ldValue=0;
	/* Read the timer1 Value */
	Local_u16TimerValue=TIMER1_u16ReadTcnt1Reg();

	/* Here, we will measure the off period */
	/* Here, we will change the mode of the interrupt to detect the
	 * falling edge                                                 */
	/* Set the flag to be 1*/
	if(0==Local_u8Flag){
		/* t(off) = New counter Value - Previous Counter Value */
		App_u16OffPeriod=Local_u16TimerValue-Local_u16ldValue;
		/* Change the sense Control into Falling Edge */
		EXT_INT_Enable(EXTERNAL_INT_0_INDEX,FALLING_EDGE);
		/* Change the flag to be 1 */
		Local_u8Flag=1;
	}
	/* Here, */
	else{
		/* t(on) = New counter Value - Previous Counter Value */
		App_u16OnPeriod=Local_u16TimerValue-Local_u16ldValue;
		/* Change the sense Control into rising Edge */
		EXT_INT_Enable(EXTERNAL_INT_0_INDEX,RISING_EDGE);
		/* Change the flag to be 0 */
		Local_u8Flag=0;
	}
	Local_u16ldValue=Local_u16TimerValue;
}
