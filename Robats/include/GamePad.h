/*
 * GamePad.h
 *
 *  Created on: 25 May 2016
 *      Author: midries
 */

#ifndef SRC_CONTROLENGINE_GAMEPAD_H_
#define SRC_CONTROLENGINE_GAMEPAD_H_

#define GAMEPAD_DEVNAME "/dev/input/js0"

#define GP_EVENT_BUTTON         0x01    /* button pressed/released */
#define GP_EVENT_AXIS           0x02    /* gamepad moved */
#define GP_EVENT_INIT           0x80    /* initial state of device */

#define GP_AXIS_MAX				32767	/* max axis value for this specific controller */
#define GP_AXIS_MIN				-32767 	/* min axis value for this specific controller */

/* These values can change depending on the gamepad used */
#define YAW 					0
#define THRUST 					1
#define ROLL 					5
#define PITCH 					2
#define L1						4
#define	R1						6
#define X						2

/* I took these values from the Python client*/
#define CF_YAW_MAX				180
#define CF_YAW_MIN				-180
#define CF_THRUST_MAX			60000
#define CF_THRUST_MIN			-60000
#define CF_ROLL_MAX				45
#define CF_ROLL_MIN				-45
#define CF_PITCH_MAX			-45
#define CF_PITCH_MIN			45

struct gp_event {
	unsigned int time;      /* event timestamp in milliseconds */
	short value;   /* value */
	unsigned char type;     /* event type */
	unsigned char number;   /* axis/button number */
};

struct gp_values {
	double yaw = 0;
	double roll = 0;
	double pitch = 0;
	double thrust = 0;
	bool l1 = 0;
	bool r1 = 0;
	bool x = 0;
};

class GamePad {
public:
	virtual ~GamePad();
	int readEvent(struct gp_event *gpe);
	int readValues(struct gp_values *gpv);
	GamePad();
private:
	int gamepad_fd = -1;
	double convert(double oldValue, double oldMin, double oldMax, double newMin, double newMax);
};

#endif /* SRC_CONTROLENGINE_GAMEPAD_H_ */
