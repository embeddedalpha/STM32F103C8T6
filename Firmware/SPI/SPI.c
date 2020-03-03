/*
*********************************************************************************************************************************
@file:    SPI.c
@author:  Kunal Salvi
@version: V3.05.0
@date:    29/2/2020
@brief:   SPI Driver File. 
					This file contains the functions declared in SPI.h file.
					By calling various "Init" functions, the user can configure 
					the SPI Hardware Peripheral in any of the permitted modes. 
					
@attention: This file aims at providing the user an abrstraction layer to the SPI peripheral
						and is tested on STM32f103C8T6. This file is free for use to any person or corporation.
						In case of failure of code/product due to third party tampering, the author will not be
						responsible. This code is published under MIT License.
	
*********************************************************************************************************************************	
*/
#include "SPI.h"

//*******************************************************************************************************************************//
//																				Initialization
//*******************************************************************************************************************************//

//***************************************** Full Duplex Master Mode *************************************************************
//@function: The function sets up the SPI block in Full Duplex Mode
//@param:
// 				spi 			           SPI1, SPI2
//				Port 			 				   0 = Port A
//														 1 = Port B
//														 2 = Port A and B  (Refer to the Pinout Diagram of Blue-Pill)
//				CPOL 			 				   0 or 1
//        CPHA 			 				   0 or 1
//				Baudrate 					   36 MHz,18 MHz,9 MHz, 
//														 45(4.5 MHz), 225(2.25 MHz), 1125(1.125 MHz),
//														 5625(0.5625 MHz), 2812(0.28125 MHz)
//        LSBorMSB             1 = MSB first
//                             0 = LSB first
//        DataFormat           0 = 8 bits
//                             1 = 16 bits
//        NSS_mode             1 = NSS/SS is controlled by software
//														 0 = NSS/SS is controlled by hardware
//        CRC_mode             1 = CRC Enable
//	                           0 = CRC Disable
//				multimaster_mode     1 = Multi master mode enable
//														 0 = Multi master mode disable
//@return: Returns 1 if master mode is enabled
//         Returns 0 if master mode is not enabled
 
