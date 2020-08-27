#ifndef  _ILI9341_H_
#define  _ILI9341_H_

#include "stm32f10x.h"
#include "SPI.h"

//	D/CX -> 1 data & 0 command

// 4 wire 8 - bit data serial IM[3:0] 1110



//https://cdn-shop.adafruit.com/datasheets/ILI9341.pdf


#define Display_Width  360
#define Display_Height 240



/*
 * USER ASSESSIBLE DATA
 */

void ILI9341_Display_Init();

void ILI9341_Display_Inversion_OFF(void);
void ILI9341_Display_Inversion_ON(void);

void ILI9341_Display_OFF(void);
void ILI9341_Display_ON(void);

void ILI9341_Reset_Low(void);
void ILI9341_Reset_High(void);

void ILI9341_Define_Window(uint16_t X1, uint16_t Y1, uint16_t W, uint16_t H);
void ILI9341_Draw_Pixel(uint16_t x, uint16_t y, uint16_t* color);
void ILI9341_Write_Display_Brightness(uint8_t brightness);

void ILI9341_Display_Inversion_ON(void);
void ILI9341_Display_Inversion_OFF(void);







#endif
