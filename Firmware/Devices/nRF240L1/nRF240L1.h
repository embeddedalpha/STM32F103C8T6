#ifndef _nRF240L1_H_
#define _nRF240L1_H_

#include "stm32f10x.h"
#include "board.h"
#include "SPI.h"
#include "stdbool.h"
#include "Debug.h"


	#define R_Register	          0x1F
	#define W_Register            0x3F
	#define R_RX_Payload          0x61
	#define W_TX_Payload          0xA0
	#define Flush_RX              0xE1
	#define Flush_TX              0xE2
	#define Reuse_TX_PL           0xE3
	#define R_RX_PL_WID           0x60
	#define W_ACK_Payload         0xAF
	#define W_TX_Payload_No_ACK   0xB0
	#define NOP                   0xFF
	

void nRF240L1_Init(SPI_TypeDef *SPI, uint8_t RF_Frequency, uint8_t RF_Channel);

void nRF240L1_CE_Setup(GPIO_TypeDef *GPIO, uint8_t pin);
void nRF240L1_CE_High(void);
void nRF240L1_CE_Low(void);

void nRF240L1_IRQ_Setup(GPIO_TypeDef *GPIO, uint8_t pin);
uint8_t nRF240L1_Read_IRQ_Pin(void);


uint8_t nRF240L1_Send_Data(uint8_t Register, uint8_t *buffer, uint8_t len );
uint16_t *nRF240L1_Get_Data(uint8_t Register, uint8_t *buffer, uint8_t len);

uint8_t nRF240L1_Read_Register(uint8_t Register);
uint8_t nRF240L1_Write_Register(uint8_t Register, uint8_t Data);

uint8_t *nRF240L1_Get_Payload(uint8_t *buffer, uint8_t len);
uint8_t nRF240L1_Write_Payload(uint8_t *buffer, uint8_t len);

uint8_t nRF24L01_Flush_RX_Buffer(void);
uint8_t nRF24L01_Flush_TX_Buffer(void);

void nRF24L01_Print_Payload(void);


bool nRF24L01_Test_Carrier(void);
bool nRF24L01_Test_RPD(void);



#endif
