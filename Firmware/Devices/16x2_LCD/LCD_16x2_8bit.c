#include "LCD_16x2_8Bit.h"


void LCD_Init(void)
{
   GPIO_Setup(GPIOB, 0, GENERAL_PUSH_PULL_OUTPUT); //D0
   GPIO_Setup(GPIOB, 1, GENERAL_PUSH_PULL_OUTPUT); //D1
   GPIO_Setup(GPIOB, 2, GENERAL_PUSH_PULL_OUTPUT); //D2
   GPIO_Setup(GPIOB, 3, GENERAL_PUSH_PULL_OUTPUT); //D3
   GPIO_Setup(GPIOB, 4, GENERAL_PUSH_PULL_OUTPUT); //D4
   GPIO_Setup(GPIOB, 5, GENERAL_PUSH_PULL_OUTPUT); //D5
   GPIO_Setup(GPIOB, 6, GENERAL_PUSH_PULL_OUTPUT); //D6
   GPIO_Setup(GPIOB, 7, GENERAL_PUSH_PULL_OUTPUT); //D7
   
   GPIO_Setup(GPIOA, 5, GENERAL_PUSH_PULL_OUTPUT); //RS
   GPIO_Setup(GPIOA, 6, GENERAL_PUSH_PULL_OUTPUT); //RW
   GPIO_Setup(GPIOA, 7, GENERAL_PUSH_PULL_OUTPUT); //EN
   
   GPIOA->ODR = 0x00;
   GPIOB->ODR = 0x00;
  
   lcd_cmd(0x38);
   delay();
   lcd_cmd(0x01);
   delay();
   lcd_cmd(0x10);
   delay();
   lcd_cmd(0x0C);
   delay();
  
}


void delay()
{
   int i;
   for(i = 0; i <= 12000; i++){}
   
}

void lcd_cmd(unsigned char c)
{
    GPIOB -> ODR = c;
    delay();
    GPIOA->ODR = 0x04 << 5;
    delay();
    GPIOA->ODR = 0x00 << 5;
 }

 void lcd_data(unsigned char c)
 {
    GPIOB -> ODR = c;
    delay();
    GPIOA->ODR = 0x05 << 5;
    delay();
    GPIOA->ODR = 0x01 << 5;
  }

  void LCD_SEND_DATA(char *c)
  {
	 int i;
	 for(i = 0; c[i] != 0; i++)
	 {
	    lcd_data(c[i]);
	 }
  }

void LCD_new_line()
{
 lcd_cmd(0xC0);
 delay();
}
