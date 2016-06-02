#include "../CrazyFlieEngine/CCrazyflie.h"

class AutoFlight {
public:
	AutoFlight();
	~AutoFlight();
	void setTargetAlt(double targetAltitude);
	double cycle(double curAlt, double curThrust);
private:
	double targetAlt;

	bool diff(clock_t clock1,clock_t clock2);
	double thrustchange(double curAlt);

	/* PID Controller */
	const double mscount = 10; // sample rate
	clock_t prev, cur; //to maintain sample rate NOTE: currently only more than mscount
	const double altThreshold = 0.01; // difference in threshold we care about
	const double kp = 100, ki = 100, kd = 100; // gain constants
	double itemp = 0; // accumulated error
	double iMax = 1000, iMin = -1000; // error limits
	double dtemp = 0; // historic error
	double ttemp = 0; // historic thrust
};
