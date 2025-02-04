/*
 * CrazyEngine.cpp
 *
 *  Created on: 4 Jun 2016
 *      Author: midries
 */
#include <csignal>
#include <thread>
#include <iostream>
#include "GamePad.h"
#include "CrazyEngine.h"

CrazyEngine::CrazyEngine(bool* isCycle) : g_bGoon(false), isCycle(isCycle), cf(NULL) {
	isCycle = false;
}

CCrazyflie* CrazyEngine::getCrazyFlie() {
	return cf;
}

void CrazyEngine::runOnThread() {
	std::thread([=] { run(); }).detach();
}

void CrazyEngine::run() {
	int nThrust = 10001;
	std::string strRadioURI = "radio://0/10/250K";

	std::cout << "Opening radio URI '" << strRadioURI << "'" << std::endl;
	CCrazyRadio *crRadio = new CCrazyRadio(strRadioURI);

	g_bGoon = true;
	bool bDongleConnected = false;
	bool bDongleNotConnectedNotified = false;

	struct timespec tmWait;
	tmWait.tv_sec = 0;
	tmWait.tv_nsec = 500000000;

	while (g_bGoon) {
		// Is the dongle connected? If not, try to connect it.
		if (!bDongleConnected) {
			while (!crRadio->startRadio() && g_bGoon) {
				if (!bDongleNotConnectedNotified) {
					std::cout << "Waiting for dongle." << std::endl;
					bDongleNotConnectedNotified = true;
				}

				nanosleep(&tmWait, NULL);
			}

			if (g_bGoon) {
				std::cout << "Dongle connected, radio started." << std::endl;
			}
		}

		bool bRangeStateChangedNotified = false;
		bool bCopterWasInRange = false;

		if (g_bGoon) {
			bDongleNotConnectedNotified = false;
			bDongleConnected = true;

			cf = new CCrazyflie(crRadio);
			cf->setSendSetpoints(true);
			cf->setThrust(nThrust);

//			int count = 0;
//			double sum = 0;

			while (g_bGoon && bDongleConnected) {
				if (cf->cycle()) {

					if (cf->copterInRange()) {
						*isCycle = true;
						if (!bCopterWasInRange || !bRangeStateChangedNotified) {
							// Event triggered when the copter first comes in range.
							std::cout << "In range" << std::endl;

							// This would be the perfect place to some kind hovering
							// maybe a quick flip to notify it's ready :P

							bCopterWasInRange = true;
							bRangeStateChangedNotified = true;
						}

						// Loop body for when the copter is in range continuously
					} else {
						if (bCopterWasInRange || !bRangeStateChangedNotified) {
							// Event triggered when the copter leaves the range.
							std::cout << "Not in range" << std::endl;

							bCopterWasInRange = false;
							bRangeStateChangedNotified = true;
						}

						// Loop body for when the copter is not in range
					}
				} else {
					isCycle = false;
					std::cerr << "Connection to radio dongle lost."
							<< std::endl;

					bDongleConnected = false;
				}
			}
			isCycle = false;
			if (!g_bGoon) {
				// NOTE(winkler): Here would be the perfect place to initiate a
				// landing sequence (i.e. ramping down the altitude of the
				// copter). Right now, this is a dummy branch.
			}

			delete cf;
		}
	}

	std::cout << "Cleaning up" << std::endl;
	delete crRadio;

}

void CrazyEngine::stop() {
	g_bGoon = false;
}

CrazyEngine::~CrazyEngine() {

}
