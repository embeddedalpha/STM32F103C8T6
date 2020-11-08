#include "nRF240L1.h"



void nRF240L1_Init(SPI_TypeDef *SPI, uint8_t RF_Frequency, uint8_t RF_Channel)
{
  SPI_Config(SPI,1,1,Bit_8,MSB);
	SPI_Master_Enable(SPI);
	SPI_Enable(SPI);
	SPI_NSS_Pin_Setup(GPIOA,4); //NSS
	GPIO_Setup(GPIOA,3,GENERAL_PUSH_PULL_OUTPUT); //CE
	GPIO_Setup(GPIOA,2,FLOATING_INPUT); //IRQ

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

