#include "I2C.h"




void I2C_Init(void)
	{

	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
	GPIOB->CRL |= GPIO_CRL_CNF6_1 | GPIO_CRL_MODE6_1 | GPIO_CRL_MODE6_0; //PB6 SCLK
	GPIOB->CRL |= GPIO_CRL_CNF7_1 | GPIO_CRL_MODE7_1 | GPIO_CRL_MODE7_0; //PB7 SDA

	I2C1->CR2 = 30;
	I2C1->CCR = 0x802D;
	I2C1->TRISE = 0x5;
	I2C1->CR1 |= I2C_CR1_PE;
	I2C1->CR1 |= I2C_CR1_START;
	READ_REG(I2C1->SR1);


}

void I2C_Start(void){
I2C1->CR1 |= I2C_CR1_START;
READ_REG(I2C1->SR1);
}

void I2C_Send_Address(int address){

	address &= ~(1 << 0);
	I2C1->DR = (uint8_t)address;
	READ_REG(I2C1->SR1);
	READ_REG(I2C1->SR2);
	CLEAR_BIT(I2C1->SR1,I2C_SR1_ADDR);

}
void I2C_TX_Data(int data){

	READ_REG(I2C1->SR1);
	I2C1->DR =  data;
	while(!(I2C1->CR1 & I2C_CR1_ACK)){}
  READ_REG(I2C1->SR1);
	READ_REG(I2C1->SR2);
}

void I2C_Rx_Address(int address){

	address &= ~(1 << 1);
	I2C1->DR = (uint8_t)address;
	READ_REG(I2C1->SR1);
	READ_REG(I2C1->SR2);
	CLEAR_BIT(I2C1->SR1,I2C_SR1_ADDR);

}

int I2C_RX_Data(void)
{
  int data;
	while(!(I2C1->CR1 & I2C_CR1_ACK)){}
	data = I2C1->DR;
	READ_REG(I2C1->SR1);
	READ_REG(I2C1->SR2);	
	return data;
}


void I2C_Stop(void)
{
	I2C1->CR1 |= I2C_CR1_STOP;
}
