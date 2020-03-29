/**********************************************************************************************************************************
@file:    MCP4725.H
@author:  Kunal Salvi
@version: V3.05.0
@date:    27/3/2020
@brief:   MCP4725 Header File.
          This file contains the prototype of functions in MCP4725.c file.
          By calling various functions, the user can configure and send data to DAC

@attention: This file aims at providing the user an abstraction layer to the MCP4725 DAC
            and is tested on STM32f103C8T6. This file is free for use to any person or corporation.
            In case of failure of code/product due to third party tampering, the author will not be
            responsible. This code is published under MIT License.

**********************************************************************************************************************************/

#ifndef _MCP4725_H
#define _MCP4725_H

#include  "stm32f10x.h"
#include "I2C.h"

#define MCP4725_Address_1 192
#define MCP4725_Address_2 194


// I2C_Send(MCP4725_Address_1 | i2c_device_write);

#define MCP4725_DAC_NormalMode     0
#define MCP4725_DAC_PWDownMode1    1
#define MCP4725_DAC_PWDownMode2    2
#define MCP4725_DAC_PWDownMode3    3

//
#define MCP4725_DAC_FastMode      0  //This command is used to change the DAC register. EEPROM is not affected
#define MCP4725_DAC_WRDACREG      2  //Load configuration bits and data code to the DAC Register
#define MCP4725_DAC_WRDACnER      3  //Load configuration bits and data code to the DAC Register and also write the EEPROM



/***************************************** Write DAC in Fast Mode *****************************************************************
//@brief: The function writes DAC in fast mode.
//@param: 12 bit data
//@return: none
********************************************************************************************************************************/
void MCP_Write_DAC_Fast_Mode(uint16_t data);



/***************************************** Write DAC in Normal Mode *****************************************************************
//@brief: The function writes DAC in normal mode.
//@param: 12 bit data
//@return: none
********************************************************************************************************************************/
void MCP_Write_DAC(uint16_t);



/***************************************** Write DAC and EEPROM *****************************************************************
//@brief: The function writes DAC and EEPROM .
//@param: 12 bit data
//@return: none
********************************************************************************************************************************/
void MCP_Write_DACnEEPROM(uint16_t);
//should be able to support DMA transfers



#endif
