/******************************************************************************************/
/*  Module       :   DIO                                                                  */
/*  File Name    :   Dio_Program.c                                                        */
/*  Description  :   File contains the Definitions of the functions used and data types   */
/*  Author       :   Ahmed Ibrahim                                                        */
/*  Date         :   04/08/2023                                                           */
/******************************************************************************************/

#include "Std_Types.h"
/* This file is private to the DIO only so, No module can't include it*/
#include "Dio_Registers.h"
/* Every module.c must include its header file*/
#include "common_macros.h"
#include "DIO_Interface.h"

/************************************************************************************
* Function Name : DIO_enuWritePin
* Description   : Function to write a logic high or low to a specific bit
************************************************************************************/
tenuErrorStatus DIO_enuWritePin(Dio_ChannelType ChannelIdCpy,Dio_PinLevelValue PinValueCpy){
	tenuErrorStatus enuState = EOK;
	if( ChannelIdCpy>=DIO_PIN_NUM_A0  && ChannelIdCpy<=DIO_PIN_NUM_A7)
	{
		switch(PinValueCpy){
		case LEVEL_LOW:
			CLEAR_BIT(PORTA,ChannelIdCpy);
			break;
		case LEVEL_HIGH:
			SET_BIT(PORTA,ChannelIdCpy);
			break;
		default:
			enuState=PARAMETER_OUT_RANGE;

		}
	}
	else if(ChannelIdCpy>=DIO_PIN_NUM_B0  && ChannelIdCpy<=DIO_PIN_NUM_B7)
	{
		switch(PinValueCpy){
		case LEVEL_LOW:
			CLEAR_BIT(PORTB,ChannelIdCpy%8);
			break;
		case LEVEL_HIGH:
			SET_BIT(PORTB,ChannelIdCpy%8);
			break;
		default:
			enuState=PARAMETER_OUT_RANGE;

		}
	}
	else if(ChannelIdCpy>=DIO_PIN_NUM_C0  && ChannelIdCpy<=DIO_PIN_NUM_B7)
	{
		switch(PinValueCpy){
		case LEVEL_LOW:
			CLEAR_BIT(PORTC,ChannelIdCpy%8);
			break;
		case LEVEL_HIGH:
			SET_BIT(PORTC,ChannelIdCpy%8);
			break;
		default:
			enuState=PARAMETER_OUT_RANGE;

		}
	}
	else if(ChannelIdCpy>=DIO_PIN_NUM_D0  && ChannelIdCpy<=DIO_PIN_NUM_B7)
	{
		switch(PinValueCpy){
		case LEVEL_LOW:
			CLEAR_BIT(PORTD,ChannelIdCpy%8);
			break;
		case LEVEL_HIGH:
			SET_BIT(PORTD,ChannelIdCpy%8);
			break;
		default:
			enuState=PARAMETER_OUT_RANGE;

		}
	}
	else{
		enuState=PARAMETER_OUT_RANGE;
	}
	return enuState;
}

/************************************************************************************
* Function Name : DIO_enuReadPin
* Description   : Function to read a logic high or low to a specific bit
************************************************************************************/
tenuErrorStatus DIO_enuReadPin(Dio_ChannelType ChannelIdCpy,Dio_PinLevelValue* PinValueCpy){
	tenuErrorStatus enuState = EOK;
	if( ChannelIdCpy>=DIO_PIN_NUM_A0  && ChannelIdCpy<=DIO_PIN_NUM_A7)
	{
		*PinValueCpy=GET_BIT(PINA,ChannelIdCpy);

	}
	else if(ChannelIdCpy>=DIO_PIN_NUM_B0  && ChannelIdCpy<=DIO_PIN_NUM_B7)
	{
		*PinValueCpy=GET_BIT(PINB,ChannelIdCpy%8);
	}
	else if(ChannelIdCpy>=DIO_PIN_NUM_C0  && ChannelIdCpy<=DIO_PIN_NUM_B7)
	{
		*PinValueCpy=GET_BIT(PINC,ChannelIdCpy%8);
	}
	else if(ChannelIdCpy>=DIO_PIN_NUM_D0  && ChannelIdCpy<=DIO_PIN_NUM_B7)
	{
		*PinValueCpy=GET_BIT(PIND,ChannelIdCpy%8);
	}
	else
	{
		enuState=PARAMETER_OUT_RANGE;
	}
	return enuState;

}

/************************************************************************************
* Function Name : DIO_enuStatePullup
* Description   : Function to state the internal resistor inside the pin
************************************************************************************/

tenuErrorStatus DIO_enuStatePullup(Dio_ChannelType ChannelIdCpy,Dio_InternalResistor PinInternalCpy){
	return DIO_enuWritePin(ChannelIdCpy,(Dio_PinLevelValue)PinInternalCpy);
}

/************************************************************************************
* Function Name : DIO_enuWriteGroup
* Description   : Function to write on group of pins
************************************************************************************/

tenuErrorStatus DIO_enuWriteGroup(Dio_ChannelType* pau8PinNumCpy ,Dio_PinLevelValue* pau8PinValueCpy,uint8 u8Sizecpy){
	tenuErrorStatus enuState =EOK;

	uint8 u8CounterLoc=0;

	for ( u8CounterLoc=0 ;   u8CounterLoc< u8Sizecpy ;u8CounterLoc++)
	{
		enuState=DIO_enuWritePin(pau8PinNumCpy[u8CounterLoc],pau8PinValueCpy[u8CounterLoc]);

		if (enuState !=EOK)
		{
			break;
		}
	}

	return enuState;
}


/************************************************************************************
* Function Name : DIO_enuWritePort
* Description   : Function to write to specific port
************************************************************************************/
tenuErrorStatus DIO_enuWritePort(Dio_PortType PortIdCpy,Dio_PortLevelValue PortValueCpy){
	tenuErrorStatus enuState=EOK;
	switch(PortIdCpy){
	case DIO_PORTA_INDEX:
		PORTA=PortValueCpy;
		break;
	case DIO_PORTB_INDEX:
		PORTB=PortValueCpy;
		break;
	case DIO_PORTC_INDEX:
		PORTC=PortValueCpy;
		break;
	case DIO_PORTD_INDEX:
		PORTD=PortValueCpy;
		break;
	default:
		enuState=ENOK;
	}
	return enuState;

}

/************************************************************************************
* Function Name : DIO_enuReadPort
* Description   : Function to read from specific port
************************************************************************************/
tenuErrorStatus DIO_enuReadPort(Dio_PortType PortIdCpy,Dio_PortLevelValue* PortValueCpy){
	tenuErrorStatus enuState=EOK;
	switch(PortIdCpy){
	case DIO_PORTA_INDEX:
		*PortValueCpy=PINA;
		break;
	case DIO_PORTB_INDEX:
		*PortValueCpy=PINB;
		break;
	case DIO_PORTC_INDEX:
		*PortValueCpy=PINB;
		break;
	case DIO_PORTD_INDEX:
		*PortValueCpy=PINB;
		break;
	default:
		enuState=ENOK;
	}
	return enuState;
}
