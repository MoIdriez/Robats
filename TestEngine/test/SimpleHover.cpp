#include "GamePad.h"
#include "CCrazyflie.h"
#include <iostream>
#include <math.h>
#include <cstdlib>

class SimpleHover {
public:
	double error = 0.0;
	double perror = 0.0;
	double integral = 0.0;

	double convert(double oldValue, double oldMin, double oldMax, double newMin,
			double newMax) {
		double oldRange = oldMax - oldMin;
		double newRange = newMax - newMin;
		return (((oldValue - oldMin) * newRange) / oldRange) + newMin;
	}

	double range(double thrust) {
		if (thrust > 60000) {
			thrust = 60000;
		} else if (thrust < 0) {
			thrust = 0;
		}
		return thrust;
	}

	void run() {

		CCrazyRadio *crRadio = new CCrazyRadio("radio://0/10/250K");
		if (crRadio->startRadio()) {
			bool fullstop = false, althold = false, thrustenabled = false;
			struct gp_values gpv;
			GamePad *gamepad = new GamePad();

			CCrazyflie *cf = new CCrazyflie(crRadio);
			cf->setSendSetpoints(true);
			double counter = 0, sum = 0, avg = 0;
			double tcounter = 0, tsum = 0, tavg = 0;
			double tp = 40000,  tpi = 40000,  tpid = 40000;

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
					if (gpv.r1) {
						thrustenabled = true;
					}

					if (gpv.l1) {
						althold = true;
					}

					if (gpv.x) {
						fullstop = true;
					}

					if (althold) {
						if (tcounter <= 1000) {
							tsum += accZ;
							tcounter++;
						} else {
							// Control factor
							int kp = 0.8, ki = 0, kd = 0;

							tavg = tsum / tcounter;
							//P

							error = avg - tavg;
							double pout = kp * error;

							// I
							integral += error * 1;
							double iout = ki * integral;

							// D
							double derivative = (error - perror) / 1;
							double dout = kd * derivative;

							double piout = pout + iout;
							double pidout = piout + dout;
//							if (pe > 0.001) {
							double pc = convert(pout, -1, 1, -1000, 1000);
							double pic = convert(piout, -1, 1, -3000, 3000);
							double pidc = convert(pidout, -1, 1, -5000, 5000);

							tp += pc; tpi+= pic; tpid += pidc;

							tp = range(tp);
							tpi = range(tpi);
							tpid = range(tpid);

							std::cout << "TP: " << tp
									<< "\tTPI: " << tpi
									<< "\tTPID: " << tpid <<std::endl;
//							}
//							cf->setThrust(thrust);
							perror = error;
							tcounter = 0;
							tsum = 0;
						}


						// PID - Just P

//						smoothedValue = smooth(cf->accZ(), 0.1, smoothedValue);
//						error += smoothedValue;
//						double sigma = calcSigma(abs(error), smoothedValue,2,2,-0.54);
//						std::cout << "Sigma: " << sigma;
//						double cor = (sigma -0.95) * 10000;
//						double t = cf->thrust() + cor;
//						std::cout << "\tCor: " << cor << "\tT: " << t << std::endl;
					} else {
//					std::cout << cf->accZ() <<","<< cf->thrust() << "," << cf->roll() << "," << cf->pitch() << ","
//									<< cf->yaw() << std::endl;
					}


					cf->setRoll(gpv.roll);
					cf->setPitch(gpv.pitch);

					if (thrustenabled) {
						cf->setThrust(tpid);
					}
				}
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
