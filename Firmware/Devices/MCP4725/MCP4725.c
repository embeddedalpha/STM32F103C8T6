/**********************************************************************************************************************************
@file:    MCP4725.C
@author:  Kunal Salvi
@version: V3.05.0
@date:    27/3/2020
@brief:   MCP4725 Source File.
          This file contains the functions declared in MCP4725.h file.
          By calling various functions, the user can configure and send data to DAC

@attention: This file aims at providing the user an abstraction layer to the MCP4725 DAC
            and is tested on STM32f103C8T6. This file is free for use to any person or corporation.
            In case of failure of code/product due to third party tampering, the author will not be
            responsible. This code is published under MIT License.

**********************************************************************************************************************************/

#include "MCP4725.h"

/***************************************** Write DAC in Fast Mode *****************************************************************
//@brief: The function writes DAC in fast mode.
//@param: 12 bit data
//@return: none
********************************************************************************************************************************/

void MCP_Write_DAC_Fast_Mode(uint16_t data)
{
uint8_t first_byte	=	(MCP4725_DAC_FastMode << 0x06)| (MCP4725_DAC_NormalMode << 0x04)| ((0xFF00 & data) >> 0x08);
uint8_t second_byte =   (uint8_t)0x00FF & data;
}



/***************************************** Write DAC in Normal Mode *****************************************************************
//@brief: The function writes DAC in normal mode.
//@param: 12 bit data
//@return: none
********************************************************************************************************************************/

void MCP_Write_DAC(uint16_t)
{
	uint8_t first_byte = (MCP4725_DAC_WRDACREG << 5) | (0 << 3) | (MCP4725_DAC_NormalMode << 1) ;
	uint8_t second_byte = (uint8_t)(0xFF00 & data) >> 0x08;
	uint8_t third_byte = (uint8_t)(0x00FF & data) << 3;
}




/***************************************** Write DAC and EEPROM *****************************************************************
//@brief: The function writes DAC and EEPROM .
//@param: 12 bit data
//@return: none
********************************************************************************************************************************/

void MCP_Write_DACnEEPROM(uint16_t)
{
	uint8_t first_byte = (MCP4725_DAC_WRDACnER << 5) | (0 << 3) | (MCP4725_DAC_NormalMode << 1) ;
	uint8_t second_byte = (uint8_t)(0xFF00 & data) >> 0x08;
	uint8_t third_byte = (uint8_t)(0x00FF & data) << 3;
}



