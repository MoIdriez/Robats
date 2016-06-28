/*
 * Hover.cpp
 *
 *  Created on: 8 Jun 2016
 *      Author: midries
 */
#include <iostream>
#include <fstream>
#include "GamePad.h"
#include "AutoFlight.h"
#include "CCrazyflie.h"

class Hover {
public:
	static void run() {
		CCrazyRadio *crRadio = new CCrazyRadio("radio://0/10/250K");
		if (crRadio->startRadio()) {

			struct gp_values gpv;
			struct gp_event gpe;
			GamePad *gamepad = new GamePad();
			AutoFlight *af = new AutoFlight();
			bool afEnabled = false;
			CCrazyflie *cf = new CCrazyflie(crRadio);

//			std::ofstream myfile;
//			myfile.open("example.txt");

			cf->setSendSetpoints(true);
			while (cf->cycle()) {
//				float ax = cf->accX() * 1000, ay = cf->accY() * 1000, az = cf->accZ() * 1000;
				gamepad->readValues(&gpv);
				gamepad->readEvent(&gpe);
				std::cout << "V: " << gpe.value << "\tT: " << gpe.type << "\tN: " << gpe.number << std::endl;
//				std::cout << "dx: " << ax << "\tdy: " << ay << "\tdz: " << az << std::endl;
//				px = ax; py = ay; pz = az;
//				myfile << cf->accX() << "," << cf->accY() << "," << cf->accZ() << std::endl;
//
//				if (gpv.althold){
//					myfile.close();
//				}

//				float asl = cf->asl();
////				float pressure = cflieCopter->aslLong();
//				if (!afEnabled) {
//					af->setTargetAlt(asl);
//				}
//				if (true){// || gpv.althold && afEnabled == false) {
//					cf->althold();
//					std::cout << "Yep" << std::endl;
////					std::cout << "Altitude set to " << asl << std::endl;
////					af->setTargetAlt(asl);
//				}

//				if (afEnabled) {
//					double thrustchange = af->thrustchange(asl);
//					if (thrustchange != 0) {
//						std::cout << "TA: " << af->getTargetAlt() << "\tCA: "
//								<< asl << "\tTC: " << thrustchange << std::endl;
//					}
//				}

//				cflieCopter->setRoll(gpv.roll);
//				cflieCopter->setPitch(gpv.pitch);
				cf->setThrust(gpv.thrust);
//				std::cout << "T: " << gpv.thrust << "\tR: " << gpv.roll
//									<< "\tP: " << gpv.pitch << "\tY: " << gpv.yaw
//									<< std::endl;
			}
			std::cout << "Ended" << std::endl;
			delete cf;
		} else {
			std::cerr << "Could not connect to dongle. Did you plug it in?"
					<< std::endl;
		}

		delete crRadio;
	}
};

