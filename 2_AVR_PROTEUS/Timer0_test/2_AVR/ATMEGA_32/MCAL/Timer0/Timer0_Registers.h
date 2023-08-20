/*******************************************************************************************/
/*  Module       :   TIMER0                                                                   */
/*  File Name    :   Timer0_Registers.h                                                       */
/*  Description  :   Header File of the Timer Addresses                                      */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   18/08/2023                                                            */
/*******************************************************************************************/


#ifndef MCAL_TIMER0_TIMER0_REGISTERS_H_
#define MCAL_TIMER0_TIMER0_REGISTERS_H_

#define   OCR0     *((volatile uint8 * const)0x5C)

#ifndef   TIMSK
#define   TIMSK    *((volatile uint8 * const)0x59)
#endif
#define   TOIE0                  0
#define   OCIE0                  1

#ifndef   TIFR
#define   TIFR     *((volatile uint8 * const)0x58)
#endif
#define   TOV0                   0
#define   OCF0                   1

#define   TCCR0    *((volatile uint8 * const)0x53)
#define   FOC0                   7
#define   WGM00                  6
#define   COM01                  5
#define   COM00                  4
#define   WGM01                  3
#define   CS02                   2
#define   CS01                   1
#define   CS00                   0


#define   TCNT0    *((volatile uint8 * const)0x52)




             /* Timer 1*/
#define TCCR1A   *((volatile uint8 *)0x4F)

#define TCCR1B   *((volatile uint8 *)0x4E)

#define TCNT1H   *((volatile uint8 *)0x4D)
#define TCNT1L   *((volatile uint8 *)0x4C)
#define TCNT1    *((volatile uint16 *)0x4C)

#define OCR1AH   *((volatile uint8 *)0x4B)
#define OCR1AL   *((volatile uint8 *)0x4A)
#define OCR1A    *((volatile uint16 *)0x4A)

#define OCR1BH   *((volatile uint8 *)0x49)
#define OCR1BL   *((volatile uint8 *)0x48)
#define OCR1B    *((volatile uint16 *)0x48)

#define ICR1H   *((volatile uint8 *)0x47)
#define ICR1L   *((volatile uint8 *)0x46)
#define ICR1    *((volatile uint16 *)0x46)

#endif /* MCAL_TIMER0_TIMER0_REGISTERS_H_ */
