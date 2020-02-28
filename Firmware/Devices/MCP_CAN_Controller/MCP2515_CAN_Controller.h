#ifndef _MCP2515_
#define _MCP2515_

#include "stm32f10x.h"
#include "SPI.h"

static SPI_TypeDef *spi;

struct MCP_Standard_Frame
{
uint16_t identifier;
uint16_t dlc;
uint16_t data0, data1, data2, data3, 
         data4, data5, data6, data6;
         
};

uint8_t MCP_Read_Instruction(uint8_t address);
void MCP_Write_Byte_Instruction(uint8_t address, uint8_t data);
void MCP_Load_TX_Buff_1();
void MCP_Bit_Modify_Instruction(uint8_t address, uint8_t mask_byte, uint8_t data_byte);
void MCP_Transmit_Buffer_0(uint8_t data);
uint16_t MCP_Read_Status_Instruction(void);




// SPI Instruction Set
#define MCP_RESET 					0xC0 //Reset internal registers
#define MCP_READ						0x03 //Read data from the register at selected address
#define MCP_READ_RX_BUFFER_0	0x90 //When reading a receive buffer, reduces the overhead of a normal READ
#define MCP_READ_RX_BUFFER_1	0x90
#define MCP_READ_RX_BUFFER_2	0x90
#define MCP_READ_RX_BUFFER_3	0x90
#define MCP_WRITE						0x02 //Writes data to the register beginning at the selected address
#define MCP_LOAD_TX_BUFFER  0x40 //When loading a transmit buffer, reduces the overhead of a normal WRITE
#define MCP_RTS							0x80 //Instructs controller to begin message transmission sequence for any of the transmit buffers
#define MCP_READ_STATUS			0xA0 //Quick polling command that reads several status bits for transmit and receive functions.
#define MCP_RX_STATU				0xB0 //Quick polling command that indicates filter match and message type  of received message.
#define MCP_BIT_MODIFY			0x05 //Allows the user to set or clear individual bits in a particular register. 


//Transmit Buffer Register Set
#define TXB_1_CTRL	0x30
#define TXB_2_CTRL	0x40
#define TXB_3_CTRL	0x50
#define TXRTSCTRL		0x0D
#define TXB_1_SIDH	0x31
#define TXB_2_SIDH	0x41
#define TXB_3_SIDH	0x51
#define TXB_1_SIDL	0x32
#define TXB_2_SIDL	0x42
#define TXB_3_SIDL	0x52
#define TXB_1_EID8	0x33
#define TXB_2_EID8	0x43
#define TXB_3_EID8	0x53
#define TXB_1_EID0	0x34
#define TXB_2_EID0	0x44
#define TXB_3_EID0	0x54
#define TXB_1_DLC		0x35
#define TXB_2_DLC		0x45
#define TXB_3_DLC		0x55
#define TXB_1_D_1		0x36
#define TXB_1_D_2		0x37
#define TXB_1_D_3		0x38
#define TXB_1_D_4		0x39
#define TXB_1_D_5		0x3a
#define TXB_1_D_6		0x3b
#define TXB_1_D_7		0x3c
#define TXB_1_D_8		0x3d
#define TXB_2_D_1		0x46
#define TXB_2_D_2		0x47
#define TXB_2_D_3		0x48
#define TXB_2_D_4		0x49
#define TXB_2_D_5		0x4a
#define TXB_2_D_6		0x4b
#define TXB_2_D_7		0x4c
#define TXB_2_D_8		0x4d
#define TXB_3_D_1		0x56
#define TXB_3_D_2		0x57
#define TXB_3_D_3		0x58
#define TXB_3_D_4		0x59
#define TXB_3_D_5		0x5a
#define TXB_3_D_6		0x5b
#define TXB_3_D_7		0x5c
#define TXB_3_D_8		0x5d




#endif
