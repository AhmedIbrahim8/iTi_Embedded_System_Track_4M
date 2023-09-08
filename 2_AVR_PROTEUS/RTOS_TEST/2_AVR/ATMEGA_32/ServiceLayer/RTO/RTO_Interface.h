/*******************************************************************************************/
/*  Module       :   RTO                                                                   */
/*  File Name    :   RTO_Interface.h                                                       */
/*  Description  :   Header File of the RTO Driver                                           */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   30/08/2023                                                            */
/*******************************************************************************************/


#ifndef SERVICELAYER_RTO_RTO_INTERFACE_H_
#define SERVICELAYER_RTO_RTO_INTERFACE_H_

/*********************************************************************/
/* This Function responsible for allocating TCB for the task         */
/* Function Parameter [in] :          TCB Parameters                 */
/*                         1- Priority                               */
/*                         2- Periodicity                            */
/*                         3- First Delay                            */
/*                         4- Pointer to the function                */
/* Function Return [out]   :                                         */
/*********************************************************************/
uint8 RTO_u8CreateTask(uint8 Copy_u8Priority,
		               uint16 Copy_u16Periodicity,
					   uint16 Copy_u16FirstDelay,
					   void (*Copy_Pf)(void)
					   );





/*********************************************************************/
/* Function Responsible for start the RTO                            */
/*********************************************************************/
void RTO_voidInit(void);


#endif /* SERVICELAYER_RTO_RTO_INTERFACE_H_ */
