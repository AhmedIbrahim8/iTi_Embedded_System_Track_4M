/*******************************************************************************************/
/*  Module       :   TFT LCD                                                               */
/*  File Name    :   HTFT_Private.h                                                        */
/*  Description  :   Header File of the TFT Private Driver                                 */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   20/09/2023                                                            */
/*******************************************************************************************/

#ifndef HTFT_PRIVATE_H_
#define HTFT_PRIVATE_H_



/********************************************************************************************/
/********************************** TFT Commands and DATA ***********************************/
/********************************************************************************************/

#define      TFT_SLEEP_OUT_COMMAND                         0x11

#define      TFT_COLOR_MODE_COMMAND                        0x3A
#define      TFT_COLOR_MODE_R4G4B4_DATA                    0x03
#define      TFT_COLOR_MODE_R5G6B5_DATA                    0x05
#define      TFT_COLOR_MODE_R6G6B6_DATA                    0x06

#define      TFT_DISPLAY_ON_MODE_COMMAND                   0x29


#define      TFT_SET_X_COMMAND                             0x2A

#define      TFT_SET_Y_COMMAND                             0x2B


#endif /* HTFT_PRIVATE_H_ */
