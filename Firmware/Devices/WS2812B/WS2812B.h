#ifndef _WS2812B_H_
#define _WS2812B_H_




#include "stm32f10x.h"
#include "TIMER.h"


void WS2812B_Init();
void RGB_Reset();
void WS2812B_RGB(uint8_t red, uint8_t green, uint8_t blue);
void RGB_One();
void RGB_Zero();





#endif

