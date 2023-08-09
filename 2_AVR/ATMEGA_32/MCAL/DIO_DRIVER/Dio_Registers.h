 /******************************************************************************
 *
 * Module: DIO Registers 
 *
 * File Name: Dio_Registers.h
 *
 * Description: Addresses of the DIO Registers Used in Dio.c 
 *
 * Author: Ahmed Ibrahim
 *
 *******************************************************************************/
#ifndef DIO_REGISTERS_H
#define DIO_REGISTERS_H

/* PORT A registers addresses */
#define PORTA *((volatile uint8 *const)0x3B) 
#define DDRA  *((volatile uint8 *const)0x3A)
#define PINA  *((volatile const uint8 *const)0x39)

/* PORT B registers addresses */
#define PORTB *((volatile uint8 *const)0x38) 
#define DDRB  *((volatile uint8 *const)0x37)
#define PINB  *((volatile const uint8 *const)0x36)

/* PORT A registers addresses */
#define PORTC *((volatile uint8 *const)0x35) 
#define DDRC  *((volatile uint8 *const)0x34)
#define PINC  *((volatile const uint8 *const)0x33)

/* PORT A registers addresses */
#define PORTD *((volatile uint8 *const)0x32) 
#define DDRD  *((volatile uint8 *const)0x31)
#define PIND  *((volatile const uint8 *const)0x30)


#endif