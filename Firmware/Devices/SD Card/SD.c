#include "SD.h"


void SD_Delay(int i)
{
	int x;
	for (x = 0; x < i; ++x) {}
}

void SD_Dummy_Clock(int i)
{
	int x;
	for (x = 0; x < i; ++x) SPI_Master_TX(SPI1,0xFF);
}

void SD_PowerUPSequence(void)
{
SPI_NSS_HIGH(GPIOA);
SD_Delay(10000);
SD_Dummy_Clock(10);
SPI_NSS_HIGH(GPIOA);
SD_Dummy_Clock(1);
}

void SD_Proceed(void)
{
	SPI_NSS_LOW(GPIOA);
	SPI_Master_TX(SPI1,0xff);
	SPI_NSS_HIGH(GPIOA);
}

void SD_Send_Commands(uint8_t command, uint32_t arg, uint8_t sdCRC)
{
	SPI_Master_TX(SPI1,0xFF);
	SPI_Master_TX(SPI1,command | 0x40);
	SPI_Master_TX(SPI1,(uint8_t)(arg >> 24));
	SPI_Master_TX(SPI1,(uint8_t)(arg >> 16));
	SPI_Master_TX(SPI1,(uint8_t)(arg >> 8));
	SPI_Master_TX(SPI1,(uint8_t)arg);
	SPI_Master_TX(SPI1,sdCRC);
}


//********************************************************************************************************************************************
void SD_Init(void)
{
	char buff;
	int count;
	struct SPI_Master_Parameters sd;
	sd.Baudrate = 6;
	sd.DataFormat = Bit_8;
	sd.BiDirectional_Mode = Duplex;
	sd.CPHA = 1;
	sd.CPOL = 1;
	sd.LSBorMSB = MSB;
	sd.Slave_Management = Software_Managed;
	SPI_Master_Config(SPI1,sd);
	NSS_Pin = 4;
	SPI_NSS_Pin_Setup(GPIOA);

	//Actual Setup starts from here
do {
	SD_Dummy_Clock(8);
	SD_Send_Commands(CMD0,0x00000000,0x95);
	SD_Proceed();
	do
	{
		buff = SPI_Master_RX(SPI1);
		count++;
	} while ((buff != SD_Idle) && (count < 10));
	count = 0;
} while (buff != SD_Idle);

do {
	SD_Send_Commands(CMD1,0x00000000,0x00);
	SD_Proceed();
	do {
		buff = SPI_Master_RX(SPI1);
		count++;
	} while ((buff != 0x00) && (count < 10));
	count = 0;
} while (buff != 0x00);

}



