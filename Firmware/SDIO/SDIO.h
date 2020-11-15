#ifndef _SDIO_H_
#define _SDIO_H_


#include "stm32f10x.h"
#include "board.h"



void SDIO_1_Bit_Init(uint32_t data_length);
void SDIO_4_Bit_Init(uint32_t data_length);
void SDIO_8_Bit_Init(uint32_t data_length);

void SDIO_Power_ON(void);
void SDIO_Power_OFF(void);

void SDIO_Send_Command(uint32_t command);
uint8_t SDIO_Read_CMD_Response_(void);
uint32_t SDIO_Read_Response_1(void);
uint32_t SDIO_Read_Response_2(void);
uint32_t SDIO_Read_Response_3(void);
uint32_t SDIO_Read_Response_4(void);






#endif
