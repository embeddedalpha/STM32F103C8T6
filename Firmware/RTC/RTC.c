#include "RTC.h"


//void RTC_Init(void)
//{
//	
//  RCC->BDCR |= RCC_BDCR_BDRST;
//	RCC->BDCR |= RCC_BDCR_RTCSEL_LSE;
//	RCC->BDCR |= RCC_BDCR_LSEON;
//	while(!(RCC->BDCR & RCC_BDCR_LSERDY));
//	RCC->BDCR |= RCC_BDCR_RTCEN;
//	
//	while(!(RTC ->CRL & RTC_CRL_RTOFF));
//	RTC->CRL |= RTC_CRL_CNF;
//	//register
//	RTC -> CRL &= ~RTC_CRL_CNF;
//	while(!(RTC ->CRL & RTC_CRL_RTOFF));
//	


//}

void RTC_Init(void){

	RCC->APB1ENR |= RCC_APB1ENR_BKPEN ;
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;
	PWR->CR |= PWR_CR_DBP;
  RCC->BDCR |= RCC_BDCR_BDRST;
	RCC->BDCR |= RCC_BDCR_RTCSEL_LSE;
	RCC->BDCR |= RCC_BDCR_LSEON;
	while(!(RCC->BDCR & RCC_BDCR_LSERDY));
	RCC->BDCR |= RCC_BDCR_RTCEN;	
	while(!(RTC ->CRL & RTC_CRL_RSF));
	while(!(RTC ->CRL & RTC_CRL_RTOFF));
	


}