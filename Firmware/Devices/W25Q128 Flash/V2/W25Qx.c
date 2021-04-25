/*
 * W25Qx.c
 *
 *  Created on: 25-Apr-2021
 *      Author: Kunal
 */


#include "W25Qx.h"


void W25Qx_Init(SPI_TypeDef *SPI)
{
	W25Q.SPI = SPI;
	W25Q.clock_phase = 0;
	W25Q.clock_polarity = 0;
	W25Q.frame_format = 0;
	W25Q.lsb_or_msb = 0;
	SPI_Master_Init(W25Q);
}


void W25Qx_Read_Block(uint32_t address, uint8_t data[], uint32_t length)
{
	int i = 0;
	W25Qx_Select();
	SPI_Master_TX(W25Q, 0x0B);
	SPI_Master_TX(W25Q, ((address >> 16) & 0xFF));
	SPI_Master_TX(W25Q, ((address >> 8) & 0xFF));
	SPI_Master_TX(W25Q, ((address >> 0) & 0xFF));
	SPI_Master_TX(W25Q, 0xFF);
	for(i = 0 ;i <length; i++)
	{
		data[i] = SPI_Master_RX(W25Q);
	}
	W25Qx_Deselect();
}

uint8_t W25Qx_Read_Byte(uint32_t address)
{
	uint8_t temp;

	W25Qx_Select();
	SPI_Master_TX(W25Q, 0x03);	//Send Read Instruction
	SPI_Master_TX(W25Q, ((address >> 16) & 0xFF));
	SPI_Master_TX(W25Q, ((address >> 8) & 0xFF));
	SPI_Master_TX(W25Q, ((address >> 0) & 0xFF));
	temp = SPI_Master_RX(W25Q);
	W25Qx_Deselect();

	return temp;
}

void W25Qx_Write_Block(uint32_t address, uint8_t *data, uint32_t length)
{
	int i=0;
	W25Qx_Write_Enable();
	W25Qx_Select();
	SPI_Master_TX(W25Q, 0x02);	//Send Read Instruction
	SPI_Master_TX(W25Q, ((address >> 16) & 0xFF));
	SPI_Master_TX(W25Q, ((address >> 8) & 0xFF));
	SPI_Master_TX(W25Q, ((address >> 0) & 0xFF));

	for(i = 0; i< length; i++)
	{
		SPI_Master_TX(W25Q, data[i]);
	}
	W25Qx_Deselect();
	W25Qx_Write_Disable();
}

void W25Qx_Write_Byte(uint32_t address, uint8_t byte)
{
	W25Qx_Write_Enable();
	W25Qx_Select();
	SPI_Master_TX(W25Q, 0x02);	//Send Read Instruction
	SPI_Master_TX(W25Q, ((address >> 16) & 0xFF));
	SPI_Master_TX(W25Q, ((address >> 8) & 0xFF));
	SPI_Master_TX(W25Q, ((address >> 0) & 0xFF));
	SPI_Master_TX(W25Q, byte);
	W25Qx_Deselect();
	W25Qx_Write_Disable();

}

void W25Qx_Write_Enable(void)
{
	uint8_t temp;

	do{
		W25Qx_Select();
		SPI_Master_TX(W25Q, 0x06);
		W25Qx_Deselect();
		temp = W25Qx_Read_Status_Register_1();
	}while((temp & Write_Enable_Latch) == 1);

}

void W25Qx_Write_Disable(void)
{
	uint8_t temp;

	do{
		W25Qx_Select();
		SPI_Master_TX(W25Q, 0x04);
		W25Qx_Deselect();
		temp = W25Qx_Read_Status_Register_1();
	}while((temp & Write_Enable_Latch) == 0);

}


void W25Qx_Select(void)
{
	if(W25Q.SPI == SPI1)
	{
		SPI1_CSS_HIGH();
		delay1(300);
		SPI1_CSS_LOW();
		delay1(300);
	}
	else{
		SPI2_CSS_HIGH();
		delay1(300);
		SPI2_CSS_LOW();
		delay1(300);
	}
}

void W25Qx_Deselect(void)
{
	if(W25Q.SPI == SPI1)
	{
		SPI1_CSS_LOW();
		delay1(300);
		SPI1_CSS_HIGH();
		delay1(300);
	}
	else{
		SPI2_CSS_LOW();
		delay1(300);
		SPI2_CSS_HIGH();
		delay1(300);
	}
}

uint8_t W25Qx_Read_Status_Register_1(void)
{
	uint8_t temp;
	W25Qx_Select();
	SPI_Master_TX(W25Q, 0x05);
	temp = SPI_Master_RX(W25Q);
	W25Qx_Deselect();
	return temp;
}


uint8_t W25Qx_Read_Status_Register_2(void)
{
	uint8_t temp;
	W25Qx_Select();
	SPI_Master_TX(W25Q, 0x35);
	temp = SPI_Master_RX(W25Q);
	W25Qx_Deselect();
	return temp;
}

void W25Qx_Block_Erase_64KB(void)
{
	W25Qx_Write_Enable();
	W25Qx_Select();
	SPI_Master_TX(W25Q, 0xD8);
	SPI_Master_TX(W25Q, ((address >> 16) & 0xFF));
	SPI_Master_TX(W25Q, ((address >> 8) & 0xFF));
	SPI_Master_TX(W25Q, ((address >> 0) & 0xFF));
	W25Qx_Deselect();
	W25Qx_Write_Disable();

}

void W25Qx_Block_Erase_32KB(void)
{
	W25Qx_Write_Enable();
	W25Qx_Select();
	SPI_Master_TX(W25Q, 0x52);
	SPI_Master_TX(W25Q, ((address >> 16) & 0xFF));
	SPI_Master_TX(W25Q, ((address >> 8) & 0xFF));
	SPI_Master_TX(W25Q, ((address >> 0) & 0xFF));
	W25Qx_Deselect();
	W25Qx_Write_Disable();

}

void W25Qx_Block_Erase_4KB(void)
{
	W25Qx_Write_Enable();
	W25Qx_Select();
	SPI_Master_TX(W25Q, 0x20);
	SPI_Master_TX(W25Q, ((address >> 16) & 0xFF));
	SPI_Master_TX(W25Q, ((address >> 8) & 0xFF));
	SPI_Master_TX(W25Q, ((address >> 0) & 0xFF));
	W25Qx_Deselect();
	W25Qx_Write_Disable();

}

void W25Qx_Chip_Erase(void)
{
	W25Qx_Write_Enable();
	W25Qx_Select();
	SPI_Master_TX(W25Q, 0xC7);
	W25Qx_Deselect();
	W25Qx_Write_Disable();

}

void W25Qx_Power_Down(void)
{
	W25Qx_Write_Enable();
	W25Qx_Select();
	SPI_Master_TX(W25Q, 0xB9);
	W25Qx_Deselect();
	W25Qx_Write_Disable();
}

void W25Qx_Memory_Protect(void)
{
	W25Qx_Write_Enable();
	W25Qx_Select();
	SPI_Master_TX(W25Q, 0x01);
	SPI_Master_TX(W25Q, 0x9C);
	SPI_Master_TX(W25Q, 0x01);
	W25Qx_Deselect();
	W25Qx_Write_Disable();

}
