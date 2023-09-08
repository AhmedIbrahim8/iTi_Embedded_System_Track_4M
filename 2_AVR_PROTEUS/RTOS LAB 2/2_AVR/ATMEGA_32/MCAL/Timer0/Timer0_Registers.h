/*******************************************************************************************/
/*  Module       :   TIMER0                                                                */
/*  File Name    :   Timer0_Registers.h                                                    */
/*  Description  :   Header File of the Timer Addresses                                    */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   18/08/2023                                                            */
/*******************************************************************************************/


#ifndef MCAL_TIMER0_TIMER0_REGISTERS_H_
#define MCAL_TIMER0_TIMER0_REGISTERS_H_

#define   OCR0     *((volatile uint8 * const)0x5C)

/* TIMSK has a bits with Timer1 and Timer2 */
#ifndef   TIMSK
#define   TIMSK    *((volatile uint8 * const)0x59)
#endif

#define   TOIE0                  0
#define   OCIE0                  1

/* TIFR has a bits with Timer1 and Timer2 */
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






#endif /* MCAL_TIMER0_TIMER0_REGISTERS_H_ */
