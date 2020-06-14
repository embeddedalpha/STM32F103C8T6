#include "GPIO.h"




void GPIO_Pin_Setup(GPIO_TypeDef *port, int pin, int mode)
{
if(port == GPIOA)
{
	if((mode == ALT_OPEN_DRAIN_OUTPUT) || (mode == ALT_PUSH_PULL_OUTPUT))
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
	}
	else
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	}

	if(pin < 8)
	{
		port -> CRL |= mode << (4*pin);
	}
	else
	{
		port -> CRH |= mode << (4*(pin - 8));
	}
}


if(port == GPIOB)
{
	if((mode == ALT_OPEN_DRAIN_OUTPUT) || (mode == ALT_PUSH_PULL_OUTPUT))
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN;
	}
	else
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	}

	if(pin < 8)
	{
		port -> CRL |= mode << (4*pin);
	}
	else
	{
		port -> CRH |= mode << (4*(pin - 8));
	}
}

if(port == GPIOC)
{
	if((mode == ALT_OPEN_DRAIN_OUTPUT) || (mode == ALT_PUSH_PULL_OUTPUT))
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPCEN | RCC_APB2ENR_AFIOEN;
	}
	else
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPcEN;
	}

	if(pin < 8)
	{
		port -> CRL |= mode << (4*pin);
	}
	else
	{
		port -> CRH |= mode << (4*(pin - 8));
	}
}

if(port == GPIOD)
{
	if((mode == ALT_OPEN_DRAIN_OUTPUT) || (mode == ALT_PUSH_PULL_OUTPUT))
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPDEN | RCC_APB2ENR_AFIOEN;
	}
	else
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
	}

	if(pin < 8)
	{
		port -> CRL |= mode << (4*pin);
	}
	else
	{
		port -> CRH |= mode << (4*(pin - 8));
	}
}

if(port == GPIOE)
{
	if((mode == ALT_OPEN_DRAIN_OUTPUT) || (mode == ALT_PUSH_PULL_OUTPUT))
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
	}
	else
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;
	}

	if(pin < 8)
	{
		port -> CRL |= mode << (4*pin);
	}
	else
	{
		port -> CRH |= mode << (4*(pin - 8));
	}
}

if(port == GPIOF)
{
	if((mode == ALT_OPEN_DRAIN_OUTPUT) || (mode == ALT_PUSH_PULL_OUTPUT))
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPFEN | RCC_APB2ENR_AFIOEN;
	}
	else
	{
		RCC->APB2ENR |= RCC_APB2ENR_IOPFEN;
	}

	if(pin < 8)
	{
		port -> CRL |= mode << (4*pin);
	}
	else
	{
		port -> CRH |= mode << (4*(pin - 8));
	}
}
}

