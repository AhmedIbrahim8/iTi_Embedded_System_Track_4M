/*******************************************************************************************/
/*  Module       :   RTO                                                                   */
/*  File Name    :   RTO_Private.h                                                       */
/*  Description  :   Header File of the Private RTO Driver                                           */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   30/08/2023                                                            */
/*******************************************************************************************/


#ifndef SERVICELAYER_RTO_RTO_PRIVATE_H_
#define SERVICELAYER_RTO_RTO_PRIVATE_H_


static void RTO_voidScheduler(void);

typedef struct{
	uint16 Periodicity;

	uint16 FirstDelay;

	void (*Pf) (void);
}TCB;


#endif /* SERVICELAYER_RTO_RTO_PRIVATE_H_ */
