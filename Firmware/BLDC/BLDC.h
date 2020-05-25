#ifndef _BLDC_H_
#define _BLDC_H_


#include "stm32f10x.h"
#include "board.h"


void BLDC_Timer_Init(void);

void PWM1_Active(void);
void PWM1N_Active(void);
void PWM2_Active(void);
void PWM2N_Active(void);
void PWM3_Active(void);
void PWM3N_Active(void);

void PWM1_Update(uint8_t update);
void PWM2_Update(uint8_t update);
void PWM3_Update(uint8_t update);




#endif
