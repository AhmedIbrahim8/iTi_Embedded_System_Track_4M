/*
 * Seven_Segment.h
 *
 *  Created on: Aug 6, 2023
 *      Author: Ahmed
 */

#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#include "SevenSegment_Types.h"
#include "SevenSegment_Cfg.h"

/***************************************************************/
/*                    Functions Prototypes                     */
/***************************************************************/
void SEV_Write(uint8 SEV_Index,uint8 number);
void SEV_Enable(uint8 SEV_Index);
void SEV_Disable(uint8 SEV_Index);

/***************************************************************/
/*          Extern of the shared Global Variables              */
/***************************************************************/
extern const SEV_ConfigType SEV_Configuration[NUMBER_OF_SEV_SEGMENT];

#endif /* SEVENSEGMENT_H_ */
