/*******************************************************************************************/
/*  Module       :   GPIO                                                                   */
/*  File Name    :   MGPIO_Program.c                                                        */
/*  Description  :   Source File of the GPIO Driver                                         */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   10/09/2023                                                            */
/*******************************************************************************************/



/*******************************************************************************************/
/*********************************** Included  Files ***************************************/
/*******************************************************************************************/
/* Standard Types File */
#include "../include\STD_Types.h"
/* Bit Math File */
#include "../include\BIT_MATH.h"

/* RCC Specified Header Files */
#include "../include\MGPIO_Interface.h"
#include "../include\MGPIO_Config.h"
#include "../include\MGPIO_Private.h"

/********************************************************************************************/
/************************************** APIs Definition *************************************/
/********************************************************************************************/

void MGPIO_SetMode(u8 Copy_u8PortIndex,u8 Copy_u8PinIndex,u8 Copy_u8PinMode)
{
	/* Reference Manual Page 148 (8.3.1 General-purpose I/O (GPIO))             */
	/* Check for the debug pins because we can't change the logic of those bits */
	if( (Copy_u8PortIndex==PORTA) && ( Copy_u8PinIndex == PIN13 || Copy_u8PinIndex == PIN14 || Copy_u8PinIndex == PIN15))
	{
		/* Do No thing */
	}
	else if((Copy_u8PortIndex==PORTB) && ( Copy_u8PinIndex == PIN3 || Copy_u8PinIndex == PIN4 ))
	{
		/* Do No thing */
	}
	else
	{
		/* Switch Case for the port index to decide which port will be accessed */
		switch(Copy_u8PortIndex)
		{
		/* case of PORTA */
		case PORTA:
			/* Reference Manual Page 158                */
			/* Here we want to access the MODE register */
			GPIOA->MODER = ( GPIOA->MODER &~(GPIO_MODE_MASK<<(Copy_u8PinIndex*2)) ) | (Copy_u8PinMode << (Copy_u8PinIndex*2));
			break;
		case PORTB:
			GPIOB->MODER = ( GPIOB->MODER &~(GPIO_MODE_MASK<<(Copy_u8PinIndex*2)) ) | (Copy_u8PinMode << (Copy_u8PinIndex*2));
			break;
		case PORTC:
			GPIOC->MODER = ( GPIOC->MODER &~(GPIO_MODE_MASK<<(Copy_u8PinIndex*2)) ) | (Copy_u8PinMode << (Copy_u8PinIndex*2));
			break;
		default:
		}
	}
}

void MGPIO_SetOutputPinMode(u8 Copy_u8PortIndex,u8 Copy_u8PinIndex,u8 Copy_u8OutputType,u8 Copy_u8Speed)
{
	/* Reference Manual Page 148 (8.3.1 General-purpose I/O (GPIO))             */
	/* Check for the debug pins because we can't change the logic of those bits */
	if( (Copy_u8PortIndex==PORTA) && ( Copy_u8PinIndex == PIN13 || Copy_u8PinIndex == PIN14 || Copy_u8PinIndex == PIN15))
	{
		/* Do No thing */
	}
	else if((Copy_u8PortIndex==PORTB) && ( Copy_u8PinIndex == PIN3 || Copy_u8PinIndex == PIN4 ))
	{
		/* Do No thing */
	}
	else
	{
		/* Switch Case for the port index to decide which port will be accessed */
		switch(Copy_u8PortIndex)
		{
		/* Reference Manual Page 158,159                    */
		/* Here we want to access the :                     */
		/*                      - Output Type               */
		/*                      - Output Speed Type         */
		case PORTA:
			GPIOA->OTYPER = ( GPIOA->OTYPER &~(GPIO_OUTPUT_TYPE_MASK<<(Copy_u8PinIndex)) ) | (Copy_u8OutputType << (Copy_u8PinIndex));
			GPIOA->OSPEEDR = ( GPIOA->OSPEEDR &~(GPIO_OUTPUT_SPEED_TYPE_MASK<<(Copy_u8PinIndex*2)) ) | (Copy_u8Speed << (Copy_u8PinIndex*2));
			break;
		case PORTB:
			GPIOB->OTYPER = ( GPIOB->OTYPER &~(GPIO_OUTPUT_TYPE_MASK<<(Copy_u8PinIndex)) ) | (Copy_u8OutputType << (Copy_u8PinIndex));
			GPIOB->OSPEEDR = ( GPIOB->OSPEEDR &~(GPIO_OUTPUT_SPEED_TYPE_MASK<<(Copy_u8PinIndex*2)) ) | (Copy_u8Speed << (Copy_u8PinIndex*2));
			break;
		case PORTC:
			GPIOC->OTYPER = ( GPIOC->OTYPER &~(GPIO_OUTPUT_TYPE_MASK<<(Copy_u8PinIndex)) ) | (Copy_u8OutputType << (Copy_u8PinIndex));
			GPIOC->OSPEEDR = ( GPIOC->OSPEEDR &~(GPIO_OUTPUT_SPEED_TYPE_MASK<<(Copy_u8PinIndex*2)) ) | (Copy_u8Speed << (Copy_u8PinIndex*2));
			break;
		default:
		}
	}
}

