#ifndef SRC_CRAZYENGINE_CRAZYENGINE_H_
#define SRC_CRAZYENGINE_CRAZYENGINE_H_

#include "CCrazyflie.h"

class CrazyEngine {
public:
	CrazyEngine(bool* isCycle);
	void run();
	void runOnThread();
	void stop();
	CCrazyflie* getCrazyFlie();
	~CrazyEngine();
private:
	bool g_bGoon;
	bool* isCycle;
	CCrazyflie* cf;
};

#endif /* SRC_CRAZYENGINE_CRAZYENGINE_H_ */
