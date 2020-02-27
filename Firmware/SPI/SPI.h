
/*
MIT License
Copyright (c) 2018 Embedded_Alpha
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#ifndef _SPI_H_
#define _SPI_H_


#include "stm32f10x.h"
#include "board.h"

int send_buffer[100];
int receive_buffer[100];

/*
@function:- The function sets up the SPI block in Full Duplex Mode

@param :-
        *spi             -> SPI1, SPI2
        Port             -> 0 = Port A 
                            1 = Port B
                            2 = Port A and B
        CPOL             -> 0 or 1
        CPHA             -> 0 or 1
        Baudrate         -> 36, 18, 9, 
                            45 (4.5 MHz), 225(2.25 MHz), 1125(1.125 MHz), 
                            5625(0.5625 MHz), 2812(0.28125 MHz)
        LSBorMSB         -> 1 = MSB first
                            0 = LSB first
        DataFormat       -> 0 = 8 bits
                            1 = 16 bits
        NSS_mode         -> 1 = NSS/SS is controlled by software
                            0 = NSS/SS is controlled by hardware
        CRC_mode         -> 1 = CRC Enable
                            0 = CRC Disable
        multimaster_mode -> 1 = Multi master mode enable
                            0 = Multi master mode disable
        
        Mode      CPOL  CPHA
        0          0     0
        1          0     1
        2          1     0
        3          1     1
        
@return: Returns 1 if master mode is enabled
         Returns 0 if master mode is not enabled
*/

int SPI_Master_Full_Duplex_Init(SPI_TypeDef *spi, uint8_t Port, uint8_t CPOL, uint8_t CPHA, int BaudRate, uint8_t LSBorMSB, uint8_t DataFormat, uint8_t NSS_mode, uint8_t CRC_mode, uint8_t multimaster);

/*
@function:- The function sets up the SPI block in Half Duplex Mode. If only Rx or Tx mode
            is selected, then use the respective RX and TX function.

@param :-
        *spi             -> SPI1, SPI2
        Port             -> 0 = Port A 
                            1 = Port B
                            2 = Port A and B
        CPOL             -> 0 or 1
        CPHA             -> 0 or 1
        Baudrate         -> 36, 18, 9, 
                            45 (4.5 MHz), 225(2.25 MHz), 1125(1.125 MHz), 
                            5625(0.5625 MHz), 2812(0.28125 MHz)
        LSBorMSB         -> 1 = MSB first
                            0 = LSB first
        DataFormat       -> 0 = 8 bits
                            1 = 16 bits
        NSS_mode         -> 1 = NSS/SS is controlled by software
                            0 = NSS/SS is controlled by hardware
        CRC_mode         -> 1 = CRC Enable
                            0 = CRC Disable
        multimaster_mode -> 1 = Multi master mode enable
                            0 = Multi master mode disable
        bidir_mode       -> 1 = Bidirection Data mode enabled (1 clock and 1 bidirectional mode)
                         -> 0 = Bidirection Data mode disabled (1 clock and 1 data wire)
        TxorRX           -> 1 = Receive only
                         -> 0 = Transmitter only
        
        
        Mode      CPOL  CPHA
        0          0     0
        1          0     1
        2          1     0
        3          1     1
        
@return: Returns 1 if master mode is enabled
         Returns 0 if master mode is not enabled
*/

int SPI_Master_Half_Duplex_Init(SPI_TypeDef *spi, uint8_t Port, uint8_t CPOL, uint8_t CPHA, int BaudRate, uint8_t LSBorMSB, uint8_t DataFormat, uint8_t NSS_mode, uint8_t CRC_mode, uint8_t multimaster, uint8_t bidir_mode, uint8_t TxorRX );

/*
@function:- The function sets up the SPI block in Simplex Mode. If only Rx or only Tx mode is selected, then use the respective SPI_RX or SPI_TX functions.

@param :-
        *spi             -> SPI1, SPI2
        Port             -> 0 = Port A 
                            1 = Port B
                            2 = Port A and B                    
        CPOL             -> 0 or 1
        CPHA             -> 0 or 1
        Baudrate         -> 36, 18, 9, 
                            45 (4.5 MHz), 225(2.25 MHz), 1125(1.125 MHz), 
                            5625(0.5625 MHz), 2812(0.28125 MHz)
        LSBorMSB         -> 1 = MSB first
                            0 = LSB first
        DataFormat       -> 0 = 8 bits
                            1 = 16 bits
        NSS_mode         -> 1 = NSS/SS is controlled by software
                            0 = NSS/SS is controlled by hardware
        CRC_mode         -> 1 = CRC Enable
                            0 = CRC Disable
        multimaster_mode -> 1 = Multi master mode enable
                            0 = Multi master mode disable
        TxorRX           -> 1 = Receive only
                         -> 0 = Transmitter only
        Mode      CPOL  CPHA

        0          0     0

        1          0     1

        2          1     0

        3          1     1
        
@return: Returns 1 if master mode is enabled
         Returns 0 if master mode is not enabled

*/
int SPI_Master_Simplex_Init(SPI_TypeDef *spi, uint8_t Port, uint8_t CPOL, uint8_t CPHA, int BaudRate, uint8_t LSBorMSB, uint8_t DataFormat, uint8_t NSS_mode, uint8_t CRC_mode, uint8_t multimaster, uint8_t TxorRX );
//

/*
@function : This function takes an array as input and sends out the data via MOSI pin.

@param: Integer array

@return: none
*/

void SPI_Send_Data(SPI_TypeDef *spi, int data[]);

/*
@function : This function receives data on MISO pin and fills the buffer for application processing. Thr user shall use revceive_buffer[] for processing.

@param: length -> number of bytes required.

@return: none
*/

void SPI_Recieve_Data(SPI_TypeDef *spi, int length);
//

/*
@attribute: This function is a simple implementation of Full duplex communication. Function sends out 1 byte of data and receives one byte of
            data simultaneously.
 
@param: spi -> SPI1 or SPI2

@return: Value in SPI Data Register.
*/
int SPI_Full_Duplex_Transmission(SPI_TypeDef *spi,int tx_data);
//

/*

@attribute: Interrupt handler should be copied to main.c file whenever it is needed.

@param : none

@return: none

*/

void SPI1_IRQHandler(void);
//

/*

@attribute: Interrupt handler should be copied to main.c file whenever it is needed. The user should comment the IF 

						statement not used in application.



@param : none



@return: none

*/

void SPI2_IRQHandler(void);
//

/*

@attribute: This function enables software interrupts and should be used along with SPIx_IRQHandler() 



@parameter: spi -> SPI1 or SPI2

						interrupt_type -> 0 = Transtmit buffer empty

															1 = Receive buffer not empty

															2 = Master Mode fault or Overrun error or CRC error

												



@return: none



*/



void SPI_Interrupt_Enable(SPI_TypeDef *spi, int interrupt_type);
//

/*
@attribute: This function enables SPI block

@param: spi -> SPI1 or SPI

@return: none
*/

void SPI_Enables(SPI_TypeDef *spi);
//


#endif
