/*
 * Nokia_5110.c
 *
 *  Created on: 21-Jun-2021
 *      Author: Kunal
 */

// 1	RST	PA8
// 2	CE	PA4
// 3	DC	PA9
// 4	DIN	PA7
// 5	CLK	PA5
// 6	VCC ~
// 7	BL	~
// 8	GND	~

#include "Nokia_5110.h"


void N5110_Init(SPI_TypeDef *SPI)
{
	N5110.SPI = SPI;
	N5110.clock_phase = 1;
	N5110.clock_polarity = 1;
	N5110.clock_speed = 0;
	N5110.frame_format = 0;
	N5110.lsb_or_msb = 0;
	SPI_Master_Init(N5110);

}

void N5110_Reset_High(void)
{
	GPIOA->BSRR |= GPIO_BSRR_BS8;
}

void N5110_Reset_Low(void)
{
	GPIO->BRR |= GPIO_BRR_BR8;
}

void N5110_DC_High(void)
{
	GPIOA->BSRR |= GPIO_BSRR_BS9;
}

void N5110_DC_Low(void)
{
	GPIOA->BRR |= GPIO_BRR_BR9;
}

void N5110_Send_Command(uint8_t Command_Byte, uint8_t Data_Byte)
{}

void N5110_Send_Data(unint8_t Data)
{}

void N5110_Invert_Screen(void)
{}

void N5100_Set_Pointer(uint8_t x, uint8_t y)
{}

void N5110_Draw_Point(uint8_t x, uint8_t y)
{}

void N5110_Printf(uint8_t x,uint8_t y, char *s)
{}
