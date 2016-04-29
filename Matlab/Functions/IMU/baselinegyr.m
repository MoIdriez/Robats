function [ gyr ] = baselinegyr( gyr )
%UNTITLED8 Summary of this function goes here
%   Detailed explanation goes here
    % what we care about is the change between the degrees
    % therefore we need to subtract each angle with the previous one
    offset = [gyr(1,:);gyr(1:size(gyr,1)-1,:)];

    % now let's get all the angles
    gyr = gyr - offset;
    
end

