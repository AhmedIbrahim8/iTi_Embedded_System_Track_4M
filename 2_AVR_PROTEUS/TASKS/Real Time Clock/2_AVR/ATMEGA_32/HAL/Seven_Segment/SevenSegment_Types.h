/*
 * SevenSegment_Types.h
 *
 *  Created on: Aug 5, 2023
 *      Author: Ahmed
 */

#ifndef SEVENSEGMENT_TYPES_H_
#define SEVENSEGMENT_TYPES_H_
#include "..\..\LIB\Std_Types.h"
/* Numeric ID To the LCD Channel */
typedef uint8 SEV_ChannelType;

/* Numeric ID To the LCD Channel */
typedef uint8 SEV_PortType;

/* Enumeration to store the connection type of the Seven Segment */
typedef enum{
	COMMON_ANODE,COMMON_CATHODE
}SEV_ConnectionType;

/* Structure To save the Information of the Seven Segment */

typedef struct{
	/* Array of 7 elements as indication if the connections of the 7 pins  */
	SEV_ChannelType ConnectionPins[7];
	/* type: to store the connection type of the seven segment  */
	/*       COMMON ANODE         or      COMMON CATHODE        */
	SEV_ConnectionType type;
	/* The enable pin of the seven segment */
	SEV_ChannelType enablePinIndex;
}SEV_ConfigType;

#endif /* SEVENSEGMENT_TYPES_H_ */
