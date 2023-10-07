/*******************************************************************************************/
/*  Module       :   MSPI                                                                  */
/*  File Name    :   MSPI_Config.h                                                         */
/*  Description  :   Header File of the SPI Configuration Driver                           */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   20/09/2023                                                            */
/*******************************************************************************************/

#ifndef MSPI_CONFIG_H_
#define MSPI_CONFIG_H_

#define      SPI1_BIDIRECTIONAL_DATA_MODE                                    SPI1_BIDIRECTIONAL_DATA_MODE_2_LINE

#define      SPI1_OUTPUT_BIDIRECTIONAL_MODE                                  SPI1_OUTPUT_BIDIRECTIONAL_MODE_DISABLE

#define      SPI1_HW_CRC_CALCULATION                                         SPI1_HW_CRC_CALCULATION_DISABLE

#define      SPI1_CRC_TRANSFER                                               SPI1_CRC_TRANSFER_NO_CRC

#define      SPI1_DATA_FRAME_FORMAT                                          SPI1_DATA_FRAME_8_BIT

#define      SPI1_RECEIVE_ONLY_ENABLE_DISABLE                                SPI1_FULL_DUPLEX_TRANSMIT_RECEIVE

#define      SPI1_SW_SLAVE_MANAGEMENT                                        SPI1_SW_SLAVE_MANAGEMENT_ENABLE

#define      SPI1_FRAME_FORMAT                                               SPI1_MOST_SIGNIFICANT_BIT_FIRST

#define      SPI1_PERIPHERAL_STATE                                           SPI1_PERIPHERAL_ENABLE

#define      SPI1_BAUD_RATE                                                  SPI1_BAUD_RATE_FCLK_4

#define      SPI1_MASTER_SELECTION                                           SPI1_MASTER_CONFIGURATION

#define      SPI1_CLOCK_POLARITY                                             SPI1_CLOCK_POLARITY_IDLE_ONE

#define      SPI1_CLOCK_PHASE                                                SPI1_CLOCK_PHASE_SETUP_SAMPLE



#define      SPI1_TX_BUFFER_EMPTY_INTERRUPT                                  SPI1_TX_BUFFER_EMPTY_INTERRUPT_DISABLE

#define      SPI1_RX_BUFFER_NOT_EMPTY_INTERRUPT                              SPI1_RX_BUFFER_NOT_EMPTY_INTERRUPT_DISABLE







#define   MSPI_NSS_PORT_INDEX          PORTA
#define   MSPI_NSS_PIN_INDEX           PIN4



#endif /* MSPI_CONFIG_H_ */
