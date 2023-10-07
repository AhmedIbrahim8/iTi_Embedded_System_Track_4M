#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/MEXTI_Interface.h"

#include "../include/MGPIO_Interface.h"

#include "../include/MRCC_Interface.h"

#include "../include/HIR_Interface.h"




int main()
{
	/* Initialize System Clock*/
	MRCC_Init();
	/* Initialize the systick timer */
	SYSTICK_voidInit();
	/* Set the call back function of the systick timer */
	SYSTICK_voidSetCallBack(GetData);
	/* Enable the interrupt of the systick timer */
	SYSTICK_voidCtrlIntState(0);

	/* Initialize the clock of the GPIO A */
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	/* Adjust the PIN0 in PORTA to be input */
	MGPIO_SetMode(PORTA,PIN0,INPUT_RESET_STATE);
	MGPIO_SetInputPinMode(PORTA,PIN0,PULL_UP);
	/* Enable the NVIC enable of the external interrupt 0 */
	/* External interrupt 0 is number 6 in the vector table */
	MNVIC_VoidEnbleInterrupt(6);

	/* output pins */
	MGPIO_SetMode(PORTA,PIN1,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN1,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE );

	MGPIO_SetMode(PORTA,PIN2,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN2,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE );

	MGPIO_SetMode(PORTA,PIN3,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN3,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE );

	MGPIO_SetMode(PORTA,PIN4,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN4,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE );

	/* Set the call back of the external interrupt 0 */
	MEXTI_voidSetCallBack(EXTI_LINE_0,GetFrame);
	/* Adjust the External interrupt 0 pin */
	MEXTI_voidInterruptSetPort(EXTI_LINE_0,PORTA_PIN);
	/* Set the pin to detect the falling edge */
	MEXTI_voidInterruptTrigger(EXTI_LINE_0,EXTI_FALLING_EDGE);
	/* Enable the interrupt of the external interrupt 0*/
	MEXTI_voidInterruptEnableDisable(EXTI_LINE_0,EXTI_ENABLE);
	while(1)
	{
		if(data == 12){
			MGPIO_SetPinValue(PORTA,PIN1,GPIO_PIN_LEVEL_HIGH);
			MGPIO_SetPinValue(PORTA,PIN2,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN3,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN4,GPIO_PIN_LEVEL_LOW);
		}
		else if(data == 24){
			MGPIO_SetPinValue(PORTA,PIN1,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN2,GPIO_PIN_LEVEL_HIGH);
			MGPIO_SetPinValue(PORTA,PIN3,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN4,GPIO_PIN_LEVEL_LOW);
		}
		else if(data == 94){
			MGPIO_SetPinValue(PORTA,PIN1,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN2,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN3,GPIO_PIN_LEVEL_HIGH);
			MGPIO_SetPinValue(PORTA,PIN4,GPIO_PIN_LEVEL_LOW);
		}
		else if(data == 8){
			MGPIO_SetPinValue(PORTA,PIN1,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN2,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN3,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN4,GPIO_PIN_LEVEL_HIGH);
		}
		else if(data == 22){
			MGPIO_SetPinValue(PORTA,PIN1,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN2,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN3,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN4,GPIO_PIN_LEVEL_LOW);
		}

	}
	return 0;
}
