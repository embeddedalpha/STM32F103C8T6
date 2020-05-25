#include "BLDC_120.h"


//PHASE			A		B		C
//HIGH			Q1		Q2		Q3
//
//LOW			Q4		Q5		Q6
//
//STATE			+		0		-	0
//STATE			0		+		-	1
//STATE			-		+		0	2
//STATE			-		0		+	3
//STATE			0		-		+	4
//STATE	    	+		-		0	5





void BLDC_120_Run(uint8_t state)
{


	switch (state){

	case 1:
	{
		//TIM1 ACTIVE PWM
		//TIM3N ACTIVE 1-PWM
		//TIM2 = TIM2N = TIM1N = TIM3 INACTIVE


		break;
	}

	case 2:
	{
		//TIM3 ACTIVE PWM
		//TIM3N ACTIVE 1-PWM
		//TIM2 = TIM2N = TIM1N = TIM3 INACTIVE

		break;
	}

	case 3:
	{
		break;
	}

	case 4:
	{
		break;
	}

	case 5:
	{
		break;
	}

	case 6:
	{
		break;
	}
	}

}

