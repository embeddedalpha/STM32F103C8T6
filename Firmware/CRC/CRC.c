/*
 * CRC.c
 *
 *  Created on: Feb 27, 2021
 *      Author: Kunal
 */


#include "CRC.h"

void reset_CRC(void)
{
	CRC -> CR |= CRC_CR_RESET;	//RESET CRC
}

uint32_t get_CRC(uint32_t in_CRC)
{
	uint32_t out_CRC;
	CRC ->DR = in_CRC;	//STORE INCOMING DATA IN CRC DATA REGISTER
	NOP_Delay_CPU_Ticks(4);
	asm("NOP");
	out_CRC = CRC -> DR;
    return out_CRC;
}

