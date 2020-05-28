#include "OLED_SPI.h"







void OLED_Init(void)
{
	int a[5];
	RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_SPI1EN | RCC_APB2ENR_AFIOEN;
	RCC -> AHBENR |= RCC_AHBENR_DMA1EN;
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

	a[0] = width;
	OLED_Command(0xA8,a,1);
	a[0] = 0x00;
	OLED_Command(0xD3,a,1);
	OLED_Single_Command(0x40);
	OLED_Single_Command(0xA0);
	OLED_Single_Command(0xC0);
	a[0] = 0x02;
	OLED_Command(0xDA,a,1);
	a[0] = 0x7f;
	OLED_Command(0x81,a,1);
	OLED_Single_Command(0xA4);
	OLED_Single_Command(0xA6);
	a[0] = 0x80;
	OLED_Command(0xD5, a,1);
	a[0] = 0x14;
	OLED_Command(0x8D, a,1);
	OLED_Single_Command(0xAf);
	a[0] = 0x00;
	OLED_Command(0x20, a,1); //horizontal addressing mode

}


void OLED_Vertical_Horizontal_Scroll(int scroll, int start_page, int end_page)
{
	int a[5];
	if(scoll == Vertical_and_Right_Horizontal_Scroll)
	{
		a[0] = 0x00;
		a[1] = start_page;
		a[2] = 0x00;
		a[3] = end_page;
		a[4] = 0x01;
		OLED_Command(0x29,a,5);
	}
	else if (scroll == Vertical_and_Left_Horizontal_Scroll) {
		a[0] = 0x00;
		a[1] = start_page;
		a[2] = 0x00;
		a[3] = end_page;
		a[4] = 0x01;
		OLED_Command(0x29,a,5);
		OLED_Command(0x2a,a,5);
	}
	else{
		a[0] = 0x00;
		a[1] = start_page;
		a[2] = 0x00;
		a[3] = end_page;
		a[4] = 0x01;
		OLED_Command(0x29,a,5);
	}



}

void OLED_Scroll_Activate(void)
{
OLED_Single_Command(0x2f);
}

void OLED_Scroll_Deactivate(void)
{
	OLED_Single_Command(0x2e);
}

void OLED_Send_Data(int* data, int length)
{
	DMA1_Channel3->CMAR = &(data);
	DMA1_Channel3->CPAR = &(SPI1->DR);
	DMA1_Channel3->CNDTR = length;
	DMA1_Channel3->CCR = (3 << 12) | (2 << 8) | (2 << 10)  | (1 << 4) | (1 << 7);

	SPI_NSS_HIGH();
	OLED_DC_LOW();
	SPI_NSS_LOW();
	OLED_DC_HIGH();
	DMA1_Channel3->CCR |= 1<<0;
	while(!(DMA1->ISR & DMA_ISR_TCIF3)){}
	DMA1_Channel3->CCR &= ~(1<<0);
	SPI_NSS_HIGH();
	OLED_DC_LOW();

}

void OLED_Set_Pixel_Address(int Column_Address_Start, int Column_Address_end, int Page_Address_Start, int Page_Address_End)
{
	int a[5];
	a[0] = Column_Address_Start;
	a[1] = Column_Address_end;
	OLED_Command(0x21,a,2);
	a[0] = Page_Address_Start;
	a[1] = Page_Address_End;
	OLED_Command(0x22,a,2);

}

void OLED_Printf(uint8_t *letter)
{

}

void OLED_DisplayChar(uint8_t ch)
{

}
/***************************************************************************************************************************************************************/
void OLED_Command(int command, int data[], int length)
{
	SPI_NSS_HIGH();
	OLED_DC_HIGH();
	SPI_NSS_LOW();
	OLED_DC_LOW();
	SPI_Master_TX(SPI1,command);
	for(int i = 0;i<length; i++)
	{
		SPI_Master_TX(SPI1,data[i]);
	}
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
