#ifndef _W25QxxFLASH_
#define _W25QxxFLASH_

#include "stm32f10x.h"
#include "board.h"
#include "SPI.h"

extern uint8_t flash_data_TX[256];
extern uint8_t flash_data_RX[256];


void W25Qx_Init(void);

void W25Qx_Flash_Select(void);

void W25Qx_Flash_Deselect(void);

uint8_t W25Qx_Write_Flash(uint32_t address,int length);

uint8_t W25Qx_Read_Flash(uint32_t address, int length);

void W25Qx_Sector_Erase(uint32_t address);

void W25Qx_Sector_Erase_32KB(uint32_t address);

void W25Qx_Sector_Erase_64KB(uint32_t address);

void W25Qx_Power_Down(void);

void W25Qx_Power_Down_Release(void);

uint8_t W25Qx_Read_Device_ID(void);

uint8_t W25Qx_Read_Unique_ID(void);

uint8_t W25Qx_Read_JEDEC_ID(void);

void W25Qx_Write_Flash_Bulk(uint32_t address);





#endif
