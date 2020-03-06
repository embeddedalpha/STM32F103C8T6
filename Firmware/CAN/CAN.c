/**********************************************************************************************************************************
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
	
**********************************************************************************************************************************/	


#include "CAN.h"

/***************************************** Initialization Mode *****************************************************************
//@function: The function sets up the CAN controller in Initialization mode.
//@param: none
//@return: Returns 1 if Initialization is successful
********************************************************************************************************************************/

int CAN_Initialization_Mode()
{
    CAN -> MCR &= ~CAN_MCR_SLEEP; //RESET SLEEP BIT
    while((CAN -> MSR & CAN_MSR_SLAK)){} //WAIT TILL SLAK IS RESET
    CAN -> MCR |= CAN_MCR_INRQ;         //SET INRQ BIT 
    while(!(CAN -> MSR & CAN_MSR_INAK)){}   //WAIT TILL INAK IS SET
    return 1;
}
//

/***************************************** Normal Mode *************************************************************************
//@function: The function sets up the CAN controller in Normal mode.
//@param: none
//@return: Returns 1 if Normalization is successful
********************************************************************************************************************************/

int CAN_Normal_Mode()
{
    CAN->MCR &= ~CAN_MCR_INRQL;  //CLEAR INRQ BIT
    while((CAN->MSR & CAN_MSR_INAK)); //WAIT TILL INAK BIT IS RESET
    CAN->MCR &= ~CAN_MCR_SLEEP;
    while((CAN->MSR & CAN_MSR_SLAK)); //WAIT TILL SLAK BIT IS RESET
    return 1;
}
//

/***************************************** Sleep Mode *************************************************************************
//@function: The function sets up the CAN controller in Sleep mode.
//@param: none
//@return: Returns 1 if controller is in sleep mode
********************************************************************************************************************************/

int CAN_Sleep_Mode()
{
    CAN -> MCR |= CAN_MCR_AWUM; //AUTOMATIC WAKEUP FROM SLEEP MODE ON MESSAGE RECEPTION
    CAN -> MCR |= CAN_MCR_SLEEP; //ENTER SLEEP MODE
    while(!(CAN -> MSR & CAN_MSR_SLAK)){} //WAIT TILL ACKNOWLEDGEMENT IS RECEIVED
}
//

/***************************************** CAN Bitrate *************************************************************************
//@function: The function sets up the bitrate for CAN bus
//@param: 
//       baudrate           CAN_BitRate_1000_kbps   1000     [Defined in CAN.h]
//                          CAN_BitRate_500_kbps    500
//                          CAN_BitRate_250_kbps    250
//                          CAN_BitRate_125_kbps    125
//                          CAN_BitRate_100_kbps    100
//                          CAN_BitRate_75_kbps     75
//                          CAN_BitRate_50_kbps     50
//                          CAN_BitRate_10_kbps     10
//@return: none
********************************************************************************************************************************/

void CAN_Bitrate(int baudrate)
{
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
        
        case 100: 
        {
            CAN -> BTR |= (19<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 39  |   TS1[] : 8   | TS2[] : 7
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
}
//

/***************************************** CAN Test Mode *************************************************************************
//@function: The function sets up the bitrate for CAN bus
//@param: 
//       mode               0     ->    Silent Mode     
//                          1     ->    Loop Back Mode
//                          2     ->    Silent Loop Back Mode
//@return: none
********************************************************************************************************************************/

void CAN_Test_Mode_Setup(int mode)
{
    switch(mode)
    {
        case 0:
        {   
            CAN->BTR |= CAN_BTR_SLIM;   //SET SLIM BIT 
            break;
        };
        
        case 1:
        {   
            CAN->BTR |= CAN_BTR_LBKM;  //SET LBKM BIT
            break;
        };
        
        case 2:
        {   
            CAN->BTR |= CAN_BTR_LBKM | CAN_BTR_SLIM;  //SET LBKM  AND SLIM BITS
            break;
        };        
    }
}
//
