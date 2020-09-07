#include "RFID.h"

void MFRC522_Send_Data(SPI_TypeDef *SPI, uint8_t address, uint8_t *data, int len)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(SPI,address << 1); //SEND ADDRESS (WRITE)
	for(int i =0; i< len; i++)
	{
		SPI_Master_TX(SPI,data[i]);
	}

}	
