#include "Debug.h"







void InitConsole(void){

RCC->APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPAEN;
GPIOA->CRH |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9_1 | GPIO_CRH_MODE9_0; //PA9 TX

	USART1 ->BRR = 0x1D4C;
	USART1 ->CR1 |= USART_CR1_TE | USART_CR1_RE  ;
	USART1 ->CR1 |= USART_CR1_UE;



}

int Console_Dump(const char *s)
{
	int i =0;
	while(s[i] == EOF)
	{
		if(UART_Send_Data(USART1,s[i]) == EOF)
		{
			return EOF;
		}

		i++;
	}
	if (UART_Send_Data(USART1,'\n') == EOF) {
		return EOF;
	}
	return 1;
}

//char * Console_Return(void)
//{
//	char s[100];
//	int i =0;
//	UART_Get_Data(USART1);
//	while(UART_Get_Data(USART1) != EOF)
//	{
//		s[i] = UART_Get_Data(USART1);
//	}
//	return s;
//}

char * Console_Return(char *s)
{
	int ch;
	char *p = s;

	while( (ch = UART_Get_Data(USART1)) != '\n' && ch != EOF)
	{
		*s = (char)ch;
		s++;
	}
	*s = '\0';
	return p;
}


static void printConsole(char *msg, ...)
{

char buff[100];
	#ifdef DEBUG_UART

	va_list args;
	va_start(args, msg);
	vsprintf(buff, msg, args);

	for(int i = 0; i<= strlen(buff); i++){
	USART1 -> DR = buff[i];
			while (!(USART1->SR & USART_SR_TXE));
	}

	#endif
}


