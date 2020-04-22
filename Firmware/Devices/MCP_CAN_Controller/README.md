<h1> MCP2515 CAN Controller</h1>
<b> 
uint8_t MCP2512_Read(uint8_t address);</br >
uint8_t MCP2512_Read_RX_Buffer(uint8_t buffer);</br >
void MCP2512_Write(uint8_t address, uint8_t data);</br >
void MCP2512_Load_TX_Buffer(uint8_t buffer, uint8_t data);</br >
void MCP2512_Request_To_Send(uint8_t RTS_Buffer);</br >
void MCP2512_Bit_Modify(uint8_t address, uint8_t mask, uint8_t data);</br >
uint8_t MCP2512_Read_Status(void);</br >
uint8_t MCP2512_Rx_Status(void);</br >

<b>
void MCP2512_Init(void);</br >
void MCP2512_TX_Standard_Frame(uint8_t buffer,uint16_t standard_id, uint8_t data[8], uint8_t dlc);</br >
void MCP2512_TX_Extended_Frame(uint8_t buffer,uint16_t standard_id, uint32_t extended_id, uint8_t data[8], uint8_t dlc);</br >

