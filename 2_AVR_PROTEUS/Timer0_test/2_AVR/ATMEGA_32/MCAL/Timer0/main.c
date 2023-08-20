#include "..\..\MCAL\Global_Interrupt_Enable_Driver\GIE.h"
#include "..\..\LIB\Std_Types.h"
#include "..\DIO_DRIVER\Dio_Interface.h"
#include "Timer0.h"
#include "util/delay.h"
void Toggle_led(){
	static uint16 counter=0;
	counter++;
	if(counter==2000){
		DIO_enuWritePin(DIO_PIN_NUM_B3,LEVEL_LOW);
	}
	if(counter==4000){
		DIO_enuWritePin(DIO_PIN_NUM_B3,LEVEL_HIGH);
		counter=0;
	}

}
int main(){
	DIO_Init();
	GI_voidEnable();
	TIMER0_voidTimer0_Init();
	TIMER0_voidSetTCNTValue(0);
	TIMER0_voidSetOCRValue(128);
	// TIMER0_voidEnableComparINT();
	// TIMER0_voidTimer0CMPSetCallBack(Toggle_led);
	TIMER0_voidEnable(TIMER0_CLK_8);

//	/* Set duty cycle before */
//	TIMER1_voidTimer1SetCompareMatchValueChannelA(900);
//	/* Initialize TIMER1 */
//	TIMER1_voidTimer1Init();
	while(1){

	}
}
