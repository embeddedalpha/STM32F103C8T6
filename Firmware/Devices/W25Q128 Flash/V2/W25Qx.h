/*
 * W25Qx.h
 *
 *  Created on: 24-May-2021
 *      Author: Kunal
 */

#ifndef W25QX_W25QX_H_
#define W25QX_W25QX_H_

#include "main.h"
#include "GPIO/GPIO.h"
#include "SPI/SPI.h"

struct SPI_Config W25Q;

#define Status_Reg_Protection_0          7
#define Sector_Protect                   6
#define Top_Bottom_Write_Protect         5
#define Block_Protect_Bit2               4
#define Block_Protect_Bit1               3
#define Block_Protect_Bit0               2
#define Write_Enable_Latch               1
#define Busy_Bit                         0

void W25Qx_Init(SPI_TypeDef *SPI);
uint8_t *W25Qx_Read_Block(uint32_t address, uint32_t length);

uint8_t W25Qx_Read_Byte(uint32_t address);
void W25Qx_Write_Block(uint32_t address, uint8_t *data, uint32_t length);
void W25Qx_Write_Byte(uint32_t address, uint8_t byte);
void W25Qx_Write_Enable(void);
void W25Qx_Write_Disable(void);
uint8_t W25Qx_Read_Status_Register_1(void);
uint8_t W25Qx_Read_Status_Register_2(void);
void W25Qx_Block_Erase_64KB(uint32_t address);
void W25Qx_Block_Erase_32KB(uint32_t address);
void W25Qx_Block_Erase_4KB(uint32_t address);
void W25Qx_Chip_Erase(void);
void W25Qx_Power_Down(void);
void W25Qx_Memory_Protect(void);


#endif /* W25QX_W25QX_H_ */
