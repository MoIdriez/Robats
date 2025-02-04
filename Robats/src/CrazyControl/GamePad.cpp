/*
 * GamePad.cpp
 *
 *  Created on: 25 May 2016
 *      Author: midries
 */

#include "GamePad.h"
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

GamePad::GamePad() {
	gamepad_fd = open(GAMEPAD_DEVNAME, O_RDONLY | O_NONBLOCK); /* read write for force feedback? */
	if (gamepad_fd < 0)
		throw "Couldn't open gamepad";
	else
		std::cout << "Opened gamepad" << std::endl;
}

int GamePad::readValues(struct gp_values *gpv) {
	struct gp_event gpe;
	if (readEvent(&gpe) == 1) {
		//gpe.type &= ~GP_EVENT_INIT; /* ignore synthetic events */
		if (gpe.type == GP_EVENT_AXIS) {
			switch (gpe.number) {
			case YAW:
				gpv->yaw = convert(gpe.value, GP_AXIS_MIN, GP_AXIS_MAX,
						CF_YAW_MIN, CF_YAW_MAX);
				break;
			case PITCH:
				gpv->pitch = convert(gpe.value, GP_AXIS_MIN, GP_AXIS_MAX,
						CF_PITCH_MIN, CF_PITCH_MAX);
				break;
			case ROLL:
				gpv->roll = convert(gpe.value, GP_AXIS_MIN, GP_AXIS_MAX,
						CF_ROLL_MIN, CF_ROLL_MAX);
				break;
			case THRUST:
				/* MAX and MIN of the axis are swapt on purpose because of the gamepad I am using*/
				gpv->thrust = convert(gpe.value, GP_AXIS_MAX, GP_AXIS_MIN,
						CF_THRUST_MIN, CF_THRUST_MAX);
				break;
			default:
				break;
			}
		} else if (gpe.type == GP_EVENT_BUTTON) {
			switch (gpe.number) {
			case L1:
				gpv->l1 = gpe.value;
				break;
			case R1:
				gpv->r1 = gpe.value;
				break;
			case X:
				gpv->x = gpe.value;
				break;
			default:
				break;
			}
		}

	} else {
		//printf("Couldn't read event\n");
	}
}

double GamePad::convert(double oldValue, double oldMin, double oldMax,
		double newMin, double newMax) {
	double oldRange = oldMax - oldMin;
	double newRange = newMax - newMin;
	return (((oldValue - oldMin) * newRange) / oldRange) + newMin;
}

int GamePad::readEvent(struct gp_event *gpe) {
	int bytes;
	bytes = read(gamepad_fd, gpe, sizeof(*gpe));

	if (bytes == -1)
		return 0;

	if (bytes == sizeof(*gpe))
		return 1;

	printf("Unexpected bytes from gamepad:%d\n", bytes);
	return -1;
}

GamePad::~GamePad() {
	close(gamepad_fd);
}

