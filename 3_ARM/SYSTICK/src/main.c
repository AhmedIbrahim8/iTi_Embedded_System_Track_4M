

#include "../include/MGPIO_Interface.h"
#include "../include/MSYSTICK_Interface.h"
#include "../include/MRCC_Interface.h"

int main()
{
  // At this stage the system clock should have already been configured
  // at high speed.
	MRCC_Init();
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	SYSTICK_voidInit();
	SYSTICK_voidCtrlIntState(SYSTICK_DISABLE_EXCEPTION_REQUEST);
	MGPIO_SetMode(PORTA,PIN0,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN0,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetResetValue(PORTA,PIN0,OUTPUT_SET);

  // Infinite loop
  while (1)
    {
       // Add your code here.
	  MGPIO_SetResetValue(PORTA,PIN0,OUTPUT_SET);
	  SYSTICK_voidDelayUs(1000000);
	  MGPIO_SetResetValue(PORTA,PIN0,OUTPUT_RESET);
	  SYSTICK_voidDelayUs(1000000);
    }
  return 0;
}

