/******************************************************************************
 *
 * Module     : External Interrupt Functions
 *
 * File Name  : EXT_INT.c
 *
 * Description: External Interrupt program
 *
 * Author     : Ahmed Ibrahim
 *
 * Date       : 12/08/2023
 *******************************************************************************/
#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\common_macros.h"
#include "EXT_INT_Register.h"
#include "EXT_INT.h"
/* Global Pointer to Functions *
 * Array of 3-pointer to Function */
/* Initialize the pointer to null */
static void (*EXT_INT[3])(void)={NULL_PTR,NULL_PTR,NULL_PTR};

void EXT_INT_SetCallBack(void (*EXT_INT_PfCpy)(void),uint8 ExtIntIndexCpy){
	/* The index must be in the range of the external interrupts */
	/* and the pointer to function must be not NULL_PTR          */
	if((ExtIntIndexCpy <= EXTERNAL_INT_2_INDEX) && EXT_INT_PfCpy!=NULL_PTR){
		EXT_INT[ExtIntIndexCpy]=EXT_INT_PfCpy;
	}
	else{
		/* Do No thing */
	}
}


void EXT_INT_Enable(uint8 ExtIntIndexCpy,EXT_INT_LevelType levelTypeCopy){
	switch(ExtIntIndexCpy){
	case EXTERNAL_INT_0_INDEX:
		/* Adjust the configuration of the Interrupt 0 */
		switch(levelTypeCopy){
		case FALLING_EDGE:
			CLEAR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		case LOW_LEVEL:
			CLEAR_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
		case ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;

		}
		/* Setting the Peripheral Interrupt Enable (PIE) of the Interrupt 0 */
		SET_BIT(GICR,INT0);
		break;
	case EXTERNAL_INT_1_INDEX:
		/* Adjust the configuration of the Interrupt 1 */
		switch(levelTypeCopy){
		case FALLING_EDGE:
			CLEAR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
		case LOW_LEVEL:
			CLEAR_BIT(MCUCR,ISC10);
			CLEAR_BIT(MCUCR,ISC11);
			break;
		case ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC10);
			CLEAR_BIT(MCUCR,ISC11);
			break;

		}
		/* Setting the Peripheral Interrupt Enable (PIE) of the Interrupt 1 */
		SET_BIT(GICR,INT1);
		break;
	case EXTERNAL_INT_2_INDEX:
		/* Adjust the configuration of the Interrupt 2 */
		switch(levelTypeCopy){
		case FALLING_EDGE:
			CLEAR_BIT(MCUCSR,ISC2);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCSR,ISC2);
			break;

		}
		/* Setting the Peripheral Interrupt Enable (PIE) of the Interrupt 2 */
		SET_BIT(GICR,INT2);
		break;
	default:
		/* Do No thing */
		break;

	}
}

void EXT_INT_Disable(uint8 ExtIntIndexCpy){
	switch(ExtIntIndexCpy){
	/* Interrupt 0 Disable */
	case EXTERNAL_INT_0_INDEX:
		/* Disable PIE of Interrupt 0 */
		CLEAR_BIT(GICR,INT0);
		break;
	/* Interrupt 1 Disable */
	case EXTERNAL_INT_1_INDEX:
		/* Disable PIE of Interrupt 1 */
		CLEAR_BIT(GICR,INT1);
		break;
	/* Interrupt 2 Disable */
	case EXTERNAL_INT_2_INDEX:
		/* Disable PIE of Interrupt 2 */
		CLEAR_BIT(GICR,INT2);
		break;
	default:
		break;
		/* Do No thing*/

	}
}

/* Interrupt Service Routine of INT 0 */
void __vector_1(void)            __attribute__((signal));
void __vector_1(void){
	if(EXT_INT[EXTERNAL_INT_0_INDEX]!=NULL_PTR){
		(*EXT_INT[EXTERNAL_INT_0_INDEX])();
	}
	else{
		/* Do No thing */
	}

}

/* Interrupt Service Routine of INT 1 */
void __vector_2(void)            __attribute__((signal));
void __vector_2(void){
	if(EXT_INT[EXTERNAL_INT_1_INDEX]!=NULL_PTR){
		(*EXT_INT[EXTERNAL_INT_1_INDEX])();
	}
	else{
		/* Do No thing */
	}
}

/* Interrupt Service Routine of INT 2 */
void __vector_3(void)            __attribute__((signal));
void __vector_3(void){
	if(EXT_INT[EXTERNAL_INT_2_INDEX]!=NULL_PTR){
		(*EXT_INT[EXTERNAL_INT_2_INDEX])();
	}
	else{
		/* Do No thing */
	}
}




