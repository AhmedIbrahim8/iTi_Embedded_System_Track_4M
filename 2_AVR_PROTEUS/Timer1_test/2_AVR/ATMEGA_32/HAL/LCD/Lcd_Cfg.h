/*******************************************************************************************/
/*  Module       :   LCD                                                                   */
/*  File Name    :   Lcd_Cfg.h                                                             */
/*  Description  :   Header File of the configuration of the LCD Driver                    */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   06/08/2023                                                            */
/*******************************************************************************************/




#ifndef LCD_CFG_H
#define LCD_CFG_H
/* LCD Pins Connections */
#define LCD_NUMBERS                  1

/* LCD 1 Pins Connections */
#define LCD1_INDEX_NUMBER            0

#define LCD1_RS_PIN           (LCD_ChannelType)16
#define LCD1_RW_PIN           (LCD_ChannelType)17
#define LCD1_E_PIN            (LCD_ChannelType)18

#define LCD1_DB_0             (LCD_ChannelType)8
#define LCD1_DB_1             (LCD_ChannelType)9
#define LCD1_DB_2             (LCD_ChannelType)10
#define LCD1_DB_3             (LCD_ChannelType)11
#define LCD1_DB_4             (LCD_ChannelType)12
#define LCD1_DB_5             (LCD_ChannelType)13
#define LCD1_DB_6             (LCD_ChannelType)14
#define LCD1_DB_7             (LCD_ChannelType)15


/* LCD1 Modes Type */
#define LCD1_MODE              LCD_8_BIT_MODE
#define LCD1_LINE_MODE         LCD_TWO_LINE
#define LCD1_FONT              LCD_FONT_5X7
#define LCD1_CURSOR            LCD_CURSOR_ON
#define LCD1_CURSOR_BLINK      LCD_CURSOR_BLINK_ON
#define LCD1_DISPLAY           LCD_DISPLAY_ON
#define LCD1_SHIFT             LCD_SHIFT_OFF
#define LCD1_CURSOR_MOVE       LCD_LEFT_RIGHT









#endif
