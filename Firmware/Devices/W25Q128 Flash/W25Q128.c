#include "W25Q128.h"

uint8_t W25Q128_Read_Status_Register_1(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Read_Status_Register_1);
	uint8_t status = SPI_Master_RX();
	return status;
}

void W25Q128_Chip_Erase(void)
{
	uint8_t status, busy;
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Write_Enable);
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Chip_Erase);
	SPI_NSS_LOW();
	do{
		 status = W25Q128_Read_Status_Register_1();
		 busy = 0x01 & status;
	}while( busy != 0);
}


void W25Q128_Erase_4KB_Sector(uint32_t address)
{
	uint8_t status, busy;
	uint8_t A23_16 = (0x00FF0000 & address) >> 16;
	uint8_t A15_08 = (0x0000FF00 & address) >> 8;
	uint8_t A07_00 = (0x000000FF & address) >> 0;
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Write_Enable);
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Sector_Erase_4KB);
	SPI_Master_TX(A23_16);
	SPI_Master_TX(A15_08);
	SPI_Master_TX(A07_00);
	SPI_NSS_HIGH();
	do{
		 status = W25Q128_Read_Status_Register_1();
		 busy = 0x01 & status;
	}while( busy != 0);
}

void W25Q128_Erase_32KB_Block(uint32_t address)
{
	uint8_t status, busy;
	uint8_t A23_16 = (0x00FF0000 & address) >> 16;
	uint8_t A15_08 = (0x0000FF00 & address) >> 8;
	uint8_t A07_00 = (0x000000FF & address) >> 0;
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Write_Enable);
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Block_Erase_32KB);
	SPI_Master_TX(A23_16);
	SPI_Master_TX(A15_08);
	SPI_Master_TX(A07_00);
	SPI_NSS_HIGH();
	do{
		 status = W25Q128_Read_Status_Register_1();
		 busy = 0x01 & status;
	}while( busy != 0);

}


void W25Q128_Erase_64KB_Block(uint32_t address)
{
	uint8_t A23_16 = (0x00FF0000 & address) >> 16;
	uint8_t A15_08 = (0x0000FF00 & address) >> 8;
	uint8_t A07_00 = (0x000000FF & address) >> 0;
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Write_Enable);
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Block_Erase_64KB);
	SPI_Master_TX(A23_16);
	SPI_Master_TX(A15_08);
	SPI_Master_TX(A07_00);
	SPI_NSS_HIGH();
}

void W25Q128_Write(int data[256], int length, uint32_t address)
{
	uint8_t A23_16 = (0x00FF0000 & address) >> 16;
	uint8_t A15_08 = (0x0000FF00 & address) >> 8;
	uint8_t A07_00 = (0x000000FF & address) >> 0;
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Write_Enable);
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Page_Program);
	SPI_Master_TX(A23_16);
	SPI_Master_TX(A15_08);
	SPI_Master_TX(A07_00);
	for(int i = 0 ; i <= length; i++)
	{
		SPI_Master_TX(data[i]);
	}
	SPI_NSS_HIGH();
}

void W25Q128_Page_Write(int data[256], int length, uint32_t address)
{
	uint8_t A23_16 = (0x00FF0000 & address) >> 16;
	uint8_t A15_08 = (0x0000FF00 & address) >> 8;
	uint8_t A07_00 = (0x00000000 & address) >> 0;
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Write_Enable);
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Page_Program);
	SPI_Master_TX(A23_16);
	SPI_Master_TX(A15_08);
	SPI_Master_TX(A07_00);
	for(int i = 0 ; i <= length; i++)
	{
		SPI_Master_TX(data[i]);
	}
	SPI_NSS_HIGH();
}

void W25Q128_Init()
{
	W25Q128.Baudrate = 8;
	W25Q128.CPHA = 1;
	W25Q128.CPOL = 1;
	W25Q128.DataFormat = Bit_8;
	W25Q128.LSBorMSB = LSB;
	W25Q128.BiDirectional_Mode = Duplex;
	SPI_Master_Config(W25Q128);
	SPI_Master_Enable();

}
