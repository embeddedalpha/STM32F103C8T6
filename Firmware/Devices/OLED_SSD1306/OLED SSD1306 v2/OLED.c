/*
 * OLED.c
 *
 *  Created on: 08-Jun-2021
 *  Updated on: 08-Jun-2021
 *      Author: Kunal
 */


#include "OLED.h"



void OLED_Command_n_Data(uint8_t cmd, uint8_t data)
{
	I2C_Master_Start(OLED);
	I2C_Master_Send_Address(OLED, OLED_Address, write);
	I2C_Master_Send_Data(OLED, command_byte);
	I2C_Master_Send_Data(OLED, cmd);
	I2C_Master_Send_Data(OLED, data);
	I2C_Master_Stop(OLED);
}

void OLED_Command(uint8_t cmd)
{
	I2C_Master_Start(OLED);
	I2C_Master_Send_Address(OLED, OLED_Address, write);
	I2C_Master_Send_Data(OLED, command_byte);
	I2C_Master_Send_Data(OLED, cmd);
	I2C_Master_Stop(OLED);
}

void OLED_Send_Data(uint8_t data)
{
	I2C_Master_Start(OLED);
	I2C_Master_Send_Address(OLED, OLED_Address, write);
	I2C_Master_Send_Data(OLED, data_byte);
	I2C_Master_Send_Data(OLED, data);
	I2C_Master_Stop(OLED);
}

void OLED_Init(I2C_TypeDef *I2C, uint8_t screen_size)
{
	OLED.I2C = I2C;
	OLED.mode = Fast_Mode;
	I2C_Master_Init(OLED);

	OLED_Command_n_Data(0xA8, 0x3F);
	OLED_Command_n_Data(0xD3, 0x00);
	OLED_Command(0x40);
	OLED_Command(0xA0);
	OLED_Command(0xC0);
	if(screen_size == screen_128_64)OLED_Command_n_Data(0xDA, 0x02);
	if(screen_size == screen_64_32)OLED_Command_n_Data(0xDA, 0x22);
	OLED_Command_n_Data(0x81, 0x7F);
	OLED_Command(0xA4);
	OLED_Command(0xA6);
	OLED_Command_n_Data(0xD5, 0x80);
	OLED_Command_n_Data(0x8D, 0x14);
	OLED_Command(0xAF);
}

void OLED_Set_Cursor(uint8_t x, uint8_t y)
{
	OLED_Command(0x00 + (0x0F & x));
	OLED_Command(0x10 + (0x0F & x) >> 4);
	OLED_Command(0xB0 + y);

}

void OLED_Blank(void)
{
	int i,j;
	OLED_Set_Cursor(0, 0);
	for(i = 0; i<8; i++)
	{
		for(j = 0; j < 128; j++)
		{
			OLED_Send_Data(0x00);
		}
	}
	OLED_Set_Cursor(0, 0);
}


void OLED_Print(uint8_t x,uint8_t y,char buf)
{
	OLED_Set_Cursor(x, y);
	int i, j ;
	i = 0;

	while(buf[i])
	{
		for(j = 0; j < 5; j++)
		{
			OLED_Send_Data(buf[i]);
		}
		i++;
	}
}

