#include "SPI.h"

//gpio ->CRL |= 3 << (4 * trigger_pin);

void SPI1_Pin_Config_PortA(void)
{

	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN | RCC_APB2ENR_IOPAEN;
	GPIOA ->CRL |= (11 << (4 * 4)) | (11 << (4 * 5)) | (11 << (4 * 7)) ;

}
//

void SPI2_Pin_Config_PortB_Low(void)
{

	RCC->APB1ENR |= RCC_APB1ENR_SPI2EN ;
	RCC->APB2ENR |=  RCC_APB2ENR_IOPBEN;
	GPIOA ->CRH |= (11 << (4 * 4)) | (11 << (4 * 5)) | (11 << (4 * 7)) ;

}
//

void SPI2_Pin_Config_PortB_High(void)
{

	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN ;
	RCC->APB2ENR |=  RCC_APB2ENR_IOPBEN;
	GPIOA ->CRL |= (11 << (4 * 5)) | (11 << (4 * 3)) ;

}
//


int SPI_Master_Init(SPI_TypeDef *spi, uint8_t CPOL, uint8_t CPHA, uint8_t BaudRate, uint8_t LSBorMSB, uint8_t DataFormat)
{


    
  
    //@baudrate
    if(BaudRate <= 32 && BaudRate > 18 )
    {
        spi -> CR1 &= ~SPI_CR1_BR;  //0b000
        
    }
    else if(BaudRate <= 18 && BaudRate > 9)
    {
        spi -> CR1 |=   SPI_CR1_BR_0;  //0b001
    }
    else if(BaudRate <=  9 && BaudRate > 4.5)
    {
        spi -> CR1 |= SPI_CR1_BR_1; //0b010
    }
    else if(BaudRate <= 4.5 && BaudRate > 2)
    {
        spi -> CR1 |= SPI_CR1_BR_1 | SPI_CR1_BR_0;//0b011
    }
    else if(BaudRate <= 2 && BaudRate > 1)
    {
        spi -> CR1 |= SPI_CR1_BR_2 ;//0b100
    }
    else{
        spi -> CR1 &= ~SPI_CR1_BR; //0b000 36MHz
    }
    
    //@CPOL and CPHA
    if(CPOL == 0 && CPHA == 0)
    {
        spi -> CR1 &= ~ (SPI_CR1_CPOL | SPI_CR1_CPHA);
    }
    else if(CPOL == 0 && CPHA == 1)
    {
        spi -> CR1 |=  SPI_CR1_CPHA;
    }
    else if(CPOL == 1 && CPHA == 0)
    {
        spi -> CR1 |=  SPI_CR1_CPOL;
    }
    else //CPOL = 1 and CPHA 1
    {
        spi -> CR1 |=  (SPI_CR1_CPOL | SPI_CR1_CPHA);
    }
    
    //@Data Format
    if(DataFormat == 16)
    {
        spi -> CR1 |= SPI_CR1_DFF;
    }
    else
    {
        spi -> CR1 &= ~SPI_CR1_DFF;
    }
    
    //@LSBorMSB
    
    if(LSBorMSB == 0)
    {
        spi -> CR1 &= ~SPI_CR1_LSBFIRST;
    }
    else
    {
        spi -> CR1 |= SPI_CR1_LSBFIRST;
    }
    
    
    
    
    //@SSOE Bit Set
    
    spi -> CR2 |= SPI_CR2_SSOE;
    
    //MASTER CONFIGURATION
    
    spi -> CR1 |= SPI_CR1_MSTR;
    
    //@SPI Master Enable
    
    if( (spi->CR1 & SPI_CR1_MSTR) != 0)
    {
        
      return 0;
      
    }
    
    else
    {
        
     return 1;
     
     
    }
    
    
 
    
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int SPI_CRC_Config(SPI_TypeDef *spi, int CRC_Polynomial)
{
    spi -> CRCPR = CRC_Polynomial;
    spi -> CR1 |= SPI_CR1_CRCEN;
	
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int SPI_Enable(SPI_TypeDef *spi)
{
    spi -> CR1 |= SPI_CR1_SPE;
       
    if( (spi -> CR1 & SPI_CR1_SPE ) == 0)
    {
        
        return 0;
    }
    
    else
    {
        return 1;
    }
    
       
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int SPI_Slave_Device_Init(SPI_TypeDef *spi, uint8_t CPOL, uint8_t CPHA, uint8_t LSBorMSB, uint8_t DataFormat, uint8_t crc_bit)
{
   
        
    if(CPOL == 0 && CPHA == 0)
    {
        spi -> CR1 &= ~ (SPI_CR1_CPOL | SPI_CR1_CPHA);
    }
    else if(CPOL == 0 && CPHA == 1)
    {
        spi -> CR1 |=  SPI_CR1_CPHA;
    }
    else if(CPOL == 1 && CPHA == 0)
    {
        spi -> CR1 |=  SPI_CR1_CPOL;
    }
    else //CPOL = 1 and CPHA 1
    {
        spi -> CR1 |=  (SPI_CR1_CPOL | SPI_CR1_CPHA);
    }
    
   
    if(DataFormat == 16)
    {
        spi -> CR1 |= SPI_CR1_DFF;
    }
    else
    {
        spi -> CR1 &= ~SPI_CR1_DFF;
    }
    
  
    if(LSBorMSB == 0)
    {
        spi -> CR1 &= ~SPI_CR1_LSBFIRST;
    }
    else
    {
        spi -> CR1 |= SPI_CR1_LSBFIRST;
    }
    
    
    
    if(crc_bit == 1)
    {
        
        spi -> CR1 |= SPI_CR1_CRCEN;
    }
    else
    {
        spi -> CR1 &= ~SPI_CR1_CRCEN;
    }
    
    
    
    spi -> CR2 |= SPI_CR2_SSOE;
    
    //MASTER CONFIGURATION
    
    spi -> CR1 &= ~SPI_CR1_MSTR;
    
    //@SPI SLAVE Enable
    
    if( (spi->CR1 & SPI_CR1_MSTR) == 1)
    {
        
        return 0;
    }
    
    else
    {
        return 1;
    }
    
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int SPI_Halfduplex_TX(SPI_TypeDef *spi, uint8_t CPOL, uint8_t CPHA, uint8_t BaudRate, uint8_t LSBorMSB, uint8_t DataFormat)
{ 

/*
>> SET BAUDRATE 
>> SET PPOLARITY AND PHASE
>> Set DATA FORMAT
>> SET LSB or MSB
>> SET SSOE BIT 
*/
    
    // @BaudRate 
    
    if(BaudRate <= 32 && BaudRate > 18 )
    {
        spi -> CR1 &=  ~SPI_CR1_BR;  //0b000
        
    }
    else if(BaudRate <= 18 && BaudRate > 9)
    {
        spi -> CR1 |=   SPI_CR1_BR_0;  //0b001
    }
    else if(BaudRate <=  9 && BaudRate > 4.5)
    {
        spi -> CR1 |= SPI_CR1_BR_1; //0b010
    }
    else if(BaudRate <= 4.5 && BaudRate > 2)
    {
        spi -> CR1 |= SPI_CR1_BR_1 | SPI_CR1_BR_0;//0b011
    }
    else if(BaudRate <= 2 && BaudRate > 1)
    {
        spi -> CR1 |= SPI_CR1_BR_2 ;//0b100
    }
    else{
        spi -> CR1 &= ~SPI_CR1_BR; //0b000 36MHz
    }
    
    //@CPOL and CPHA
    if(CPOL == 0 && CPHA == 0)
    {
        spi -> CR1 &= ~ (SPI_CR1_CPOL | SPI_CR1_CPHA);
    }
    else if(CPOL == 0 && CPHA == 1)
    {
        spi -> CR1 |=  SPI_CR1_CPHA;
    }
    else if(CPOL == 1 && CPHA == 0)
    {
        spi -> CR1 |=  SPI_CR1_CPOL;
    }
    else //CPOL = 1 and CPHA 1
    {
        spi -> CR1 |=  (SPI_CR1_CPOL | SPI_CR1_CPHA);
    }
    
    //@Data Format
    if(DataFormat == 16)
    {
        spi -> CR1 |= SPI_CR1_DFF;
    }
    else
    {
        spi -> CR1 &= ~SPI_CR1_DFF;
    }
    
    //@LSB == 0 or MSB == 1
    
    if(LSBorMSB == 0)
    {
        spi -> CR1 &= ~SPI_CR1_LSBFIRST;
    }
    else
    {
        spi -> CR1 |= SPI_CR1_LSBFIRST;
    }
    
    
   
    
    
    //@SSOE Bit Set
    
    spi -> CR2 |= SPI_CR2_SSOE;
    
    spi -> CR1 &= ~ SPI_CR1_BIDIMODE;
    
    //MASTER CONFIGURATION
    
    spi -> CR1 |= SPI_CR1_MSTR;
    
    //@SPI ENABLE
    
 
    
    
    if((spi->CR1 & SPI_CR1_MSTR) == 0)
    {
        
        return 0;
    }
    
    else
    {
        return 1;
    }
    
    
}
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

int SPI_Halfduplex_RX(SPI_TypeDef *spi, uint8_t CPOL, uint8_t CPHA, uint8_t BaudRate, uint8_t LSBorMSB, uint8_t DataFormat)
{

return 0;}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SPI1_NSS_HIGH(void)
{
    GPIOA->BSRR |= GPIO_BSRR_BS4;
 //GPIOA->BSRR &= ~GPIO_BSRR_BS8;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SPI1_NSS_LOW(void)
{
  //  GPIOA->BSRR |= GPIO_BSRR_BS8;
 GPIOA->BSRR &= ~GPIO_BSRR_BS4;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SPI2_NSS_HIGH(void)
{
    GPIOA->BSRR |= GPIO_BSRR_BS4;
 //GPIOA->BSRR &= ~GPIO_BSRR_BS8;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SPI2_NSS_LOW(void)
{
  //  GPIOA->BSRR |= GPIO_BSRR_BS8;
 GPIOA->BSRR &= ~GPIO_BSRR_BS4;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SPI_Send_Data(SPI_TypeDef *spi, int data[])
{
    int i =1;
    int len =  *(&data + 1) - data;
 spi -> DR = data[0];
 
 for(;i <= len; i++)
 {
     while(!(spi -> SR & SPI_SR_TXE)){}
     spi -> DR = data[i];
     
 }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int SPI_Receive_Data(SPI_TypeDef *spi, int **data, size_t length)
{
    int *result = malloc(length);
    *data = result;
    
    int counter = 0;
    
    while(counter <= length)
    {
        while((spi->SR & SPI_SR_RXNE) == SET){}
    result[counter] = spi -> DR;
    counter += 1;
    }
return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 

