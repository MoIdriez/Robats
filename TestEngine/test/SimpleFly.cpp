#include "GamePad.h"
#include "CCrazyflie.h"
#include <iostream>

class SimpleFly {
public:
	static void run() {

		CCrazyRadio *crRadio = new CCrazyRadio("radio://0/10/250K");
		if (crRadio->startRadio()) {
			struct gp_values gpv;
			GamePad *gamepad = new GamePad();

			CCrazyflie *cf = new CCrazyflie(crRadio);
			cf->setSendSetpoints(true);

			bool enableHold = false;
			while (cf->cycle()) {
				gamepad->readValues(&gpv);

				if (gpv.l1) {
					enableHold = true;
				}

				if (enableHold) {
					cf->althold();
				}

				cf->setRoll(gpv.roll);
				cf->setPitch(gpv.pitch);
				cf->setThrust(gpv.thrust);

			}
			std::cout << "Ended" << std::endl;
			delete cf;
		}else {
			std::cerr << "Could not connect to dongle. Did you plug it in?"
					<< std::endl;
		}

		delete crRadio;
	}
};