void GPIO_Pin_Interrupt_Setup(GPIO_TypeDef *port, int pin, int type)
{
	switch (pin) {
		case 0:
		{
			if(port == GPIOA) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI0_PA;
			if(port == GPIOB) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI0_PB;
			if(port == GPIOC) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI0_PC;
			if(port == GPIOD) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI0_PD;
			if(port == GPIOE) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI0_PE;
			if(port == GPIOF) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI0_PF;
			if(port == GPIOG) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI0_PG;

			break;
		}

		case 1:
		{
			if(port == GPIOA) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI1_PA;
			if(port == GPIOB) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI1_PB;
			if(port == GPIOC) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI1_PC;
			if(port == GPIOD) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI1_PD;
			if(port == GPIOE) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI1_PE;
			if(port == GPIOF) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI1_PF;
			if(port == GPIOG) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI1_PG;

			break;
		}

		case 2:
		{
			if(port == GPIOA) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI2_PA;
			if(port == GPIOB) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI2_PB;
			if(port == GPIOC) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI2_PC;
			if(port == GPIOD) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI2_PD;
			if(port == GPIOE) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI2_PE;
			if(port == GPIOF) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI2_PF;
			if(port == GPIOG) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI2_PG;

			break;
		}

		case 3:
		{
			if(port == GPIOA) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI3_PA;
			if(port == GPIOB) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI3_PB;
			if(port == GPIOC) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI3_PC;
			if(port == GPIOD) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI3_PD;
			if(port == GPIOE) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI3_PE;
			if(port == GPIOF) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI3_PF;
			if(port == GPIOG) AFIO->EXTICR[0] = AFIO_EXTICR1_EXTI3_PG;

			break;
		}

		case 4:
		{
			if(port == GPIOA) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI4_PA;
			if(port == GPIOB) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI4_PB;
			if(port == GPIOC) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI4_PC;
			if(port == GPIOD) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI4_PD;
			if(port == GPIOE) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI4_PE;
			if(port == GPIOF) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI4_PF;
			if(port == GPIOG) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI4_PG;

			break;
		}

		case 5:
		{
			if(port == GPIOA) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI5_PA;
			if(port == GPIOB) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI5_PB;
			if(port == GPIOC) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI5_PC;
			if(port == GPIOD) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI5_PD;
			if(port == GPIOE) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI5_PE;
			if(port == GPIOF) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI5_PF;
			if(port == GPIOG) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI5_PG;

			break;
		}

		case 6:
		{
			if(port == GPIOA) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI6_PA;
			if(port == GPIOB) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI6_PB;
			if(port == GPIOC) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI6_PC;
			if(port == GPIOD) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI6_PD;
			if(port == GPIOE) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI6_PE;
			if(port == GPIOF) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI6_PF;
			if(port == GPIOG) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI6_PG;

			break;
		}

		case 7:
		{
			if(port == GPIOA) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI7_PA;
			if(port == GPIOB) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI7_PB;
			if(port == GPIOC) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI7_PC;
			if(port == GPIOD) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI7_PD;
			if(port == GPIOE) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI7_PE;
			if(port == GPIOF) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI7_PF;
			if(port == GPIOG) AFIO->EXTICR[1] = AFIO_EXTICR2_EXTI7_PG;

			break;
		}

		case 8:
		{
			if(port == GPIOA) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI8_PA;
			if(port == GPIOB) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI8_PB;
			if(port == GPIOC) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI8_PC;
			if(port == GPIOD) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI8_PD;
			if(port == GPIOE) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI8_PE;
			if(port == GPIOF) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI8_PF;
			if(port == GPIOG) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI8_PG;

			break;
		}

		case 9:
		{
			if(port == GPIOA) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI9_PA;
			if(port == GPIOB) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI9_PB;
			if(port == GPIOC) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI9_PC;
			if(port == GPIOD) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI9_PD;
			if(port == GPIOE) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI9_PE;
			if(port == GPIOF) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI9_PF;
			if(port == GPIOG) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI9_PG;

			break;
		}

		case 10:
		{
			if(port == GPIOA) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI10_PA;
			if(port == GPIOB) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI10_PB;
			if(port == GPIOC) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI10_PC;
			if(port == GPIOD) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI10_PD;
			if(port == GPIOE) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI10_PE;
			if(port == GPIOF) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI10_PF;
			if(port == GPIOG) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI10_PG;

			break;
		}

		case 11:
		{
			if(port == GPIOA) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI11_PA;
			if(port == GPIOB) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI11_PB;
			if(port == GPIOC) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI11_PC;
			if(port == GPIOD) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI11_PD;
			if(port == GPIOE) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI11_PE;
			if(port == GPIOF) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI11_PF;
			if(port == GPIOG) AFIO->EXTICR[2] = AFIO_EXTICR3_EXTI11_PG;

			break;
		}

		case 12:
		{
			if(port == GPIOA) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI12_PA;
			if(port == GPIOB) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI12_PB;
			if(port == GPIOC) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI12_PC;
			if(port == GPIOD) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI12_PD;
			if(port == GPIOE) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI12_PE;
			if(port == GPIOF) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI12_PF;
			if(port == GPIOG) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI12_PG;

			break;
		}

		case 13:
		{
			if(port == GPIOA) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI13_PA;
			if(port == GPIOB) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI13_PB;
			if(port == GPIOC) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI13_PC;
			if(port == GPIOD) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI13_PD;
			if(port == GPIOE) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI13_PE;
			if(port == GPIOF) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI13_PF;
			if(port == GPIOG) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI13_PG;

			break;
		}

		case 14:
		{
			if(port == GPIOA) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI14_PA;
			if(port == GPIOB) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI14_PB;
			if(port == GPIOC) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI14_PC;
			if(port == GPIOD) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI14_PD;
			if(port == GPIOE) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI14_PE;
			if(port == GPIOF) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI14_PF;
			if(port == GPIOG) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI14_PG;

			break;
		}

		case 15:
		{
			if(port == GPIOA) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI15_PA;
			if(port == GPIOB) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI15_PB;
			if(port == GPIOC) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI15_PC;
			if(port == GPIOD) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI15_PD;
			if(port == GPIOE) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI15_PE;
			if(port == GPIOF) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI15_PF;
			if(port == GPIOG) AFIO->EXTICR[3] = AFIO_EXTICR4_EXTI15_PG;

			break;
		}

		default:
			break;
	}

	if(type == Rising_Edge) EXTI->RTSR |= 1 << pin;
	if(type == Falling_Ege) EXTI->FTSR |= 1 << pin;
	if(type == Rise_n_Fall_Edge) {
		EXTI->RTSR |= 1 << pin;
		EXTI->FTSR |= 1 << pin;
	}


}

void GPIO_Interrupt_Enable(int pin, int priority, IRQn_Type irqnum)
{
    EXTI->IMR |= 1 << pin;
    NVIC_SetPriority(irqnum,priority);
    NVIC_EnableIRQ(irqnum);
}


