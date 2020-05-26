#include "OLED_SPI.h"



void OLED_Init(void)
{

	RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_SPI1EN | RCC_APB2ENR_AFIOEN;
	GPIOA -> CRL = (ALT_PUSH_PULL_OUTPUT << 4*7) | (ALT_PUSH_PULL_OUTPUT << 4*5) |
			       (GEN_PUSH_PULL_OUTPUT << 4*4) | (GEN_PUSH_PULL_OUTPUT << 4*3) |
			       (GEN_PUSH_PULL_OUTPUT << 4*2);
	struct SPI_Master_Parameters oled;
	oled.Baudrate = 4;
	oled.BiDirectional_Mode = 0;
	oled.CPHA = 1;
	oled.CPOL = 1;
	oled.DataFormat = Bit_8;
	oled.LSBorMSB = MSB;
	oled.Slave_Management = Software_Managed;
	oled.TxDMA = ENABLE;
	SPI_Master_Config(SPI1,oled);
	SPI_Master_Enable(SPI1);

	OLED_Command(0xA8,width);
	OLED_Command(0xD3,0x00);
	OLED_Single_Command(0x40);
	OLED_Single_Command(0xA0);
	OLED_Single_Command(0xC0);
	OLED_Command(0xDA, 2);
	OLED_Command(0x81, 0x7f);
	OLED_Single_Command(0xA4);
	OLED_Single_Command(0xA6);
	OLED_Command(0xD5, 0x80);
	OLED_Command(0x8D, 0x14);
	OLED_Single_Command(0xAf);

}


void OLED_Vertical_Horizontal_Scroll(int scroll, int start_page, int end_page)
{
	if(scoll == Vertical_and_Right_Horizontal_Scroll)
	{
		OLED_Command(0x29,0x00);
	}
	else if (scroll == Vertical_and_Left_Horizontal_Scroll) {
		OLED_Command(0x2a,0x00);
	}
	else{
		OLED_Command(0x29,0x00);
	}
	OLED_Single_Command(start_page);
	OLED_Single_Command(0x00);
	OLED_Single_Command(end_page);
	OLED_Single_Command(0x01);

}

void OLED_Scroll_Activate(void)
{
OLED_Single_Command(0x2f);
}

void OLED_Scroll_Deactivate(void)
{
	OLED_Single_Command(0x2e);
}


/***************************************************************************************************************************************************************/
void OLED_Command(int command, int data)
{
	SPI_NSS_HIGH();
	OLED_DC_HIGH();
	SPI_NSS_LOW();
	OLED_DC_LOW();
	SPI_Master_TX(SPI1,command);
	SPI_Master_TX(SPI1,data);
	OLED_DC_HIGH();
	SPI_NSS_HIGH();

}

void OLED_Single_Command( int data)
{
	SPI_NSS_HIGH();
	OLED_DC_HIGH();
	SPI_NSS_LOW();
	OLED_DC_LOW();
	SPI_Master_TX(SPI1,data);
	OLED_DC_HIGH();
	SPI_NSS_HIGH();

}

void OLED_Send_Data(int* data, int length)
{
	SPI_NSS_HIGH();
	OLED_DC_LOW();
	OLED_DC_HIGH();
	SPI_NSS_LOW();

}

void OLED_DC_LOW(void)
{
     GPIOA -> BSRR &= ~GPIO_BSRR_BR3;  //
}

void OLED_DC_HIGH(void)
{
	GPIOA -> BSRR |= GPIO_BSRR_BR3;
}

void OLED_RESET_LOW(void)
{
     GPIOA -> BSRR &= ~GPIO_BSRR_BR2;  //
}

void OLED_RESET_HIGH(void)
{
	GPIOA -> BSRR |= GPIO_BSRR_BR2;
}

