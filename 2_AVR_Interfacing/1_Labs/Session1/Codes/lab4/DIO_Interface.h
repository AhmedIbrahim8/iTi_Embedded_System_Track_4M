/******************************************************************************************/
/*  Module       :   DIO                                                                  */
/*  File Name    :   Dio_Interface.h                                                      */
/*  Description  :   File contains the prototypes of the functions used and data types    */
/*  Author       :   Ahmed Ibrahim                                                        */
/*  Date         :   04/08/2023                                                           */
/******************************************************************************************/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "Std_Types.h"
#include "DIO_Cfg.h"

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Numeric ID if the DIO Channel */
typedef uint8 Dio_ChannelType;

/* Numeric ID of the DIO PORT */
typedef uint8 Dio_PortType;

/* Enumeration to indicate the level of the pin */
typedef enum{
	LEVEL_LOW,LEVEL_HIGH
}Dio_PinLevelValue;

/* Enumeration to indicate the pull up in case of input pins */
typedef enum{
	OFF,PULL_UP
}Dio_InternalResistor;

/* ATMega 16 register is 8-bits width so we need uint8 */
/* Dio_PortLevelType is the value inside the port      */
typedef uint8  Dio_PortLevelValue;

#define DIO_PIN_OUT    1
#define DIO_PIN_IN     0



/* AVR ATMEGA32 number of pins */


/*******************************************************************************
 *                            #s of the pins index                             *
 *******************************************************************************/
             /* PORT A PINS */
#define DIO_PIN_NUM_A0        (Dio_ChannelType)0
#define DIO_PIN_NUM_A1        (Dio_ChannelType)1
#define DIO_PIN_NUM_A2        (Dio_ChannelType)2
#define DIO_PIN_NUM_A3        (Dio_ChannelType)3
#define DIO_PIN_NUM_A4        (Dio_ChannelType)4
#define DIO_PIN_NUM_A5        (Dio_ChannelType)5
#define DIO_PIN_NUM_A6        (Dio_ChannelType)6
#define DIO_PIN_NUM_A7        (Dio_ChannelType)7
             /* PORT B PINS */
#define DIO_PIN_NUM_B0        (Dio_ChannelType)8
#define DIO_PIN_NUM_B1        (Dio_ChannelType)9
#define DIO_PIN_NUM_B2        (Dio_ChannelType)10
#define DIO_PIN_NUM_B3        (Dio_ChannelType)11
#define DIO_PIN_NUM_B4        (Dio_ChannelType)12
#define DIO_PIN_NUM_B5        (Dio_ChannelType)13
#define DIO_PIN_NUM_B6        (Dio_ChannelType)14
#define DIO_PIN_NUM_B7        (Dio_ChannelType)15
             /* PORT C PINS */
#define DIO_PIN_NUM_C0        (Dio_ChannelType)16
#define DIO_PIN_NUM_C1        (Dio_ChannelType)17
#define DIO_PIN_NUM_C2        (Dio_ChannelType)18
#define DIO_PIN_NUM_C3        (Dio_ChannelType)19
#define DIO_PIN_NUM_C4        (Dio_ChannelType)20
#define DIO_PIN_NUM_C5        (Dio_ChannelType)21
#define DIO_PIN_NUM_C6        (Dio_ChannelType)22
#define DIO_PIN_NUM_C7        (Dio_ChannelType)23
             /* PORT D PINS */
#define DIO_PIN_NUM_D0        (Dio_ChannelType)24
#define DIO_PIN_NUM_D1        (Dio_ChannelType)25
#define DIO_PIN_NUM_D2        (Dio_ChannelType)26
#define DIO_PIN_NUM_D3        (Dio_ChannelType)27
#define DIO_PIN_NUM_D4        (Dio_ChannelType)28
#define DIO_PIN_NUM_D5        (Dio_ChannelType)29
#define DIO_PIN_NUM_D6        (Dio_ChannelType)30
#define DIO_PIN_NUM_D7        (Dio_ChannelType)31

/*******************************************************************************
 *                            #s of the PORT index                             *
 *******************************************************************************/
#define DIO_PORTA_INDEX        (Dio_PortType)0
#define DIO_PORTB_INDEX        (Dio_PortType)1
#define DIO_PORTC_INDEX        (Dio_PortType)2
#define DIO_PORTD_INDEX        (Dio_PortType)3



/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/
tenuErrorStatus DIO_enuWritePin(Dio_ChannelType ChannelIdCpy,Dio_PinLevelValue PinValueCpy);

tenuErrorStatus DIO_enuReadPin(Dio_ChannelType ChannelIdCpy,Dio_PinLevelValue* PinValueCpy);

tenuErrorStatus DIO_enuStatePullup(Dio_ChannelType ChannelIdCpy,Dio_InternalResistor PinInternalCpy);

tenuErrorStatus DIO_enuWriteGroup(Dio_ChannelType* pau8PinNumCpy ,Dio_PinLevelValue* pau8PinValueCpy,uint8 u8Sizecpy);

tenuErrorStatus DIO_enuWritePort(Dio_PortType PortIdCpy,Dio_PortLevelValue PortValueCpy);

tenuErrorStatus DIO_enuReadPort(Dio_PortType PortIdCpy,Dio_PortLevelValue* PortValueCpy);


void DIO_Init(void);

#endif /* DIO_INTERFACE_H_ */
