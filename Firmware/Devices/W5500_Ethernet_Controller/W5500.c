#include "W5500.h"


void W5500_Write(uint16_t address_phase, uint8_t control_phase, uint8_t data[] )
{
    int len =  *(&data + 1) - data;
    int i = 0
    uint8_t array[] = {(uint8_t)(address_phase & 0xFF00), (uint8_t)(address_phase & 0x00FF), control_phase);
    while( i < len)
    {
        array[i+3] = data[i];
        ++i;
    }
    SPI_Send_Data(SPI1, data);
    SPI1_NSS_HIGH();
    SPI1_NSS_LOW(void);
    
}
