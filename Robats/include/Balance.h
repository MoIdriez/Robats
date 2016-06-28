/*
 * Balance.h
 *
 *  Created on: 8 Jun 2016
 *      Author: midries
 */

#ifndef INCLUDE_BALANCE_H_
#define INCLUDE_BALANCE_H_

class Balance {
public:
	Balance(double,double,double);
	~Balance();
	double calculate(double);
private:
	double f = 1.0; // MISSING: define what this is
	double maxAlt, prevAlt, xi;
	double xiAngle = -50.0; // MISSING: define what this is

	// barometer asl from 0 - I don't know 50?
	// pressure 10 - 1200 mbar
	double calcSigma(double);
};



#endif /* INCLUDE_BALANCE_H_ */
