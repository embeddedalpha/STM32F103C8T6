/********************************************************************************************************************************

@file:    SPI.h
@author:  Kunal Salvi aka @embeddedaplha
@version: V3.5.0
@date:    29-Feb-2020
@brief:   Serial Peripheral Interface Header File.

																												MIT License
																							Copyright (c) 2018 Embedded_Alpha

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files 
(the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify,
merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/*******************************************************************************************************************************

#ifndef _SPI_H_
#define _SPI_H_

#include "stm32f10x.h"
#include "board.h"

GPIO_TypeDef *PORT;
extern uint8_t NSS_Pin;

#define LSB 0
#define MSB 1
#define Bit_8 0
#define Bit_16 1
#define Simplex 1
#define Duplex 0
#define Tx 1
#define Rx 0
#define Enable 1
#define Disable 0


struct  SPI_Master_Parameters
{
	uint8_t CPOL ;
	uint8_t CPHA ;
	uint8_t Baudrate;
	uint8_t LSBorMSB ;
	uint8_t DataFormat ;
	uint8_t CRC_Enable ;
	uint8_t BiDirectional_Mode ;
	uint8_t TxorRX ;
	uint8_t TxDMA ;
	uint8_t RxDMA ;
};

struct SPI_Master_IRQ_Parameters
{
	uint8_t TX_Interrupt ;
	uint8_t RX_Interrupt ;
	uint8_t Error_Interrupt  ;

};

struct  SPI_Slave_Parameters
{
	uint8_t CPOL ;
	uint8_t CPHA ;
	uint8_t Baudrate ;
	uint8_t LSBorMSB ;
	uint8_t DataFormat ;
	uint8_t CRC_Enable ;
	uint8_t BiDirectional_Mode ;
	uint8_t TxorRX ;
	uint8_t TxDMA ;
	uint8_t RxDMA ;
};

struct SPI_Slave_IRQ_Parameters
{
	uint8_t TX_Interrupt ;
	uint8_t RX_Interrupt ;
	uint8_t Error_Interrupt;

};


void SPI_Master_Config(SPI_TypeDef *SPI, struct SPI_Master_Parameters SPI_M);
void SPI_Master_IRQ_Config(SPI_TypeDef *SPI, struct SPI_Master_IRQ_Parameters SPIM_I);
void SPI_Master_Enable(SPI_TypeDef *SPI);
void SPI_Master_TX(SPI_TypeDef *SPI, int data);
int SPI_Master_RX(SPI_TypeDef *SPI);
void SPI_NSS_Pin_Setup(void);
void SPI_NSS_LOW(void);
void SPI_NSS_HIGH(void);
void SPI_Slave_Init(SPI_TypeDef *SPI, struct SPI_Slave_Parameters SPI_S);
void SPI_Slave_IRQ_Config(SPI_TypeDef *SPI, struct SPI_Slave_IRQ_Parameters SPIS_I);
void SPI_Slave_Enable(SPI_TypeDef *SPI);
void SPI_Slave_TX(SPI_TypeDef *SPI, int data);
int SPI_Slave_RX(SPI_TypeDef *SPI);














#endif


