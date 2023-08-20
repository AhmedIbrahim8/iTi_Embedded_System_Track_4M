/*
 * Timer1_Register.h
 *
 *  Created on: 19 Aug 2023
 *      Author: mosam
 */

#ifndef TIMER1_REGISTER_H_
#define TIMER1_REGISTER_H_
#define TIMSK     *((volatile uint8 * const)0x59)
#define TOIE2          6
#define TICIE1         5
#define OCIE1A         4
#define OCIE1B         3
#define TOIE1          2
#define TIFR      *((volatile uint8 * const)0x58)
#define ICF1           5
#define OCF1A          4
#define OCF1B          3
#define TOV1           2
#define TCCR1A    *((volatile uint8 * const)0x4F)
#define COM1A1         7
#define COM1A0         6
#define COM1B1         5
#define COM1B0         4
#define FOC1A          3
#define FOC1B          2
#define WGM11          1
#define WGM10          0
#define TCCR1B    *((volatile uint8 * const)0x4E)
#define ICNC1          7
#define ICES1          6
#define WGM13          4
#define WGM12          3
#define CS12           2
#define CS11           1
#define CS10           0
#define TCNT1H    *((volatile uint8 * const)0x4D)
#define TCNT1L    *((volatile uint8 * const)0x4C)
#define TCNT1     *((volatile uint16 * const)0x4C)

#define OCR1AH    *((volatile uint8 * const)0x4B)
#define OCR1AL    *((volatile uint8 * const)0x4A)
#define OCR1A     *((volatile uint16 * const)0x4A)

#define OCR1BH    *((volatile uint8 * const)0x49)
#define OCR1BL    *((volatile uint8 * const)0x48)
#define OCR1B     *((volatile uint16 * const)0x48)

#define ICR1H    *((volatile uint8 * const)0x47)
#define ICR1L    *((volatile uint8 * const)0x46)
#define ICR1     *((volatile uint16 * const)0x46)


#endif /* TIMER1_REGISTER_H_ */
