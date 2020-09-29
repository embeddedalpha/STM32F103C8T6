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

static void printConsole(char *msg, ...){

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



static int scanConsole(char *str, ...)
{

	 va_list vl;
    int i = 0, j=0, ret = 0;
    char buff[100] = {0}, tmp[20], c;
    char *out_loc;
    while(c != ' ')
    {
        if (fread(&c, 1, 1))
        {
 	       buff[i] = USART1->DR;
 	       i++;
 	    }
 	}
 	va_start( vl, str );
 	i = 0;
 	while (str && str[i])
 	{
 	    if (str[i] == '%')
 	    {
 	       i++;
 	       switch (str[i])
 	       {
 	           case 'c':
 	           {
	 	           *(char *)va_arg( vl, char* ) = buff[j];
	 	           j++;
	 	           ret ++;
	 	           break;
 	           }
 	           case 'd':
 	           {
	 	           *(int *)va_arg( vl, int* ) =strtol(&buff[j], &out_loc, 10);
	 	           j+=out_loc -&buff[j];
	 	           ret++;
	 	           break;
 	            }
 	            case 'x':
 	            {
	 	           *(int *)va_arg( vl, int* ) =strtol(&buff[j], &out_loc, 16);
	 	           j+=out_loc -&buff[j];
	 	           ret++;
	 	           break;
 	            }
 	        }
 	    }
 	    else
 	    {
 	        buff[j] =str[i];
            j++;
        }
        i++;
    }
    va_end(vl);
 return ret;
}
