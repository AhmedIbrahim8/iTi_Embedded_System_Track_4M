 /******************************************************************************
 *
 * Module: External Interrupt Registers
 *
 * File Name: EXT_INT_Register.h
 *
 * Description: Addresses of the External Interrupt Registers Used.
 *
 * Author: Ahmed Ibrahim
 *
 *******************************************************************************/

#ifndef MCAL_EXTERNAL_INTERRUPT_DRIVER_EXT_INT_REGISTER_H_
#define MCAL_EXTERNAL_INTERRUPT_DRIVER_EXT_INT_REGISTER_H_

#define MCUCR       *((volatile uint8 * const)0x55)
#define MCUCSR      *((volatile uint8 * const)0x54)
#define GICR        *((volatile uint8 * const)0x5B)
#define GIFR        *((volatile uint8 * const)0x5A)

/*Pin index of the external interrupts pins */
#define ISC00        0
#define ISC01        1
#define ISC10        2
#define ISC11        3
#define ISC2         6
#define INT1         7
#define INT0         6
#define INT2         5
/* External Interrupt Flags (PIF) */

#define INTF1        7
#define INTF0        6
#define INTF2        5


#endif /* MCAL_EXTERNAL_INTERRUPT_DRIVER_EXT_INT_REGISTER_H_ */
