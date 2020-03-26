#ifndef _MCP4725_H
#define _MCP4725_H

#include  "stm32f10x.h"

#define MCP4725_Address_1 192
#define MCP4725_Address_2 194
#define i2c_device_write 0
#define i2c_device_read  1

// I2C_Send(MCP4725_Address_1 | i2c_device_write);

#define MCP4725_DAC_NormalMode     0
#define MCP4725_DAC_PWDownMode1    1
#define MCP4725_DAC_PWDownMode2    2
#define MCP4725_DAC_PWDownMode3    3

//
#define MCP4725_DAC_FastMode      0  //This command is used to change the DAC register. EEPROM is not affected
#define MCP4725_DAC_WRDACREG      2  //Load configuration bits and data code to the DAC Register
#define MCP4725_DAC_WRDACnER      3  //Load configuration bits and data code to the DAC Register and also write the EEPROM




void MCP_Write_DAC_Fast_Mode(uint16_t data);

//should be able to support DMA transfers



#endif
