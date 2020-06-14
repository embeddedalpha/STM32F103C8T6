#ifndef _GPIO_H_
#define _GPIO_H_

#include "stm32f10x.h"


#define GEN_PUSH_PULL_OUTPUT   0b0011
#define GEN_OPEN_DRAIN_OUTPUT  0b0111
#define ALT_PUSH_PULL_OUTPUT   0b1011
#define ALT_OPEN_DRAIN_OUTPUT  0b1111
#define ANALOG_INPUT           0b0000
#define FLOATING_INPUT         0b0100
#define PULL_DOWN_INPUT        0b1000
#define PULL_UP_INPUT          0b1000
#define INPUT_MODE

#define Rising_Edge     1
#define Falling_Ege     2
#define Rise_n_Fall_Edge 3

void GPIO_Pin_Setup(GPIO_TypeDef *port, int pin, int mode);

void GPIO_Pin_Interrupt_Setup(GPIO_TypeDef *port, int pin, int type);

void GPIO_Interrupt_Enable(int pin, int priority, IRQn_Type irqnum);















#endif

