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
void ILI9341_Display_Inversion_ON(void);
void ILI9341_Display_Inversion_OFF(void);
void ILI9341_Define_Window(uint16_t X1, uint16_t Y1, uint16_t W, uint16_t H);
uint32_t ILI9341_Set_Cursor(uint16_t x, uint16_t y );
void ILI9341_Get_Cursor(void);
void ILI9341_Draw_Pixel(uint16_t x, uint16_t y, uint16_t* color);
void ILI9341_Write_Display_Brightness(uint8_t brightness);
void ILI9341_Draw_Line(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2, uint16_t color );
void ILI9341_Draw_Rectangle(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2, uint16_t color);
void ILI9341_Draw_Rectangle_Filled(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2, uint16_t color);
void ILI9341_Draw_Circle(uint16_t x, uint16_t y, uint16_t radius, uint16_t color );
void ILI9341_Draw_Circle_Filled(uint16_t x, uint16_t y, uint16_t radius, uint16_t color );


void ILI9341_Print_Characters(char *c, uint16_t color);
void ILI9341_Print_Numbers(uint16_t *n,uint8_t font, uint16_t color);

void ILI9341_Draw_Image(uint16_t x, uint16_t y, uint16_t *data);
void ILI9341_Vertical_Scroll(uint16_t x, uint16_t y, uint16_t BottomFixedArea );
void ILI9341_Horizontal_Scroll(uint16_t x, uint16_t y, uint16_t color);
void ILI9341_Tearing_Effect();
void ILI9341_Paint_Screen(uint16_t color);







#endif
