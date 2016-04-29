function [ vf ] = velocity(vi, a, t)
%Velocity calculate the final velocity
%   vi is intial velocity
%   a is the acceleration
%   t is the time
    vf = vi + a * t;
end

