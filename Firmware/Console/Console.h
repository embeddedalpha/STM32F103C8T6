#ifndef _Console_H_
#define _Console_H_


#include "stm32f103x.h"
#include <stdio.h>


struct _FILE(int handle; );
    FILE  __stdin =  {0};
    FILE  __stdout = {1};
    FILE  __stderr = {2};

int Serial_Init(void);
int Serial_Write(int c);
int Serial_Read(void);
int fgetc(FILE *f);
int fputc(int c, FILE *f);










#endif