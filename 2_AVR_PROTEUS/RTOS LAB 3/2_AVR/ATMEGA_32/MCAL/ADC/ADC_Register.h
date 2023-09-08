/*******************************************************************************************/
/*  Module       :   ADC                                                                   */
/*  File Name    :   ADC_Registers.h                                                       */
/*  Description  :   Header File of the ADC Addresses                                      */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   15/08/2023                                                            */
/*******************************************************************************************/
#ifndef MCAL_ADC_ADC_REGISTER_H_
#define MCAL_ADC_ADC_REGISTER_H_

#define ADMUX   *((volatile uint8 * const)0x27)
#define REFS1        7
#define REFS0        6
#define ADLAR        5
#define MUX4         4
#define MUX3         3
#define MUX2         2
#define MUX1         1
#define MUX0         0

#define ADCSRA   *((volatile uint8 * const)0x26)
#define ADEN         7
#define ADSC         6
#define ADATE        5
#define ADIF         4
#define ADIE         3
#define ADPS2        2
#define ADPS1        1
#define ADPS0        0

#define ADCH   *((volatile uint8 * const)0x25)
#define ADCL   *((volatile uint8 * const)0x24)
#define ADC    *((volatile uint16 * const)0x24)
#define SFIOR  *((volatile uint8 * const)0x50)
#define ADTS2        7
#define ADTS1        6
#define ADTS0        5
#endif /* MCAL_ADC_ADC_REGISTER_H_ */
