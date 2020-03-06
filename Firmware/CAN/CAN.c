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
    CAN1 -> MCR &= ~CAN_MCR_SLEEP; //RESET SLEEP BIT
    while((CAN -> MSR & CAN_MSR_SLAK)){} //WAIT TILL SLAK IS RESET
    CAN1 -> MCR |= CAN_MCR_INRQ;         //SET INRQ BIT 
    while(!(CAN1 -> MSR & CAN_MSR_INAK)){}   //WAIT TILL INAK IS SET
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
    CAN1->MCR &= ~CAN_MCR_INRQL;  //CLEAR INRQ BIT
    while((CAN1->MSR & CAN_MSR_INAK)); //WAIT TILL INAK BIT IS RESET
    CAN1->MCR &= ~CAN_MCR_SLEEP;
    while((CAN1->MSR & CAN_MSR_SLAK)); //WAIT TILL SLAK BIT IS RESET
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
    CAN1 -> MCR |= CAN_MCR_AWUM; //AUTOMATIC WAKEUP FROM SLEEP MODE ON MESSAGE RECEPTION
    CAN1 -> MCR |= CAN_MCR_SLEEP; //ENTER SLEEP MODE
    while(!(CAN1 -> MSR & CAN_MSR_SLAK)){} //WAIT TILL ACKNOWLEDGEMENT IS RECEIVED
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
           CAN1 -> BTR |= (1<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 1  |   TS1[] : 8   | TS2[] : 7
            break;
        };
        
        case 500: 
        {
            CAN1 -> BTR |= (3<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 3  |   TS1[] : 8   | TS2[] : 7
            break;
        };
        
        case 250: 
        {
            CAN1 -> BTR |= (7<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 7  |   TS1[] : 8   | TS2[] : 7
            break;
        };
        
        case 125: 
        {
            CAN1 -> BTR |= (15<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 15  |   TS1[] : 8   | TS2[] : 7
            break;
        };
        
        case 100: 
        {
            CAN1 -> BTR |= (19<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 39  |   TS1[] : 8   | TS2[] : 7
            break;
        };
        
        case 50: 
        {
            CAN1 -> BTR |= (39<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 39  |   TS1[] : 8   | TS2[] : 7
            break;
        };
        
        case 20: 
        {
            CAN1 -> BTR |= (99<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 99  |   TS1[] : 8   | TS2[] : 7
            break;
        }; 
        
        case 10: 
        {
            CAN1 -> BTR |= (199<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 199  |   TS1[] : 8   | TS2[] : 7
            break;
        };
        
        default: 
        {
            CAN1 -> BTR |= (1<< 0) | (8 << 16) | (7 << 20) | (1 << 24); //PRESCALLER : 1  |   TS1[] : 8   | TS2[] : 7
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
            CAN1->BTR |= CAN_BTR_SLIM;   //SET SLIM BIT 
            break;
        };
        
        case 1:
        {   
            CAN1->BTR |= CAN_BTR_LBKM;  //SET LBKM BIT
            break;
        };
        
        case 2:
        {   
            CAN1->BTR |= CAN_BTR_LBKM | CAN_BTR_SLIM;  //SET LBKM  AND SLIM BITS
            break;
        };        
    }
}
//

/***************************************** CAN Trasnmmit Data *************************************************************************
//@function: The function sets up the bitrate for CAN bus
//@param: 
//       mailbox_no               0     ->    Mailbox 0     
//                                1     ->    Mailbox 1
//                                2     ->    Mailbox 2
//       standard_id              Any 11 bit id
//       extended_id              Any 18 bit id
//       dlc                      from 0 to 8
//       data[]                   Array of data to be transmitted
//       priority                 0     ->    Message driven by id of message
//                                1     ->    Message driven by request order
//@return: Returns 1 when data is transmitted.
********************************************************************************************************************************/

int CAN_Transmit_Data_Frame(int mailbox_no, int standard_id, int extended_id, int dlc, int data[], int priority)
{
    int i = 0;
   switch(mailbox_no)
   {
       case 0 : //mailbox 0
       {
           while(!(CAN1 -> TSR & CAN_TSR_TME0)){}
           CAN1 -> TSR |= CAN_TSR_RQCP0;
           if(extended_id != 0)
           {
               CAN1 -> TI0R |= CAN_TI0R_IDE;
               CAN1 -> TI0R |= (standard_id << 21) | (extended_id << 3);
           }
           else
           {
               CAN1 -> TI0R &= ~CAN_TI0R_IDE;
               CAN1 -> TI0R |= (standard_id << 21);
           }
           
           CAN1 -> TDT0R |= dlc << 0;
           
           for(i = 0; i < dlc; i++)
           {
               if(i <= 3)
               {
                   CAN1 -> TDL0R |= data[i] << (8 * i);
               }
               else
               {
                   CAN1 -> TDL0R |= data[i] << (8 * (i-4));
               }
           }
           
           CAN1 -> TI0R |= CAN_TI0R_TXRQ;
           
           if(priority == 0)
           {
               CAN1 -> MCR &= ~CAN_MCR_TXFP;
           }
           if(priority == 1)
           {
               CAN1 -> MCR |=  CAN_MCR_TXFP;
           }
           
           while(!(CAN1 -> TSR & CAN_TSR_TXOK0)){}
           while(!(CAN1 -> TSR & CAN_TSR_RQCP0)){}
           
           
           break;
       };
       
       case 1 : //mailbox 1
       {
           while(!(CAN1 -> TSR & CAN_TSR_TME1)){}
           CAN1 -> TSR |= CAN_TSR_RQCP1;
           if(extended_id != 0)
           {
               CAN1 -> TI1R |= CAN_TI1R_IDE;
               CAN1 -> TI1R |= (standard_id << 21) | (extended_id << 3);
           }
           else
           {
               CAN1 -> TI1R &= ~CAN_TI1R_IDE;
               CAN1 -> TI1R |= (standard_id << 21);
           }
           
           CAN1 -> TDT1R |= dlc << 0;
           
           for(i = 0; i < dlc; i++)
           {
               if(i <= 3)
               {
                   CAN1 -> TDL1R |= data[i] << (8 * i);
               }
               else
               {
                   CAN1 -> TDL1R |= data[i] << (8 * (i-4));
               }
           }
           
           CAN1 -> TI1R |= CAN_TI1R_TXRQ;
           
           if(priority == 0)
           {
               CAN1 -> MCR &= ~CAN_MCR_TXFP;
           }
           if(priority == 1)
           {
               CAN1 -> MCR |=  CAN_MCR_TXFP;
           }
           
           while(!(CAN1 -> TSR & CAN_TSR_TXOK1)){}
           while(!(CAN1 -> TSR & CAN_TSR_RQCP1)){}
           
           
           break;
       }; 
       
       case 2 : //mailbox 2
       {
           while(!(CAN1 -> TSR & CAN_TSR_TME2)){}
           CAN1 -> TSR |= CAN_TSR_RQCP2;
           if(extended_id != 0)
           {
               CAN1 -> TI2R |= CAN_TI2R_IDE;
               CAN1 -> TI2R |= (standard_id << 21) | (extended_id << 3);
           }
           else
           {
               CAN1 -> TI2R &= ~CAN_TI2R_IDE;
               CAN1 -> TI2R |= (standard_id << 21);
           }
           
           CAN1 -> TDT2R |= dlc << 0;
           
           for(i = 0; i < dlc; i++)
           {
               if(i <= 3)
               {
                   CAN1 -> TDL2R |= data[i] << (8 * i);
               }
               else
               {
                   CAN1 -> TDH2R |= data[i] << (8 * (i-4));
               }
           }
           
           CAN1 -> TI2R |= CAN_TI2R_TXRQ;
           
           if(priority == 0)
           {
               CAN1 -> MCR &= ~CAN_MCR_TXFP;
           }
           if(priority == 1)
           {
               CAN1 -> MCR |=  CAN_MCR_TXFP;
           }
           
           while(!(CAN1 -> TSR & CAN_TSR_TXOK2)){}
           while(!(CAN1 -> TSR & CAN_TSR_RQCP2)){}
           
           
           break;
       };
   }
   
   return 1;
    
}
//

