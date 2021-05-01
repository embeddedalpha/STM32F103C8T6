/*
 * main.h
 *
 *  Created on: Feb 27, 2021
 *      Author: Kunal
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "stm32f103xb.h"
#include "stm32f1xx.h"
#include "stdbool.h"
#include <stdint.h>





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

__STATIC_INLINE void Setup_MCU_Clock()
{
	RCC->CR |= RCC_CR_HSEON ;
	while(!(RCC->CR & RCC_CR_HSERDY));
	FLASH->ACR |= FLASH_ACR_PRFTBE|FLASH_ACR_LATENCY_1;
	RCC->CFGR |= RCC_CFGR_PLLSRC;
	RCC->CFGR |= RCC_CFGR_PLLXTPRE_HSE ;
	RCC->CFGR |= RCC_CFGR_PLLMULL9;
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
	RCC->CR |= RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLRDY));
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while(!(RCC->CFGR & RCC_CFGR_SWS_PLL));
	MCO_pin_conf();
	RCC->CFGR |= RCC_CFGR_MCO_SYSCLK;

}


#endif /* MAIN_H_ */
