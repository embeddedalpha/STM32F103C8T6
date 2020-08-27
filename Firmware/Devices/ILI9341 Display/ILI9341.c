#include "ILI9341.h"


void ILI9341_Delay(int delay_ms){}


void ILI9341_Display_Init()
{

}

void ILI9341_NOP(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x00);
	SPI_NSS_HIGH();
}


void ILI9341_Software_Reset(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x01);
	SPI_NSS_HIGH();
	ILI9341_Delay(150);

}

void ILI9341_Enter_Sleep_Mode(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x10);
	SPI_NSS_HIGH();

}

void ILI9341_Sleep_Out(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x11);
	SPI_NSS_HIGH();
	ILI9341_Delay(10);

}

void ILI9341_Normal_Dsiplay_Mode(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x12);
	SPI_NSS_HIGH();

}


void ILI9341_Display_Inversion_OFF(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x20);
	SPI_NSS_HIGH();

}

void ILI9341_Display_Inversion_ON(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x21);
	SPI_NSS_HIGH();

}

void ILI9341_Display_OFF(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x28);
	SPI_NSS_HIGH();

}

void ILI9341_Display_ON(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x29);
	SPI_NSS_HIGH();

}




void ILI9341_Memory_Write(uint16_t* data, int length)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	ILI9341_Command_High();
	SPI_Master_TX(SPI1,0x2c);
	ILI9341_Command_Low();
	for(int i =0 ; i < length; i++)
	{
		SPI_Master_TX(SPI1, *data++);
	}
	SPI_NSS_HIGH();

}




void ILI9341_Reset_Low(void)
{
	GPIOB -> BSRR |= GPIO_BSRR_BS1;
}

void ILI9341_Reset_High(void)
{
	GPIOB -> BSRR |= GPIO_BSRR_BS1;
}

void ILI9341_Command_Low(void)
{
	GPIOB -> BSRR |= GPIO_BSRR_BS0;
}

void ILI9341_Command_High(void)
{
	GPIOB -> BSRR |= GPIO_BSRR_BR0;
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



void ILI9341_Draw_Pixel(uint16_t x, uint16_t y, uint16_t* color)
{

	if((x < Display_Width)&& (y < Display_Height))
	{
		ILI9341_Define_Window(x,y,1,1);
		ILI9341_Memory_Write(color,1);


	}
}


void ILI9341_Memory_Read(int* data, int length)
{
	length += 1;
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x2E);
	//command line high
	for(int i =0 ; i < length; i++)
	{
		*data = SPI_Master_RX();
		*data++;
	}
	SPI_NSS_HIGH();

}


void ILI9341_Vertical_Scroll_Definition(uint16_t TopFixedArea, uint16_t VerticalScrollingArea, uint16_t BottomFixedArea )
{
	uint8_t dummy = 0;
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x33);
	//command line high
	dummy = TopFixedArea & 0xFF00;
	SPI_Master_TX(SPI1,dummy);
	dummy = TopFixedArea & 0x00FF;
	SPI_Master_TX(SPI1,dummy);

	dummy = VerticalScrollingArea & 0xFF00;
	SPI_Master_TX(SPI1,dummy);
	dummy = VerticalScrollingArea & 0x00FF;
	SPI_Master_TX(SPI1,dummy);

	dummy = BottomFixedArea & 0xFF00;
	SPI_Master_TX(SPI1,dummy);
	dummy = BottomFixedArea & 0x00FF;
	SPI_Master_TX(SPI1,dummy);
	SPI_NSS_HIGH();

}


void ILI9341_Vertical_Scrolling_Address(uint16_t address)
{
	uint8_t dummy = 0;
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x37);
	//command line high
	dummy = address & 0xFF00;
	SPI_Master_TX(SPI1,dummy);
	dummy = address & 0x00FF;
	SPI_Master_TX(SPI1,dummy);
}


void ILI9341_Idle_Mode_OFF(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x38);
	SPI_NSS_HIGH();

}


void ILI9341_Idle_Mode_ON(void)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x39);
	SPI_NSS_HIGH();

}

void ILI9341_Write_Memory_Continue(int* data, int length)
{
	length += 1;
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x3c);
	//command line high
	for(int i =0 ; i < length; i++)
	{
		*data = SPI_Master_RX();
		*data++;
	}
	SPI_NSS_HIGH();

}


void ILI9341_Read_Memory_Continue(int* data, int length)
{
	length += 1;
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x3E);
	//command line high
	for(int i =0 ; i < length; i++)
	{
		*data = SPI_Master_RX();
		*data++;
	}
	SPI_NSS_HIGH();

}

uint32_t ILI9341_Get_ScanLine(void)
{
	uint32_t dummy = 0;
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x3E);
	ILI9341_Delay(3);
	//command line high
	dummy = (dummy & 0xFF0000) | (SPI_Master_RX() << 16);
	dummy = (dummy & 0xFF0000) | (SPI_Master_RX() << 8);
	dummy = dummy | SPI_Master_RX();
	SPI_NSS_HIGH();
}

void ILI9341_Write_Display_Brightness(uint8_t brightness)
{
	SPI_NSS_HIGH();
	SPI_NSS_LOW();
	//command line low
	SPI_Master_TX(SPI1,0x51);
	//command line high
	SPI_Master_TX(SPI1,brightness);
	SPI_NSS_HIGH();

}

