/********************************************************************************************************************************

@file:    SPI.h
@author:  Kunal Salvi aka @embeddedaplha
@version: V3.5.0
@date:    29-Feb-2020
@brief:   Serial Peripheral Interface Header File.

																												MIT License
																							Copyright (c) 2018 Embedded_Alpha

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files 
(the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify,
merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is 
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/*******************************************************************************************************************************

#ifndef _SPI_H_

#define _SPI_H_

#include "stm32f10x.h"

#include "board.h"

int receive_buffer[100];

int SPI_PORT;

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
 
int SPI_Master_Full_Duplex_Init(SPI_TypeDef *spi, uint8_t Port, uint8_t CPOL, uint8_t CPHA, int BaudRate, uint8_t LSBorMSB, uint8_t DataFormat, uint8_t NSS_mode, uint8_t CRC_mode, uint8_t multimaster);

	

	
	
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

int SPI_Master_Half_Duplex_Init(SPI_TypeDef *spi, uint8_t Port, uint8_t CPOL, uint8_t CPHA, int BaudRate, uint8_t LSBorMSB, uint8_t DataFormat, uint8_t NSS_mode, uint8_t CRC_mode, uint8_t multimaster, uint8_t bidir_mode, uint8_t TxorRX );

	

	
	
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

int SPI_Master_Simplex_Init(SPI_TypeDef *spi, uint8_t Port, uint8_t CPOL, uint8_t CPHA, int BaudRate, uint8_t LSBorMSB, uint8_t DataFormat, uint8_t NSS_mode, uint8_t CRC_mode, uint8_t multimaster, uint8_t TxorRX );




//***************************************** Interrupts and Events  ***************************************************************

//@attribute: This function enables software events and interrupts.
//@param: 
//				spi									 SPI1 or SPI2
//				interrupt_type       0 = Tx buffer empty interrupt
//														 1 = RX buffer not empty interrupt enable 
// 														 2 =  Error interrupt enable (overrun error and underrun error)
//return: none

void SPI_Interrupt_Enable(SPI_TypeDef *spi, int interrupt_type);


////***************************************** Interrupts and Events IRQHandler ***************************************************************

////@attribute: Interrupt handler should be copied to main.c file whenever it is needed.
////@param : none
////@return: none

//void SPI1_IRQHandler(void)

////@attribute: Interrupt handler should be copied to main.c file whenever it is needed. The user should comment the IF statement not used in application.
////@param : none
////@return: none

//void SPI2_IRQHandler(void)


//***************************************** SPI Enable **************************************************************************
//@attribute: This function enables SPI block.
//@param : 
//        spi           0 = SPI1 
//											1 = SPI2              
//@return: none

void SPI_Enables(SPI_TypeDef *spi);



//***************************************** SPI Trasnmit Data *******************************************************************
//@attribute: This function transmits the data through MOSI.
//@param:
//				spi           0 = SPI1 
//											1 = SPI2
//        data[]				Array to be sent
//        length        length of array
//@return: none

void SPI_Send_Data(SPI_TypeDef *spi, int data[], int length);




//***************************************** SPI Receive Data *******************************************************************
//@attribute: This function Receives data through MISO.
//@param:
//				spi           0 = SPI1
//											1 = SPI2
//        length        length of data stream to be received
//@return: none

void SPI_Receive_Data(SPI_TypeDef *spi, int length);



#include "stm32f10x.h"

int main(void)
{

    while(1)
    {
    }
}



#endif
