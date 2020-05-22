#include "W25QxxFLASH.h"



void W25Qx_Init(void)
{

RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_SPI1EN;
RCC -> AHBENR |= RCC_AHBENR_DMA1EN;

GPIOA -> CRL |= (ALT_PUSH_PULL_OUTPUT << (4*5)) | (ALT_PUSH_PULL_OUTPUT << (4*7));
GPIOA -> CRL |= (GEN_PUSH_PULL_OUTPUT << (4*4));
GPIOA -> CRL |= (FLOATING_INPUT << (4*6));

struct SPI_Master_Parameters flash;
flash.Baudrate = 4;
flash.CPHA = 1;
flash.CPOL = 1;
flash.DataFormat = Bit_8;
flash.LSBorMSB = MSB;
flash.Slave_Management = Software_Managed;
flash.TxDMA = ENABLE;
flash.RxDMA = ENABLE;

SPI_Master_Config(SPI1,flash);
SPI_Master_Enable(SPI1);

//SPI DMA TX
DMA1_Channel3->CPAR = SPI1->DR;
DMA1_Channel3->CCR = (3 << 12) | (2 << 8) | (2 << 10)  | (1 << 4) | (1 << 7) | (1 << 1);

//SPI DMA RX
DMA1_Channel2->CPAR = SPI1->DR;
DMA1_Channel2->CMAR = RXptr;
DMA1_Channel2->CCR = (3 << 12) | (2 << 8) | (2 << 10)   | (1 << 7) | (1 << 4) | (1 << 1);

}

void W25Qx_Flash_Select(void)
{
	GPIOA->BSRR |= GPIO_BSRR_BS4;
	GPIOA->BSRR &= ~GPIO_BSRR_BS4;
}

void W25Qx_Flash_Deselect(void)
{
	GPIOA->BSRR |= GPIO_BSRR_BS4;
}

uint8_t W25Qx_Write_Flash(uint32_t address,int length)
{
W25Qx_Flash_Select();
SPI_Master_TX(SPI1,0x06);
W25Qx_Flash_Deselect();
DMA1_Channel3->CMAR = &flash_data_TX;
DMA1_Channel3->CNDTR = length;
W25Qx_Flash_Select();
SPI_Master_TX(SPI1,0x02);
SPI_Master_TX(SPI1,((address & 0x00ff0000) >> 16));
SPI_Master_TX(SPI1,((address & 0x0000ff00) >> 8));
SPI_Master_TX(SPI1,((address & 0x000000ff) >> 0));
DMA1_Channel3->CCR |= 1<< 0;
while(!(DMA1->ISR & DMA_ISR_TCIF3)){}
DMA1_Channel3->CCR &= ~(1<< 0);
W25Qx_Flash_Deselect();
return 1;
}

uint8_t W25Qx_Read_Flash(uint32_t address, int length)
{
	for(int i = 0 ; i < length; i++)
	{
		flash_data_TX[i] = 0xAA;
	}
	DMA1_Channel2->CMAR = &flash_data_RX;
	DMA1_Channel2->CNDTR = length;
	DMA1_Channel3->CMAR = &flash_data_TX;
	DMA1_Channel3->CNDTR = length;
	W25Qx_Flash_Select();
	SPI_Master_TX(SPI1,0x03);
	SPI_Master_TX(SPI1,((address & 0x00ff0000) >> 16));
	SPI_Master_TX(SPI1,((address & 0x0000ff00) >> 8));
	SPI_Master_TX(SPI1,((address & 0x000000ff) >> 0));
	DMA1_Channel2->CCR |= 1<< 0;
	DMA1_Channel3->CCR |= 1<< 0;
	while(!(DMA1->ISR & DMA_ISR_TCIF2)){}
	W25Qx_Flash_Deselect();
	return 1;
}

void W25Qx_Sector_Erase(uint32_t address)
{
	W25Qx_Flash_Select();
	SPI_Master_TX(SPI1,0x06);
	W25Qx_Flash_Deselect();
	W25Qx_Flash_Select();
	SPI_Master_TX(SPI1,0x20);
	SPI_Master_TX(SPI1,((address & 0x00ff0000) >> 16));
	SPI_Master_TX(SPI1,((address & 0x0000ff00) >> 8));
	SPI_Master_TX(SPI1,((address & 0x000000ff) >> 0));
	W25Qx_Flash_Deselect();

}

