#ifndef _SPI_H_
#define _SPI_H_

#include "stm32f10x.h"
#include <stdio.h>
#include <stdlib.h>

void SPI1_Pin_Config_PortA(void);

void SPI2_Pin_Config_PortB_Low(void);

void SPI2_Pin_Config_PortB_High(void);

int SPI_Master_Init(SPI_TypeDef *spi, uint8_t CPOL, uint8_t CPHA, uint8_t BaudRate, uint8_t LSBorMSB, uint8_t DataFormat);

int SPI_CRC_Config(SPI_TypeDef *spi, int CRC_Polynomial);

int SPI_Enable(SPI_TypeDef *spi);

int SPI_Slave_Device_Init(SPI_TypeDef *spi, uint8_t CPOL, uint8_t CPHA, uint8_t LSBorMSB, uint8_t DataFormat, uint8_t crc_bit);

int SPI_Halfduplex_TX(SPI_TypeDef *spi, uint8_t CPOL, uint8_t CPHA, uint8_t BaudRate, uint8_t LSBorMSB, uint8_t DataFormat);

int SPI_Halfduplex_RX(SPI_TypeDef *spi, uint8_t CPOL, uint8_t CPHA, uint8_t BaudRate, uint8_t LSBorMSB, uint8_t DataFormat);

void SPI1_NSS_HIGH(void);

void SPI1_NSS_LOW(void);

void SPI2_NSS_HIGH(void);

void SPI2_NSS_LOW(void);

int SPI_Receive_Data(SPI_TypeDef *spi, int **data, size_t length);

void SPI_Send_Data(SPI_TypeDef *spi, int data[]);

void SPI_DMA_Config(SPI_TypeDef *spi);





#endif
