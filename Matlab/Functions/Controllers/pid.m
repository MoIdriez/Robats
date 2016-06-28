function [ changes ] = pid(values, setpoint, kp)%% dt, max, min, Kp, Kd, Ki, setpoint)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
changes = [];
for i=1:size(values,1)
    %%Calculate error
    error = setpoint - values(i,:);
    
    %%Proportional term
    pout = kp * error;
    changes = [changes;pout];
    
%     // Calculate error
%     double error = setpoint - pv;
% 
%     // Proportional term
%     double Pout = _Kp * error;
% 
%     // Integral term
%     _integral += error * _dt;
%     double Iout = _Ki * _integral;
% 
%     // Derivative term
%     double derivative = (error - _pre_error) / _dt;
%     double Dout = _Kd * derivative;
% 
%     // Calculate total output
%     double output = Pout + Iout + Dout;
% 
%     // Restrict to max/min
%     if( output > _max )
%         output = _max;
%     else if( output < _min )
%         output = _min;
% 
%     // Save error to previous error
%     _pre_error = error;
% 
%     return output;
end

end

