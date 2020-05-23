
#ifndef _PID_H_
#define _PID_H_



typedef struct{
	float KP;
	float KI;
	float KD;
	float Time_constant;
	float minLimit;
	float maxLimit;
	float sample_time;
	float integrator, prevError, differentiator, prevMeasurement;
	float out;

}PID_Controller;


void PID_Init(PID_Controller *pid);
float PID_Update(PID_Controller *pid, float setpoint, float measurement);





#endif