void W25Qx_Sector_Erase_32KB(uint32_t address)
{
	W25Qx_Flash_Select();
	SPI_Master_TX(SPI1,0x52);
	W25Qx_Flash_Deselect();
	W25Qx_Flash_Select();
	SPI_Master_TX(SPI1,0x20);
	SPI_Master_TX(SPI1,((address & 0x00ff0000) >> 16));
	SPI_Master_TX(SPI1,((address & 0x0000ff00) >> 8));
	SPI_Master_TX(SPI1,((address & 0x000000ff) >> 0));
	W25Qx_Flash_Deselect();
}

void W25Qx_Sector_Erase_64KB(uint32_t address)
{
	W25Qx_Flash_Select();
	SPI_Master_TX(SPI1,0xD8);
	W25Qx_Flash_Deselect();
	W25Qx_Flash_Select();
	SPI_Master_TX(SPI1,0x20);
	SPI_Master_TX(SPI1,((address & 0x00ff0000) >> 16));
	SPI_Master_TX(SPI1,((address & 0x0000ff00) >> 8));
	SPI_Master_TX(SPI1,((address & 0x000000ff) >> 0));
	W25Qx_Flash_Deselect();
}

void W25Qx_Chip_Erase(void)
{
	W25Qx_Flash_Select();
	SPI_Master_TX(SPI1,0x06);
	W25Qx_Flash_Deselect();
	W25Qx_Flash_Select();
	SPI_Master_TX(SPI1,0xC7);
	W25Qx_Flash_Deselect();
}

void W25Qx_Power_Down(void)
{
	W25Qx_Flash_Select();
	SPI_Master_TX(SPI1,0xB9);
	W25Qx_Flash_Deselect();
}

void W25Qx_Power_Down_Release(void)
{
	W25Qx_Flash_Select();
	SPI_Master_TX(SPI1,0xB9);
	W25Qx_Flash_Deselect();
}

uint8_t W25Qx_Read_Device_ID(void)
{
	W25Qx_Flash_Select();
	SPI_Master_TX(SPI1,0x90);
	SPI_Master_TX(SPI1,0x00);
	SPI_Master_TX(SPI1,0x00);
	SPI_Master_TX(SPI1,0x00);
	uint8_t mauf_id = SPI_Master_RX();
	uint8_t device_id = SPI_Master_RX();
	W25Qx_Flash_Deselect();
	return device_id;
}

uint8_t W25Qx_Read_Unique_ID(void)
{
	W25Qx_Flash_Select();
	SPI_Master_TX(SPI1,0x4B);
	SPI_Master_TX(SPI1,0x00);
	SPI_Master_TX(SPI1,0x00);
	SPI_Master_TX(SPI1,0x00);
	uint8_t uique_id = SPI_Master_RX();
	W25Qx_Flash_Deselect();
	return uique_id;
}

uint8_t W25Qx_Read_JEDEC_ID(void)
{
	W25Qx_Flash_Select();
	SPI_Master_TX(SPI1,0x9F);
	uint8_t jedec_id = SPI_Master_RX();
	W25Qx_Flash_Deselect();
	return jedec_id;
}

void W25Qx_Write_Flash_Bulk(uint32_t address)
{
	int length = sizeof(data)/sizeof(data[0]);
	int increment = length / 256;
	int remaining = length - (256 + ((increment -1)*256));
	int counter = length - remaining;

	for(int i = 0; i<increment; i++)
		{
			for(int j = 0; j < 256; j++){
				flash_data_TX[j] = data[j + (i*256)];
			}
			 W25Qx_Write_Flash((address + (i*256)),255);
		}
	for(int k = 0; k<remaining; k++)
	{
		flash_data_TX[k] = data[counter+k];
		W25Qx_Write_Flash(address  +(i*remaining),remaining);
	}

}

