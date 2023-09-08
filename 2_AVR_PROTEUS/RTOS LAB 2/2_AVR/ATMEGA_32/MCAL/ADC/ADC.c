/*******************************************************************************************/
/*  Module       :   ADC                                                                   */
/*  File Name    :   ADC.c                                                                 */
/*  Description  :   Source File of the ADC Driver                                         */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   15/08/2023                                                            */
/*******************************************************************************************/
#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\common_macros.h"
#include "ADC_Register.h"
#include "ADC.h"

static void (*ADC_Call_Back)(void)=NULL_PTR;
static volatile uint16 u16DigitalVlaue=0;
static volatile uint8 busy_flag=0;
void ADC_voidInit(){
	/* Reference voltage not changed at run time so, we use #if */
#if ADC_REFERENCE_VOLTAGE==ADC_REFERENCE_TYPE_AREF
	/* 0x3F =  0b 0011 1111 */
	/* Masking to the ADMUX */
	/* Shift left the value by REFS0 (Bit 6)*/
	ADMUX=( ADMUX & 0x3F ) | (ADC_REFERENCE_VOLTAGE<< REFS0);
#elif ADC_REFERENCE_VOLTAGE==ADC_REFERENCE_TYPE_AVCC
	ADMUX=( ADMUX & 0x3F ) | (ADC_REFERENCE_VOLTAGE<< REFS0);
#elif ADC_REFERENCE_VOLTAGE==ADC_REFERENCE_TYPE_INTERNAL
	ADMUX=( ADMUX & 0x3F ) | (ADC_REFERENCE_VOLTAGE<< REFS0);
#endif

/*  Adjust the left or the right adjustment */
/* We use #if because it will not change at the run time */
/* If left adjustment , we will read from ADCH Register  */
/* If right adjustment, we will read from ADCL then ADCH */
#if ADC_LEFT_ADJUST_RESULT==ADC_ADJUST_TYPE_RIGHT
	CLEAR_BIT(ADMUX,ADLAR);
#elif ADC_LEFT_ADJUST_RESULT==ADC_ADJUST_TYPE_LEFT
	SET_BIT(ADMUX,ADLAR);
#endif

/*  ADC Auto Trigger Disable -> single conversion mode is chosen */
#if ADC_AUTO_TRIGGER==AUTO_TRIGGER_DISABLE
	CLEAR_BIT(ADCSRA,ADATE);
/*  ADC Auto Trigger Enable  -> auto trigger is on and the source of
 * trigger is chosen from SFIOR Register */
#elif ADC_AUTO_TRIGGER==AUTO_TRIGGER_ENABLE
	SET_BIT(ADCSRA,ADATE);
#endif

	/* ADC_PRESCALER_SELECT */
/* 0XF8 = 0b 1111 1000 */
ADCSRA=(ADCSRA & 0xF8) | ADC_PRESCALER_SELECT;

}

/* To enable the ADC Clock */
void ADC_voidEnable(){
	/*Writing ADEN to one enables the ADC */
	SET_BIT(ADCSRA,ADEN);
}

/* To disable the ADC Clock */
void ADC_voidDisable(){
	/*  By writing ADEN to zero, the ADC is turned off. Turning the ADC off while a
	 * conversion is in progress, will terminate this conversion */
	CLEAR_BIT(ADCSRA,ADEN);
}

/* To enable the ADC Interrupt */
void ADC_voidEnableInterrupt(void){
	/* When ADIE is written to one and the I-bit in SREG is set,  */
	/* the ADC Conversion Complete Interrupt is activated.            */
	SET_BIT(ADCSRA,ADIE);
}

/* To disable the ADC Interrupt */
/* In this case, we will use the polling method to get the ADC Digital Value */
void ADC_voidDisableInterrupt(void){
	/* Disable the interrupt */
	CLEAR_BIT(ADCSRA,ADIE);
}


/* Function Responsible of setting the call back of the ADC Driver
 * Advantages : To make the ADC Driver not dependent on the Application*/
void ADC_voidSetCallback(void (*local_Call_Back) (void)){
	ADC_Call_Back=local_Call_Back;
}

/* In single conversion mode, we need to tell the ADC Driver each time to start conversion */
/* In Free Running Mode, write this bit to one to start the first conversion */
void ADC_voidStartConversion(uint8 u8ChannelNbCpy){
	/* The previous conversion must be finished before the new one */
	if(busy_flag==0){
		busy_flag=1;
		/* To choose the channel index */
		ADMUX = (ADMUX & 0xE0) | (u8ChannelNbCpy & 0x1F);
		/* To start the conversion of the ADC */
		SET_BIT(ADCSRA,ADSC);
	}
}


void ADC_voidChangeMode(ADC_AutoTriggerType ModeCpy){
	/* Enable Auto trigger */
	SET_BIT(ADCSRA,ADATE);
	if(ModeCpy <= TIMER1_CAPTURE_EVENT){
		SFIOR=(SFIOR & 0x0F) | (ModeCpy<<ADTS0);
	}
	else{
		/*Do no thing */
	}
}

/* Read the value from ADC polling method*/
uint16 ADC_u16ReadSync(uint8 u8ChannelNbCpy){
	uint16 u16LocDigitalVlaue=0;
	/* Start Conversion from the channel if that is passed to the function*/
	ADC_voidStartConversion(u8ChannelNbCpy);
	/* Loop until ADC Flag equal 0 */
	while(!GET_BIT(ADCSRA,ADIF));
	/* Here, we need to clear the flag for the next read */
	SET_BIT(ADCSRA , ADIF);
	/* In case of right adjustment, we will read from ADCL Then ADCH*/
#if ADC_LEFT_ADJUST_RESULT == ADC_ADJUST_TYPE_RIGHT
	u16LocDigitalVlaue= ADCL | (ADCH << 8);
#elif ADC_LEFT_ADJUST_RESULT == ADC_ADJUST_TYPE_LEFT
	u16LocDigitalVlaue= ADCH;
#endif

	return u16LocDigitalVlaue;

}
/* Read the value from ADC Interrupt method*/
uint16 ADC_u16ReadAsync(void){
	return u16DigitalVlaue;
}

void __vector16_ (void)       __attribute__((signal));
void __vector16_ (void){

#if ADC_LEFT_ADJUST_RESULT == ADC_ADJUST_TYPE_RIGHT
	u16DigitalVlaue= ADCL | (ADCH << 8);
#elif ADC_LEFT_ADJUST_RESULT == ADC_ADJUST_TYPE_LEFT
	u16DigitalVlaue= ADCH;
#endif
	/* If pointer is not equal Null , we will call the call back function */
	if(ADC_Call_Back != NULL_PTR){
		ADC_Call_Back();
	}
	/* If pointer equal Null , we will not call and will do nothing */
	else{
		/*DO NO THING */
	}
	busy_flag=0;

}
