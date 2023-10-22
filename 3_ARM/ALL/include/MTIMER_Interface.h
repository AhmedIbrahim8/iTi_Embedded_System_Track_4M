/*
 * MTIMER_Interface.h
 *
 *  Created on: Oct 16, 2023
 *      Author: Ahmed
 */

#ifndef MTIMER_INTERFACE_H_
#define MTIMER_INTERFACE_H_







/********************************************************************************************/
/************************************* GPT INDEX ********************************************/
/********************************************************************************************/
typedef enum{
	TIMER2_SELECTION,TIMER5_SELECTION,TIMER3_SELECTION,TIMER4_SELECTION
}TIMER_IDType;


typedef enum{
	TIMER_CHANNEL_1=1,
	TIMER_CHANNEL_2,
	TIMER_CHANNEL_3,
	TIMER_CHANNEL_4
}TIMER_ChannelType;


typedef enum{
	TIMER_FROZEN ,
	TIMER_SET_CHANNEL_ACTIVE_ON_MATCH,
	TIMER_SET_CHANNEL_INACTIVE_ON_MATCH,
	TIMER_SET_CHANNEL_TOGGLE_ON_MATCH,
	TIMER_FORCE_INACTIVE_OCxREF_LOW,
	TIMER_FORCE_ACTIVE_OCxREF_HIGH,
	TIMER_PWM_MODE_1,
	TIMER_PWM_MODE_2
}TIMER_OutputCompareModeType;



typedef enum{
	COUNT_UP,COUNT_DOWN
}TIMER_CountModeType;

typedef  u32 TIMER_AutoReloadType;

typedef  u16 TIMER_PrescalerType;

typedef enum{
	TIMER_INPUT_CAPTURE,TIMER_OUTPUT_COMPARE,TIMER_PWM,TIMER_ONE_PULSE_MODE
}TIMER_ModeType;


typedef enum{
	TIMER_ARR_NOT_BUFFERED,
	TIMER_ARR_BUFFERED
}TIMER_AutoReloadPreloadType;


typedef enum{
	TIMER_EGDE_ALIGNED_MODE,
	TIMER_CENTER_ALIGNED_MODE_1,
	TIMER_CENTER_ALIGNED_MODE_2,
	TIMER_CENTER_ALIGNED_MODE_3
}TIMER_CenterAlignedMode;


typedef enum{
	ACTIVE_HIGH,
	ACTIVE_LOW
}TIMER_ChannelOutputActiveType;

typedef enum{
	TIMER_NO_STOP,
	TIMER_ONE_PULSE

}TIMER_OnePulseType;

typedef u32 TIMER_OutputCompareValue;


typedef enum{
	TIMER_ANY_EVENT_GENERATE_UPDATE_INTERRUPT_OR_DMA_REQUEST,
	TIMER_ONLY_COUNTER_OVF_UNF_GENERATE
}TIMER_UpdateRequestSourceType;








typedef struct{
	TIMER_IDType timer_id;
	TIMER_AutoReloadPreloadType PreloadType;
	TIMER_CenterAlignedMode AlignedType;
	TIMER_CountModeType CountMode;
	TIMER_OnePulseType OnePulseMode;
	TIMER_UpdateRequestSourceType UpdateRequestSource;
	TIMER_OutputCompareModeType Mode;
	TIMER_ChannelType ChannelID;
	TIMER_ChannelOutputActiveType ActiveType;
}TIMER_configType;




#define       CHANNEL1_MASK           0xFFFFFF00
#define       CHANNEL2_MASK           0xFFFF00FF
#define       CHANNEL3_MASK           0xFFFFFF00
#define       CHANNEL4_MASK           0xFFFF00FF


void TIMER_Init(TIMER_configType *Configuration);

void TIMER_Stop(TIMER_IDType Timer_Number);


void TIMER_Start(TIMER_IDType Timer_Number);

void TIMER_SetPrescaler(TIMER_IDType Timer_Number , TIMER_PrescalerType prescaler);

void TIMER_SetCompareValue(TIMER_IDType Timer_Number, TIMER_ChannelType ChannelID , TIMER_OutputCompareValue ComapreValue);


void TIMER_SetARR(TIMER_IDType Timer_Number , TIMER_AutoReloadType AutoReloadValue);

void TIMER_ClearTimerCount(TIMER_IDType Timer_Number);


void TIMER_SetDutyCycle(TIMER_IDType Timer_Number, TIMER_ChannelType ChannelID ,u8 DutyCycle);





/********************************************************************************************/
/************************************* Extern Configuration *********************************/
/********************************************************************************************/
extern TIMER_configType Timer_configuration;

#endif /* MTIMER_INTERFACE_H_ */
