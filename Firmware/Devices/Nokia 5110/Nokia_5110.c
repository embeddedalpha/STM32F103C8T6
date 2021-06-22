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
	Delay_Config();
	N5110.SPI = SPI;
	N5110.clock_phase = 1;
	N5110.clock_polarity = 1;
	N5110.clock_speed = 0;
	N5110.frame_format = 0;
	N5110.lsb_or_msb = 0;
	SPI_Master_Init(N5110);

	N5110_Reset_High();
	Delay_ms(10);
	N5110_Reset_Low();
	Delay_ms(10);
	N5110_Reset_High();

	N5110_Send_Command((1 << 0) | (1 << 5)); //Select Extended Instruction Set
	N5110_Send_Command(0xC0); //Set Vop to 16x
	N5110_Send_Command(1 << 5); //Select Normal Instruction Set
	N5110_Send_Command((1 << 3) | (1 << 2)); //Set Display mode as Normal

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

void N5110_Send_Command(uint8_t Command_Byte)
{
	SPI_Master_SS_Select(N5110);
	N5110_DC_Low();
	SPI_Master_TX(N5110, Command_Byte);
	N5110_DC_High();
	SPI_Master_SS_Deselect(N5110);

}

void N5110_Send_Data(unint8_t Data)
{
	N5110_DC_High();
	SPI_Master_TX(N5110, Data);
	N5110_DC_Low();
}

void N5110_Send_Buffer(uint8_t *data, int length)
{
	int i;
	N5110_DC_High();

	for(i=0;i<length;i++)SPI_Master_TX(N5110, Data);

	N5110_DC_Low();
}

void N5110_Invert_Screen(void)
{
	N5110_Send_Command((1 << 3) | (1 << 2) | (1 << 0));
}

void N5110_Set_Pointer(uint8_t x, uint8_t y)
{
	N5110_Send_Command((1 << 6) | (y));
	N5110_Send_Command((1 << 7) | (x));

}

void N5110_Draw_Point(uint8_t x, uint8_t y)
{
	N5110_Set_Pointer(x, y);
	N5110_Send_Data(0x01);
}

void N5110_Printf(uint8_t x,uint8_t y, char *s)
{
	N5110_Set_Pointer(x,y);
	while(*s)
	{
		for(i = 0;i < 5; i++)
		{
			N5110_Send_Data(ASCII[s-0x20][i]);
		}
	}
}

void N5110_Screen_Clear()
{
	for (i = 0; i < (LCD_X * LCD_Y/8); i++) {
		N5110_Send_Data(0);
	}
}