int SPI_Master_Full_Duplex_Init(SPI_TypeDef *spi, uint8_t Port, uint8_t CPOL, uint8_t CPHA, int BaudRate, uint8_t LSBorMSB, uint8_t DataFormat, uint8_t NSS_mode, uint8_t CRC_mode, uint8_t multimaster){
// Choose SPI1 or SPI2
if(spi == SPI1)
{
RCC -> APB2ENR |= RCC_APB2ENR_SPI1EN ; //ENABLE SPI1
}
if(spi == SPI2)
{
RCC -> APB1ENR |= RCC_APB1ENR_SPI2EN; //ENABLE SPI2
}
// Select Port
switch(Port)
{
case 0:
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;  //ENABLE PORT A
GPIOA -> CRL |= (ALT_PUSH_PULL_OUTPUT << 7) | (ALT_PUSH_PULL_OUTPUT << 5);	
SPI_PORT = 0;
break;
}
case 1:
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN; //ENABLE PORT B
GPIOA -> CRH |= (ALT_PUSH_PULL_OUTPUT << 13) | (ALT_PUSH_PULL_OUTPUT << 15);	
SPI_PORT = 1;
break;
}
case 2:
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPAEN; //ENABLE PORT A AND B
GPIOA -> CRH |= (ALT_PUSH_PULL_OUTPUT << 3) | (ALT_PUSH_PULL_OUTPUT << 5);
SPI_PORT = 2;
break;
}
}
// Select Clock Phase and Clock Polarity
if(CPOL == 0 && CPHA == 0)
{
 spi -> CR1 &= ~ (SPI_CR1_CPOL | SPI_CR1_CPHA); //CPOL = 0 & CPHA = 0
}
else if(CPOL == 0 && CPHA == 1)
{
spi -> CR1 |=  SPI_CR1_CPHA;   //CPOL = 0 & CPHA = 1
}
else if(CPOL == 1 && CPHA == 0)
{
spi -> CR1 |=  SPI_CR1_CPOL;      //CPOL = 1 & CPHA = 0
}
else //CPOL = 1 and CPHA 1
{
spi -> CR1 |=  (SPI_CR1_CPOL | SPI_CR1_CPHA);   //CPOL = 1 & CPHA = 1
}
// Select Baud-rate
switch(BaudRate)
{
case 36:
{
spi -> CR1 &= ~SPI_CR1_BR; //36 MHz
break;
}
case 18:
{ 
spi -> CR1 |= SPI_CR1_BR_0; //18 MHz
break; 
}
case 9:
{ 
spi -> CR1 |= SPI_CR1_BR_1; //9 MHz
break; 
}
case 45:
{ 
spi -> CR1 |= SPI_CR1_BR_1 | SPI_CR1_BR_0; //4.5 MHz
break; 
}
case 225:
{ 
spi -> CR1 |= SPI_CR1_BR_2; //2.25 MHz
break; 
}
case 1125:
{
spi -> CR1 |= SPI_CR1_BR_2 | SPI_CR1_BR_0; //1.25 MHz
break; 
}
case 5625:
{
spi -> CR1 |= SPI_CR1_BR_2 | SPI_CR1_BR_1; //0.625 MHz
break; 
}
case 2812:
{ 
spi -> CR1 |= SPI_CR1_BR; //0.28125 MHz
break; 
}
}
// Select LSB or MSB first
if(LSBorMSB == 0)
{
  spi -> CR1 &= ~SPI_CR1_LSBFIRST; //MSB first
}
if(LSBorMSB == 1)
{
  spi -> CR1 |= SPI_CR1_LSBFIRST; //LSB first
}
// Select Data Format
if(DataFormat == 1)
{
 spi -> CR1 |= SPI_CR1_DFF; //16 bits
}
if(DataFormat == 0)
{
 spi -> CR1 &= ~SPI_CR1_DFF; //8 bits
}  
// Select NSS Mode
if(NSS_mode == 1)
{
spi -> CR1 |= SPI_CR1_SSM ; //Software NSS Management
	spi -> CR1 |= SPI_CR1_SSI;
}
if(NSS_mode == 0)
{
spi -> CR1 &= ~SPI_CR1_SSM ; //Hardware NSS Management
	spi -> CR1 &= ~SPI_CR1_SSI;
}
// Select CRC Mode
if(CRC_mode == 1)
{
spi -> CR1 |= SPI_CR1_CRCEN ; //Software NSS Management
}
if(CRC_mode == 0)
{
spi -> CR1 &= ~SPI_CR1_CRCEN ; //Hardware NSS Management
}
// Select Multimaster Mode
if(multimaster == 0)
{
spi -> CR2 |= SPI_CR2_SSOE; //Multi Master Mode Enable
}
if(multimaster == 1)
{
spi -> CR2 &= ~SPI_CR2_SSOE; //Multi Master Mode Disable
}
// Enter Master Mode
spi -> CR1 |= SPI_CR1_MSTR; //Master Mode Enable
// 
if( (spi -> CR1 & SPI_CR1_MSTR) == SPI_CR1_MSTR)  
{
return 1;
}
if((spi -> CR1 & SPI_CR1_MSTR) != SPI_CR1_MSTR)
{
return 0;
}
}
//***************************************** Full Duplex Master Mode Ends ********************************************************


//***************************************** Half Duplex Master Mode *************************************************************
//@function: The function sets up the SPI block in Half Duplex Mode. If only Rx or Tx mode is selected, then use the respective RX and TX function.
//@param:
// 				spi 			           SPI1, SPI2
//				Port 			 				   0 = Port A
//														 1 = Port B
//														 2 = Port A and B  (Refer to the Pinout Diagram of Blue-Pill)
//				CPOL 			 				   0 or 1
//        CPHA 			 				   0 or 1
//				Baudrate 					   36 MHz,18 MHz,9 MHz, 
//														 45(4.5 MHz), 225(2.25 MHz), 1125(1.125 MHz),
//														 5625(0.5625 MHz), 2812(0.28125 MHz)
//        LSBorMSB             1 = MSB first
//                             0 = LSB first
//        DataFormat           0 = 8 bits
//                             1 = 16 bits
//        NSS_mode             1 = NSS/SS is controlled by software
//														 0 = NSS/SS is controlled by hardware
//        CRC_mode             1 = CRC Enable
//	                           0 = CRC Disable
//				multimaster_mode     1 = Multi master mode enable
//														 0 = Multi master mode disable
//        bidir_mode           1 = Bidirection Data mode enabled (1 clock and 1 bidirectional mode)
//                             0 = Bidirection Data mode disabled (1 clock and 1 data wire)
//        TxorRX               1 = Receive only
//                             0 = Transmitter only
//@return: Returns 1 if master mode is enabled
//         Returns 0 if master mode is not enabled

