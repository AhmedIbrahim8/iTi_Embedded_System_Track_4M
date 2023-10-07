/*******************************************************************************************/
/*  Module       :   Systick Timer                                                         */
/*  File Name    :   MSYSTICK_Interface.c                                                  */
/*  Description  :   Header File of the Interface of the Systick Timer Driver              */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   12/09/2023                                                            */
/*******************************************************************************************/

#ifndef MNVIC_INTERFACE_H_
#define MNVIC_INTERFACE_H_
#include "STD_Types.h"

/********************************************************************************************/
/************************************** Masks and Numbers Used  *****************************/
/********************************************************************************************/
#define  SYSTICK_CLOCK_SOURCE_MASK                0xFFFFFFFB
#define  SYSTICK_TICK_INT_MASK                    0xFFFFFFFD
#define  SYSTICK_ENABLE_MASK                      0xFFFFFFFE
#define  SYSTICK_LOAD_REGISTER_MASK               0x00FFFFFF
/********************************************************************************************/
/************************************** #s used in the Module *******************************/
/********************************************************************************************/
#define  SYSTICK_PROCESSOR_CLOCK_AHB_8            0
#define  SYSTICK_PROCESSOR_CLOCK_AHB              1

#define  SYSTICK_DISABLE_EXCEPTION_REQUEST        0
#define  SYSTICK_ENABLE_EXCEPTION_REQUEST         1

#define  SYSTICK_DISABLE_COUNTER                  0
#define  SYSTICK_ENABLE_COUNTER                   1


/********************************************************************************************/
/************************************** Types Declaration ***********************************/
/********************************************************************************************/







/********************************************************************************************/
/************************************** APIs Proto-Types ************************************/
/********************************************************************************************/



void SYSTICK_voidInit(void);

void SYSTICK_voidStart(u32 Copy_u32LoadValue);

void SYSTICK_voidDelayUs(u32 Copy_u32DelayValue);

void SYSTICK_voidDelayMs(u32 Copy_u32DelayValue);

u8 SYSTICK_u8ReadFlag(void);

void SYSTICK_voidCtrlIntState(u8 Copy_u8State);

u32 SYSTICK_u32GetElapsedTime(void);

u32 SYSTICK_u32GetRemainingTime(void);
void SYSTICK_voidSetCallBack(void (*ptr) (void));

void SYSTICK_SetInterval(u32 Copy_u32LoadValue);
//
//void SYSTICK_VoidAdjustClockSource(u8 Copy_u8ClockSourceType);
//
//void SYSTICK_VoidEnableExceptionRequest();
//
//void SYSTICK_VoidDisableExceptionRequest();
//
//void SYSTICK_EnableCounter();
//
//void SYSTICK_DisableCounter();
//
//void SYSTICK_VoidAdjustReloadValue(u32 Copy_u32ReloadValue);


#endif /* MNVIC_INTERFACE_H_ */
