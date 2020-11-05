#include "USART.h"


/***********************************************************************************************************************/
//                                                         UART
/***********************************************************************************************************************/

/**********************************************************************************************************************
 * @brief: This function sets up basic functions of UART (without clock)
 * @parameters:
 *              USART        ->       USART1
 *                                    USART2
 *                                    USART3
 *              baudrate     ->       2400
 *                                    9600
 *                                    19200
 *                                    57600
 *                                    115200
 *                                    230400
 *                                    460800
 *                                    921600
 *                                    2250000
 *                                    450000
 *              frame_length ->   0:  1 Start bit, 8 Data bits, n Stop bit
 *                                1:  1 Start bit, 9 Data bits, n Stop bit
 *              stop_bits    ->   0:  1 Stop bit
 *                                1:  0.5 Stop bit
 *                                2:  2 Stop bits
 *                                3:  1.5 Stop bit
 *              DMA_TX       ->   0:  DMA mode is enabled for transmission
 *                                1:  DMA mode is disabled for transmission
 *              DMA_RX       ->   0:  DMA mode is enabled for reception
 *                                1:  DMA mode is disabled for reception
 **********************************************************************************************************************/


void UART_Setup(USART_TypeDef *USART,uint8_t baudrate, uint8_t frame_length, uint8_t stop_bits, uint8_t DMA_TX, uint8_t DMA_RX)
{
	if (USART == USART1)
	{
		RCC -> APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
		GPIO_Setup(GPIOA,9,ALTERNATE_PUSH_PULL_OUTPUT);
		GPIO_Setup(GPIOA,8,FLOATING_INPUT);
		if(frame_length)
		{
			USART ->CR1 |= USART_CR1_M;
		}
		else
		{
			USART ->CR1 &= ~USART_CR1_M;
		}

		if(DMA_TX)
		{
			USART ->CR3 |= USART_CR3_DMAT;
		}
		else
		{
			USART ->CR3 &= ~USART_CR3_DMAT;
		}

		if(DMA_RX)
		{
			USART ->CR3 |= USART_CR3_DMAR;
		}
		else
		{
			USART ->CR3 &= ~USART_CR3_DMAR;
		}

		USART -> CR1 |= stop_bits << 12;
		USART ->BRR = (int)(TIMER_CLOCK_ADVANCED / (16 * baudrate));

		USART ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
		USART ->CR1 |= USART_CR1_UE;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////
	if (USART == USART2)
	{
		RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
		RCC -> APB1ENR |= RCC_APB1ENR_USART2EN;
		GPIO_Setup(GPIOA,2,ALTERNATE_PUSH_PULL_OUTPUT);
		GPIO_Setup(GPIOA,3,FLOATING_INPUT);
		if(frame_length)
		{
			USART ->CR1 |= USART_CR1_M;
		}
		else
		{
			USART ->CR1 &= ~USART_CR1_M;
		}

		if(DMA_TX)
		{
			USART ->CR3 |= USART_CR3_DMAT;
		}
		else
		{
			USART ->CR3 &= ~USART_CR3_DMAT;
		}

		if(DMA_RX)
		{
			USART ->CR3 |= USART_CR3_DMAR;
		}
		else
		{
			USART ->CR3 &= ~USART_CR3_DMAR;
		}

		USART ->BRR = (int)(TIMER_CLOCK_GENERAL / (16 * baudrate));
		USART ->CR1 |= stop_bits << 12;
		USART ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
		USART ->CR1 |= USART_CR1_UE;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////
	if(USART == USART3)
	{
		RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN;
		RCC -> APB1ENR |= RCC_APB1ENR_USART3EN ;
		GPIO_Setup(GPIOA,10,ALTERNATE_PUSH_PULL_OUTPUT);
		GPIO_Setup(GPIOA,11,FLOATING_INPUT);
		if(frame_length)
		{
			USART ->CR1 |= USART_CR1_M;
		}
		else
		{
			USART ->CR1 &= ~USART_CR1_M;
		}

		if(DMA_TX)
		{
			USART ->CR3 |= USART_CR3_DMAT;
		}
		else
		{
			USART ->CR3 &= ~USART_CR3_DMAT;
		}

		if(DMA_RX)
		{
			USART ->CR3 |= USART_CR3_DMAR;
		}
		else
		{
			USART ->CR3 &= ~USART_CR3_DMAR;
		}

		USART ->BRR = (int)(TIMER_CLOCK_GENERAL / (16 * baudrate));
		USART -> CR1 |= stop_bits << 12;
		USART ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
		USART ->CR1 |= USART_CR1_UE;
	}
}


/**********************************************************************************************************************
*@brief: This function sets up various interrupts for USART/UART block
*@parameters: uart  ->  USART1
*                       USART2
*                       USART3
*             parity_interrupt                      ->  0: Disable
*                                                       1: Enable
*             transmitter_register_empty_interrupt  ->  1: Enable
*                                                       0: Disable
*             transmitter_complete_interrupt        ->  1: Enable
*                                                       0: Disable
*             receiver_register_empty_interrupt     ->  1: Enable
*                                                       0: Disable
*             idle_interrupt                        ->  1: Enable
*                                                       0: Disable
*             CTS_interrupt                         ->  1: Enable
*                                                       0: Disable
*             Error_interrupt                       ->  1: Enable
*                                                       0: Disable
***********************************************************************************************************************/


void USART_Interrupt_Setup(USART_TypeDef *uart,
						  bool parity_interrupt,
						  bool transmitter_register_empty_interrupt,
						  bool transmitter_complete_interrupt,
						  bool receiver_register_empty_interrupt,
						  bool idle_interrupt,
						  bool CTS_interrupt,
						  bool Error_interrupt
						  )
{
	uart -> CR1 |= parity_interrupt << 8 | transmitter_register_empty_interrupt << 7 | transmitter_complete_interrupt << 6 | receiver_register_empty_interrupt << 5 | idle_interrupt << 4;
	uart -> CR3 |= CTS_interrupt << 10 | Error_interrupt << 0;

}


/***********************************************************************************************************************
 * @brief: This function enables hardware flow control for asynchronous communication
 * @parameter: uart  -> USART1
 *                      USART2
 *                      USART3
 ***********************************************************************************************************************/


void UART_Flow_Control_Setup(USART_TypeDef *uart)
{
	uart -> CR3 |= USART_CR3_CTSE | USART_CR3_RTSE;
}



/***********************************************************************************************************************
 * @brief: This function receives incoming data
 * @parameter: uart  -> USART1
 *                      USART2
 *                      USART3
 *@return: UART 8 bit data
 ***********************************************************************************************************************/

uint8_t UART_Get_Data(USART_TypeDef *uart)
{
	while((uart->SR & USART_SR_RXNE) == 0);
	return uart -> DR;
}



/***********************************************************************************************************************
 * @brief: This function sends out data
 * @parameter: uart  -> USART1
 *                      USART2
 *                      USART3
 *             data  -> 8 bit data
 ***********************************************************************************************************************/

int UART_Send_Data(USART_TypeDef *uart,uint8_t data)
{
	uart -> DR = data;
	while((uart->SR & USART_SR_TC) == 0);
	return data;
}


/***********************************************************************************************************************/
//                                                         USART
/***********************************************************************************************************************/


/**********************************************************************************************************************
 * @brief: This function sets up basic functions of USART1 (with clock)
 * @parameters:
 *              USART        ->       USART1
 *                                    USART2
 *                                    USART3
 *              baudrate     ->       2400
 *                                    9600
 *                                    19200
 *                                    57600
 *                                    115200
 *                                    230400
 *                                    460800
 *                                    921600
 *                                    2250000
 *                                    450000
 *              frame_length ->   0:  1 Start bit, 8 Data bits, n Stop bit
 *                                1:  1 Start bit, 9 Data bits, n Stop bit
 *              stop_bits    ->   0:  1 Stop bit
 *                                1:  0.5 Stop bit
 *                                2:  2 Stop bits
 *                                3:  1.5 Stop bit
 *              CPOL              0:  Steady low value on CK pin outside transmission window
 *                                1:  Steady high value on CK pin outside transmission window
 *              CPHA              0:  The first clock transition is the first data capture edge
 *                                1:  The second clock transition is the first data capture edge
 *              DMA_TX       ->   0:  DMA mode is enabled for transmission
 *                                1:  DMA mode is disabled for transmission
 *              DMA_RX       ->   0:  DMA mode is enabled for reception
 *                                1:  DMA mode is disabled for reception
 **********************************************************************************************************************/


void USART_Setup(USART_TypeDef *USART,uint8_t baudrate, bool frame_length, uint8_t stop_bits,bool CPOL,bool CPHA, bool DMA_TX, bool DMA_RX)
{
	if(USART == USART1)
	{
		RCC -> APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
		GPIO_Setup(GPIOA,8,ALTERNATE_PUSH_PULL_OUTPUT);
		GPIO_Setup(GPIOA,9,ALTERNATE_PUSH_PULL_OUTPUT);
		GPIO_Setup(GPIOA,10,FLOATING_INPUT);

		if(frame_length)
		{
			USART ->CR1 |= USART_CR1_M;
		}
		else
		{
			USART ->CR1 &= ~USART_CR1_M;
		}
		if(DMA_TX)
		{
			USART ->CR3 |= USART_CR3_DMAT;
		}
		else
		{
			USART ->CR3 &= ~USART_CR3_DMAT;
		}
		if(DMA_RX)
		{
			USART ->CR3 |= USART_CR3_DMAR;
		}
		else
		{
			USART ->CR3 &= ~USART_CR3_DMAR;
		}
		if(CPOL)
		{
			USART ->CR2 |= USART_CR2_CPOL;
		}
		else
		{
			USART ->CR2 &= ~USART_CR2_CPOL;
		}
		if(CPHA)
		{
			USART ->CR2 |= USART_CR2_CPHA;
		}
		else
		{
			USART ->CR2 &= ~USART_CR2_CPHA;
		}

		USART -> CR2 |= stop_bits << 12;
		USART ->BRR = (int)(TIMER_CLOCK_ADVANCED / (16 * baudrate));
		USART -> CR2 |= USART_CR2_CLKEN;
		USART ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
		USART ->CR1 |= USART_CR1_UE;
	}
////////////////////////////////////////////////////////////////////////////////////
	if(USART == USART2)
	{
		RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
		RCC -> APB1ENR |= RCC_APB1ENR_USART2EN;

		GPIO_Setup(GPIOA,2,ALTERNATE_PUSH_PULL_OUTPUT);
		GPIO_Setup(GPIOA,4,ALTERNATE_PUSH_PULL_OUTPUT);
		GPIO_Setup(GPIOA,3,FLOATING_INPUT);
		if(frame_length)
		{
			USART ->CR1 |= USART_CR1_M;
		}
		else
		{
			USART ->CR1 &= ~USART_CR1_M;
		}

		if(DMA_TX)
		{
			USART ->CR3 |= USART_CR3_DMAT;
		}
		else
		{
			USART ->CR3 &= ~USART_CR3_DMAT;
		}

		if(DMA_RX)
		{
			USART ->CR3 |= USART_CR3_DMAR;
		}
		else
		{
			USART ->CR3 &= ~USART_CR3_DMAR;
		}

		if(CPOL)
		{
			USART ->CR2 |= USART_CR2_CPOL;
		}
		else
		{
			USART ->CR2 &= ~USART_CR2_CPOL;
		}

		if(CPHA)
		{
			USART ->CR2 |= USART_CR2_CPHA;
		}
		else
		{
			USART ->CR2 &= ~USART_CR2_CPHA;
		}



		USART ->BRR = (int)(TIMER_CLOCK_GENERAL / (16 * baudrate));
		USART -> CR2 |= USART_CR2_CLKEN;
		USART -> CR2 |= stop_bits << 12;
		USART ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
		USART ->CR1 |= USART_CR1_UE;
	}

	if(USART == USART3)
	{
		RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN;
		RCC -> APB1ENR |= RCC_APB1ENR_USART3EN ;
		GPIO_Setup(GPIOB,10,ALTERNATE_PUSH_PULL_OUTPUT);
		GPIO_Setup(GPIOB,11,ALTERNATE_PUSH_PULL_OUTPUT);
		GPIO_Setup(GPIOB,12,FLOATING_INPUT);

		if(frame_length)
		{
			USART ->CR1 |= USART_CR1_M;
		}
		else
		{
			USART ->CR1 &= ~USART_CR1_M;
		}

		if(DMA_TX)
		{
			USART ->CR3 |= USART_CR3_DMAT;
		}
		else
		{
			USART ->CR3 &= ~USART_CR3_DMAT;
		}

		if(DMA_RX)
		{
			USART ->CR3 |= USART_CR3_DMAR;
		}
		else
		{
			USART ->CR3 &= ~USART_CR3_DMAR;
		}

		if(CPOL)
		{
			USART ->CR2 |= USART_CR2_CPOL;
		}
		else
		{
			USART ->CR2 &= ~USART_CR2_CPOL;
		}

		if(CPHA)
		{
			USART ->CR2 |= USART_CR2_CPHA;
		}
		else
		{
			USART ->CR2 &= ~USART_CR2_CPHA;
		}

		USART ->BRR = (int)(TIMER_CLOCK_GENERAL / (16 * baudrate));
		USART -> CR2 |= USART_CR2_CLKEN;
		USART -> CR2 |= stop_bits << 12;
		USART ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
		USART ->CR1 |= USART_CR1_UE;
	}
}

/***********************************************************************************************************************
 * @brief: This function receives incoming data
 * @parameter: uart  -> USART1
 *                      USART2
 *                      USART3
 *@return: UART 8 bit data
 ***********************************************************************************************************************/

uint8_t USART_Get_Data(USART_TypeDef *uart)
{
	while((uart->SR & USART_SR_RXNE) == 0);
	return uart -> DR;
}



/***********************************************************************************************************************
 * @brief: This function sends out data
 * @parameter: uart  -> USART1
 *                      USART2
 *                      USART3
 *             data  -> 8 bit data
 ***********************************************************************************************************************/

void USART_Send_Data(USART_TypeDef *uart,uint8_t data)
{
	uart -> DR = data;
	while((uart->SR & USART_SR_TC) == 0);
}




