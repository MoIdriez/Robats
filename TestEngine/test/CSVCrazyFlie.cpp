#include "GamePad.h"
#include "CCrazyflie.h"
#include <fstream>
#include <iostream>

class CSVCrazyFlie {
public:
	CSVCrazyFlie(const char* filename) {
		f.open(filename);
	}

	void logGMP(gp_values gpv) {
		f << gpv.thrust << "," << gpv.roll << "," << gpv.pitch << "," << gpv.yaw
				<< std::endl;
	}

	void logACC() {
		f << cf->accX() << "," << cf->accY() << "," << cf->accZ() << std::endl;
	}

	void logGYR() {
		f << cf->gyroX() << "," << cf->gyroY() << "," << cf->gyroZ()
				<< std::endl;
	}

	void logASL() {
		f << cf->asl() << "," << cf->aslLong() << "," << cf->pressure() << ","
				<< cf->temperature() << std::endl;
	}

	void logTRPY() {
		f << cf->thrust() << "," << cf->roll() << "," << cf->pitch() << ","
				<< cf->yaw() << std::endl;
	}

	void run() {
		CCrazyRadio *crRadio = new CCrazyRadio("radio://0/10/250K");
		if (crRadio->startRadio()) {
			bool started = false, stopped = false;
			struct gp_values gpv;
			GamePad *gamepad = new GamePad();

			cf = new CCrazyflie(crRadio);
			cf->setSendSetpoints(true);
			while (cf->cycle()) {
				// Enter here what you want to log
				gamepad->readValues(&gpv);

				std::cout << cf->adc() << std::endl;

				if (gpv.l1 && !started) {
					started = true;
					std::cout << "Started Recording" << std::endl;
				} else if (gpv.r1 && !stopped) {
					stopped = true;
					std::cout << "Ended Recording" << std::endl;
				}

				if (started) {
					logACC();
				}

				if (stopped) {
					f.close();
					std::cout << "Saved" << std::endl;
				}

				cf->setThrust(gpv.thrust);
			}
			std::cout << "Ended" << std::endl;
			delete cf;
		} else {
			std::cerr << "Could not connect to dongle. Did you plug it in?"
					<< std::endl;
		}

		delete crRadio;
	}
private:
	std::ofstream f;
	CCrazyflie * cf;

};
