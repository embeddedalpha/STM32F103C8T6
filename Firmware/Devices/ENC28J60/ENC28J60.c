/*
 * ENC28J60.c
 *
 *  Created on: 25-May-2021
 *      Author: Kunal
 */


#include "ENC28J60.h"

void ENC28J60_Init(uint8_t *local_Mac)
{
	ENC_System_Reset();
	//RX buffer
	ENC_Write_Control_Reg(ERXSTL, RX_BUFFER_START & 0x00FF);
	ENC_Write_Control_Reg(ERXSTH, RX_BUFFER_START >> 8);
	ENC_Write_Control_Reg(ERXNDL, RX_BUFFER_END & 0x00FF);
	ENC_Write_Control_Reg(ERXNDH, RX_BUFFER_END >> 8);
	// TX Buffer
	ENC_Write_Control_Reg(ETXSTL, TX_BUFFER_START & 0x00FF);
	ENC_Write_Control_Reg(ETXSTH, TX_BUFFER_START >> 8);
	ENC_Write_Control_Reg(ETXNDL, TX_BUFFER_END & 0x00FF);
	ENC_Write_Control_Reg(ETXNDH, TX_BUFFER_END >> 8);
	//MAC init
	ENC_Write_Control_Reg(MACON1, 0x0D);
	ENC_Write_Control_Reg(MACON2, 0xF1);
	ENC_Write_Control_Reg(MACON4, 0x40);
	ENC_Write_Control_Reg(MAMXFLL, 0xDC);
	ENC_Write_Control_Reg(MAMXFLH, 0x05);
	ENC_Write_Control_Reg(MABBIPG, 0x15);
	ENC_Write_Control_Reg(MAIPGL, 0x12);
	//local MAC
	ENC_Write_Control_Reg(MAADR1, mac[0]);
	ENC_Write_Control_Reg(MAADR2, mac[1]);
	ENC_Write_Control_Reg(MAADR3, mac[2]);
	ENC_Write_Control_Reg(MAADR4, mac[3]);
	ENC_Write_Control_Reg(MAADR5, mac[4]);
	ENC_Write_Control_Reg(MAADR6, mac[5]);
	//phy init
	Write_Phy_Register(PHCON1, 0x100);

}

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


uint8_t ENC_Read_Control_Reg(uint8_t address)
{
	uint8_t x;
	SPI_Master_SS_Deselect(ENC);
	SPI_Master_SS_Select(ENC);
	SPI_Master_TX(ENC, (Read_Control_Register | address));
	x = SPI_Master_RX(ENC);
	SPI_Master_SS_Deselect(ENC);
	return x;
}


void ENC_Write_Control_Reg(uint8_t address, unit8_t data)
{
	SPI_Master_SS_Deselect(ENC);
	SPI_Master_SS_Select(ENC);
	SPI_Master_TX(ENC, (Write_Control_Register | address));
	SPI_Master_TX(ENC, data);
	SPI_Master_SS_Deselect(ENC);
}


bool ENC_Write_Buffer(uint8_t *buffer, int length)
{
	int i;
	Write_Register(ECON2, 1 << 7, BANK0);
	SPI_Master_SS_Deselect(ENC);
	SPI_Master_SS_Select(ENC);
	for(i = 0;i < length;i++)
	{
		SPI_Master_TX(ENC, buffer[i]);
	}
	SPI_Master_SS_Deselect(ENC);
	return SUCCESS;
}

{
	int i;
	if(auto_increment)	Write_Register(ECON2, 1 << 7, BANK0);
	if(length > 0xFFF) return ER;
	SPI_Master_SS_Deselect(ENC);
	SPI_Master_SS_Select(ENC);
	SPI_Master_TX(ENC, Read_Buffer_Memory);
	for(i = 0; i< length;i++)
	{
		buffer[i] = SPI_Master_RX(ENC);
	}
	SPI_Master_SS_Deselect(ENC);
	return buffer;
}
