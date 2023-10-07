#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"

#include "../include/MEXTI_Interface.h"
#include "../include/MGPIO_Interface.h"
#include "../include/MNVIC_Interface.h"
#include "../include/MRCC_Interface.h"
#include "../include/MSYSTICK_Interface.h"

u8 TASKA_flag;
u8 TASKB_flag;
u8 IRQ_flag=0;



#define    TaskA_Stack_Size       100
#define    TaskB_Stack_Size       100

/* extern e_stack from the linker */
extern int _estack;


/* Main stack pointer start and end               */
unsigned int _S_MSP = &_estack;
unsigned int _E_MSP;

/* process stack pointer start and end for task A */
unsigned int _S_PSP_TA;
unsigned int _E_PSP_TA;


/* process stack pointer start and end for task B */
unsigned int _S_PSP_TB;
unsigned int _E_PSP_TB;


/* Volatile to stop optimization */
#define  OS_SET_PSP(add)         __asm volatile("mov r0,%[in1] \n\t" \
		                                        "msr PSP,r0" \
										        : \
										        :[in1] "r" (add))

#define  OS_SWITCH_SP_TO_PSP     __asm volatile("mrs r0,CONTROL \n\t"\
		                                        "mov r1,#0x02 \n\t"\
                                                "orr r0,r1,r0 \n\t"\
												"msr CONTROL,r0")

#define  OS_SWITCH_SP_TO_MSP     __asm volatile("mrs r0,CONTROL \n\t"\
		                                        "mov r1,#0x05 \n\t"\
                                                "and r0,r1,r0 \n\t"\
												"msr CONTROL,r0")

#define  OS_Generate_Exception   __asm volatile("SVC #0x3")
void SWITCH_CPU_AccessLevel(CPU_AccessLevel level)
{
	switch(level)
	{
	case PRIVILEGED:
		__asm(" mrs r3,CONTROL    \n\t"
			  " lsr r3, r3, #0x01 \n\t"
			  " lsl r3, r3, #0x01 \n\t"
			  " msr CONTROL, r3 ");

		break;
	case UNPRIVILEGED:
		__asm(" mrs r3, CONTROL   \n\t"
			  " orr r3, r3, #0x01 \n\t"
			  " msr CONTROL, r3 ");
		break;
	}
}

void func1(void);

void func2(void);

void SVC_Handler()
{
	SWITCH_CPU_AccessLevel(PRIVILEGED);
}


int TaskA(int a,int b,int c)
{
	return a+b+c;
}


int TaskB(int a,int b,int c,int d)
{
	return a+b+c;
}





/* Initialize all stack area for all tasks and initialize the end of the msp
 * MSP size = 512 Bytes
 * */
void Main_os()
{
	/* Specify the end of the end of the main stack pointer */
	_E_MSP = _S_MSP - 512;

	/* Task A */

	/* The stack area of the task A starts at the end of the MSP by 8 */
	_S_PSP_TA = _E_MSP - 8 ;
	/* The end of the task A is the start of task A - the size of the stack
	 * of task A which we will adjust to be 100 bytes */
	_E_PSP_TA = _S_PSP_TA - TaskA_Stack_Size;



	/* Task B */

	/* The stack area of the task B starts at the end of the PSP of Task A by 8 */
	_S_PSP_TB = _E_PSP_TA - 8 ;
	/* The end of the task A is the start of task A - the size of the stack
	 * of task A which we will adjust to be 100 bytes */
	_E_PSP_TB = _S_PSP_TA - TaskB_Stack_Size;


	/* Here, we want to make an simple ideal task */
	while(1)
	{
		__asm("NOP");
		if(TASKA_flag == 1)
		{
			/* Set PSP Register to _S_PSP_TA */
			OS_SET_PSP(_S_PSP_TA);
			/* Adjust the SP to point to PSP */
			OS_SWITCH_SP_TO_PSP;
			/* Switch to unprivilleged */
			SWITCH_CPU_AccessLevel(UNPRIVILEGED);


			TASKA_flag=TaskA(1,2,3);


			/* Switch from unpriv to priv */
			OS_Generate_Exception;
			/* Adjust the SP to point to MSP */
			OS_SWITCH_SP_TO_MSP;
		}
		else if(TASKA_flag == 1)
		{
			/* Set PSP Register to _S_PSP_TB */
			OS_SET_PSP(_S_PSP_TB);
			/* Adjust the SP to point to PSP */
			OS_SWITCH_SP_TO_PSP;
			/* Switch to unprivilleged */
			SWITCH_CPU_AccessLevel(UNPRIVILEGED);


			TASKB_flag=TaskB(1,2,3,4);

			/* Switch from unpriv to priv */
			OS_Generate_Exception;
			/* Adjust the SP to point to MSP */
			OS_SWITCH_SP_TO_MSP;
		}
	}

}


