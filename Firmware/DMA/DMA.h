#ifndef _DMA_H_
#define _DMA_H_


#include "stm32f10x.h"
#include <stdbool.h>

#define DMA_Priority_Very_High 3
#define DMA_Priority_High      2
#define DMA_Priority_Medium    1
#define DMA_Priority_Low       0

void DMA_Memory_2_Memory(uint32_t destination, uint32_t source, uint8_t direction, uint16_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority);

void USART1_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer);
void USART1_RX_DMA_Init(uint32_t destination_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer);

void USART2_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer);
void USART2_RX_DMA_Init(uint32_t destination_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer);

void USART3_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer);
void USART3_RX_DMA_Init(uint32_t destination_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer);

void I2C1_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer);
void I2C1_RX_DMA_Init(uint32_t destination_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer);

void I2C2_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer);
void I2C2_RX_DMA_Init(uint32_t destination_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer);

void SPI1_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer);
void SPI1_RX_DMA_Init(uint32_t destination_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer);

void SPI2_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer);
void SPI2_RX_DMA_Init(uint32_t destination_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer);

void ADC1_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer);












#endif
