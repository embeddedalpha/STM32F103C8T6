#ifndef _board_h_
#define _board_h_

#include "stm32f10x.h"

#define TIMER_CLOCK_GENERAL 36000000
#define TIMER_CLOCK_ADVANCED 72000000


#define GEN_PUSH_PULL_OUTPUT   (uint8_t)0b0011
#define GEN_OPEN_DRAIN_OUTPUT  (uint8_t)0b0111
#define ALT_PUSH_PULL_OUTPUT   (uint8_t)0b1011
#define ALT_OPEN_DRAIN_OUTPUT  (uint8_t)0b1111
#define ANALOG_INPUT           (uint8_t)0b0000
#define FLOATING_INPUT         (uint8_t)0b0100
#define PULL_DOWN_INPUT        (uint8_t)0b1000
#define PULL_UP_INPUT          (uint8_t)0b1000



void Delay_Init(TIM_TypeDef *timer);
void Delay_us(TIM_TypeDef *timer, float usSeconds);
void Delay_ms(TIM_TypeDef *timer, float msSeconds);
void Delay_s (TIM_TypeDef *timer, float Seconds);


void Send_16Bit_Data(uint16_t data);
void Send_8Bit_Data(GPIO_TypeDef *GPIO ,uint8_t data);
void Paralle_Transmission_Init(void);

void GPIO_Setup(GPIO_TypeDef *PORT, uint8_t pin, uint8_t type);

#endif
