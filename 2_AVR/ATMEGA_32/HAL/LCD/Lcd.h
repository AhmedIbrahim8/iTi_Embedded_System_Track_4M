/*******************************************************************************************/
/*  Module       :   LCD                                                                   */
/*  File Name    :   Lcd.h                                                                 */
/*  Description  :   Header File of the LCD Driver                                         */
/*  Author       :   Ahmed Ibrahim                                                         */
/*  Date         :   06/08/2023                                                            */
/*******************************************************************************************/



#ifndef LCD_H
#define LCD_H
#include "Lcd_Types.h"
#include "Lcd_Cfg.h"

/***************************************************************/
/*                    #s used in the driver                    */
/*       -This #s can't be change through the driver           */
/***************************************************************/

#define        LCD_8_BIT_MODE              (LCD_ModeType)1
#define        LCD_4_BIT_MODE              (LCD_ModeType)0
#define        LCD_ONE_LINE                (LCD_LineType)0
#define        LCD_TWO_LINE                (LCD_LineType)1
#define        LCD_FONT_5X11               (LCD_FontType)1
#define        LCD_FONT_5X7                (LCD_FontType)0
#define        LCD_CURSOR_ON               (LCD_CursorType)1
#define        LCD_CURSOR_OFF              (LCD_CursorType)0
#define        LCD_CURSOR_BLINK_ON         (LCD_CursorBlinkType)1
#define        LCD_CURSOR_BLINK_OFF        (LCD_CursorBlinkType)0
#define        LCD_DISPLAY_ON              (LCD_DisplayType)1
#define        LCD_DISPLAY_OFF             (LCD_DisplayType)0
#define        LCD_SHIFT_ON                      1
#define        LCD_SHIFT_OFF                     0
#define        LCD_RIGHT_LEFT                    0
#define        LCD_LEFT_RIGHT                    1


#define        LCD_LINE_0_BASE_ADDRESS           0x00
#define        LCD_LINE_1_BASE_ADDRESS           0x40
#define        LCD_COL_0_INDEX                   0
#define        LCD_COL_1_INDEX                   1
#define        LCD_COL_2_INDEX                   2
#define        LCD_COL_3_INDEX                   3
#define        LCD_COL_4_INDEX                   4
#define        LCD_COL_5_INDEX                   5
#define        LCD_COL_6_INDEX                   6
#define        LCD_COL_7_INDEX                   7
#define        LCD_COL_8_INDEX                   8
#define        LCD_COL_9_INDEX                   9
#define        LCD_COL_10_INDEX                  10
#define        LCD_COL_11_INDEX                  11
#define        LCD_COL_12_INDEX                  12
#define        LCD_COL_13_INDEX                  13
#define        LCD_COL_14_INDEX                  14
#define        LCD_COL_15_INDEX                  15
/* Those command not finished, and we will ORing some bits with them to control the mode */
#define        SET_DDRM_ADDRESS_COMMAND             0x80
#define        FUNCTION_SET_COMMAND                 0x20
#define        CURSOR_OR_DISPLAY_SHIFT_COMMAND      0x10
#define        DISPLAY_ON_OFF_COMMAND               0x08
#define        ENTRY_MODE_COMMAND                   0x04
#define        RETURN_HOME_COMMAND                  0x02
#define        CLEAR_DISPLAY_COMMAND                0x01
#define        LCD_SHIFT_DISPLAY_RIGHT              0x1C
#define        LCD_SHIFT_DISPLAY_LEFT               0x18

/***************************************************************/
/*                    Functions Prototypes                     */
/***************************************************************/
void LCD_voidSendChar(uint8 u8IndexCpy,uint8 u8CommandCpy);
void LCD_voidWriteCommand(uint8 u8IndexCpy,uint8 u8CommandCpy);

void LCD_voidSendCommand(uint8 u8IndexCpy,uint8 u8CommandCpy);

void LCD_voidSendString(uint8 u8IndexCpy,uint8 *pau8CharCpy);

void LCD_voidInit(void);

void LCD_voidClrScr(uint8 u8IndexCpy);

void LCD_voidSendNumber(uint8 u8IndexCpy,uint16 u16NumberCpy);

void LCD_voidDisplayHex(uint8 u8IndexCpy,uint16 u16HexNumberCpy);

void LCD_voidMoveCursor(uint8 u8IndexCpy,uint8 u8RowCpy,uint8 u8ColCpy);
void LCD_displayStringRowColumn(uint8 u8IndexCpy,uint8 u8RowCpy,uint8 u8ColCpy,uint8 *pau8CharCpy);

void LCD_sendSpecialCharacter(uint8 u8IndexCpy,uint8 u8CharacterIndex,uint8 u8CharacterLocation,uint8 pattern);

/***************************************************************/
/*                    Extern shared Variables                  */
/***************************************************************/
extern LCD_Configuration configuration[LCD_NUMBERS];
extern LCD_PinsConfiguration pinsConfiguration[LCD_NUMBERS];

#endif
