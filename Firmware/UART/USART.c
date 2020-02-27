#include "USART.h"

//													CNF					MODE
//TX -> ALT FUN PUSH-PULL		10					11	PA9
//RX -> I/P FLOAT						01					00	PA10
//CLK -> ALT FUN PUSH-PULL  10					11	PA8
//RTS -> ALT FUN PUSH-PULL  10					11	PA12
//CTS -> I/P FLOAT					01					00	PA11

void USART_Init(){

	RCC->APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN;
	GPIOA->CRH |= GPIO_CRH_CNF8_1 | GPIO_CRH_MODE8_1 | GPIO_CRH_MODE8_0; //PA8 CLK
	GPIOA->CRH |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9_1 | GPIO_CRH_MODE9_0; //PA9 TX
	GPIOA->CRH |= GPIO_CRH_CNF12_1 | GPIO_CRH_MODE12_1 | GPIO_CRH_MODE12_0; //PA12 RTS
	
	
	
	//468.75 1D4C
	USART1 ->BRR = 0x1D4C;
	USART1 ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
	USART1 ->CR1 |= USART_CR1_UE;

}

char USART_TX_CHAR(char data){

	
	if(USART1->SR & USART_SR_TXE){
	
	USART1->DR = data;
		
		while (!(USART1->SR & USART_SR_TC));
	}
	

}

char USART_TX_INT(int data){

	
	if(USART1->SR & USART_SR_TXE){
	
	USART1->DR = data;
		
		while (!(USART1->SR & USART_SR_TC));
	}
	

}

void UART_Init(){

	RCC->APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN;

	GPIOA->CRH |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9_1 | GPIO_CRH_MODE9_0; //PA9 TX
	
	//468.75 1D4C
	USART1 ->BRR = 0x1D4C;
	USART1 ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
	USART1 ->CR1 |= USART_CR1_UE;

}

char UART_TX_CHAR(char data){

	
	if(USART1->SR & USART_SR_TXE){
	
	USART1->DR = data;
		
		while (!(USART1->SR & USART_SR_TC));
	}
	

}

char UART_TX_INT(int data){

	
	if(USART1->SR & USART_SR_TXE){
	
	USART1->DR = data;
		
		while (!(USART1->SR & USART_SR_TC));
	}
	

}

char UART_RX_CHAR(char data){

	
	if(USART1->SR & USART_SR_RXNE){
	
	USART1->DR = data;
		
		while (!(USART1->SR & USART_SR_TC));
	}
	

}

char UART_RX_INT(int data){

	
	if(USART1->SR & USART_SR_RXNE){
	
	 
		data = USART1->DR;
		
		while (!(USART1->SR & USART_SR_TC));
	}
	

}

