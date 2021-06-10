#ifndef _USART_H_
#define _USART_H_


#include "main.h"
#include <stdbool.h>
#include "GPIO/GPIO.h"


#define async_mode	0;
#define sync_mode   1;
#define baudrate_

typedef struct UART_Config
{
	USART_TypeDef *USART;
	uint8_t mode;
	uint8_t baudrate;
	uint8_t frame_length;
	uint8_t stop_bits;
	uint8_t DMA_TX;
	uint8_T DMA_RX;
	uint8_t hardware_control;
}UART_Config;


void Serial_Init(USART_TypeDef *USART);

//Async functions start

uint8_t Serial_Async_TRX_Byte(uint8_t TX_Byte);

void Serial_Async_TX_Byte(uint8_t TX_Byte);

uint8_t Serial_Async_RX_Byte(void);

void Serial_Async_TX_Buffer(uint8_t *TX_Buffer, int length);

void Serial_Async_RX_Buffer(uint8_t *RX_Buffer, int length);

void Serial_Async_TX_Burst(uint32_t *TX_Buffer, int length);

void Serial_Async_RX_Burst(uint32_t *RX_Buffer, int length);

//Async function ends

//Hardware Control Functions start
uint8_t Serial_HWC_TRX_Byte(uint8_t TX_Byte);

void Serial_HWC_TRX_Buffer(uint8_t *TX_Buffer, int length, uint8_t *RX_Buffer, int length);


//Hardware Control Functions end


#endif

