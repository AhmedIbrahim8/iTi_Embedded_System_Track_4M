/*******************************************************************************************/
/*  Module       :   TIMER2                                                                */
/*  File Name    :   Timer2_Registers.h                                                    */
/*  Description  :   Header File of the Timer2 Addresses                                    */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   21/08/2023                                                            */
/*******************************************************************************************/


#ifndef MCAL_TIMER2_TIMER2_REGISTERS_H_
#define MCAL_TIMER2_TIMER2_REGISTERS_H_



#define   TCCR2    *((volatile uint8 * const)0x45)
#define   FOC2                   7
#define   WGM20                  6
#define   COM21                  5
#define   COM20                  4
#define   WGM21                  3
#define   CS22                   2
#define   CS21                   1
#define   CS20                   0


#define   TCNT2    *((volatile uint8 * const)0x44)

#define   OCR2     *((volatile uint8 * const)0x43)

#define   ASSR     *((volatile uint8 * const)0x42)
#define AS2                      3
#define TCN2UB                   2
#define OCR2UB                   1
#define TCR2UB                   0

/* TIMSK has a bits with Timer1 and Timer2 */
#ifndef   TIMSK
#define   TIMSK    *((volatile uint8 * const)0x59)
#endif

#define   TOIE2                  6
#define   OCIE2                  7



/* TIFR has a bits with Timer1 and Timer2 */
#ifndef   TIFR
#define   TIFR     *((volatile uint8 * const)0x58)
#endif
#define   TOV2                   6
#define   OCF2                   7


#ifndef   SFIOR
#define   SFIOR    *((volatile uint8 * const)0x50)
#endif
#define   PSR2                   1

#endif /* MCAL_TIMER0_TIMER0_REGISTERS_H_ */