int SPI_Master_Half_Duplex_Init(SPI_TypeDef *spi, uint8_t Port, uint8_t CPOL, uint8_t CPHA, int BaudRate, uint8_t LSBorMSB, uint8_t DataFormat, uint8_t NSS_mode, uint8_t CRC_mode, uint8_t multimaster, uint8_t bidir_mode, uint8_t TxorRX ){
// Choose SPI1 or SPI2
if(spi == SPI1)
{
RCC -> APB2ENR |= RCC_APB2ENR_SPI1EN ; //ENABLE SPI1
}
if(spi == SPI2)
{
RCC -> APB1ENR |= RCC_APB1ENR_SPI2EN; //ENABLE SPI2
}
// Select Port
switch(Port)
{
case 0:
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;  //ENABLE PORT A
GPIOA -> CRL |= (ALT_PUSH_PULL_OUTPUT << 7) | (ALT_PUSH_PULL_OUTPUT << 5);	
SPI_PORT = 0;
break;
}
case 1:
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN; //ENABLE PORT B
GPIOA -> CRH |= (ALT_PUSH_PULL_OUTPUT << 13) | (ALT_PUSH_PULL_OUTPUT << 15);	
SPI_PORT = 1;
break;
}
case 2:
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPAEN; //ENABLE PORT A AND B
GPIOA -> CRH |= (ALT_PUSH_PULL_OUTPUT << 3) | (ALT_PUSH_PULL_OUTPUT << 5);
SPI_PORT = 2;
break;
}
}
// Select Clock Phase and Clock Polarity
if(CPOL == 0 && CPHA == 0)
{
 spi -> CR1 &= ~ (SPI_CR1_CPOL | SPI_CR1_CPHA); //CPOL = 0 & CPHA = 0
}
else if(CPOL == 0 && CPHA == 1)
{
spi -> CR1 |=  SPI_CR1_CPHA;   //CPOL = 0 & CPHA = 1
}
else if(CPOL == 1 && CPHA == 0)
{
spi -> CR1 |=  SPI_CR1_CPOL;      //CPOL = 1 & CPHA = 0
}
else //CPOL = 1 and CPHA 1
{
spi -> CR1 |=  (SPI_CR1_CPOL | SPI_CR1_CPHA);   //CPOL = 1 & CPHA = 1
}
// Select Baud-rate
switch(BaudRate)
{
case 36:
{
spi -> CR1 &= ~SPI_CR1_BR; //36 MHz
break;
}
case 18:
{ 
spi -> CR1 |= SPI_CR1_BR_0; //18 MHz
break; 
}
case 9:
{ 
spi -> CR1 |= SPI_CR1_BR_1; //9 MHz
break; 
}
case 45:
{ 
spi -> CR1 |= SPI_CR1_BR_1 | SPI_CR1_BR_0; //4.5 MHz
break; 
}
case 225:
{ 
spi -> CR1 |= SPI_CR1_BR_2; //2.25 MHz
break; 
}
case 1125:
{
spi -> CR1 |= SPI_CR1_BR_2 | SPI_CR1_BR_0; //1.25 MHz
break; 
}
case 5625:
{
spi -> CR1 |= SPI_CR1_BR_2 | SPI_CR1_BR_1; //0.625 MHz
break; 
}
case 2812:
{ 
spi -> CR1 |= SPI_CR1_BR; //0.28125 MHz
break; 
}
}
// Select LSB or MSB first
if(LSBorMSB == 0)
{
  spi -> CR1 &= ~SPI_CR1_LSBFIRST; //MSB first
}
if(LSBorMSB == 1)
{
  spi -> CR1 |= SPI_CR1_LSBFIRST; //LSB first
}
// Select Data Format
if(DataFormat == 1)
{
 spi -> CR1 |= SPI_CR1_DFF; //16 bits
}
if(DataFormat == 0)
{
 spi -> CR1 &= ~SPI_CR1_DFF; //8 bits
}  
// Select NSS Mode
if(NSS_mode == 1)
{
spi -> CR1 |= SPI_CR1_SSM ; //Software NSS Management
	spi -> CR1 |= SPI_CR1_SSI;
}
if(NSS_mode == 0)
{
spi -> CR1 &= ~SPI_CR1_SSM ; //Hardware NSS Management
	spi -> CR1 &= ~SPI_CR1_SSI;
}
// Select CRC Mode
if(CRC_mode == 1)
{
spi -> CR1 |= SPI_CR1_CRCEN ; //Software NSS Management
}
if(CRC_mode == 0)
{
spi -> CR1 &= ~SPI_CR1_CRCEN ; //Hardware NSS Management
}
// Select Multimaster Mode
if(multimaster == 0)
{
spi -> CR2 |= SPI_CR2_SSOE; //Multi Master Mode Enable
}
if(multimaster == 1)
{
spi -> CR2 &= ~SPI_CR2_SSOE; //Multi Master Mode Disable
}
// Select Bidirectional Mode
if(bidir_mode == 1)
{
spi -> CR1 |= SPI_CR1_BIDIMODE; //Bidirectional Mode is enabled
// Select TX or RX Mode
if(TxorRX == 1)
{
spi -> CR1 &= ~SPI_CR1_BIDIOE; //RX only mode is enabled
}
if(TxorRX == 0)
{
spi -> CR1 |= SPI_CR1_BIDIOE; //TX only mode is enabled
}
}
if(bidir_mode == 0)
{
 spi -> CR1 &= ~SPI_CR1_BIDIMODE; //Bidirectional Mode is disabled
}
// Enter Master Mode
spi -> CR1 |= SPI_CR1_MSTR; //Master Mode Enable
// 
if( (spi -> CR1 & SPI_CR1_MSTR) == SPI_CR1_MSTR)  
{
return 1;
}
if((spi -> CR1 & SPI_CR1_MSTR) != SPI_CR1_MSTR)
{
return 0;
}
}
//***************************************** Half Duplex Master Mode Ends ********************************************************//


