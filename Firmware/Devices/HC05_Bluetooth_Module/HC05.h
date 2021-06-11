/*
 * HC05.h
 *
 *  Created on: 11-Jun-2021
 *      Author: Kunal
 */

#ifndef HC05_HC05_H_
#define HC05_HC05_H_

#include "Debug/Debug.h"
#include "main.h"

#define HC05_Master 1
#define HC05_Slave  0

bool HC05_Set_Mode(bool mode);
bool HC05_Test(void);
bool HC05_Reset(void);
bool HC05_Restore_Default(void);
bool HC05_Set_Device_Name(char *s);


bool HC05_Delete_Device(char *s);
bool HC05_Delete_All_Devices(void);

int HC05_Get_Auth_Device_Count(void);

uint8_t HC05_Get_Working_Status(void);

bool HC05_Pair_Device(char *s);

bool HC05_Connect_Device(char *s);

bool HC05_Disconnect(void);

int  HC05_Disconnection_Status(void);


#endif /* HC05_HC05_H_ */
