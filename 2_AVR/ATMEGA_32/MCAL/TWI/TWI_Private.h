/*******************************************************************************************/
/*  Module       :   TWI                                                                   */
/*  File Name    :   TWI_Private.h                                                       */
/*  Description  :   Header File of the TWI Driver Private                                      */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   27/08/2023                                                            */
/*******************************************************************************************/


#ifndef MCAL_TWI_TWI_PRIVATE_H_
#define MCAL_TWI_TWI_PRIVATE_H_

#define  TWI_ACKNOWLEDGMENT_ENABLE         1
#define  TWI_ACKNOWLEDGMENT_DISABLE        0

#define  TWI_MODULE_ENABLE                 1
#define  TWI_MODULE_DISABLE                0

#define  TWI_INTERRUPT_ENABLE              1
#define  TWI_INTERRUPT_DISABLE             0

#define  TWI_PRESCALER_1                   0
#define  TWI_PRESCALER_4                   1
#define  TWI_PRESCALER_16                  2
#define  TWI_PRESCALER_64                  3

#define  TWI_GENERAL_CALL_ENABLE           1
#define  TWI_GENERAL_CALL_DISABLE          0


#define  TWI_TWSR_MASK                         0xF8
#define  TWI_TWPS_4_0                           1
#define  TWI_TWPS_4_1                           4
#define  TWI_TWPS_4_2                           16
#define  TWI_TWPS_4_3                           64



       /* Status Code when Master Sends */
#define  TWI_START                         0x08

#define  TWI_REPEATED_START                0x10

#define  TWI_MT_SLA_W_ACK                  0x18

#define  TWI_MT_SLA_W_NACK                 0x20

#define  TWI_MT_DATA_W_ACK                 0x28

#define  TWI_MT_DATA_W_NACK                0x30

#define  TWI_MT_ARBITRATION_LOST_DATA      0x38

       /* Status Code when Master receive */

#define  TWI_MR_SLA_W_ACK                  0x40

#define  TWI_MR_SLA_W_NACK                 0x48

#define  TWI_MR_DATA_W_ACK                 0x50

#define  TWI_MR_DATA_W_NACK                0x58

#define  TWI_MR_ARBITRATION_LOST_SLA       0x38

#endif /* MCAL_TWI_TWI_PRIVATE_H_ */
