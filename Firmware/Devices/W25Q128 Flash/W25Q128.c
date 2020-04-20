#include "W25Q128.h"





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

/***********************************************************************************/


void W25Q128_Write_Status_Register(uint8_t reg, uint8_t data)
{
	//Send Write Enable
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Write_Enable);
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(reg);
	SPI_Master_TX(data);
	SPI_NSS_HIGH();
}

void W25Q128_Page_Write(int data[256], int length, uint32_t address)
{
	uint8_t status, busy, wel;
	uint8_t A23_16 = (0x00FF0000 & address) >> 16;
	uint8_t A15_08 = (0x0000FF00 & address) >> 8;
	uint8_t A07_00 = (0x00000000 & address) >> 0;
	//Send Write Enable
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Write_Enable);
	SPI_NSS_HIGH();
	//Check Status Register for WEL Bit
	SPI_NSS_LOW();
	SPI_Master_TX(Read_Status_Register_1);
	do{
			 status = W25Q128_Read_Status_Register_1();
			 busy = 0x02 & status;
		}while( wel != 0);
	SPI_NSS_HIGH();
	//Start Page Program
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
	//Check Status Register for BUSY Bit
	do{
		 status = W25Q128_Read_Status_Register_1();
		 busy = 0x01 & status;
	}while( busy != 0);
}


void W25Q128_Write(int data[256], int length, uint32_t address)
{
	uint8_t status, busy, wel;
	uint8_t A23_16 = (0x00FF0000 & address) >> 16;
	uint8_t A15_08 = (0x0000FF00 & address) >> 8;
	uint8_t A07_00 = (0x000000FF & address) >> 0;
	//Send Write Enable
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Write_Enable);
	SPI_NSS_HIGH();
	//Check Status Register for WEL Bit
	SPI_NSS_LOW();
	SPI_Master_TX(Read_Status_Register_1);
	do{
				status = W25Q128_Read_Status_Register_1();
				busy = 0x02 & status;
	   }while( wel != 0);
	SPI_NSS_HIGH();
	//Start Page Program
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
	//Check Status Register for BUSY Bit
	do{
		 status = W25Q128_Read_Status_Register_1();
		 busy = 0x01 & status;
	}while( busy != 0);
}


/***********************************************************************************/

uint8_t W25Q128_Read_Status_Register_1(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Read_Status_Register_1);
	uint8_t status = SPI_Master_RX();
	SPI_NSS_HIGH();
	return status;
}

uint8_t W25Q128_Read_Status_Register_2(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Read_Status_Register_2);
	uint8_t status = SPI_Master_RX();
	SPI_NSS_HIGH();
	return status;
}

uint8_t W25Q128_Read_Status_Register_3(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Read_Status_Register_3);
	uint8_t status = SPI_Master_RX();
	SPI_NSS_HIGH();
	return status;
}

/**********************************************************************************/


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
	uint8_t status, busy;
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
	do{
		 status = W25Q128_Read_Status_Register_1();
		 busy = 0x01 & status;
	}while( busy != 0);
}

/***********************************************************************************/


void W25Q128_Reset_Device(void)
{
	uint8_t status_1, status_2,busy, sus;
	do{
		 status_1 = W25Q128_Read_Status_Register_1();
		 status_2 = W25Q128_Read_Status_Register_2();
		 busy = 0x01 & status_1;
		 sus = 0x80 & status_2;
	}while( (busy != 0) & (sus != 0));
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Enable_Reset);
	SPI_Master_TX(Reset_Device);
	SPI_NSS_HIGH();


}

void W25Q128_Global_Block_Sector_Lock(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Write_Enable);
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Global_Block_Lock);
	SPI_NSS_HIGH();

}


void W25Q128_Global_Block_Sector_Unlock(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Write_Enable);
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(Global_Block_Unlock);
	SPI_NSS_HIGH();

}

