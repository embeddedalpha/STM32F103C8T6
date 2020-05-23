#include "PID.h"
#include "stm32f10x.h"

float Test(float inp)
{
	int output;
	return output;
}

int main(void)
{

	PID_Controller roll;
	roll.KD = 0.1f;
	roll.KI = 0.01f;
	roll.KP = 5.0f;
	roll.Time_constant = 0.01f;
	roll.sample_time = 0.01f;
	roll.maxLimit = 100;
	roll.minLimit = 0;

	PID_Init(&roll);

float setpoint = 50.0f;

for(float t = 0.0f; t < roll.sample_time; t += roll.sample_time)
{
	float measurement = Test(roll.out);
	PID_Update(&roll,setpoint,measurement);
}


    while(1)
    {
    }
}

