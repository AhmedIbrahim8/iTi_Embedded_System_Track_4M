/*******************************************************************************************/
/*  Module       :   TWI                                                                   */
/*  File Name    :   TWI_Registers.h                                                       */
/*  Description  :   Header File of the TWI Registers                                      */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   27/08/2023                                                            */
/*******************************************************************************************/

#ifndef MCAL_TWI_TWI_REGISTERS_H_
#define MCAL_TWI_TWI_REGISTERS_H_

#define  TWCR   *((volatile uint8 * const)0x56)
#define  TWINT                7
#define  TWEA                 6
#define  TWSTA                5
#define  TWSTO                4
#define  TWWC                 3
#define  TWEN                 2
#define  TWIE                 0

#define  TWDR   *((volatile uint8 * const)0x23)
#define  TWD7                  7
#define  TWD6                  6
#define  TWD5                  5
#define  TWD4                  4
#define  TWD3                  3
#define  TWD2                  2
#define  TWD1                  1
#define  TWD0                  0


#define  TWAR   *((volatile uint8 * const)0x22)
#define  TWA6                 7
#define  TWA5                 6
#define  TWA4                 5
#define  TWA3                 4
#define  TWA2                 3
#define  TWA1                 2
#define  TWA0                 1
#define  TWGCE                0

#define  TWSR   *((volatile uint8 * const)0x21)
#define  TWS7                 7
#define  TWS6                 6
#define  TWS5                 5
#define  TWS4                 4
#define  TWS3                 3
#define  TWPS1                1
#define  TWPS0                0

#define  TWBR   *((volatile uint8 * const)0x20)

#endif /* MCAL_TWI_TWI_REGISTERS_H_ */
