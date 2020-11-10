#ifndef _ETH_H_
#define _ETH_H_


#include "stm32f10x.h"
#include "board.h"


void Ethernet_MII_Init(void);
void Ethernet_RMII_Init(void);
uint16_t Ethernet_SMI_Read(uint8_t PHY_Address,uint8_t PHY_Register);
void Ethernet_SMI_Write(uint8_t PHY_Address,uint8_t PHY_Register, uint16_t data);


#endif
