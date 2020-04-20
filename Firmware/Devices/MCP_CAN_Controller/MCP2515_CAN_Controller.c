#include "MCP2512_CAN_Controller.h"





void MCP2512_Init(void)
{
	MCP2512.Baudrate = 8;
	MCP2512.CPHA = 1;
	MCP2512.CPOL = 1;
	MCP2512.DataFormat = Bit_8;
	MCP2512.LSBorMSB = MSB;
	MCP2512.BiDirectional_Mode = Duplex;
	SPI_Master_Config(MCP2512);
	SPI_Master_Enable();
	NSS_Pin = 4;
	SPI_NSS_Pin_Setup();
}

uint8_t MCP2512_Read(uint8_t address)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(MCP2512_Read_INST);
	SPI_Master_TX(address);
	uint8_t data = SPI_Master_RX();
	SPI_NSS_HIGH();
	return data;
}

uint8_t MCP2512_Read_RX_Buffer(uint8_t buffer)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(buffer);
	uint8_t data = SPI_Master_RX();
	SPI_NSS_HIGH();
	return data;
}

void MCP2512_Write(uint8_t address, uint8_t data)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(MCP2512_Write_INST);
	SPI_Master_TX(address);
	SPI_Master_TX(data);
	SPI_NSS_HIGH();
}


void MCP2512_Load_TX_Buffer(uint8_t buffer, uint8_t data)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(buffer);
	SPI_Master_TX(data);
	SPI_NSS_HIGH();

}

void MCP2512_Request_To_Send(uint8_t RTS_Buffer)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(RTS_Buffer);
	SPI_NSS_HIGH();
}

void MCP2512_Bit_Modify(uint8_t rts_buffer,uint8_t address, uint8_t mask, uint8_t data)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(rts_buffer);
	SPI_Master_TX(address);
	SPI_Master_TX(mask);
	SPI_Master_TX(data);
	SPI_NSS_HIGH();
}


uint8_t MCP2512_Read_Status(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(MCP2512_Read_Status_INST);
	uint8_t data = SPI_Master_RX();
	SPI_NSS_HIGH();
	return data;
}

uint8_t MCP2512_Rx_Status(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	SPI_Master_TX(MCP2512_Rx_Status_INST);
	uint8_t data = SPI_Master_RX();
	SPI_NSS_HIGH();
	return data;
}