//***************************************** Simplex Master Mode *****************************************************************//
//@function: The function sets up the SPI block in Simplex Mode. If only Rx or only Tx mode is selected, then use the respective SPI_RX or SPI_TX functions
//@param:
// 				spi 			           SPI1, SPI2
//				Port 			 				   0 = Port A
//														 1 = Port B
//														 2 = Port A and B  (Refer to the Pinout Diagram of Blue-Pill)
//				CPOL 			 				   0 or 1
//        CPHA 			 				   0 or 1
//				Baudrate 					   36 MHz,18 MHz,9 MHz, 
//														 45(4.5 MHz), 225(2.25 MHz), 1125(1.125 MHz),
//														 5625(0.5625 MHz), 2812(0.28125 MHz)
//        LSBorMSB             1 = MSB first
//                             0 = LSB first
//        DataFormat           0 = 8 bits
//                             1 = 16 bits
//        NSS_mode             1 = NSS/SS is controlled by software
//														 0 = NSS/SS is controlled by hardware
//        CRC_mode             1 = CRC Enable
//	                           0 = CRC Disable
//				multimaster_mode     1 = Multi master mode enable
//														 0 = Multi master mode disable
//        TxorRX               1 = Receive only
//                             0 = Transmitter only
//@return: Returns 1 if master mode is enabled
//         Returns 0 if master mode is not enabled

