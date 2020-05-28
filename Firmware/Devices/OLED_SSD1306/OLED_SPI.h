#ifndef _OLED_SPI_H_
#define _OLED_SPI_H_



#include "stm32f10x.h"
#include "SPI.h"
#include "board.h"
#include "OLED_Font.h"
#include "OLED_Graphics.h"


#define Vertical_and_Right_Horizontal_Scroll 0
#define Vertical_and_Left_Horizontal_Scroll 1


static int length;
static int width;

//PA7          MOSI
//PA5          SCK1
//PA4          NSS
//PA3          D/C
//PA2          RESET


void OLED_Init(void);
void OLED_Vertical_Horizontal_Scroll(int scroll, int start_page, int end_page);
void OLED_Scroll_Activate(void);
void OLED_Scroll_Deactivate(void);
void OLED_Send_Data(int* data, int length);
void OLED_Printf(uint8_t *letter);
void OLED_DisplayChar(uint8_t ch);

void OLED_Command(int command, int data);
void OLED_Single_Command( int data);
void OLED_DC_LOW(void);
void OLED_DC_HIGH(void);
void OLED_RESET_LOW(void);
void OLED_RESET_HIGH(void);







#endif
