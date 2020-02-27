#ifndef _LCD_16x2_H_
#define _LCD_16x2_H_


#include "stm32f10x.h"
#include "Timer.h"

/*PA0 - PA7 === D0 - D7
  PB12 === RS
  PB13 === R/W
  PB14 === EN
*/

void LCD_Init(int bit);
void LCD_CLEAR_SCREEN(void);
void LCD_Pin_Setup(int bit);
void LCD_Write_Command(unsigned char command);
void LCD_Write_Data(char data);


#endif
