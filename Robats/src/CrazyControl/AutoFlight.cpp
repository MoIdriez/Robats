#include "AutoFlight.h"
#include <valarray>

AutoFlight::AutoFlight( ) {
//	pid = new PID(mscount, 60000, 0, 1, 1, 1);
}
AutoFlight::~AutoFlight() {}

double AutoFlight::getTargetAlt() { return targetAlt; }

void AutoFlight::setTargetAlt(double targetAltitude) {
	b = new Balance(targetAlt + 2.0, targetAlt,1);
	targetAlt = targetAltitude;
//	prev = clock();
}

//double AutoFlight::thrustchange(double curAlt) {
//	cur = clock();
//	if (this->diff(cur, prev)) {
//		prev = cur;
//		double r = pid->calculate(targetAlt, curAlt);
//		return r;
//	}
//	return 0;
//}

// basically doing a running average. Keep in mind the higher the mean size the slower the response
double AutoFlight::thrustchange(double curAlt){
	if (buffersize == MEANSIZE) {
		buffersize = 0;
		std::valarray<double> r (buffer,MEANSIZE);
		double alt = r.sum() / MEANSIZE;
		return b->calculate(alt);
	}
	buffer[buffersize] = curAlt;
	buffersize++;

	return 0;
}

bool AutoFlight::diff(clock_t cur,clock_t prev)
{
    double diffticks=cur-prev;
    double diffms=(diffticks)/(CLOCKS_PER_SEC/1000);
    return diffms > mscount;
}
