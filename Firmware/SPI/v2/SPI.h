/*
 * SPI.h
 *
 *  Created on: May 02, 2021
 *      Author: Kunal Salvi
 */

#ifndef SPI_SPI_H_
#define SPI_SPI_H_


#include "main.h"
#include "GPIO/GPIO.h"

typedef struct SPI_Config
{
	SPI_TypeDef *SPI;
	bool mode;
	bool onlyTXorRX;
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

}SPI_Config;


void SPI_Master_Init(SPI_Config SPI);

void SPI_Master_TX(SPI_Config SPI, uint16_t data);

uint16_t SPI_Master_RX(SPI_Config SPI);

void SPI_Slave_Init(SPI_Config SPI);

void SPI_Slave_TX(SPI_Config SPI, uint16_t data);

uint16_t SPI_Slave_RX(SPI_Config SPI);

void SPI_Disable(SPI_Config SPI);

void SPI_Master_SS_Select(SPI_Config SPI);

void SPI_Master_SS_Deselect(SPI_Config SPI);


void delay1(uint32_t delay);
#endif /* SPI_SPI_H_ */
