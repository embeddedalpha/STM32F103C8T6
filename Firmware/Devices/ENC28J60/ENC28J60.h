/*
 * ENC28J60.h
 *
 *  Created on: 25-May-2021
 *      Author: Kunal
 */

#ifndef ENC28J60_ENC28J60_H_
#define ENC28J60_ENC28J60_H_

#include "main.h"
#include "SPI/SPI.h"
#include "ENC28J60_REG.h"

struct SPI_Config ECN;


bool ENC28J60_Init(SPI_TypeDef *SPI);

void Write_Register(uint8_t reg_address, uint8_t byte, uint8_t bank);

uint8_t Read_Register(uint8_t reg_address, uint8_t bank);

uint16_t Read_Phy_Register(uint8_t reg_address);


#endif /* ENC28J60_ENC28J60_H_ */
