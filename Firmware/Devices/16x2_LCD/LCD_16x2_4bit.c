#include "LCD_16x2_4Bit.h"


void LCD_Init(void)
{
   GPIO_Setup(GPIOB, 0, GENERAL_PUSH_PULL_OUTPUT); //D4
   GPIO_Setup(GPIOB, 1, GENERAL_PUSH_PULL_OUTPUT); //D5
   GPIO_Setup(GPIOB, 2, GENERAL_PUSH_PULL_OUTPUT); //D6
   GPIO_Setup(GPIOB, 3, GENERAL_PUSH_PULL_OUTPUT); //D7
   
   GPIO_Setup(GPIOA, 5, GENERAL_PUSH_PULL_OUTPUT); //RS
   GPIO_Setup(GPIOA, 6, GENERAL_PUSH_PULL_OUTPUT); //RW
   GPIO_Setup(GPIOA, 7, GENERAL_PUSH_PULL_OUTPUT); //EN
   
   GPIOA->ODR = 0x00;
   GPIOB->ODR = 0x00;
  
   lcd_cmd(0x02);
   delay();
   lcd_cmd(0x28);
   delay();
   lcd_cmd(0x0c);
   delay();
   lcd_cmd(0x06);
   delay();
   lcd_cmd(0x01);
   delay();
   lcd_cmd(0x80);
   delay();
}

void delay()
{
   int i;
   for(i = 0; i <= 12000; i++)
      {}
   
}

   void lcd_cmd(unsigned char c)
   {  
    GPIOB -> ODR = (c & 0xF0) >> 4;
    delay();
    GPIOA->ODR = 0x04 << 5;
    delay();
    GPIOA->ODR = 0x00 << 5;
    delay();
      
    GPIOB -> ODR = c & 0x0F;
    delay();
    GPIOA->ODR = 0x04 << 5;
    delay();
    GPIOA->ODR = 0x00 << 5;
    delay(); 
      }
      
      
    void lcd_data(unsigned char c)
   {
    GPIOB -> ODR = (c & 0xF0) >> 4;
    delay();
    GPIOA->ODR = 0x05 << 5;
    delay();
    GPIOA->ODR = 0x01 << 5;
    delay();
    
    GPIOB -> ODR = c & 0x0F;
    delay();
    GPIOA->ODR = 0x05 << 5;
    delay();
    GPIOA->ODR = 0x01 << 5;
    delay();
     
      }
      
      
 void LCD_Send_Data(char *c)
  {
   int i;
   for(i=0; c[i] != 0; i++)
   {
    if((c[i] == '\n'))
    {
      lcd_cmd(0xC0);
      delay();
    }
  
  lcd_data(c[i]);  
    }
       lcd_cmd(0x01);
      delay();
   }
