/*
 * SPI_Register.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Ahmed
 */

#ifndef MCAL_SPI_SPI_REGISTERS_H_
#define MCAL_SPI_SPI_REGISTERS_H_

#define  SPDR    *((volatile uint8 * const)0x2F)

#define  SPSR    *((volatile uint8 * const)0x2E)
#define  SPIF                  7
#define  WCOL                  6
#define  SPI2X                 0

#define  SPCR    *((volatile uint8 * const)0x2D)
#define  SPIE                  7
#define  SPE                   6
#define  DORD                  5
#define  MSTR                  4
#define  CPOL                  3
#define  CPHA                  2
#define  SPR1                  1
#define  SPR0                  0
















#endif /* MCAL_SPI_SPI_REGISTERS_H_ */
