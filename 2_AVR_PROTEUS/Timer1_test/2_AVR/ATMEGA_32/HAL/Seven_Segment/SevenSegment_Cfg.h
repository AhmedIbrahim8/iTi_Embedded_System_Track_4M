/*
 * SevenSegment_Cfg.h
 *
 *  Created on: Aug 6, 2023
 *      Author: Ahmed
 */

#ifndef SEVENSEGMENT_CFG_H_
#define SEVENSEGMENT_CFG_H_

#define NUMBER_OF_LCDS          (uint8)2

/* Seven Segment 1 Configuration Connection pins */
#define SEV1_INDEX_NUMBER       (uint8)0
#define SEV1_LED_A_PIN          (SEV_ChannelType)16
#define SEV1_LED_B_PIN          (SEV_ChannelType)17
#define SEV1_LED_C_PIN          (SEV_ChannelType)18
#define SEV1_LED_D_PIN          (SEV_ChannelType)19
#define SEV1_LED_E_PIN          (SEV_ChannelType)20
#define SEV1_LED_F_PIN          (SEV_ChannelType)21
#define SEV1_LED_G_PIN          (SEV_ChannelType)22
#define SEV1_ENABLE_PIN         (SEV_ChannelType)23

#define SEV1_CONNECTION_TYPE    (SEV_ConnectionType)COMMON_ANODE

/* Seven Segment 1 Configuration Connection pins */
#define SEV2_INDEX_NUMBER       (uint8)1
#define SEV2_LED_A_PIN       (SEV_ChannelType)31
#define SEV2_LED_B_PIN       (SEV_ChannelType)30
#define SEV2_LED_C_PIN       (SEV_ChannelType)29
#define SEV2_LED_D_PIN       (SEV_ChannelType)28
#define SEV2_LED_E_PIN       (SEV_ChannelType)27
#define SEV2_LED_F_PIN       (SEV_ChannelType)26
#define SEV2_LED_G_PIN       (SEV_ChannelType)25
#define SEV2_ENABLE_PIN      (SEV_ChannelType)24

#define SEV2_CONNECTION_TYPE    (SEV_ConnectionType)COMMON_ANODE


#endif /* SEVENSEGMENT_CFG_H_ */
