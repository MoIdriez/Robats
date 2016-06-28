#include "GamePad.h"
#include "CCrazyflie.h"
#include <iostream>

class SimpleBalance {
public:
	double f = 1.5;
	double prev = 0.0;
	double smoothedValue = 0.0;
	double smooth(double data, double filterVal, double smoothedVal) {
		if (filterVal > 1) {      // check to make sure param's are within range
			filterVal = .99;
		} else if (filterVal <= 0) {
			filterVal = 0;
		}

		smoothedVal = (data * (1 - filterVal)) + (smoothedVal * filterVal);

		return smoothedVal;
	}
	double calcSigma(double x, double y, double scx, double scy, double xi) {
		double s, qx, qy, qs;
		qx = x / (x + scx);
		qy = y / (y + scy);
		qs = qx * qy;
		s = f * (exp(xi * qs));
		return s;
	}
	void run() {

		CCrazyRadio *crRadio = new CCrazyRadio("radio://0/10/250K");
		if (crRadio->startRadio()) {
			struct gp_values gpv;
			GamePad *gamepad = new GamePad();

			CCrazyflie *cf = new CCrazyflie(crRadio);
			cf->setSendSetpoints(true);
			bool althold = false, fullstop = false, enablethrust = false;
			double counter = 0, sum = 0, avg = 0;
			while (cf->cycle() && !fullstop) {
				gamepad->readValues(&gpv);
				double accZ = cf->accZ();
				if (counter <= 60000) {
					if (accZ != 0) {
						std::cout << "Gathering sample " << counter << "/60000"
								<< std::endl;
						sum += accZ;
						counter++;
					}
				} else {
					if (avg == 0) {
						avg = sum / counter;
						std::cout << "Samples gathered" << std::endl;
						std::cout << "Average sample: " << avg << std::endl;
					}

					if (gpv.l1) {
						althold = true;
					}

					if (gpv.r1) {
						enablethrust = true;
					}

					if (gpv.x) {
						fullstop = true;
					}

					if (althold) {
						smoothedValue = smooth(accZ, 0.1, smoothedValue);
						double diff = prev - accZ;
						double sigma = calcSigma(diff, smoothedValue, 4, 4, 1.5);


						if (diff > 0) {
							sigma = 1 + (1 - sigma);
						}

						double thrust = 30000 * sigma;
						std::cout << "Sigma: " << sigma
								<< "\tDiff: " << diff
								<< "\tThrust: " <<thrust << std::endl;
						// 0 - 60000 / 10000 30000
						if (enablethrust) {
							cf->setThrust(thrust);
						}
					}

				}
				cf->setRoll(gpv.roll);
				cf->setPitch(gpv.pitch);


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

