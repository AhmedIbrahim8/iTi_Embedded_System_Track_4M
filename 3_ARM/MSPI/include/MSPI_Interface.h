/*******************************************************************************************/
/*  Module       :   MSPI                                                                  */
/*  File Name    :   MSPI_Interface.h                                                      */
/*  Description  :   Header File of the SPI Interface Driver                               */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   20/09/2023                                                            */
/*******************************************************************************************/

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_


/********************************************************************************************/
/************************************** Mask and #s Used ************************************/
/********************************************************************************************/
#define   INTERRUPT_MASK                                            0xFFFFFF3F





#define   SPI1_CLOCK_PHASE_SAMPLE_SETUP                             0
#define   SPI1_CLOCK_PHASE_SETUP_SAMPLE                             1

#define   SPI1_CLOCK_POLARITY_IDLE_ZERO                             0
#define   SPI1_CLOCK_POLARITY_IDLE_ONE                              1

#define   SPI1_SLAVE_CONFIGURATION                                  0
#define   SPI1_MASTER_CONFIGURATION                                 1

#define   SPI1_BAUD_RATE_FCLK_2                                     0
#define   SPI1_BAUD_RATE_FCLK_4                                     1
#define   SPI1_BAUD_RATE_FCLK_8                                     2
#define   SPI1_BAUD_RATE_FCLK_16                                    3
#define   SPI1_BAUD_RATE_FCLK_32                                    4
#define   SPI1_BAUD_RATE_FCLK_64                                    5
#define   SPI1_BAUD_RATE_FCLK_128                                   6
#define   SPI1_BAUD_RATE_FCLK_256                                   7

#define   SPI1_PERIPHERAL_DISABLE                                   0
#define   SPI1_PERIPHERAL_ENABLE                                    1

#define   SPI1_MOST_SIGNIFICANT_BIT_FIRST                           0
#define   SPI1_LEAST_SIGNIFICANT_BIT_FIRST                          1

#define   SPI1_SW_SLAVE_MANAGEMENT_DISABLE                          0
#define   SPI1_SW_SLAVE_MANAGEMENT_ENABLE                           1

#define   SPI1_FULL_DUPLEX_TRANSMIT_RECEIVE                         0
#define   SPI1_RECEIVE_ONLY_MODE                                    1

#define   SPI1_DATA_FRAME_8_BIT                                     0
#define   SPI1_DATA_FRAME_16_BIT                                    1

#define   SPI1_CRC_TRANSFER_NO_CRC                                  0
#define   SPI1_CRC_TRANSFER_CRC                                     1

#define   SPI1_HW_CRC_CALCULATION_DISABLE                           0
#define   SPI1_HW_CRC_CALCULATION_ENABLE                            1

#define   SPI1_OUTPUT_BIDIRECTIONAL_MODE_DISABLE                    0
#define   SPI1_OUTPUT_BIDIRECTIONAL_MODE_ENABLE                     1


#define   SPI1_BIDIRECTIONAL_DATA_MODE_2_LINE                       0
#define   SPI1_BIDIRECTIONAL_DATA_MODE_1_LINE                       1

#define   SPI1_TX_BUFFER_EMPTY_INTERRUPT_DISABLE                    0
#define   SPI1_TX_BUFFER_EMPTY_INTERRUPT_ENABLE                     1

#define   SPI1_RX_BUFFER_NOT_EMPTY_INTERRUPT_DISABLE                0
#define   SPI1_RX_BUFFER_NOT_EMPTY_INTERRUPT_ENABLE                 1


/********************************************************************************************/
/************************************** Typedef Used ****************************************/
/********************************************************************************************/






/********************************************************************************************/
/************************************** APIs Proto-Types ************************************/
/********************************************************************************************/
void MSPI1_voidInit        (void) ;
u8   MSPI1_u8SendDataU8    (u8 Copy_u8Data) ;
void MSPI1_voidSetCallBack (void (*ptr) (void) ) ;


#endif /* MSPI_INTERFACE_H_ */
