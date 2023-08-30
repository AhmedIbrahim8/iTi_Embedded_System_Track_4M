#include "..\..\MCAL\Global_Interrupt_Enable_Driver\GIE.h"
#include "..\..\LIB\Std_Types.h"
#include "..\DIO_DRIVER\Dio_Interface.h"
#include "Timer1.h"
#include "util/delay.h"
void Toggle_led(){
	static uint16 counter=0;
	counter++;
	if(counter==2){
		DIO_enuWritePin(DIO_PIN_NUM_B3,LEVEL_LOW);
	}
	if(counter==4){
		DIO_enuWritePin(DIO_PIN_NUM_B3,LEVEL_HIGH);
		counter=0;
	}

}
int main(){
	DIO_Init();
	GI_voidEnable();
	//TIMER1_voidEnableCompareAINT();
	TIMER1_voidTimer1_Init();
	TIMER1_voidSetTCNT1Value(0);
	TIMER1_voidSetOCR1AValue(0);
	TIMER1_voidSetOCR1BValue(10000);
	TIMER1_voidSetICR1Value(20000);
	//TIMER1_voidTimer1CMPASetCallBack(Toggle_led);
    // TIMER1_voidSetOCR1Value(128);
	// TIMER0_voidEnableComparINT();
	// TIMER0_voidTimer0CMPSetCallBack(Toggle_led);
	TIMER1_voidEnable(TIMER1_CLK_8);

//	/* Set duty cycle before */
//	TIMER1_voidTimer1SetCompareMatchValueChannelA(900);
//	/* Initialize TIMER1 */
//	TIMER1_voidTimer1Init();
	while(1){

	}
}
