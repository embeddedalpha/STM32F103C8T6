/*
 * SPI.h
 *
 *  Created on: March 11, 2021
 *      Author: Kunal Salvi
 */

#ifndef SPI_SPI_H_
#define SPI_SPI_H_

#include "stm32f103xb.h"
#include "stm32f1xx.h"
#include "stdbool.h"

typedef struct SPI_Master_Config
{
	SPI_TypeDef *SPI;
	uint8_t mode;
	bool frame_format;
	uint8_t clock_speed;
	uint8_t lsb_or_msb;
	bool crc;
	bool interrupts;
	bool tx_int;
	bool err_int;
	bool rx_int;
	bool clock_phase;
	bool clock_polarity;
	bool txDMA;
	bool rxDMA;

}SPI_Master_Config;

void SPI_Master_Init(SPI_Master_Config SPI);


#endif /* SPI_SPI_H_ */

