#include <iostream>
#include <cmath>
#include "PID.h"
#include "Balance.h"

#define MEANSIZE 		20000

class AutoFlight {
public:
	AutoFlight();
	~AutoFlight();
	double getTargetAlt();
	void setTargetAlt(double targetAltitude);
	double thrustchange(double curAlt);
private:
	PID *pid;
	Balance * b;
	 //to maintain sample rate
	clock_t prev, cur;
	const double mscount = 100;

	double targetAlt;
	int buffersize = 0;
	double buffer[MEANSIZE];

	bool diff(clock_t clock1,clock_t clock2);
};
