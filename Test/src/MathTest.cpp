/*
 * MathTest.cpp
 *
 *  Created on: 27 May 2016
 *      Author: midries
 */

double convert(double oldValue, double oldMin, double oldMax, double newMin, double newMax) {
	double oldRange = oldMax - oldMin;
	double newRange = newMax - newMin;
	return (((oldValue - oldMin) * newRange) / oldRange) + newMin;
}

int main() {

}

