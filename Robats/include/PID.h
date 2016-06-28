/*
 * PID.h
 *
 *  Created on: 8 Jun 2016
 *      Author: midries
 */

#ifndef INCLUDE_PID_H_
#define INCLUDE_PID_H_

class PIDImpl;
class PID
{
    public:
        // Kp -  proportional gain
        // Ki -  Integral gain
        // Kd -  derivative gain
        // dt -  loop interval time
        // max - maximum value of manipulated variable
        // min - minimum value of manipulated variable
        PID( double dt, double max, double min, double Kp, double Kd, double Ki );

        // Returns the manipulated variable given a setpoint and current process value
        double calculate( double setpoint, double pv );
        ~PID();

    private:
        PIDImpl *pimpl;
};

#endif /* INCLUDE_PID_H_ */
