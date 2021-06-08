/*
 * OLED.h
 *
 *  Created on: 08-Jun-2021
 *      Author: Kunal
 */

#ifndef OLED_DISPLAY_OLED_H_
#define OLED_DISPLAY_OLED_H_

#include "main.h"
#include "I2C/I2C.h"
#include "GPIO/GPIO.h"
#include "OLED_text.h"

#define OLED_Address	0x78
#define command_byte	0x00
#define data_byte	    0x40
#define screen_128_64	0x00
#define screen_64_32    0x01

struct I2C_Config OLED;

void OLED_Init(I2C_TypeDef *I2C, uint8_t screen_size);

void OLED_Command_n_Data(uint8_t cmd, uint8_t data);

void OLED_Command(uint8_t cmd);

void OLED_Send_Data(uint8_t data);

void OLED_Init(I2C_TypeDef *I2C, uint8_t screen_size);

void OLED_Set_Cursor(uint8_t x, uint8_t y);

void OLED_Blank(void);

void OLED_Print(uint8_t x,uint8_t y,char buf);

#endif /* OLED_DISPLAY_OLED_H_ */