int main(){
	volatile void (*ptr)()=func1;
	MRCC_Init();
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOB);
	MRCC_Enable_Peripheral(RCC_APB2,RCC_APB2_SYSCFG);

	SYSTICK_voidInit();

	MGPIO_SetMode(PORTA,PIN0,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN0,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetMode(PORTA,PIN1,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN1,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetMode(PORTA,PIN2,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN2,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetMode(PORTA,PIN3,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN3,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetMode(PORTA,PIN4,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN4,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetMode(PORTA,PIN5,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN5,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetMode(PORTA,PIN6,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN6,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
	MGPIO_SetMode(PORTA,PIN7,GENRAL_PURPOSE_OUTPUT_MODE);
	MGPIO_SetOutputPinMode(PORTA,PIN7,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);

	MGPIO_SetPinValue(PORTA,PIN0,GPIO_PIN_LEVEL_LOW);
	MGPIO_SetPinValue(PORTA,PIN1,GPIO_PIN_LEVEL_LOW);
	MGPIO_SetPinValue(PORTA,PIN2,GPIO_PIN_LEVEL_LOW);
	MGPIO_SetPinValue(PORTA,PIN3,GPIO_PIN_LEVEL_LOW);
	MGPIO_SetPinValue(PORTA,PIN4,GPIO_PIN_LEVEL_LOW);
	MGPIO_SetPinValue(PORTA,PIN5,GPIO_PIN_LEVEL_LOW);
	MGPIO_SetPinValue(PORTA,PIN6,GPIO_PIN_LEVEL_LOW);
	MGPIO_SetPinValue(PORTA,PIN7,GPIO_PIN_LEVEL_LOW);


	MGPIO_SetMode(PORTB,PIN0,INPUT_RESET_STATE);
	MGPIO_SetInputPinMode(PORTB,PIN0,PULL_UP);

	MGPIO_SetMode(PORTB,PIN1,INPUT_RESET_STATE);
	MGPIO_SetInputPinMode(PORTB,PIN1,PULL_UP);

	/* Set Groups and Sub Groups */
	MNVIC_VoidSetInterruptGroupMode(GROUP_2_SUB_8);
	MNVIC_VoidSetInterruptPriority(6,1,0);
	MNVIC_VoidSetInterruptPriority(7,0,0);

//	SWITCH_CPU_AccessLevel(UNPRIVILEGED);

	MNVIC_VoidEnbleInterrupt(6);
	MNVIC_VoidEnbleInterrupt(7);




	/* Set the call back of the external 0 */
	MEXTI_voidSetCallBack(EXTI_LINE_0,func2);
	/* Set the call back of the external 1 */
	MEXTI_voidSetCallBack(EXTI_LINE_1,func1);

	/* Set the source of the external interrupt 0 */
	MEXTI_voidInterruptSetPort(EXTI_LINE_0,PORTB_PIN);
	/* Set the source of the external interrupt 1 */
	MEXTI_voidInterruptSetPort(EXTI_LINE_1,PORTB_PIN);

	MEXTI_voidInterruptTrigger(EXTI_LINE_0,EXTI_ONCHANGE);
	MEXTI_voidInterruptTrigger(EXTI_LINE_1,EXTI_ONCHANGE);

	MEXTI_voidInterruptEnableDisable(EXTI_LINE_0,EXTI_ENABLE);
	MEXTI_voidInterruptEnableDisable(EXTI_LINE_1,EXTI_ENABLE);


	Main_os();

//	SWITCH_CPU_AccessLevel(PRIVILEGED);

	/* */
	while(1)
	{


	}
	return 0;
}









void func1(void)
{
	while (1){
			MGPIO_SetPinValue(PORTA,PIN7,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN0,GPIO_PIN_LEVEL_HIGH);
			SYSTICK_voidDelayMs(1000);
			MGPIO_SetPinValue(PORTA,PIN0,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN1,GPIO_PIN_LEVEL_HIGH);
			SYSTICK_voidDelayMs(1000);
			MGPIO_SetPinValue(PORTA,PIN1,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN2,GPIO_PIN_LEVEL_HIGH);
			SYSTICK_voidDelayMs(1000);
			MGPIO_SetPinValue(PORTA,PIN2,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN3,GPIO_PIN_LEVEL_HIGH);
			SYSTICK_voidDelayMs(1000);
			MGPIO_SetPinValue(PORTA,PIN3,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN4,GPIO_PIN_LEVEL_HIGH);
			SYSTICK_voidDelayMs(1000);
			MGPIO_SetPinValue(PORTA,PIN4,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN5,GPIO_PIN_LEVEL_HIGH);
			SYSTICK_voidDelayMs(1000);
			MGPIO_SetPinValue(PORTA,PIN5,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN6,GPIO_PIN_LEVEL_HIGH);
			SYSTICK_voidDelayMs(1000);
			MGPIO_SetPinValue(PORTA,PIN6,GPIO_PIN_LEVEL_LOW);
			MGPIO_SetPinValue(PORTA,PIN7,GPIO_PIN_LEVEL_HIGH);
			SYSTICK_voidDelayMs(1000);
		}


}

/* will be called when external line 0 is triggered */
void func2(void)
{
//	MGPIO_SetPinValue(PORTA,PIN0,GPIO_PIN_LEVEL_HIGH);
//	MGPIO_SetPinValue(PORTA,PIN1,GPIO_PIN_LEVEL_HIGH);
//	MGPIO_SetPinValue(PORTA,PIN2,GPIO_PIN_LEVEL_HIGH);
//	MGPIO_SetPinValue(PORTA,PIN3,GPIO_PIN_LEVEL_HIGH);
//	MGPIO_SetPinValue(PORTA,PIN4,GPIO_PIN_LEVEL_HIGH);
//	MGPIO_SetPinValue(PORTA,PIN5,GPIO_PIN_LEVEL_HIGH);
//	MGPIO_SetPinValue(PORTA,PIN6,GPIO_PIN_LEVEL_HIGH);
//	MGPIO_SetPinValue(PORTA,PIN7,GPIO_PIN_LEVEL_HIGH);
//
//	SYSTICK_voidDelayMs(5000);

	if(IRQ_flag == 0)
	{
		TASKA_flag=1;
		IRQ_flag=1;
	}
	if(IRQ_flag == 1)
	{
		TASKB_flag=1;
		IRQ_flag=0;
	}

}
















































































































//#include "../include/STD_Types.h"
//#include "../include/BIT_MATH.h"
//
//#include "../include/MEXTI_Interface.h"
//#include "../include/MGPIO_Interface.h"
//#include "../include/MNVIC_Interface.h"
//#include "../include/MRCC_Interface.h"
//#include "../include/MSYSTICK_Interface.h"
//
//
//
//void SWITCH_CPU_AccessLevel(CPU_AccessLevel level)
//{
//	switch(level)
//	{
//	case PRIVILEGED:
//		__asm(" mrs r3,CONTROL    \n\t"
//			  " lsr r3, r3, #0x01 \n\t"
//			  " lsl r3, r3, #0x01 \n\t"
//			  " msr CONTROL, r3 ");
//
//		break;
//	case UNPRIVILEGED:
//		__asm(" mrs r3, CONTROL   \n\t"
//			  " orr r3, r3, #0x01 \n\t"
//			  " msr CONTROL, r3 ");
//		break;
//	}
//}
//
//
//
//
//void func1(void);
//
//void func2(void);
//
//
//
//int main(){
//	volatile void (*ptr)()=func1;
//	MRCC_Init();
//	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOA);
//	MRCC_Enable_Peripheral(RCC_AHB1,RCC_AHB1_GPIOB);
//	MRCC_Enable_Peripheral(RCC_APB2,RCC_APB2_SYSCFG);
//
//	SYSTICK_voidInit();
//
//	MGPIO_SetMode(PORTA,PIN0,GENRAL_PURPOSE_OUTPUT_MODE);
//	MGPIO_SetOutputPinMode(PORTA,PIN0,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
//	MGPIO_SetMode(PORTA,PIN1,GENRAL_PURPOSE_OUTPUT_MODE);
//	MGPIO_SetOutputPinMode(PORTA,PIN1,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
//	MGPIO_SetMode(PORTA,PIN2,GENRAL_PURPOSE_OUTPUT_MODE);
//	MGPIO_SetOutputPinMode(PORTA,PIN2,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
//	MGPIO_SetMode(PORTA,PIN3,GENRAL_PURPOSE_OUTPUT_MODE);
//	MGPIO_SetOutputPinMode(PORTA,PIN3,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
//	MGPIO_SetMode(PORTA,PIN4,GENRAL_PURPOSE_OUTPUT_MODE);
//	MGPIO_SetOutputPinMode(PORTA,PIN4,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
//	MGPIO_SetMode(PORTA,PIN5,GENRAL_PURPOSE_OUTPUT_MODE);
//	MGPIO_SetOutputPinMode(PORTA,PIN5,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
//	MGPIO_SetMode(PORTA,PIN6,GENRAL_PURPOSE_OUTPUT_MODE);
//	MGPIO_SetOutputPinMode(PORTA,PIN6,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
//	MGPIO_SetMode(PORTA,PIN7,GENRAL_PURPOSE_OUTPUT_MODE);
//	MGPIO_SetOutputPinMode(PORTA,PIN7,OUTPUT_PUSH_PULL,OUTPUT_LOW_SPEED_TYPE);
//
//	MGPIO_SetPinValue(PORTA,PIN0,GPIO_PIN_LEVEL_LOW);
//	MGPIO_SetPinValue(PORTA,PIN1,GPIO_PIN_LEVEL_LOW);
//	MGPIO_SetPinValue(PORTA,PIN2,GPIO_PIN_LEVEL_LOW);
//	MGPIO_SetPinValue(PORTA,PIN3,GPIO_PIN_LEVEL_LOW);
//	MGPIO_SetPinValue(PORTA,PIN4,GPIO_PIN_LEVEL_LOW);
//	MGPIO_SetPinValue(PORTA,PIN5,GPIO_PIN_LEVEL_LOW);
//	MGPIO_SetPinValue(PORTA,PIN6,GPIO_PIN_LEVEL_LOW);
//	MGPIO_SetPinValue(PORTA,PIN7,GPIO_PIN_LEVEL_LOW);
//
//
//	MGPIO_SetMode(PORTB,PIN0,INPUT_RESET_STATE);
//	MGPIO_SetInputPinMode(PORTB,PIN0,PULL_UP);
//
//	MGPIO_SetMode(PORTB,PIN1,INPUT_RESET_STATE);
//	MGPIO_SetInputPinMode(PORTB,PIN1,PULL_UP);
//
//	/* Set Groups and Sub Groups */
//	MNVIC_VoidSetInterruptGroupMode(GROUP_2_SUB_8);
//	MNVIC_VoidSetInterruptPriority(6,1,0);
//	MNVIC_VoidSetInterruptPriority(7,0,0);
//
////	SWITCH_CPU_AccessLevel(UNPRIVILEGED);
//
//	MNVIC_VoidEnbleInterrupt(6);
//	MNVIC_VoidEnbleInterrupt(7);
//
//
//
//
//	/* Set the call back of the external 0 */
//	MEXTI_voidSetCallBack(EXTI_LINE_0,func2);
//	/* Set the call back of the external 1 */
//	MEXTI_voidSetCallBack(EXTI_LINE_1,func1);
//
//	/* Set the source of the external interrupt 0 */
//	MEXTI_voidInterruptSetPort(EXTI_LINE_0,PORTB_PIN);
//	/* Set the source of the external interrupt 1 */
//	MEXTI_voidInterruptSetPort(EXTI_LINE_1,PORTB_PIN);
//
//	MEXTI_voidInterruptTrigger(EXTI_LINE_0,EXTI_ONCHANGE);
//	MEXTI_voidInterruptTrigger(EXTI_LINE_1,EXTI_ONCHANGE);
//
//	MEXTI_voidInterruptEnableDisable(EXTI_LINE_0,EXTI_ENABLE);
//	MEXTI_voidInterruptEnableDisable(EXTI_LINE_1,EXTI_ENABLE);
//
//
//
////	SWITCH_CPU_AccessLevel(PRIVILEGED);
//
//	/* */
//	while(1)
//	{
//
//
//	}
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//void func1(void)
//{
//	while (1){
//			MGPIO_SetPinValue(PORTA,PIN7,GPIO_PIN_LEVEL_LOW);
//			MGPIO_SetPinValue(PORTA,PIN0,GPIO_PIN_LEVEL_HIGH);
//			SYSTICK_voidDelayMs(1000);
//			MGPIO_SetPinValue(PORTA,PIN0,GPIO_PIN_LEVEL_LOW);
//			MGPIO_SetPinValue(PORTA,PIN1,GPIO_PIN_LEVEL_HIGH);
//			SYSTICK_voidDelayMs(1000);
//			MGPIO_SetPinValue(PORTA,PIN1,GPIO_PIN_LEVEL_LOW);
//			MGPIO_SetPinValue(PORTA,PIN2,GPIO_PIN_LEVEL_HIGH);
//			SYSTICK_voidDelayMs(1000);
//			MGPIO_SetPinValue(PORTA,PIN2,GPIO_PIN_LEVEL_LOW);
//			MGPIO_SetPinValue(PORTA,PIN3,GPIO_PIN_LEVEL_HIGH);
//			SYSTICK_voidDelayMs(1000);
//			MGPIO_SetPinValue(PORTA,PIN3,GPIO_PIN_LEVEL_LOW);
//			MGPIO_SetPinValue(PORTA,PIN4,GPIO_PIN_LEVEL_HIGH);
//			SYSTICK_voidDelayMs(1000);
//			MGPIO_SetPinValue(PORTA,PIN4,GPIO_PIN_LEVEL_LOW);
//			MGPIO_SetPinValue(PORTA,PIN5,GPIO_PIN_LEVEL_HIGH);
//			SYSTICK_voidDelayMs(1000);
//			MGPIO_SetPinValue(PORTA,PIN5,GPIO_PIN_LEVEL_LOW);
//			MGPIO_SetPinValue(PORTA,PIN6,GPIO_PIN_LEVEL_HIGH);
//			SYSTICK_voidDelayMs(1000);
//			MGPIO_SetPinValue(PORTA,PIN6,GPIO_PIN_LEVEL_LOW);
//			MGPIO_SetPinValue(PORTA,PIN7,GPIO_PIN_LEVEL_HIGH);
//			SYSTICK_voidDelayMs(1000);
//		}
//
//
//}
//
//void func2(void)
//{
//	MGPIO_SetPinValue(PORTA,PIN0,GPIO_PIN_LEVEL_HIGH);
//	MGPIO_SetPinValue(PORTA,PIN1,GPIO_PIN_LEVEL_HIGH);
//	MGPIO_SetPinValue(PORTA,PIN2,GPIO_PIN_LEVEL_HIGH);
//	MGPIO_SetPinValue(PORTA,PIN3,GPIO_PIN_LEVEL_HIGH);
//	MGPIO_SetPinValue(PORTA,PIN4,GPIO_PIN_LEVEL_HIGH);
//	MGPIO_SetPinValue(PORTA,PIN5,GPIO_PIN_LEVEL_HIGH);
//	MGPIO_SetPinValue(PORTA,PIN6,GPIO_PIN_LEVEL_HIGH);
//	MGPIO_SetPinValue(PORTA,PIN7,GPIO_PIN_LEVEL_HIGH);
//
//	SYSTICK_voidDelayMs(5000);
//}
