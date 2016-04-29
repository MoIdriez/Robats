function [ gyrpoints ] = gyrtopoints(gyr, accpoints )
%UNTITLED10 Summary of this function goes here
%   Detailed explanation goes here

    % let's assume an initial position
    gyrpoints = zeros(size(gyr,1),size(gyr,2));
    
    % now let's calculate all the new points
    for i=1:size(gyr,1)
        %let's get the current angles
        ang = gyr(i,:);
        
        % let's get the last point we were at
        if (i == 1) 
            point = accpoints(1,:) + [25 0 0];
        else
            point = gyrpoints(i-1,:) + (accpoints(i,:) - accpoints(i-1,:));
        end

        % let's rotate it around the origin
        %newpoint = rotaroundorigin(point, ang(1), ang(2), ang(3));
        newpoint = rotypr(point, accpoints(i,:), ang(3), ang(2), ang(1));

        % let's add the new point to the points
        gyrpoints(i,:) = newpoint;
    end

end

