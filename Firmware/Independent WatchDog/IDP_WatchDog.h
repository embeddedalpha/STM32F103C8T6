/*
 * IDP_WatchDog.h
 *
 *  Created on: 15-May-2021
 *      Author: Kunal
 */

#ifndef WATCHDOG_IDP_WATCHDOG_H_
#define WATCHDOG_IDP_WATCHDOG_H_

#include "main.h"

void IDP_WatchDog_Init(void);
void IDP_WatchDog_Start(void);
void IDP_WatchDog_Reload(void);
void IDP_WatchDog_Stop(void);



#endif /* WATCHDOG_IDP_WATCHDOG_H_ */