int SPI_Master_Simplex_Init(SPI_TypeDef *spi, uint8_t Port, uint8_t CPOL, uint8_t CPHA, int BaudRate, uint8_t LSBorMSB, uint8_t DataFormat, uint8_t NSS_mode, uint8_t CRC_mode, uint8_t multimaster, uint8_t TxorRX )
{
// Choose SPI1 or SPI2
if(spi == SPI1)
{
RCC -> APB2ENR |= RCC_APB2ENR_SPI1EN ; //ENABLE SPI1
}
if(spi == SPI2)
{
RCC -> APB1ENR |= RCC_APB1ENR_SPI2EN; //ENABLE SPI2
}
// Select Port
switch(Port)
{
case 0:
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;  //ENABLE PORT A
GPIOA -> CRL |= (ALT_PUSH_PULL_OUTPUT << 7) | (ALT_PUSH_PULL_OUTPUT << 5);	
SPI_PORT = 0;
break;
}
case 1:
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN; //ENABLE PORT B
GPIOA -> CRH |= (ALT_PUSH_PULL_OUTPUT << 13) | (ALT_PUSH_PULL_OUTPUT << 15);	
SPI_PORT = 1;
break;
}
case 2:
{
RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPAEN; //ENABLE PORT A AND B
GPIOA -> CRH |= (ALT_PUSH_PULL_OUTPUT << 3) | (ALT_PUSH_PULL_OUTPUT << 5);
SPI_PORT = 2;
break;
}
}
// Select Clock Phase and Clock Polarity
if(CPOL == 0 && CPHA == 0)
{
 spi -> CR1 &= ~ (SPI_CR1_CPOL | SPI_CR1_CPHA); //CPOL = 0 & CPHA = 0
}
else if(CPOL == 0 && CPHA == 1)
{
spi -> CR1 |=  SPI_CR1_CPHA;   //CPOL = 0 & CPHA = 1
}
else if(CPOL == 1 && CPHA == 0)
{
spi -> CR1 |=  SPI_CR1_CPOL;      //CPOL = 1 & CPHA = 0
}
else //CPOL = 1 and CPHA 1
{
spi -> CR1 |=  (SPI_CR1_CPOL | SPI_CR1_CPHA);   //CPOL = 1 & CPHA = 1
}
// Select Baud-rate
switch(BaudRate)
{
case 36:
{
spi -> CR1 &= ~SPI_CR1_BR; //36 MHz
break;
}
case 18:
{ 
spi -> CR1 |= SPI_CR1_BR_0; //18 MHz
break; 
}
case 9:
{ 
spi -> CR1 |= SPI_CR1_BR_1; //9 MHz
break; 
}
case 45:
{ 
spi -> CR1 |= SPI_CR1_BR_1 | SPI_CR1_BR_0; //4.5 MHz
break; 
}
case 225:
{ 
spi -> CR1 |= SPI_CR1_BR_2; //2.25 MHz
break; 
}
case 1125:
{
spi -> CR1 |= SPI_CR1_BR_2 | SPI_CR1_BR_0; //1.25 MHz
break; 
}
case 5625:
{
spi -> CR1 |= SPI_CR1_BR_2 | SPI_CR1_BR_1; //0.625 MHz
break; 
}
case 2812:
{ 
spi -> CR1 |= SPI_CR1_BR; //0.28125 MHz
break; 
}
}
// Select LSB or MSB first
if(LSBorMSB == 0)
{
  spi -> CR1 &= ~SPI_CR1_LSBFIRST; //MSB first
}
if(LSBorMSB == 1)
{
  spi -> CR1 |= SPI_CR1_LSBFIRST; //LSB first
}
// Select Data Format
if(DataFormat == 1)
{
 spi -> CR1 |= SPI_CR1_DFF; //16 bits
}
if(DataFormat == 0)
{
 spi -> CR1 &= ~SPI_CR1_DFF; //8 bits
}  
// Select NSS Mode
if(NSS_mode == 1)
{
spi -> CR1 |= SPI_CR1_SSM ; //Software NSS Management
	spi -> CR1 |= SPI_CR1_SSI;
}
if(NSS_mode == 0)
{
spi -> CR1 &= ~SPI_CR1_SSM ; //Hardware NSS Management
	spi -> CR1 &= ~SPI_CR1_SSI;
}
// Select CRC Mode
if(CRC_mode == 1)
{
spi -> CR1 |= SPI_CR1_CRCEN ; //Software NSS Management
}
if(CRC_mode == 0)
{
spi -> CR1 &= ~SPI_CR1_CRCEN ; //Hardware NSS Management
}
// Select Multimaster Mode
if(multimaster == 0)
{
spi -> CR2 |= SPI_CR2_SSOE; //Multi Master Mode Enable
}
if(multimaster == 1)
{
spi -> CR2 &= ~SPI_CR2_SSOE; //Multi Master Mode Disable
}
// Select TX or RX Mode
if(TxorRX == 0) //TX only mode is selected
{ 
spi -> CR1 &= ~SPI_CR1_BIDIMODE;
spi -> CR1 &= ~SPI_CR1_RXONLY;
}
if(TxorRX == 1) //RX only mode is selected
{
spi -> CR1 &= ~SPI_CR1_BIDIMODE;
spi -> CR1 |= SPI_CR1_RXONLY;
}
// Enter Master Mode
spi -> CR1 |= SPI_CR1_MSTR; //Master Mode Enable
// 
if( (spi -> CR1 & SPI_CR1_MSTR) == SPI_CR1_MSTR)  
{
return 1;
}
if((spi -> CR1 & SPI_CR1_MSTR) != SPI_CR1_MSTR)
{
return 0;
}
}
//***************************************** Simplex Master Mode Ends ************************************************************



