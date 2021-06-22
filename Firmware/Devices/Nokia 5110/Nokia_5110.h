/*
 * Nokia_5110.h
 *
 *  Created on: 21-Jun-2021
 *      Author: Kunal
 */

#ifndef NOKIA_5110_NOKIA_5110_H_
#define NOKIA_5110_NOKIA_5110_H_

#include "main.h"
#include "SPI/SPI.h"
#include "Nokia_5110_Font.h"

struct SPI_Config N5110;

// 1	RST	PA8
// 2	CE	PA4
// 3	DC	PA9
// 4	DIN	PA7
// 5	CLK	PA5
// 6	VCC ~
// 7	BL	~
// 8	GND	~

#define N5110_NOP	0
#define N5110_NOP	0
#define N5110_NOP	0

void N5110_Init(SPI_TypeDef *SPI);
void N5110_Reset_High(void);
void N5110_Reset_Low(void);
void N5110_DC_High(void);
void N5110_DC_Low(void);

void N5110_Send_Command(uint8_t Command_Byte);
void N5110_Send_Data(unint8_t Data);

void N5110_Invert_Screen(void);
void N5110_Set_Pointer(uint8_t x, uint8_t y);
void N5110_Draw_Point(uint8_t x, uint8_t y);
void N5110_Printf(uint8_t x,uint8_t y, char *s);
void N5110_Screen_Clear();


#endif /* NOKIA_5110_NOKIA_5110_H_ */
