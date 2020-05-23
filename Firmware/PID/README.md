<h1> PID Library for Embedded Applications </h1>


```javascript

	PID_Controller roll;
  
	roll.KD = 0.1f;
	roll.KI = 0.01f;
	roll.KP = 5.0f;
	roll.Time_constant = 0.01f;
	roll.sample_time = 0.01f;
	roll.maxLimit = 100;
	roll.minLimit = 0;
  
        PID_Init(&roll);

````
