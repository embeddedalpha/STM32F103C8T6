/*
 * CRC.h
 *
 *  Created on: Feb 27, 2021
 *      Author: Kunal
 */

#ifndef CRC_CRC_H_
#define CRC_CRC_H_

#include "stm32f103xb.h"

void reset_CRC(void);
uint32_t get_CRC(uint32_t in_CRC);

#endif /* CRC_CRC_H_ */