void MGPIO_SetInputPinMode(u8 Copy_u8PortIndex,u8 Copy_u8PinIndex,u8 Copy_u8InputType)
{
	/* Reference Manual Page 148 (8.3.1 General-purpose I/O (GPIO))             */
		/* Check for the debug pins because we can't change the logic of those bits */
		if( (Copy_u8PortIndex==PORTA) && ( Copy_u8PinIndex == PIN13 || Copy_u8PinIndex == PIN14 || Copy_u8PinIndex == PIN15))
		{
			/* Do No thing */
		}
		else if((Copy_u8PortIndex==PORTB) && ( Copy_u8PinIndex == PIN3 || Copy_u8PinIndex == PIN4 ))
		{
			/* Do No thing */
		}
		else
		{
			/* Switch Case for the port index to decide which port will be accessed */
			switch(Copy_u8PortIndex)
			{
			/* case of PORTA */
			case PORTA:
				/* Reference Manual Page 159,160                        */
				/* Here we want to access the PULL UP DOWN Register     */
				GPIOA->PUPDR = ( GPIOA->PUPDR &~(GPIO_PULL_UP_DOWN__MASK<<(Copy_u8PinIndex*2)) ) | (Copy_u8InputType << (Copy_u8PinIndex*2));
				break;
			case PORTB:
				GPIOB->PUPDR = ( GPIOB->PUPDR &~(GPIO_PULL_UP_DOWN__MASK<<(Copy_u8PinIndex*2)) ) | (Copy_u8InputType << (Copy_u8PinIndex*2));
				break;
			case PORTC:
				GPIOC->PUPDR = ( GPIOC->PUPDR &~(GPIO_PULL_UP_DOWN__MASK<<(Copy_u8PinIndex*2)) ) | (Copy_u8InputType << (Copy_u8PinIndex*2));
				break;
			default:
			}
		}
}

void MGPIO_GetPinValue(u8 Copy_u8PortIndex,u8 Copy_u8PinIndex,u8 *Copy_pu8Data)
{

}

void MGPIO_SetPinValue(u8 Copy_u8PortIndex,u8 Copy_u8PinIndex,u8 Copy_u8)
{

}
void MGPIO_SetResetValue(u8 Copy_u8PortIndex,u8 Copy_u8PinIndex,u8 Copy_u8SetOrReset)
{
	/* Reference Manual Page 148 (8.3.1 General-purpose I/O (GPIO))             */
		/* Check for the debug pins because we can't change the logic of those bits */
		if( (Copy_u8PortIndex==PORTA) && ( Copy_u8PinIndex == PIN13 || Copy_u8PinIndex == PIN14 || Copy_u8PinIndex == PIN15))
		{
			/* Do No thing */
		}
		else if((Copy_u8PortIndex==PORTB) && ( Copy_u8PinIndex == PIN3 || Copy_u8PinIndex == PIN4 ))
		{
			/* Do No thing */
		}
		else
		{
			/* Switch Case for the port index to decide which port will be accessed */
			switch(Copy_u8PortIndex)
			{
			/* case of PORTA */
			case PORTA:
				if( Copy_u8SetOrReset == OUTPUT_SET )
				{
					GPIOA->BSRR = (GPIOA->BSRR &~(1<<Copy_u8PinIndex)) | (1<<Copy_u8PinIndex);
				}
				else if( Copy_u8SetOrReset == OUTPUT_RESET )
				{
					Copy_u8PinIndex = Copy_u8PinIndex +16;
					GPIOA->BSRR = (GPIOA->BSRR &~(1<<Copy_u8PinIndex)) | (1<<Copy_u8PinIndex);
				}
				break;
			/* case of PORTB */
			case PORTB:
				if( Copy_u8SetOrReset == OUTPUT_SET )
				{
					GPIOB->BSRR = (GPIOB->BSRR &~(1<<Copy_u8PinIndex)) | (1<<Copy_u8PinIndex);
				}
				else if( Copy_u8SetOrReset == OUTPUT_RESET )
				{
					Copy_u8PinIndex = Copy_u8PinIndex +16;
					GPIOB->BSRR = (GPIOB->BSRR &~(1<<Copy_u8PinIndex)) | (1<<Copy_u8PinIndex);
				}
				break;
			/* case of PORTC */
			case PORTC:
				if( Copy_u8SetOrReset == OUTPUT_SET )
				{
					GPIOC->BSRR = (GPIOC->BSRR &~(1<<Copy_u8PinIndex)) | (1<<Copy_u8PinIndex);
				}
				else if( Copy_u8SetOrReset == OUTPUT_RESET )
				{
					Copy_u8PinIndex = Copy_u8PinIndex +16;
					GPIOC->BSRR = (GPIOC->BSRR &~(1<<Copy_u8PinIndex)) | (1<<Copy_u8PinIndex);
				}
				break;
			default:

			}
		}
}
