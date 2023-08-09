#ifndef STD_TYPES_H
#define STD_TYPES_H
#include "Compiler.h" 
#include "Platform_Types.h"

/* This Type is used with value : 
   - E_OK
   - E_NOT_OK   
   If those return values are not sufficient 
   user specific values can be defined by using
   the 6 least specific bits. 
*/
typedef uint8 Std_ReturnType;

/* This type shall be used to request the version of a 
   BSW module using the <Module name>_GetVersionInfo()
   function.
*/
typedef struct{
	uint16 vendorID;
	uint16 moduleID;
	uint8 sw_major_version;
	uint8 sw_minor_version;
	uint8 sw_patch_version;
}Std_VersionInfoType;


typedef enum{
	EOK,
	ENOK,
	PARAMETER_OUT_RANGE
}tenuErrorStatus;


#define E_OK    	0x00
#define E_NOT_OK    0x01

/* Physical state 5V or 3.3V */
#define STD_HIGH 0x01  
/* Physical state 0V */
#define STD_LOW  0x00

 
 /* Logical state active */ 
#define STD_ACTIVE 0x01
 /* Logical state idle */
#define STD_IDLE 0x00


#define STD_ON  0x01 
#define STD_OFF 0x00
#endif
