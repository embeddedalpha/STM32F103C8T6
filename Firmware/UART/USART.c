#include "USART.h"


/***********************************************************************************************************************/
//                                                         UART
/***********************************************************************************************************************/


/**********************************************************************************************************************
 * @brief: This function sets up basic functions of UART1 (without clock)
 * @parameters:
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


void UART1_Init(uint8_t baudrate, bool frame_length, uint8_t stop_bits, bool DMA_TX, bool DMA_RX)
{
	RCC -> APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
	GPIOA -> CRH |= GPIO_Config(9,ALT_PUSH_PULL_OUTPUT);
	GPIOA->CRH |= GPIO_Config(8,4);
	if(frame_length)
	{
		USART1 ->CR1 |= USART_CR1_M;
	}
	else
	{
		USART1 ->CR1 &= ~USART_CR1_M;
	}

	if(DMA_TX)
	{
		USART1 ->CR3 |= USART_CR3_DMAT;
	}
	else
	{
		USART1 ->CR3 &= ~USART_CR3_DMAT;
	}

	if(DMA_RX)
	{
		USART1 ->CR3 |= USART_CR3_DMAR;
	}
	else
	{
		USART1 ->CR3 &= ~USART_CR3_DMAR;
	}

	USART1 -> CR1 |= stop_bits << 12;
	USART1 ->BRR = (int)(TIMER_CLOCK_ADVANCED / (16 * baudrate));

	USART1 ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
	USART1 ->CR1 |= USART_CR1_UE;
}

/**********************************************************************************************************************
 * @brief: This function sets up basic functions of UART2 (without clock)
 * @parameters:
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

void UART2_Init(uint8_t baudrate, bool frame_length, uint8_t stop_bits, bool DMA_TX, bool DMA_RX)
{
	RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
	RCC -> APB1ENR |= RCC_APB1ENR_USART2EN;
	GPIOA -> CRL |= GPIO_Config(2,ALT_PUSH_PULL_OUTPUT);
	GPIOA->CRH |= GPIO_Config(3,4);
	if(frame_length)
	{
		USART2 ->CR1 |= USART_CR1_M;
	}
	else
	{
		USART2 ->CR1 &= ~USART_CR1_M;
	}

	if(DMA_TX)
	{
		USART2 ->CR3 |= USART_CR3_DMAT;
	}
	else
	{
		USART2 ->CR3 &= ~USART_CR3_DMAT;
	}

	if(DMA_RX)
	{
		USART2 ->CR3 |= USART_CR3_DMAR;
	}
	else
	{
		USART2 ->CR3 &= ~USART_CR3_DMAR;
	}

	USART2 ->BRR = (int)(TIMER_CLOCK_GENERAL / (16 * baudrate));
	USART2 ->CR1 |= stop_bits << 12;
	USART2 ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
	USART2 ->CR1 |= USART_CR1_UE;
}

/**********************************************************************************************************************
 * @brief: This function sets up basic functions of UART3 (without clock)
 * @parameters:
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

void UART3_Init(uint8_t baudrate, bool frame_length, uint8_t stop_bits, bool DMA_TX, bool DMA_RX)
{
	RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN;
	RCC -> APB1ENR |= RCC_APB1ENR_USART3EN ;
	GPIOB -> CRH |= GPIO_Config(10,ALT_PUSH_PULL_OUTPUT);
	GPIOB -> CRH |= GPIO_Config(11,4);
	if(frame_length)
	{
		USART3 ->CR1 |= USART_CR1_M;
	}
	else
	{
		USART3 ->CR1 &= ~USART_CR1_M;
	}

	if(DMA_TX)
	{
		USART3 ->CR3 |= USART_CR3_DMAT;
	}
	else
	{
		USART3 ->CR3 &= ~USART_CR3_DMAT;
	}

	if(DMA_RX)
	{
		USART3 ->CR3 |= USART_CR3_DMAR;
	}
	else
	{
		USART3 ->CR3 &= ~USART_CR3_DMAR;
	}

	USART3 ->BRR = (int)(TIMER_CLOCK_GENERAL / (16 * baudrate));
	USART3 -> CR1 |= stop_bits << 12;
	USART3 ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
	USART3 ->CR1 |= USART_CR1_UE;
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


void USART1_Setup(uint8_t baudrate, bool frame_length, uint8_t stop_bits,bool CPOL,bool CPHA, bool DMA_TX, bool DMA_RX)
{
	RCC -> APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
	GPIOA -> CRH |= GPIO_Config(9,ALT_PUSH_PULL_OUTPUT);
	GPIOA->CRH |= GPIO_Config(10,4);
	GPIOA -> CRH |= GPIO_Config(8,ALT_PUSH_PULL_OUTPUT );
	if(frame_length)
	{
		USART1 ->CR1 |= USART_CR1_M;
	}
	else
	{
		USART1 ->CR1 &= ~USART_CR1_M;
	}

	if(DMA_TX)
	{
		USART1 ->CR3 |= USART_CR3_DMAT;
	}
	else
	{
		USART1 ->CR3 &= ~USART_CR3_DMAT;
	}

	if(DMA_RX)
	{
		USART1 ->CR3 |= USART_CR3_DMAR;
	}
	else
	{
		USART1 ->CR3 &= ~USART_CR3_DMAR;
	}

	if(CPOL)
	{
		USART1 ->CR2 |= USART_CR2_CPOL;
	}
	else
	{
		USART1 ->CR2 &= ~USART_CR2_CPOL;
	}

	if(CPHA)
	{
		USART1 ->CR2 |= USART_CR2_CPHA;
	}
	else
	{
		USART1 ->CR2 &= ~USART_CR2_CPHA;
	}

	USART1 -> CR2 |= stop_bits << 12;
	USART1 ->BRR = (int)(TIMER_CLOCK_ADVANCED / (16 * baudrate));
	USART1 -> CR2 |= USART_CR2_CLKEN;
	USART1 ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
	USART1 ->CR1 |= USART_CR1_UE;
}

/**********************************************************************************************************************
 * @brief: This function sets up basic functions of USART2 (with clock)
 * @parameters:
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


void USART2_Setup(uint8_t baudrate, bool frame_length, uint8_t stop_bits,bool CPOL,bool CPHA, bool DMA_TX, bool DMA_RX)
{
	RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
	RCC -> APB1ENR |= RCC_APB1ENR_USART2EN;
	GPIOA -> CRL |= GPIO_Config(2,ALT_PUSH_PULL_OUTPUT);
	GPIOA->CRL |= GPIO_Config(3,4);
	GPIOA -> CRL |= GPIO_Config(4,ALT_PUSH_PULL_OUTPUT );
	if(frame_length)
	{
		USART2 ->CR1 |= USART_CR1_M;
	}
	else
	{
		USART2 ->CR1 &= ~USART_CR1_M;
	}

	if(DMA_TX)
	{
		USART2 ->CR3 |= USART_CR3_DMAT;
	}
	else
	{
		USART2 ->CR3 &= ~USART_CR3_DMAT;
	}

	if(DMA_RX)
	{
		USART2 ->CR3 |= USART_CR3_DMAR;
	}
	else
	{
		USART2 ->CR3 &= ~USART_CR3_DMAR;
	}

	if(CPOL)
	{
		USART2 ->CR2 |= USART_CR2_CPOL;
	}
	else
	{
		USART2 ->CR2 &= ~USART_CR2_CPOL;
	}

	if(CPHA)
	{
		USART2 ->CR2 |= USART_CR2_CPHA;
	}
	else
	{
		USART2 ->CR2 &= ~USART_CR2_CPHA;
	}



	USART2 ->BRR = (int)(TIMER_CLOCK_GENERAL / (16 * baudrate));
	USART2 -> CR2 |= USART_CR2_CLKEN;
	USART2 -> CR2 |= stop_bits << 12;
	USART2 ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
	USART2 ->CR1 |= USART_CR1_UE;
}


/**********************************************************************************************************************
 * @brief: This function sets up basic functions of USART3 (with clock)
 * @parameters:
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
void USART3_Setup(uint8_t baudrate, bool frame_length, uint8_t stop_bits,bool CPOL,bool CPHA, bool DMA_TX, bool DMA_RX)
{
	RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN;
	RCC -> APB1ENR |= RCC_APB1ENR_USART3EN ;
	GPIOB -> CRH |= GPIO_Config(10,ALT_PUSH_PULL_OUTPUT);
	GPIOB -> CRH |= GPIO_Config(11,4);
	GPIOB -> CRH |= GPIO_Config(12,ALT_PUSH_PULL_OUTPUT);
	if(frame_length)
	{
		USART3 ->CR1 |= USART_CR1_M;
	}
	else
	{
		USART3 ->CR1 &= ~USART_CR1_M;
	}

	if(DMA_TX)
	{
		USART3 ->CR3 |= USART_CR3_DMAT;
	}
	else
	{
		USART3 ->CR3 &= ~USART_CR3_DMAT;
	}

	if(DMA_RX)
	{
		USART3 ->CR3 |= USART_CR3_DMAR;
	}
	else
	{
		USART3 ->CR3 &= ~USART_CR3_DMAR;
	}

	if(CPOL)
	{
		USART3 ->CR2 |= USART_CR2_CPOL;
	}
	else
	{
		USART3 ->CR2 &= ~USART_CR2_CPOL;
	}

	if(CPHA)
	{
		USART3 ->CR2 |= USART_CR2_CPHA;
	}
	else
	{
		USART3 ->CR2 &= ~USART_CR2_CPHA;
	}

	USART3 ->BRR = (int)(TIMER_CLOCK_GENERAL / (16 * baudrate));
	USART3 -> CR2 |= USART_CR2_CLKEN;
	USART3 -> CR2 |= stop_bits << 12;
	USART3 ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
	USART3 ->CR1 |= USART_CR1_UE;
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