//*******************************************************************************************************************************//
//																				Interrupts and Events Configuration
//*******************************************************************************************************************************//

//***************************************** Interrupts and Events Enable ***************************************************************

//@attribute: This function enables software events and interrupts.
//@param: 
//				spi									 SPI1 or SPI2
//				interrupt_type       0 = Tx buffer empty interrupt
//														 1 = RX buffer not empty interrupt enable 
// 														 2 =  Error interrupt enable (overrun error and underrun error)
//return: none

void SPI_Interrupt_Enable(SPI_TypeDef *spi, int interrupt_type)
{
if(interrupt_type == 0){spi -> CR2 |= SPI_CR2_TXEIE;}
if(interrupt_type == 1){spi -> CR2 |= SPI_CR2_RXNEIE;}
if(interrupt_type == 2){spi -> CR2 |= SPI_CR2_ERRIE ;}
}
//***************************************** Interrupts and Events Ends **********************************************************


//***************************************** Interrupts and Events IRQHandler ***************************************************************

//@attribute: Interrupt handler should be copied to main.c file whenever it is needed.
//if SPI1 is enabled, NVIC_EnableIRQ(SPI1_IRQn); should be copied and pasted in the code
//and if SPI2 is to be enabled, NVIC_EnableIRQ(SPI2_IRQn); should be copied and pasted in the code
//@param : none
//@return: none

void SPI1_IRQHandler(void)
{
if((SPI1->SR & SPI_SR_TXE) == SPI_SR_TXE)
{
//Add user code
}
if((SPI1 -> SR & SPI_SR_RXNE) == SPI_SR_RXNE)
{
//Add user code
}
}
//

//@attribute: Interrupt handler should be copied to main.c file whenever it is needed. The user should comment the IF statement not used in application.
//@param : none
//@return: none


void SPI2_IRQHandler(void)
{
if((SPI2->SR & SPI_SR_TXE) == SPI_SR_TXE)
{
//Add user code
}
if((SPI2 -> SR & SPI_SR_RXNE) == SPI_SR_RXNE)
{
//Add user code
}
}
//***************************************** Interrupts and Events IRQHandler Ends **********************************************************



//*******************************************************************************************************************************//
//																				Enabling 
//*******************************************************************************************************************************//

//***************************************** SPI Enable **************************************************************************
//@attribute: This function enables SPI block.
//@param : 
//        spi           0 = SPI1 
//											1 = SPI2              
//@return: none

void SPI_Enables(SPI_TypeDef *spi)
{
spi -> CR1 |= SPI_CR1_SPE;
}
//***************************************** SPI Enable Ends *********************************************************************



//*******************************************************************************************************************************//
//																				Communication 
//*******************************************************************************************************************************//


//***************************************** SPI Trasnmit Data *******************************************************************
//@attribute: This function transmits the data through MOSI.
//@param:
//				spi           0 = SPI1
//											1 = SPI2
//        data[]				Array to be sent
//        length        length of array
//@return: none

void SPI_Send(SPI_TypeDef *spi, int data[], int length)
{
int i;
	for(i = 0; i < length; i++)
	{
	spi -> DR = data[i];
	while((spi -> SR & SPI_SR_TXE) != SPI_SR_TXE){}
	}
}
//


//***************************************** SPI Receive Data *******************************************************************
//@attribute: This function Receives data through MISO.
//@param:
//				spi           0 = SPI1
//											1 = SPI2
//        length        length of data stream to be received
//@return: none

void SPI_Receive_Data(SPI_TypeDef *spi, int length)
{
int i;
	for(i = 0; i < length; i++)
	{
	spi -> DR = 0xAA;
	while((spi -> SR & SPI_SR_TXE) != SPI_SR_TXE){}
	while((spi -> SR & SPI_SR_RXNE) != SPI_SR_RXNE){}
	receive_buffer[i] = spi -> DR;
	}
}
//


