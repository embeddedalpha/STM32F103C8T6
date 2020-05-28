
#include "PID.h"


void PID_Init(PID_Controller *pid)
{
	pid ->integrator = 0.0f;
	pid ->prevError = 0.0f;
	pid ->differentiator = 0.0f;
	pid ->prevMeasurement = 0.0f;
	pid -> out = 0.0f;


}



float PID_Update(PID_Controller *pid, float setpoint, float measurement)
{
	//Error Calculation
	float  error = setpoint - measurement;

	//Proportional
	float proportional = (pid ->KP) * error;

	//Integral
	pid -> integrator = pid ->integrator + 0.5f * pid -> KI * pid->sample_time * (error + pid->prevError);

	//Anti wind-up

	float LimitMin, LimitMax;

	if(pid->maxLimit > proportional)
	{
		LimitMax = pid->maxLimit - proportional;
	}
	else {
		LimitMax = 0.0f;
	}

	if(pid->minLimit < proportional)
	{
		LimitMin = pid->minLimit - proportional;
	}
	else {
		LimitMin = 0.0f;
	}

	//Clamping Integrator

	if(pid->integrator > LimitMax)
	{
		pid->integrator = LimitMax;
	}
	else if (pid->integrator < LimitMin) {

		pid->integrator = LimitMin;
	}

	//Derivative

	pid->differentiator = (2.0f * -(pid ->KD) * (measurement - pid->prevMeasurement)
			+ (2.0f * pid->Time_constant - pid ->sample_time) * pid->differentiator)
			/ (2.0f * pid->Time_constant + pid ->sample_time);


	//Output

	pid->out = proportional +  pid->integrator + pid->differentiator;

	if(pid -> out > pid->maxLimit)
	{
		pid -> out =  pid->maxLimit;
	}
	else if (pid -> out < pid -> minLimit) {
		pid -> out =  pid->minLimit;
	}


	pid->prevError = error;
	pid->prevMeasurement = measurement;


	return pid->out;

}
