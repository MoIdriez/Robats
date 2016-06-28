#include "GamePad.h"
#include "CCrazyflie.h"
#include "CrazyEngine.h"
#include <iostream>
#include <thread>

class PrintGamePad {
public:
	static void run() {

		struct gp_event gpe;
		struct gp_values gpv;
		GamePad *gamepad = new GamePad();
		int rc;
		while (true) {
			rc = gamepad->readEvent(&gpe);

			if (rc == 1) {
				printf("Event: time %8u, value %8hd, type: %3u, axis/button: %u\n",
									gpe.time, gpe.value, gpe.type, gpe.number);
			}

		}
	}
};

