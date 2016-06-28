/*
 * Balance.cpp
 *
 *  Created on: 8 Jun 2016
 *      Author: midries
 */
#include "Balance.h"
#include <math.h>

Balance::Balance(double maxAlt, double prevAlt, double xi) : maxAlt(maxAlt), prevAlt(prevAlt), xi(xi) {}

double Balance::calculate(double curAlt) {
	double sigma = calcSigma(curAlt);

	// make sure sigma is in minSigma and MaxSigma bounderies
	// make sure you correct it for the crazyflie

	return sigma;
}


double Balance::calcSigma(double curAlt) {
	double diffAlt = prevAlt - curAlt;
	double qx = curAlt / (curAlt + maxAlt);
	double qy = diffAlt / (diffAlt + maxAlt);
	double qs = qx * qy;
	double s = f * (exp(xi * qs));
	prevAlt = curAlt;
	return s;
}

Balance::~Balance() {

}
