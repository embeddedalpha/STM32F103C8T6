#include "MCP2515_CAN_Controller.h"



uint8_t MCP_Read_Instruction(uint8_t address)
{
	int data[] = { MCP_READ, address};
	 SPI1_NSS_HIGH();//NSS HIGH
	 SPI1_NSS_LOW();//NSS LOW
	 SPI_Send_Data(SPI1, data);//SEND MCP_READ & ADDRESS
	return (uint8_t)(spi -> DR);//RETURN DATA

}
//

void MCP_Write_Byte_Instruction(uint8_t address, uint8_t data)
{
int d[] = {MCP_WRITE,address, data};
 SPI1_NSS_HIGH();//NSS HIGH
	 SPI1_NSS_LOW();//NSS LOW
SPI_Send_Data(SPI1, d); //send data
 SPI1_NSS_HIGH();//NSS HIGH

}
	//
	
void MCP_Load_TX_Buff_1(){}
	//
	
	void MCP_Request_to_Send()
	{
		 SPI1_NSS_HIGH();//NSS HIGH
	 SPI1_NSS_LOW();//NSS LOW
		spi -> DR = MCP_RTS | (1 << 0);
		spi -> DR = MCP_RTS | (1 << 1);
		spi -> DR = MCP_RTS | (1 << 2);
		SPI1_NSS_HIGH();//NSS HIGH
	}
	//
	
	void MCP_Bit_Modify_Instruction(uint8_t address, uint8_t mask_byte, uint8_t data_byte)
	{
	int data[] = {MCP_BIT_MODIFY, address, mask_byte, data_byte};
			 SPI1_NSS_HIGH();//NSS HIGH
	 SPI1_NSS_LOW();//NSS LOW
	SPI_Send_Data(spi,data);
	SPI1_NSS_HIGH();//NSS HIGH
	
	}
	//
	
	void MCP_Transmit_Buffer_0(uint8_t data)
	{
	int flag;
		flag = MCP_Read_Instruction(TXB_1_CTRL);
		while((flag & 0x04) != 1)
		{
		flag = MCP_Read_Instruction(TXB_1_CTRL);
		}
		MCP_Bit_Modify_Instruction(TXB_1_CTRL, 0x0f, 0x00);
		
	
	}
	//
	
	uint16_t MCP_Read_Status_Instruction(void)
	{
	uint16_t status = 0;
		
		int data[] = {MCP_READ_STATUS};
		SPI1_NSS_HIGH();
		SPI1_NSS_LOW();
		SPI_Send_Data(SPI1, data);
		status = SPI1 ->DR << 8;
		status = SPI1 ->DR;
		SPI1_NSS_HIGH();
		
	
	return status;
	}
	//
	
	
	void MCP_Standard_Frame(uint8_t priority, uint16_t identifier, uint8_t data_length, uint8_t data[], uint16_t crc)
	{
	uint8_t flag = MCP_Read_Instruction(TXB_1_CTRL);
		while( flag & 0x08)
		{
		flag = MCP_Read_Instruction(TXB_1_CTRL);
		}
		
		MCP_Bit_Modify_Instruction(TXB_1_CTRL, 0x70, 0x00);
		
		MCP_Bit_Modify_Instruction(TXB_1_CTRL, 0x08, 0x08);
		
		MCP_Request_to_Send();
		
		MCP_Bit_Modify_Instruction(TXRTSCTRL, 0x08, 0x00);
		
		flag = MCP_Read_Instruction(TXB_1_CTRL);
		while( flag & 0x40)
		{
		flag = MCP_Read_Instruction(TXB_1_CTRL);
			
					MCP_Bit_Modify_Instruction(TXB_1_CTRL, 0x08, 0x08);
		
		MCP_Request_to_Send();
		
		MCP_Bit_Modify_Instruction(TXRTSCTRL, 0x08, 0x00);
		}
		
		if(priority == 0) MCP_Bit_Modify_Instruction(TXB_1_CTRL, 0x03, 0x00);
		if(priority == 1) MCP_Bit_Modify_Instruction(TXB_1_CTRL, 0x03, 0x01);
		if(priority == 2) MCP_Bit_Modify_Instruction(TXB_1_CTRL, 0x03, 0x02);
		if(priority == 3) MCP_Bit_Modify_Instruction(TXB_1_CTRL, 0x03, 0x03);		
		
		uint8_t mask = identifier & 7 ; 
		MCP_Bit_Modify_Instruction(TXB_1_SIDL, 0xe0, mask << 5);
		
		MCP_Write_Byte_Instruction(TXB_1_SIDH, identifier >> 3);
		
		MCP_Write_Byte_Instruction(TXB_1_DLC, data_length);
		
		
		
		
	}		
