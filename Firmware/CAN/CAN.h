/*
*********************************************************************************************************************************
@file:    CAN.H
@author:  Kunal Salvi
@version: V3.05.0
@date:    29/2/2020
@brief:   CAN Header File. 
		  This file contains the prototype of functions in CAN.c file.
		  By calling various "Init" functions, the user can configure 
		  the CAN Hardware Peripheral in any of the permitted modes. 
					
@attention: This file aims at providing the user an abrstraction layer to the CAN peripheral
			and is tested on STM32f103C8T6. This file is free for use to any person or corporation.
			In case of failure of code/product due to third party tampering, the author will not be
			responsible. This code is published under MIT License.
	
*********************************************************************************************************************************	
*/


#ifndef _CAN_H_
#define _CAN_H_

#include "stm32f10x.h"

struct CAN_Standard_Frame{
    uint16_t id;
    uint8_t  data[8];
    
}

struct CAN_Extended_Frame{
    uint16_ id;
    uint32 extended_id;
    uint8_t data[8];
}

#define CAN_BitRate_1000_kbps   1000
#define CAN_BitRate_500_kbps    500
#define CAN_BitRate_250_kbps    250
#define CAN_BitRate_125_kbps    125
#define CAN_BitRate_100_kbps    100
#define CAN_BitRate_75_kbps     75
#define CAN_BitRate_50_kbps     50
#define CAN_BitRate_10_kbps     10






#endif
