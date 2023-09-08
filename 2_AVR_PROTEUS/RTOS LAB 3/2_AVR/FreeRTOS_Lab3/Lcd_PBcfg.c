/*******************************************************************************************/
/*  Module       :   LCD                                                                   */
/*  File Name    :   Lcd_PBcfg.c                                                           */
/*  Description  :   Source File of the configuration of the LCD Driver                    */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   06/08/2023                                                            */
/*******************************************************************************************/


#include     "Lcd.h"

LCD_Configuration configuration[LCD_NUMBERS]={
		{LCD1_MODE,
		LCD1_LINE_MODE,
		LCD1_FONT,
		LCD1_CURSOR,
		LCD1_CURSOR_BLINK,
		LCD1_DISPLAY,
		LCD1_SHIFT,
		LCD1_CURSOR_MOVE}
};

LCD_PinsConfiguration pinsConfiguration[LCD_NUMBERS]={
		{{LCD1_DB_0,LCD1_DB_1,LCD1_DB_2,LCD1_DB_3,LCD1_DB_4,LCD1_DB_5,LCD1_DB_6,LCD1_DB_7},
		LCD1_RS_PIN,
		LCD1_RW_PIN,
		LCD1_E_PIN}
};
