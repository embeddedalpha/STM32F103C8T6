#ifndef _OLED_GRAPHICS_H_
#define _OLED_GRAPHICS_H_





#include "OLED_SPI.h"

static int graphics_buffer[length*width];


void OLED_Draw_Line(int x1, int x2, int y1, int y2, int thickness);

void OLED_Draw_Rectangle(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, int thickess, int fill_or_nofill);

void OLED_Draw_Circle(int x1, int y1, int radius, int thickness, int fill_or_nofill);












#endif

