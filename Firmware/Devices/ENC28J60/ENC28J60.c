/*
 * ENC28J60.c
 *
 *  Created on: 25-May-2021
 *      Author: Kunal
 */


#include "ENC28J60.h"


uint16_t Read_Phy_Register(uint8_t reg_address)
{
	uint8_t status = 0;
	int counter = 0;
	Write_Register(MIREGADR, reg_address, Bank2);
	Write_Register(MICMD, 0x01, Bank2);
	Delay_us(11);
	do{
		status = Read_Register(MISTAT, Bank3);
		counter++;
	}while(status != 0 || counter <= 1000);
	if(counter > 1000) return 1000;
	status = 0;
	Write_Register(MICMD, 0x00, Bank2);
	return (Read_Register(MIRDH, Bank2) << 8 | Read_Register(MIRDL, Bank2));

}


bool Write_Phy_Register(unit8_t reg_address, uint16_t data)
{
	uint8_t status = 0;
	int counter = 0;
	Write_Control_Register(MIREGADR, reg_address, Bank2);
	Write_Control_Register(MIWRL, (data & 0x00FF), Bank2);
	Write_Control_Register(MIWRH, ((data & 0xFF00) >> 8), Bank2);
	Delay_us(11);
	do{
		status = Read_Control_Register(MISTAT, Bank3);
		counter++;
	}while(status != 0 || counter <= 1000);
	if(counter > 1000) return ER;
	return SUCCESS;
}


