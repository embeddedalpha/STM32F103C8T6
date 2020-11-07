#ifndef _SPI_H_
#define _SPI_H_

#include "stm32f10x.h"
#include "board.h"



static uint8_t NSS_Pin;

#define LSB 0
#define MSB 1
#define Bit_8 0
#define Bit_16 1
#define Tx 1
#define Rx 0




void SPI_Config(SPI_TypeDef *SPI,uint8_t CPHA,uint8_t CPOL,uint8_t data_format, uint8_t LSBorMSB);
void SPI_Simplex_Config(SPI_TypeDef *SPI, uint8_t TXorRX);
void SPI_CRC_Enable(SPI_TypeDef *SPI, uint16_t CRC_Polynomial);
void SPI_DMA_Enable(SPI_TypeDef *SPI, uint8_t TXorRX);

void SPI_Master_Enable(SPI_TypeDef *SPI);
void SPI_Slave_Enable(SPI_TypeDef *SPI);

void SPI_Enable(SPI_TypeDef *SPI);

void SPI_TX(SPI_TypeDef *SPI,uint8_t data);
int SPI_RX(SPI_TypeDef *SPI);
uint8_t SPI_TXRX(SPI_TypeDef *SPI,uint8_t data);


void SPI_NSS_Pin_Setup(GPIO_TypeDef *PORT, uint8_t pin);
void SPI_NSS_LOW(GPIO_TypeDef *PORT);
void SPI_NSS_HIGH(GPIO_TypeDef *PORT);




#endif
