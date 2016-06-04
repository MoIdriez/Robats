#ifndef SRC_CRAZYENGINE_CRAZYENGINE_H_
#define SRC_CRAZYENGINE_CRAZYENGINE_H_

#include "CCrazyflie.h"

class CrazyEngine {
public:
	typedef void (*landing_function)(void);
	typedef void (*main_function)(CCrazyflie* cflieCopter);
	CrazyEngine(main_function mFunc);
	void setLandingFunction(landing_function lFunc);
	void run();
	void stop();
	~CrazyEngine();
private:
	bool g_bGoon;
	main_function mainFunc;
	landing_function landingFunc;
};

#endif /* SRC_CRAZYENGINE_CRAZYENGINE_H_ */
