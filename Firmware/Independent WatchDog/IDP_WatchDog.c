/*
 * IDP_WatchDog.c
 *
 *  Created on: 15-May-2021
 *      Author: Kunal
 */

#include "IDP_WatchDog.h"


void IDP_WatchDog_Init(void)
{
	//IWDG RUNS ON 40KHz LSI OCS, TIME PERIOD 25uS
	RCC ->CR |= RCC_CSR_IWDGRSTF;
}

void IDP_WatchDog_Start(void)
{
	IWDG ->KR = 0xCCCC;

}

void IDP_WatchDog_Reload(void)
{
	IWDG ->KR = 0xAAAA; //Without reload the next reset will happen after 1.09225 s
}

void IDP_WatchDog_Stop(void)
{

}


