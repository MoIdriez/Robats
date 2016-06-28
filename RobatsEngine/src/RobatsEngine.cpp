#include <iostream>
#include "GamePad.h"
#include "AutoFlight.h"
#include "CCrazyflie.h"
#include "CrazyServer.h"

class RobatsEngine {
public:
	static void run() {
		CCrazyRadio *crRadio = new CCrazyRadio("radio://0/10/250K");
		if (crRadio->startRadio()) {

			struct gp_values gpv;
			GamePad *gamepad = new GamePad();
			AutoFlight *af = new AutoFlight();
			CCrazyflie *cflieCopter = new CCrazyflie(crRadio);

			cflieCopter->setSendSetpoints(true);

			while (cflieCopter->cycle()) {
				gamepad->readValues(&gpv);

				cflieCopter->setRoll(gpv.roll);
				cflieCopter->setPitch(gpv.pitch);
				cflieCopter->setThrust(gpv.thrust);
				std::cout << "T: " << gpv.thrust << "\tR: " << gpv.roll
						<< "\tP: " << gpv.pitch << "\tY: " << gpv.yaw
						<< std::endl;
			}
			delete cflieCopter;
		} else {
			std::cerr << "Could not connect to dongle. Did you plug it in?"
					<< std::endl;
		}

		delete crRadio;
	}
	void logGMP(gp_values gpv) {
		cout << "T: " << gpv.thrust << "\tR: " << gpv.roll << "\tP: "
				<< gpv.pitch << "\tY: " << gpv.yaw << endl;
	}
	void logACC(CCrazyflie *cflieCopter) {
		std::cout << cflieCopter->accX() << "," << cflieCopter->accY() << ","
				<< cflieCopter->accZ() << std::endl;
	}
	void logASL(CCrazyflie *cflieCopter) {
		cout << "Asl: " << cflieCopter->asl() << ", AslLong"
				<< cflieCopter->aslLong() << ", Pressure"
				<< cflieCopter->pressure() << ", Temperature"
				<< cflieCopter->temperature() << endl;
	}

	void logTRPY(CCrazyflie *cflieCopter) {
		cout << "T: " << cflieCopter->thrust() << "\tR: " << cflieCopter->roll()
				<< "\tP: " << cflieCopter->pitch() << "\tY: "
				<< cflieCopter->yaw() << endl;
	}
private:
	bool altHold = false; // just so that we set it once
	bool gamepadEnabled = true;
	bool autoflightEnabled = true;

};
