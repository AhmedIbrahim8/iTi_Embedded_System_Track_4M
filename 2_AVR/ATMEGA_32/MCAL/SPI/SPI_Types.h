/*
 * SPI_Types.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_SPI_SPI_TYPES_H_
#define MCAL_SPI_SPI_TYPES_H_

#define SPI_INTERRUPT_ENABLE                     1
#define SPI_INTERRUPT_DISABLE                    0

#define SPI_ENABLE                               1
#define SPI_DISABLE                              0

#define SPI_DATA_ORDER_LSB_FIRST                 1
#define SPI_DATA_ORDER_MSB_FIRST                 0

#define SPI_MASTER_MODE                          1
#define SPI_SLAVE_MODE                           0

#define SPI_CLOCK_POLARITY_LEADING_RISING        0
#define SPI_CLOCK_POLARITY_LEADING_FALLING       1

#define SPI_CLOCK_PHASE_SAMLPE_SETUP             0
#define SPI_CLOCK_PHASE_SETUP_SAMPLE             1

#define SPI_CLOCK_RATE_F_4                       0
#define SPI_CLOCK_RATE_F_16                      1
#define SPI_CLOCK_RATE_F_64                      2
#define SPI_CLOCK_RATE_F_128                     3
#define SPI_CLOCK_RATE_F_2                       4
#define SPI_CLOCK_RATE_F_8                       5
#define SPI_CLOCK_RATE_F_32                      6



#endif /* MCAL_SPI_SPI_TYPES_H_ */
