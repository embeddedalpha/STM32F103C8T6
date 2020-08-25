#ifndef  _ILI9341_H_
#define  _ILI9341_H_

#include "stm32f10x.h"
#include "SPI.h"

//	D/CX -> 1 data & 0 command

// 4 wire 8 - bit data serial IM[3:0] 1110



//https://cdn-shop.adafruit.com/datasheets/ILI9341.pdf


void ILI9341_Display_Init();

void ILI9341_NOP(void);









#endif

