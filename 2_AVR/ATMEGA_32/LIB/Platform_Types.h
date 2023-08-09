#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H


/*
 * CPU register type width
 */

#define CPU_TYPE_8                                  (8U)
#define CPU_TYPE_16                                 (16U)
#define CPU_TYPE_32                                 (32U)

/*
 * Bit order definition
 */
#define MSB_FIRST                   (0u)        /* Big endian bit ordering        */
#define LSB_FIRST                   (1u)        /* Little endian bit ordering     */


/*
 * Byte order definition
 */
#define HIGH_BYTE_FIRST             (0u)        /* Big endian byte ordering       */
#define LOW_BYTE_FIRST              (1u)        /* Little endian byte ordering    */


/*
 * Platform type and endianess definitions, specific for AVR ATMEGA 32
 */
#define CPU_TYPE            CPU_TYPE_8

#define CPU_BIT_ORDER       LSB_FIRST
#define CPU_BYTE_ORDER      LOW_BYTE_FIRST


#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif


typedef unsigned char         boolean;

typedef unsigned char         uint8;          /*                   0 .. 255                   */
typedef unsigned short        uint16;         /*                   0 .. 65535                 */
typedef unsigned long         uint32;         /*                   0 .. 4294967295            */
typedef unsigned long long    uint64;         /*                   0 .. 18446744073709551615  */

typedef signed char           sint8;          /*                -128 .. +127                  */
typedef signed short          sint16;         /*              -32768 .. +32767                */
typedef signed long           sint32;         /*         -2147483648 .. +2147483647           */
typedef signed long long      sint64;         /*-9223372036854775808 .. 9223372036854775807   */

typedef unsigned char          uint8_least; 
typedef unsigned short         uint16_least;
typedef unsigned int           uint32_least;

typedef signed char          sint8_least; 
typedef signed short         sint16_least;
typedef signed int           sint32_least;

typedef float                float32;
typedef double               float64;

#endif
