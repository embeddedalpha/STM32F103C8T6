#include "USART.h"

/**********************************************************************************************************************
 * @brief: This function sets up basic functions of UART (without clock)
 * @parameters: uart         ->       USART1
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


void UART_Setup(USART_TypeDef *uart,uint8_t baudrate, bool frame_length, uint8_t stop_bits, bool DMA_TX, bool DMA_RX)
{
	switch(uart)
	{

		case USART1:
		{
			RCC -> APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
			GPIOA -> CRH |= GPIO_Config(9,ALT_PUSH_PULL_OUTPUT);
			GPIOA->CRH |= GPIO_Config(8,4);
			if(frame_length)
			{
				uart ->CR1 |= USART_CR1_M;
			}
			else
			{
				uart ->CR1 &= ~USART_CR1_M;
			}

			if(DMA_TX)
			{
				uart ->CR3 |= USART_CR3_DMAT;
			}
			else
			{
				uart ->CR3 &= ~USART_CR3_DMAT;
			}

			if(DMA_RX)
			{
				uart ->CR3 |= USART_CR3_DMAR;
			}
			else
			{
				uart ->CR3 &= ~USART_CR3_DMAR;
			}

			uart -> stop_bits << 12;
			uart ->BRR = (int)(TIMER_CLOCK_ADVANCED / (16 * baudrate));

			uart ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
			uart ->CR1 |= USART_CR1_UE;
		}

		case USART2:
		{
			RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
			RCC -> APB1ENR |= RCC_APB1ENR_USART2EN;
			GPIOA -> CRL |= GPIO_Config(2,ALT_PUSH_PULL_OUTPUT);
			GPIOA->CRH |= GPIO_Config(3,4);
			if(frame_length)
			{
				uart ->CR1 |= USART_CR1_M;
			}
			else
			{
				uart ->CR1 &= ~USART_CR1_M;
			}

			if(DMA_TX)
			{
				uart ->CR3 |= USART_CR3_DMAT;
			}
			else
			{
				uart ->CR3 &= ~USART_CR3_DMAT;
			}

			if(DMA_RX)
			{
				uart ->CR3 |= USART_CR3_DMAR;
			}
			else
			{
				uart ->CR3 &= ~USART_CR3_DMAR;
			}

			uart ->BRR = (int)(TIMER_CLOCK_GENERAL / (16 * baudrate));
			uart -> stop_bits << 12;
			uart ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
			uart ->CR1 |= USART_CR1_UE;
		}

		case USART3:
		{
			RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN;
			RCC -> APB1ENR |= RCC_APB1ENR_USART3EN ;
			GPIOB -> CRH |= GPIO_Config(10,ALT_PUSH_PULL_OUTPUT);
			GPIOB -> CRH |= GPIO_Config(11,4);
			if(frame_length)
			{
				uart ->CR1 |= USART_CR1_M;
			}
			else
			{
				uart ->CR1 &= ~USART_CR1_M;
			}

			if(DMA_TX)
			{
				uart ->CR3 |= USART_CR3_DMAT;
			}
			else
			{
				uart ->CR3 &= ~USART_CR3_DMAT;
			}

			if(DMA_RX)
			{
				uart ->CR3 |= USART_CR3_DMAR;
			}
			else
			{
				uart ->CR3 &= ~USART_CR3_DMAR;
			}

			uart ->BRR = (int)(TIMER_CLOCK_GENERAL / (16 * baudrate));
			uart -> stop_bits << 12;
			uart ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
			uart ->CR1 |= USART_CR1_UE;
		}

	}

}

/**********************************************************************************************************************/


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
			   bool Error_interrupt )
{
	uart -> CR1 |= parity_interrupt << 8 | transmitter_register_empty_interrupt << 7 | transmitter_complete_interrupt << 6 | receiver_register_empty_interrupt << 5 | idle_interrupt << 4;
	uart -> CR3 |= CTS_interrupt << 10 | Error_interrupt << 0;

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
	while((uart->SR & USART_SR_RXNE) != 1);
	return uart -> DR;
}



/***********************************************************************************************************************
 * @brief: This function sends out data
 * @parameter: uart  -> USART1
 *                      USART2
 *                      USART3
 *             data  -> 8 bit data
 ***********************************************************************************************************************/

void UART_Send_Data(USART_TypeDef *uart,uint8_t data)
{
	uart -> DR = data;
	while((uart->SR & USART_SR_TC) != 1);
}

