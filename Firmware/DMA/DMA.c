#include "DMA.h"

/*
ADC = ch1

USART1_TX = CH4
       RX = CH5

USART2_TX = CH6
      _RX = CH7

USART3_TX = CH2
      _RX = CH3

SPI1_TX = CH3
    _RX = CH2

SPI2_TX = CH5
    _RX = CH4

I2C1_TX = CH6
    _RX = CH7

I2C2_TX = CH4
    _RX = CH5
*/








void DMA_Memory_2_Memory(uint32_t destination, uint32_t source, uint8_t direction, uint8_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority)
{

	DMA1_Channel1->CPAR = destination;
	DMA1_Channel1->CMAR = source;
	DMA1_Channel1->CNDTR = data_buffer_size;

	DMA1_Channel1->CCR |= DMA_CCR1_DIR;

	DMA1_Channel1->CCR |= DMA_CCR1_MEM2MEM;
	if(memory_size == 8){
	DMA1_Channel1->CCR &= ~DMA_CCR1_MSIZE;
	}
	else
		if(memory_size == 16){
		DMA1_Channel1->CCR |= DMA_CCR1_MSIZE_0;
		}
			else{
			DMA1_Channel1->CCR |= DMA_CCR1_MSIZE_1;
			}



		if(peripheral_size == 8){
	DMA1_Channel1->CCR &= ~DMA_CCR1_PSIZE;
	}
	else
		if(peripheral_size == 16){
		DMA1_Channel1->CCR |= DMA_CCR1_PSIZE_0;
		}
			else{
			DMA1_Channel1->CCR |= DMA_CCR1_PSIZE_1;
			}

			if(priority == 0){
	DMA1_Channel1->CCR &= ~DMA_CCR1_PL;
	}
	else
		if(peripheral_size == 1){
		DMA1_Channel1->CCR |= DMA_CCR1_PL_0;
		}
			else
				if(peripheral_size == 2){
			DMA1_Channel1->CCR |= DMA_CCR1_PL_1;
			}
				else{
				DMA1_Channel1->CCR |= DMA_CCR1_PL_1 | DMA_CCR1_PL_0 ;
				}

}



void USART1_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
{
	DMA1_Channel4 ->CPAR = (uint32_t)(USART1->DR);
	DMA1_Channel4 ->CMAR = (uint32_t)(source_address);
	DMA1_Channel4 ->CNDTR = buffer_size;
	DMA1_Channel4 ->CCR |= (priority << 12) | (3<<10) | (3<<8) | (1 << 7) | (1<<4);
	if(Circular_buffer)
	{
		DMA1_Channel4 -> CCR |=	 DMA_CCR4_CIRC;
	}
	else
	{
		DMA1_Channel4 -> CCR &=	~DMA_CCR4_CIRC;
	}

}


void USART2_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
{
	DMA1_Channel7 ->CPAR = (uint32_t)(USART1->DR);
	DMA1_Channel7 ->CMAR = (uint32_t)(source_address);
	DMA1_Channel7 ->CNDTR = buffer_size;
	DMA1_Channel7 ->CCR |= (priority << 12) | (3<<10) | (3<<8) | (1 << 7) | (1<<4);
	if(Circular_buffer)
	{
		DMA1_Channel7 -> CCR |=	 DMA_CCR7_CIRC;
	}
	else
	{
		DMA1_Channel7 -> CCR &=	~DMA_CCR7_CIRC;
	}

}

void USART3_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
{
	DMA1_Channel2 ->CPAR = (uint32_t)(USART1->DR);
	DMA1_Channel2 ->CMAR = (uint32_t)(source_address);
	DMA1_Channel2 ->CNDTR = buffer_size;
	DMA1_Channel2 ->CCR |= (priority << 12) | (3<<10) | (3<<8) | (1 << 7) | (1<<4);
	if(Circular_buffer)
	{
		DMA1_Channel2 -> CCR |=	 DMA_CCR2_CIRC;
	}
	else
	{
		DMA1_Channel2 -> CCR &=	~DMA_CCR2_CIRC;
	}

}

void I2C1_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
{
	DMA1_Channel6 ->CPAR = (uint32_t)(USART1->DR);
	DMA1_Channel6 ->CMAR = (uint32_t)(source_address);
	DMA1_Channel6 ->CNDTR = buffer_size;
	DMA1_Channel6 ->CCR |= (priority << 12) | (3<<10) | (3<<8) | (1 << 7) | (1<<4);
	if(Circular_buffer)
	{
		DMA1_Channel6 -> CCR |=	 DMA_CCR6_CIRC;
	}
	else
	{
		DMA1_Channel6 -> CCR &=	~DMA_CCR6_CIRC;
	}

}


void I2C2_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
{
	DMA1_Channel4 ->CPAR = (uint32_t)(USART1->DR);
	DMA1_Channel4 ->CMAR = (uint32_t)(source_address);
	DMA1_Channel4 ->CNDTR = buffer_size;
	DMA1_Channel4 ->CCR |= (priority << 12) | (3<<10) | (3<<8) | (1 << 7) | (1<<4);
	if(Circular_buffer)
	{
		DMA1_Channel4 -> CCR |=	 DMA_CCR4_CIRC;
	}
	else
	{
		DMA1_Channel4 -> CCR &=	~DMA_CCR4_CIRC;
	}

}

void SPI1_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
{
	DMA1_Channel3 ->CPAR = (uint32_t)(USART1->DR);
	DMA1_Channel3 ->CMAR = (uint32_t)(source_address);
	DMA1_Channel3 ->CNDTR = buffer_size;
	DMA1_Channel3 ->CCR |= (priority << 12) | (3<<10) | (3<<8) | (1 << 7) | (1<<4);
	if(Circular_buffer)
	{
		DMA1_Channel3 -> CCR |=	 DMA_CCR3_CIRC;
	}
	else
	{
		DMA1_Channel3 -> CCR &=	~DMA_CCR3_CIRC;
	}

}

void SPI2_TX_DMA_Init(uint32_t source_address, uint16_t buffer_size, uint8_t priority, bool Circular_buffer)
{
	DMA1_Channel5 ->CPAR = (uint32_t)(USART1->DR);
	DMA1_Channel5 ->CMAR = (uint32_t)(source_address);
	DMA1_Channel5 ->CNDTR = buffer_size;
	DMA1_Channel5 ->CCR |= (priority << 12) | (3<<10) | (3<<8) | (1 << 7) | (1<<4);
	if(Circular_buffer)
	{
		DMA1_Channel5 -> CCR |=	 DMA_CCR5_CIRC;
	}
	else
	{
		DMA1_Channel5 -> CCR &=	~DMA_CCR5_CIRC;
	}

}
