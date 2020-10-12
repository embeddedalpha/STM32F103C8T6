#ifndef _SPI_H_
#define _SPI_H_

#include "stm32f10x.h"
#include "board.h"



extern int NSS_Pin;

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
#define Hardware_Managed 0
#define Software_Managed 1


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
	uint8_t Slave_Management;
	uint16_t CRC_Polynomial;
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
void SPI_Master_TX(SPI_TypeDef *SPI,int data);
int SPI_Master_RX(SPI_TypeDef *SPI);
void SPI_Master_Enable(SPI_TypeDef *SPI);
uint8_t SPI_Master_TXRX(SPI_TypeDef *SPI,uint8_t data);

void SPI_NSS_Pin_Setup(GPIO_TypeDef *PORT);
void SPI_NSS_LOW(GPIO_TypeDef *PORT);
void SPI_NSS_HIGH(GPIO_TypeDef *PORT);

void SPI_Slave_Init(SPI_TypeDef *SPI,struct SPI_Slave_Parameters SPI_S);
void SPI_Slave_IRQ_Config(SPI_TypeDef *SPI,struct SPI_Slave_IRQ_Parameters SPIS_I);
void SPI_Slave_Enable(SPI_TypeDef *SPI);
void SPI_Slave_TX(SPI_TypeDef *SPI,int data);
int SPI_Slave_RX(SPI_TypeDef *SPI);














#endif
