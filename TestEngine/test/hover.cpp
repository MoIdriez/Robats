#include "AutoFlight.h"
#include "CCrazyflie.h"
#include "CrazyEngine.h"
#include <iostream>

//void hoverFunc(CCrazyflie* cflieCopter, void* obj) {
//	AutoFlight *af = new AutoFlight();
//
//	if (af->getTargetAlt() == 0) {
//		std::cout << "Setting Target Alt to " << cflieCopter->asl()
//				<< std::endl;
//		af->setTargetAlt(cflieCopter->asl());
//	}
//	double thrustchange = af->thrustchange(cflieCopter->asl());
//	std::cout << "Target Alt: " << af->getTargetAlt() << "\tCurrent Alt: "
//			<< cflieCopter->asl() << "\t ThrustChange: " << thrustchange
//			<< std::endl;
//}
//
//bool hover() {
//	CrazyEngine * ce = new CrazyEngine(hoverFunc, NULL);
//	ce->run();
//	return true;
//}

