#include "ILI9341.h"


void ILI9341_Command_Low(void)
{
	GPIOB -> BSRR |= GPIO_BSRR_BS0;
}

void ILI9341_Command_High(void)
{
	GPIOB -> BSRR |= GPIO_BSRR_BR0;
}


//*********************************************************************************************************************************************
void ILI9341_Display_Init()
{

}


void ILI9341_Display_Inversion_OFF(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	ILI9341_Command_High();
	SPI_Master_TX(SPI1,0x20);
	SPI_NSS_HIGH();
	ILI9341_Command_Low();
}
void ILI9341_Display_Inversion_ON(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	ILI9341_Command_High();
	SPI_Master_TX(SPI1,0x21);
	SPI_NSS_HIGH();
	ILI9341_Command_Low();
}


void ILI9341_Display_OFF(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	ILI9341_Command_High();
	SPI_Master_TX(SPI1,0x28);
	SPI_NSS_HIGH();
	ILI9341_Command_Low();
}


void ILI9341_Display_ON(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	ILI9341_Command_High();
	SPI_Master_TX(SPI1,0x29);
	SPI_NSS_HIGH();
	ILI9341_Command_Low();
}

void ILI9341_Reset_Low(void)
{
	GPIOB -> BSRR |= GPIO_BSRR_BS1;
}

void ILI9341_Reset_High(void)
{
	GPIOB -> BSRR |= GPIO_BSRR_BS1;
}

void ILI9341_Define_Window(uint16_t X1, uint16_t Y1, uint16_t W, uint16_t H)
{
	uint16_t X2 = (X1 + W - 1);
	uint16_t Y2 = (Y1 + H - 1);
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	ILI9341_Command_Low();
	SPI_Master_TX(SPI1,0x2A); //
	ILI9341_Command_High();
	SPI_Master_TX(SPI1,X1 >> 8);
	SPI_Master_TX(SPI1,X1 & 0xFF);
	SPI_Master_TX(SPI1,X2 >> 8);
	SPI_Master_TX(SPI1,X2 & 0xFF);
	ILI9341_Command_Low();
	SPI_Master_TX(SPI1,0x2B);
	ILI9341_Command_High();
	SPI_Master_TX(SPI1,Y1 >> 8);
	SPI_Master_TX(SPI1,Y1 & 0xFF);
	SPI_Master_TX(SPI1,Y2 >> 8);
	SPI_Master_TX(SPI1,Y2 & 0xFF);
	SPI_NSS_HIGH();
}


uint32_t ILI9341_Get_Cursor(uint16_t x, uint16_t y )
{
	uint32_t dummy;
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	ILI9341_Command_Low();
	SPI_Master_TX(SPI1,0x3E);
	ILI9341_Delay(3);
	ILI9341_Command_High();
	dummy |= SPI_Master_RX() << 16;
	dummy |= SPI_Master_RX() << 8;
	dummy |= SPI_Master_RX();
	SPI_NSS_HIGH();
	return dummy;
}


void ILI9341_Set_Cursor(uint16_t x, uint16_t y )
{
	ILI9341_Define_Window(x,y,x,y);
}


void ILI9341_Draw_Pixel()
