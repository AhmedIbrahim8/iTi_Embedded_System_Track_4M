/*******************************************************************************************/
/*  Module       :   LCD                                                                   */
/*  File Name    :   Lcd_Types.c                                                           */
/*  Description  :   header File of the LCD Driver types                                   */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   06/08/2023                                                            */
/*******************************************************************************************/


#ifndef LCD_TYPES_H_
#define LCD_TYPES_H_

#include "Std_Types.h"
/* Type for the mode of the LCD :                     */
/*            -LCD_8_BIT_MODE                         */
/*            -LCD_4_BIT_MODE                         */
typedef uint8 LCD_ModeType;

/* Type for the line of the LCD :                     */
/*            - LCD_ONE_LINE                          */
/*            - LCD_TWO_LINE                          */
typedef uint8 LCD_LineType;

/* Type for the Font of the LCD :                     */
/*            - LCD_FONT_5X11                         */
/*            - LCD_FONT_5*7                          */
typedef uint8 LCD_FontType;

/* Type for the cursor of the LCD :                   */
/*            - LCD_CURSOR_OFF                        */
/*            - LCD_CURSOR_ON                         */
typedef uint8 LCD_CursorType;

/* Type for the cursor of the LCD :                   */
/*            - LCD_CURSOR_BLINK_ON                   */
/*            - LCD_CURSOR_BLINK_OFF                  */
typedef uint8 LCD_CursorBlinkType;

/* If the display is off, the data inside the DDRAM will   */
/* remain in the memory but it will not show in the Screen */

/* Type for the Display of the LCD :                  */
/*            - LCD_DISPLAY_ON                        */
/*            - LCD_DISPLAY_OFF                       */
typedef uint8 LCD_DisplayType;

/* Numeric index of lCD pins */
typedef uint8 LCD_ChannelType;
/* Type for the shift of the LCD :                    */
/*            - LCD_SHIFT_ON                          */
/*            - LCD_SHIFT_OFF                         */
typedef uint8 LCD_shiftType;

/* Type for the cursor move of the LCD :              */
/*            - LCD_RIGHT_LEFT                        */
/*            - LCD_LEFT_RIGHT                        */
typedef uint8 LCD_cursorMoveType;



typedef struct{
	LCD_ModeType         mode         : 1;
	LCD_LineType         line         : 1;
	LCD_FontType         font         : 1;
	LCD_CursorType       cursor       : 1;
	LCD_CursorBlinkType  blink        : 1;
	LCD_DisplayType      display      : 1;
	LCD_shiftType        shift        : 1;
	LCD_cursorMoveType   cursorMove   : 1;
}LCD_Configuration;

typedef struct{
	LCD_ChannelType dataPins[8];
	LCD_ChannelType registerSelectPin;
	LCD_ChannelType readWritePin;
	LCD_ChannelType enablePin;
}LCD_PinsConfiguration;




#endif /* LCD_TYPES_H_ */
