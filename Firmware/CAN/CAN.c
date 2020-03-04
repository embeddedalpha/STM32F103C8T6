/*
*********************************************************************************************************************************
@file:    CAN.c
@author:  Kunal Salvi
@version: V3.05.0
@date:    29/2/2020
@brief:   CAN Source File. 
This file contains the functions declared in CAN.h file.
By calling various "Init" functions, the user can configure 
the CAN Hardware Peripheral in any of the permitted modes. 
					
@attention: This file aims at providing the user an abrstraction layer to the CAN peripheral
and is tested on STM32f103C8T6. This file is free for use to any person or corporation.
In case of failure of code/product due to third party tampering, the author will not be
responsible. This code is published under MIT License.
	
*********************************************************************************************************************************	
*/

#include "CAN.h"

int CAN_Init_Mode(int baudrate)
{
    CAN -> MCR &= ~CAN_MCR_SLEEP; //RESET SLEEP BIT
    while((CAN -> MSR & CAN_MSR_SLAK)){} //WAIT TILL SLAK IS RESET
    CAN -> MCR |= CAN_MCR_INRQ;         //SET INRQ BIT 
    while(!(CAN -> MSR & CAN_MSR_INAK)){}   //WAIT TILL INAK IS SET
    
    switch(baudrate)
    {
        case 1000: 
        {
           CAN -> BTR |= (1<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 1  |   TS1[] : 8   | TS2[] : 7
            break;
        };
        
        case 500: 
        {
            CAN -> BTR |= (3<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 3  |   TS1[] : 8   | TS2[] : 7
            break;
        };
        
        case 250: 
        {
            CAN -> BTR |= (7<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 7  |   TS1[] : 8   | TS2[] : 7
            break;
        };
        
        case 125: 
        {
            CAN -> BTR |= (15<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 15  |   TS1[] : 8   | TS2[] : 7
            break;
        };
        
        case 50: 
        {
            CAN -> BTR |= (39<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 39  |   TS1[] : 8   | TS2[] : 7
            break;
        };
        
        case 20: 
        {
            CAN -> BTR |= (99<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 99  |   TS1[] : 8   | TS2[] : 7
            break;
        }; 
        
        case 10: 
        {
            CAN -> BTR |= (199<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 199  |   TS1[] : 8   | TS2[] : 7
            break;
        };
        
        default: 
        {
            CAN -> BTR |= (1<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 1  |   TS1[] : 8   | TS2[] : 7
            break;
        };        
    }
    
    CAN -> MCR |= CAN_MCR_AWUM; //AUTOMATIC WAKEUP FROM SLEEP MODE ON MESSAGE RECEPTION
    
    
}

int CAN_Normal_Mode()
{}

int CAN_Sleep_Mode()
{}


