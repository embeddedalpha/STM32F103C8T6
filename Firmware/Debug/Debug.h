#ifndef _DEBUG_
#define _DEBUG_

#include "stm32f10x.h"
#include "stdlib.h"
#include "stdarg.h"
#include "string.h"
#include "USART.h"
#include "stdio.h"
#include <stdint.h>


#define DEBUG_UART  USART1



void InitConsole(void);
static void printConsole(char *msg, ...);
int Console_Dump(const char *s);
char * Console_Return(char *s);

__STATIC_INLINE uint32_t Delay_Config(void)
{

	SysTick->CTRL = 0;
	SysTick->LOAD = 0x00FFFFFF;
	SysTick->VAL = 0;
	SysTick->CTRL |= 5;
	return (0UL);                                                     /* Function successful */
}

__STATIC_INLINE uint32_t Delay_us(unsigned long us)
{

	SysTick->LOAD = (uint32_t)(us * (1/1000000) * SystemCoreClock);
	SysTick->VAL = 0;
	while((SysTick->CTRL & 0x00010000) == 0);
	return (0UL);                                                     /* Function successful */
}

__STATIC_INLINE uint32_t Delay_ms(unsigned long ms)
{
	SysTick->LOAD = (uint32_t)(ms * (1/1000) * SystemCoreClock);
	SysTick->VAL = 0;
	while((SysTick->CTRL & 0x00010000) == 0);
	return (0UL);                                                     /* Function successful */
}


__STATIC_INLINE uint32_t Delay_s(unsigned long s)
{
	s = s * 1000;
	for (; s>0; s--)
	{
		Delay_ms(1);
	}
	return (0UL);
}


#endif
