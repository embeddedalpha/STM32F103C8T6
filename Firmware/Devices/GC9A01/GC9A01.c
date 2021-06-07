/*
 * GC9A01_I2C.c
 *
 *  Created on: 04-Jun-2021
 *  Updated on: 05-Jun-2021
 *      Author: Kunal
 */


#include "GC9A01.h"


void GC9A01_DC_Low(void)
{
	GPIOA->BRR |= GPIO_BRR_BR3;
}
void GC9A01_DC_High(void)
{
	GPIOA->BSRR |= GPIO_BSRR_BR3;
}
void GC9A01_RS_Low(void)
{
	GPIOB->BRR |= GPIO_BRR_BR0;
}
void GC9A01_RS_High(void)
{
	GPIOB->BSRR |= GPIO_BSRR_BR0;
}

void GC9A01_Init(SPI_TypeDef *SPI)
{

	uint8_t data[3];
	Delay_Config();
	GPIO_Pin_Setup(GPIOA, 3, GEN_PUSH_PULL_OUTPUT);
	GPIO_Pin_Setup(GPIOB, 0, GEN_PUSH_PULL_OUTPUT);
	SPI_Master_SS_Deselect(GC9A01);
	GC9A01.SPI = SPI;
	GC9A01.clock_phase = 1;
	GC9A01.clock_polarity = 1;
	GC9A01.frame_format = 0;
	GC9A01.lsb_or_msb = 0;
	SPI_Master_Init(GC9A01);
	SPI_Master_SS_Select(GC9A01);
	Delay_ms(5);
	GC9A01_RS_Low();
	Delay_ms(10);
	GC9A01_RS_High();
	Delay_ms(120);

	GC9A01_Send_Command(0xEF, 0);
	GC9A01_Send_Command(0xEB, 0x14);
	GC9A01_Send_Command(0x84, 0x40);
	GC9A01_Send_Command(0x86, 0xFF);
	GC9A01_Send_Command(0x87, 0xFF);
	GC9A01_Send_Command(0x88, 0x0a);
	GC9A01_Send_Command(0x89, 0x21);
	GC9A01_Send_Command(0x8a, 0x00);
	GC9A01_Send_Command(0x8b, 0x80);
	GC9A01_Send_Command(0x8c, 0x01);
	GC9A01_Send_Command(0x8d, 0x01);
	GC9A01_Send_Command(0x8e, 0xFF);
	GC9A01_Send_Command(0x8f, 0xFF);

	GC9A01_Send_Command(0xB6, 0x00);
	GC9A01_Send_Command(0x36, 0x48);
	GC9A01_Send_Command(0x3A, 0x05);

	data[0] = 0x08;
	data[1] = 0x08;
	data[2] = 0x08;

	GC9A01_Send_Command(0x90, 0x08);
	GC9A01_Send_Buffer_Data(data, 3);

	GC9A01_Send_Command(0xBD, 0x06);
	GC9A01_Send_Command(0xBC, 0x00);

	GC9A01_Send_Command(0xFF, 0x60);
	data[0] = 0x01;
	data[1] = 0x04;
	GC9A01_Send_Buffer_Data(data, 2);

	GC9A01_Send_Command(0xC3, 0x13);
	GC9A01_Send_Command(0xC4, 0x13);
	GC9A01_Send_Command(0xC9, 0x22);
	GC9A01_Send_Command(0xBE, 0x11);



}

void GC9A01_Send_Command(uint8_t command, uint8_t data)
{
	SPI_Master_SS_Deselect(GC9A01);
	SPI_Master_SS_Select(GC9A01);
	GC9A01_DC_Low();
	SPI_Master_TX(GC9A01, command);
	SPI_Master_SS_Deselect(GC9A01);
	SPI_Master_SS_Select(GC9A01);
	GC9A01_DC_High();
	SPI_Master_TX(GC9A01, data);
	SPI_Master_SS_Deselect(GC9A01);

}

void GC9A01_Send_Buffer_Data(uint8_t *buffer, int length)
{

}
