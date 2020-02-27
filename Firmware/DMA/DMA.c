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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void USART1_TX_DMA(uint32_t desitnation, uint8_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority)
{
	
	DMA1_Channel4->CPAR = USART1->DR; //
	DMA1_Channel4->CMAR = desitnation;
	DMA1_Channel4->CNDTR = data_buffer_size;
	
	DMA1_Channel4->CCR |= DMA_CCR1_DIR; //write to peripheral
	 
	DMA1_Channel4->CCR |= DMA_CCR1_MEM2MEM;
	if(memory_size == 8){
	DMA1_Channel4->CCR &= ~DMA_CCR1_MSIZE;
	}
	else
		if(memory_size == 16){
		DMA1_Channel4->CCR |= DMA_CCR1_MSIZE_0;
		}
			else{
			DMA1_Channel4->CCR |= DMA_CCR1_MSIZE_1;
			}
			
			
			
		if(peripheral_size == 8){
	DMA1_Channel4->CCR &= ~DMA_CCR1_PSIZE;
	}
	else
		if(peripheral_size == 16){
		DMA1_Channel4->CCR |= DMA_CCR1_PSIZE_0;
		}
			else{
			DMA1_Channel4->CCR |= DMA_CCR1_PSIZE_1;
			}
	 
			if(priority == 0){
	DMA1_Channel4->CCR &= ~DMA_CCR1_PL;
	}
	else
		if(peripheral_size == 1){
		DMA1_Channel4->CCR |= DMA_CCR1_PL_0;
		}
			else
				if(peripheral_size == 2){
			DMA1_Channel4->CCR |= DMA_CCR1_PL_1;
			}
				else{
				DMA1_Channel4->CCR |= DMA_CCR1_PL_1 | DMA_CCR1_PL_0 ;
				}
	 		
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void USART1_RX_DMA(uint32_t desitnation, uint8_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority)
{
	
	DMA1_Channel5->CPAR = USART1->DR; //
	DMA1_Channel5->CMAR = desitnation;
	DMA1_Channel5->CNDTR = data_buffer_size;
	
	DMA1_Channel5->CCR &= ~DMA_CCR1_DIR; //read from peripheral
	 
	DMA1_Channel5->CCR |= DMA_CCR1_MEM2MEM;
	if(memory_size == 8){
	DMA1_Channel5->CCR &= ~DMA_CCR1_MSIZE;
	}
	else
		if(memory_size == 16){
		DMA1_Channel5->CCR |= DMA_CCR1_MSIZE_0;
		}
			else{
			DMA1_Channel5->CCR |= DMA_CCR1_MSIZE_1;
			}
			
			
			
		if(peripheral_size == 8){
	DMA1_Channel5->CCR &= ~DMA_CCR1_PSIZE;
	}
	else
		if(peripheral_size == 16){
		DMA1_Channel5->CCR |= DMA_CCR1_PSIZE_0;
		}
			else{
			DMA1_Channel5->CCR |= DMA_CCR1_PSIZE_1;
			}
	 
			if(priority == 0){
	DMA1_Channel5->CCR &= ~DMA_CCR1_PL;
	}
	else
		if(peripheral_size == 1){
		DMA1_Channel5->CCR |= DMA_CCR1_PL_0;
		}
			else
				if(peripheral_size == 2){
			DMA1_Channel5->CCR |= DMA_CCR1_PL_1;
			}
				else{
				DMA1_Channel5->CCR |= DMA_CCR1_PL_1 | DMA_CCR1_PL_0 ;
				}
	 		
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void USART2_TX_DMA(uint32_t desitnation, uint8_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority)
{
	
	DMA1_Channel6->CPAR = USART2->DR; //
	DMA1_Channel6->CMAR = desitnation;
	DMA1_Channel6->CNDTR = data_buffer_size;
	
	DMA1_Channel6->CCR |= DMA_CCR1_DIR; //write to peripheral
	 
	DMA1_Channel6->CCR |= DMA_CCR1_MEM2MEM;
	if(memory_size == 8){
	DMA1_Channel6->CCR &= ~DMA_CCR1_MSIZE;
	}
	else
		if(memory_size == 16){
		DMA1_Channel6->CCR |= DMA_CCR1_MSIZE_0;
		}
			else{
			DMA1_Channel6->CCR |= DMA_CCR1_MSIZE_1;
			}
			
			
			
		if(peripheral_size == 8){
	DMA1_Channel6->CCR &= ~DMA_CCR1_PSIZE;
	}
	else
		if(peripheral_size == 16){
		DMA1_Channel6->CCR |= DMA_CCR1_PSIZE_0;
		}
			else{
			DMA1_Channel6->CCR |= DMA_CCR1_PSIZE_1;
			}
	 
			if(priority == 0){
	DMA1_Channel6->CCR &= ~DMA_CCR1_PL;
	}
	else
		if(peripheral_size == 1){
		DMA1_Channel6->CCR |= DMA_CCR1_PL_0;
		}
			else
				if(peripheral_size == 2){
			DMA1_Channel6->CCR |= DMA_CCR1_PL_1;
			}
				else{
				DMA1_Channel6->CCR |= DMA_CCR1_PL_1 | DMA_CCR1_PL_0 ;
				}
	 		
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void USART2_RX_DMA(uint32_t desitnation, uint8_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority)
{
	
	DMA1_Channel7->CPAR = USART2->DR; //
	DMA1_Channel7->CMAR = desitnation;
	DMA1_Channel7->CNDTR = data_buffer_size;
	
	DMA1_Channel7->CCR &= ~DMA_CCR1_DIR; //read from peripheral
	 
	DMA1_Channel7->CCR |= DMA_CCR1_MEM2MEM;
	if(memory_size == 8){
	DMA1_Channel7->CCR &= ~DMA_CCR1_MSIZE;
	}
	else
		if(memory_size == 16){
		DMA1_Channel7->CCR |= DMA_CCR1_MSIZE_0;
		}
			else{
			DMA1_Channel7->CCR |= DMA_CCR1_MSIZE_1;
			}
			
			
			
		if(peripheral_size == 8){
	DMA1_Channel7->CCR &= ~DMA_CCR1_PSIZE;
	}
	else
		if(peripheral_size == 16){
		DMA1_Channel7->CCR |= DMA_CCR1_PSIZE_0;
		}
			else{
			DMA1_Channel7->CCR |= DMA_CCR1_PSIZE_1;
			}
	 
			if(priority == 0){
	DMA1_Channel7->CCR &= ~DMA_CCR1_PL;
	}
	else
		if(peripheral_size == 1){
		DMA1_Channel7->CCR |= DMA_CCR1_PL_0;
		}
			else
				if(peripheral_size == 2){
			DMA1_Channel7->CCR |= DMA_CCR1_PL_1;
			}
				else{
				DMA1_Channel7->CCR |= DMA_CCR1_PL_1 | DMA_CCR1_PL_0 ;
				}
	 		
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void USART3_TX_DMA(uint32_t desitnation, uint8_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority)
{
	
	DMA1_Channel3->CPAR = USART3->DR; //
	DMA1_Channel3->CMAR = desitnation;
	DMA1_Channel3->CNDTR = data_buffer_size;
	
	DMA1_Channel3->CCR |= DMA_CCR1_DIR; //write to peripheral
	 
	DMA1_Channel3->CCR |= DMA_CCR1_MEM2MEM;
	if(memory_size == 8){
	DMA1_Channel3->CCR &= ~DMA_CCR1_MSIZE;
	}
	else
		if(memory_size == 16){
		DMA1_Channel3->CCR |= DMA_CCR1_MSIZE_0;
		}
			else{
			DMA1_Channel3->CCR |= DMA_CCR1_MSIZE_1;
			}
			
			
			
		if(peripheral_size == 8){
	DMA1_Channel3->CCR &= ~DMA_CCR1_PSIZE;
	}
	else
		if(peripheral_size == 16){
		DMA1_Channel3->CCR |= DMA_CCR1_PSIZE_0;
		}
			else{
			DMA1_Channel3->CCR |= DMA_CCR1_PSIZE_1;
			}
	 
			if(priority == 0){
	DMA1_Channel3->CCR &= ~DMA_CCR1_PL;
	}
	else
		if(peripheral_size == 1){
		DMA1_Channel3->CCR |= DMA_CCR1_PL_0;
		}
			else
				if(peripheral_size == 2){
			DMA1_Channel3->CCR |= DMA_CCR1_PL_1;
			}
				else{
				DMA1_Channel3->CCR |= DMA_CCR1_PL_1 | DMA_CCR1_PL_0 ;
				}
	 		
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void USART3_RX_DMA(uint32_t desitnation, uint8_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority)
{
	
	DMA1_Channel2->CPAR = USART3->DR; //
	DMA1_Channel2->CMAR = desitnation;
	DMA1_Channel2->CNDTR = data_buffer_size;
	
	DMA1_Channel2->CCR &= ~DMA_CCR1_DIR; //read from peripheral
	 
	DMA1_Channel2->CCR |= DMA_CCR1_MEM2MEM;
	if(memory_size == 8){
	DMA1_Channel2->CCR &= ~DMA_CCR1_MSIZE;
	}
	else
		if(memory_size == 16){
		DMA1_Channel2->CCR |= DMA_CCR1_MSIZE_0;
		}
			else{
			DMA1_Channel2->CCR |= DMA_CCR1_MSIZE_1;
			}
			
			
			
		if(peripheral_size == 8){
	DMA1_Channel2->CCR &= ~DMA_CCR1_PSIZE;
	}
	else
		if(peripheral_size == 16){
		DMA1_Channel2->CCR |= DMA_CCR1_PSIZE_0;
		}
			else{
			DMA1_Channel2->CCR |= DMA_CCR1_PSIZE_1;
			}
	 
			if(priority == 0){
	DMA1_Channel2->CCR &= ~DMA_CCR1_PL;
	}
	else
		if(peripheral_size == 1){
		DMA1_Channel2->CCR |= DMA_CCR1_PL_0;
		}
			else
				if(peripheral_size == 2){
			DMA1_Channel2->CCR |= DMA_CCR1_PL_1;
			}
				else{
				DMA1_Channel2->CCR |= DMA_CCR1_PL_1 | DMA_CCR1_PL_0 ;
				}
	 		
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void I2C1_TX_DMA(uint32_t desitnation, uint8_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority)
{
	
	DMA1_Channel6->CPAR = I2C1->DR; //
	DMA1_Channel6->CMAR = desitnation;
	DMA1_Channel6->CNDTR = data_buffer_size;
	
	DMA1_Channel6->CCR |= DMA_CCR1_DIR; //write to peripheral
	 
	DMA1_Channel6->CCR |= DMA_CCR1_MEM2MEM;
	if(memory_size == 8){
	DMA1_Channel6->CCR &= ~DMA_CCR1_MSIZE;
	}
	else
		if(memory_size == 16){
		DMA1_Channel6->CCR |= DMA_CCR1_MSIZE_0;
		}
			else{
			DMA1_Channel6->CCR |= DMA_CCR1_MSIZE_1;
			}
			
			
			
		if(peripheral_size == 8){
	DMA1_Channel6->CCR &= ~DMA_CCR1_PSIZE;
	}
	else
		if(peripheral_size == 16){
		DMA1_Channel6->CCR |= DMA_CCR1_PSIZE_0;
		}
			else{
			DMA1_Channel6->CCR |= DMA_CCR1_PSIZE_1;
			}
	 
			if(priority == 0){
	DMA1_Channel6->CCR &= ~DMA_CCR1_PL;
	}
	else
		if(peripheral_size == 1){
		DMA1_Channel6->CCR |= DMA_CCR1_PL_0;
		}
			else
				if(peripheral_size == 2){
			DMA1_Channel6->CCR |= DMA_CCR1_PL_1;
			}
				else{
				DMA1_Channel6->CCR |= DMA_CCR1_PL_1 | DMA_CCR1_PL_0 ;
				}
	 		
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void I2C1_RX_DMA(uint32_t desitnation, uint8_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority)
{
	
	DMA1_Channel7->CPAR = I2C1->DR; 
	DMA1_Channel7->CMAR = desitnation;
	DMA1_Channel7->CNDTR = data_buffer_size;
	
	DMA1_Channel7->CCR &= ~DMA_CCR1_DIR; //read from peripheral
	 
	DMA1_Channel7->CCR |= DMA_CCR1_MEM2MEM;
	if(memory_size == 8){
	DMA1_Channel7->CCR &= ~DMA_CCR1_MSIZE;
	}
	else
		if(memory_size == 16){
		DMA1_Channel7->CCR |= DMA_CCR1_MSIZE_0;
		}
			else{
			DMA1_Channel7->CCR |= DMA_CCR1_MSIZE_1;
			}
			
			
			
		if(peripheral_size == 8){
	DMA1_Channel7->CCR &= ~DMA_CCR1_PSIZE;
	}
	else
		if(peripheral_size == 16){
		DMA1_Channel7->CCR |= DMA_CCR1_PSIZE_0;
		}
			else{
			DMA1_Channel7->CCR |= DMA_CCR1_PSIZE_1;
			}
	 
			if(priority == 0){
	DMA1_Channel7->CCR &= ~DMA_CCR1_PL;
	}
	else
		if(peripheral_size == 1){
		DMA1_Channel7->CCR |= DMA_CCR1_PL_0;
		}
			else
				if(peripheral_size == 2){
			DMA1_Channel7->CCR |= DMA_CCR1_PL_1;
			}
				else{
				DMA1_Channel7->CCR |= DMA_CCR1_PL_1 | DMA_CCR1_PL_0 ;
				}
	 		
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void I2C2_TX_DMA(uint32_t desitnation, uint8_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority)
{
	
	DMA1_Channel4->CPAR = I2C2->DR; //
	DMA1_Channel4->CMAR = desitnation;
	DMA1_Channel4->CNDTR = data_buffer_size;
	
	DMA1_Channel4->CCR |= DMA_CCR1_DIR; //write to peripheral
	 
	DMA1_Channel4->CCR |= DMA_CCR1_MEM2MEM;
	if(memory_size == 8){
	DMA1_Channel4->CCR &= ~DMA_CCR1_MSIZE;
	}
	else
		if(memory_size == 16){
		DMA1_Channel4->CCR |= DMA_CCR1_MSIZE_0;
		}
			else{
			DMA1_Channel4->CCR |= DMA_CCR1_MSIZE_1;
			}
			
			
			
		if(peripheral_size == 8){
	DMA1_Channel4->CCR &= ~DMA_CCR1_PSIZE;
	}
	else
		if(peripheral_size == 16){
		DMA1_Channel4->CCR |= DMA_CCR1_PSIZE_0;
		}
			else{
			DMA1_Channel4->CCR |= DMA_CCR1_PSIZE_1;
			}
	 
			if(priority == 0){
	DMA1_Channel4->CCR &= ~DMA_CCR1_PL;
	}
	else
		if(peripheral_size == 1){
		DMA1_Channel4->CCR |= DMA_CCR1_PL_0;
		}
			else
				if(peripheral_size == 2){
			DMA1_Channel4->CCR |= DMA_CCR1_PL_1;
			}
				else{
				DMA1_Channel4->CCR |= DMA_CCR1_PL_1 | DMA_CCR1_PL_0 ;
				}
	 		
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void I2C2_RX_DMA(uint32_t desitnation, uint8_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority)
{
	
	DMA1_Channel5->CPAR = I2C2->DR; 
	DMA1_Channel5->CMAR = desitnation;
	DMA1_Channel5->CNDTR = data_buffer_size;
	
	DMA1_Channel5->CCR &= ~DMA_CCR1_DIR; //read from peripheral
	 
	DMA1_Channel5->CCR |= DMA_CCR1_MEM2MEM;
	if(memory_size == 8){
	DMA1_Channel5->CCR &= ~DMA_CCR1_MSIZE;
	}
	else
		if(memory_size == 16){
		DMA1_Channel5->CCR |= DMA_CCR1_MSIZE_0;
		}
			else{
			DMA1_Channel5->CCR |= DMA_CCR1_MSIZE_1;
			}
			
			
			
		if(peripheral_size == 8){
	DMA1_Channel5->CCR &= ~DMA_CCR1_PSIZE;
	}
	else
		if(peripheral_size == 16){
		DMA1_Channel5->CCR |= DMA_CCR1_PSIZE_0;
		}
			else{
			DMA1_Channel5->CCR |= DMA_CCR1_PSIZE_1;
			}
	 
			if(priority == 0){
	DMA1_Channel5->CCR &= ~DMA_CCR1_PL;
	}
	else
		if(peripheral_size == 1){
		DMA1_Channel5->CCR |= DMA_CCR1_PL_0;
		}
			else
				if(peripheral_size == 2){
			DMA1_Channel5->CCR |= DMA_CCR1_PL_1;
			}
				else{
				DMA1_Channel5->CCR |= DMA_CCR1_PL_1 | DMA_CCR1_PL_0 ;
				}
	 		
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SPI1_TX_DMA(uint32_t desitnation, uint8_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority)
{
	
	DMA1_Channel3->CPAR = SPI1->DR; //
	DMA1_Channel3->CMAR = desitnation;
	DMA1_Channel3->CNDTR = data_buffer_size;
	
	DMA1_Channel3->CCR |= DMA_CCR1_DIR; //write to peripheral
	 
	DMA1_Channel3->CCR |= DMA_CCR1_MEM2MEM;
	if(memory_size == 8){
	DMA1_Channel3->CCR &= ~DMA_CCR1_MSIZE;
	}
	else
		if(memory_size == 16){
		DMA1_Channel3->CCR |= DMA_CCR1_MSIZE_0;
		}
			else{
			DMA1_Channel3->CCR |= DMA_CCR1_MSIZE_1;
			}
			
			
			
		if(peripheral_size == 8){
	DMA1_Channel3->CCR &= ~DMA_CCR1_PSIZE;
	}
	else
		if(peripheral_size == 16){
		DMA1_Channel3->CCR |= DMA_CCR1_PSIZE_0;
		}
			else{
			DMA1_Channel3->CCR |= DMA_CCR1_PSIZE_1;
			}
	 
			if(priority == 0){
	DMA1_Channel3->CCR &= ~DMA_CCR1_PL;
	}
	else
		if(peripheral_size == 1){
		DMA1_Channel3->CCR |= DMA_CCR1_PL_0;
		}
			else
				if(peripheral_size == 2){
			DMA1_Channel3->CCR |= DMA_CCR1_PL_1;
			}
				else{
				DMA1_Channel3->CCR |= DMA_CCR1_PL_1 | DMA_CCR1_PL_0 ;
				}
	 		
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SPI1_RX_DMA(uint32_t desitnation, uint8_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority)
{
	
	DMA1_Channel2->CPAR = SPI1->DR; 
	DMA1_Channel2->CMAR = desitnation;
	DMA1_Channel2->CNDTR = data_buffer_size;
	
	DMA1_Channel2->CCR &= ~DMA_CCR1_DIR; //read from peripheral
	 
	DMA1_Channel2->CCR |= DMA_CCR1_MEM2MEM;
	if(memory_size == 8){
	DMA1_Channel2->CCR &= ~DMA_CCR1_MSIZE;
	}
	else
		if(memory_size == 16){
		DMA1_Channel2->CCR |= DMA_CCR1_MSIZE_0;
		}
			else{
			DMA1_Channel2->CCR |= DMA_CCR1_MSIZE_1;
			}
			
			
			
		if(peripheral_size == 8){
	DMA1_Channel2->CCR &= ~DMA_CCR1_PSIZE;
	}
	else
		if(peripheral_size == 16){
		DMA1_Channel2->CCR |= DMA_CCR1_PSIZE_0;
		}
			else{
			DMA1_Channel2->CCR |= DMA_CCR1_PSIZE_1;
			}
	 
			if(priority == 0){
	DMA1_Channel2->CCR &= ~DMA_CCR1_PL;
	}
	else
		if(peripheral_size == 1){
		DMA1_Channel2->CCR |= DMA_CCR1_PL_0;
		}
			else
				if(peripheral_size == 2){
			DMA1_Channel2->CCR |= DMA_CCR1_PL_1;
			}
				else{
				DMA1_Channel2->CCR |= DMA_CCR1_PL_1 | DMA_CCR1_PL_0 ;
				}
	 		
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SPI2_TX_DMA(uint32_t desitnation, uint8_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority)
{
	
	DMA1_Channel5->CPAR = SPI2->DR; //
	DMA1_Channel5->CMAR = desitnation;
	DMA1_Channel5->CNDTR = data_buffer_size;
	
	DMA1_Channel5->CCR |= DMA_CCR1_DIR; //write to peripheral
	 
	DMA1_Channel5->CCR |= DMA_CCR1_MEM2MEM;
	if(memory_size == 8){
	DMA1_Channel5->CCR &= ~DMA_CCR1_MSIZE;
	}
	else
		if(memory_size == 16){
		DMA1_Channel5->CCR |= DMA_CCR1_MSIZE_0;
		}
			else{
			DMA1_Channel5->CCR |= DMA_CCR1_MSIZE_1;
			}
			
			
			
		if(peripheral_size == 8){
	DMA1_Channel5->CCR &= ~DMA_CCR1_PSIZE;
	}
	else
		if(peripheral_size == 16){
		DMA1_Channel5->CCR |= DMA_CCR1_PSIZE_0;
		}
			else{
			DMA1_Channel5->CCR |= DMA_CCR1_PSIZE_1;
			}
	 
			if(priority == 0){
	DMA1_Channel5->CCR &= ~DMA_CCR1_PL;
	}
	else
		if(peripheral_size == 1){
		DMA1_Channel5->CCR |= DMA_CCR1_PL_0;
		}
			else
				if(peripheral_size == 2){
			DMA1_Channel5->CCR |= DMA_CCR1_PL_1;
			}
				else{
				DMA1_Channel5->CCR |= DMA_CCR1_PL_1 | DMA_CCR1_PL_0 ;
				}
	 		
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SPI2_RX_DMA(uint32_t desitnation, uint8_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority)
{
	
	DMA1_Channel4->CPAR = SPI2->DR; 
	DMA1_Channel4->CMAR = desitnation;
	DMA1_Channel4->CNDTR = data_buffer_size;
	
	DMA1_Channel4->CCR &= ~DMA_CCR1_DIR; //read from peripheral
	 
	DMA1_Channel4->CCR |= DMA_CCR1_MEM2MEM;
	if(memory_size == 8){
	DMA1_Channel4->CCR &= ~DMA_CCR1_MSIZE;
	}
	else
		if(memory_size == 16){
		DMA1_Channel4->CCR |= DMA_CCR1_MSIZE_0;
		}
			else{
			DMA1_Channel4->CCR |= DMA_CCR1_MSIZE_1;
			}
			
			
			
		if(peripheral_size == 8){
	DMA1_Channel4->CCR &= ~DMA_CCR1_PSIZE;
	}
	else
		if(peripheral_size == 16){
		DMA1_Channel4->CCR |= DMA_CCR1_PSIZE_0;
		}
			else{
			DMA1_Channel4->CCR |= DMA_CCR1_PSIZE_1;
			}
	 
			if(priority == 0){
	DMA1_Channel4->CCR &= ~DMA_CCR1_PL;
	}
	else
		if(peripheral_size == 1){
		DMA1_Channel4->CCR |= DMA_CCR1_PL_0;
		}
			else
				if(peripheral_size == 2){
			DMA1_Channel4->CCR |= DMA_CCR1_PL_1;
			}
				else{
				DMA1_Channel4->CCR |= DMA_CCR1_PL_1 | DMA_CCR1_PL_0 ;
				}
	 		
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ADC1_DMA(uint32_t desitnation, uint8_t data_buffer_size, uint8_t memory_size, uint8_t peripheral_size, uint8_t priority)
{
	
	DMA1_Channel1->CPAR = ADC1->DR; 
	DMA1_Channel1->CMAR = desitnation;
	DMA1_Channel1->CNDTR = data_buffer_size;
	
	DMA1_Channel1->CCR &= ~DMA_CCR1_DIR; //read from peripheral
	 
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