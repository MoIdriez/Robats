function [ d ] = displacement(vi, vf, t)
%Displacement from the difference in velocities and time
%   vi is the initial velocity
%   vf is the final velocity
%   t is the time 

    d = (vi + vf) / 2 * t;
end

