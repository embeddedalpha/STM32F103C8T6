#include "LCD_16x2.h"

#define set_pin 0b0011

/*
  8 BIT
  PA0 - PA7 === D0 - D7
  PB12 === RS
  PB13 === R/W
  PB14 === EN
  
  4 BIT
  PA0 - PA3 === D4 -D7
  PB12 === RS
  PB13 === R/W
  PB14 === EN
  
*/


void LCD_Init(int bit)
{
    LCD_Pin_Setup(bit);
    
    Timer_Delay_uS(TIM1, 30);
    
    LCD_Write_Command(0x30);
    
    Timer_Delay_uS(TIM1, 10);
    
    LCD_Write_Command(0x30);
          
    Timer_Delay_uS(TIM1, 1);
    
    LCD_Write_Command(0x30);
    
    LCD_Write_Command(0x38);
    
    LCD_Write_Command(0x06);
    
    LCD_Write_Command(0x01);
    
    LCD_Write_Command(0x0F);
    
    
   
}

void LCD_CLEAR_SCREEN(void)
{
    LCD_Write_Command(1);
}

void LCD_Pin_Setup(int bit)
{
    RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;
    
    if(bit == 4)
    {
        GPIOA -> CRL |= (set_pin << 0) | (set_pin << 4) | (set_pin << 8) | (set_pin << 12);
        GPIOB -> CRH |= (set_pin << 16) | (set_pin << 20) | (set_pin << 24);
        
    }
    if(bit == 8)
    {
        GPIOA -> CRL |= (set_pin << 0) | (set_pin << 4) | (set_pin << 8) | (set_pin << 12) | (set_pin << 16) | (set_pin << 20) | (set_pin << 24) | (set_pin << 28) ;
        GPIOB -> CRH |= (set_pin << 16) | (set_pin << 20) | (set_pin << 24);
        
    }
    
    GPIOB -> BSRR |= GPIO_BSRR_BR12 | GPIO_BSRR_BR13; //SET EN AND RW LOW
    
}

void LCD_Write_Command(unsigned char command)
{
    GPIOB -> BSRR |= GPIO_BSRR_BR12 | GPIO_BSRR_BR13; //SET R/S AND RW LOW
    GPIOA -> ODR = command;
    GPIOB -> BSRR |= GPIO_BSRR_BS14;  //set en
    Timer_Delay_nS(TIM1, 250);
    GPIOB -> BSRR |= GPIO_BSRR_BR14; //reset en
}

void LCD_Write_Data(char data)
{
    GPIOB -> BSRR |= GPIO_BSRR_BS12; //RS = high
    GPIOB -> BSRR |= GPIO_BSRR_BR13; //R/W = low
    GPIOA -> ODR = data;
    GPIOB -> BSRR |= GPIO_BSRR_BS14;  //set en
    Timer_Delay_nS(TIM1, 250);
    GPIOB -> BSRR |= GPIO_BSRR_BR14; //reset en  
    
}
