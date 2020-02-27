#include "Console.h"



int Serial_Init(void){
    RCC-> APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOAEN ;
    GPIOA -> CRH |= 11 << 4;
    USART1 -> BRR = 0X1D4C;
    USRAT1 -> CR1 |= USART_CR1_TE | USART_CR1_RE;
    USRAT1 -> CR1 |= USART_CR1_UE;
    
}


int Serial_Write(int c)
{
    while(!(USART1 -> SR & USART_SR_TXE)){}
    USRAT1 -> DR = (c & 0xFF);
    return c;
}


int Serial_Read(void)
{
     while(!(USART1 -> SR & USART_SR_RXNE)){}
     return USART1 - > DR;
}


int fgetc(FILE *f){
    int c;
    
    c = Serial_Read();
    if(c == '\r')
    {
        Serial_Write(c);
        c = '\n';
    }
    Serial_Write(c);
    return c;
}


int fputc(int c, FILE *f)
{
    return Serial_Write(c);
}













