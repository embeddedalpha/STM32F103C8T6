
#ifndef _CC1101_H_
#define _CC1101_H_

#include "stm32f10x.h"

void CC1101_Write_Strobe(uint8_t strobe);
void CC1101_Write_Reg(uint8_t addr, uint8_t *buffer, uint8_t count);
void CC1101_Read_Status(uint8_t strobe);
void CC1101_Read_Reg(uint8_t addr,uint8_t *buffer, uint8_t count);





#endif
