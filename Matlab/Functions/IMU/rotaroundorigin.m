function [ newpoint ] = rotaroundorigin(point, thetax, thetay, thetaz)
    % Rotates a point around the origin
    %   Detailed explanation goes here

    % convert the given degrees into radius
    thetax = thetax*pi/180;
    thetay = thetay*pi/180;
    thetaz = thetaz*pi/180;
    
    % calculate the rotation matrix
    rotx = [1 0 0;0 cos(thetax) -sin(thetax); 0 sin(thetax) cos(thetax)];
    roty = [cos(thetay) 0 sin(thetay);0 1 0; -sin(thetay) 0 cos(thetay)];
    rotz = [cos(thetaz) -sin(thetaz) 0; sin(thetaz) cos(thetaz) 0;0 0 1];

    % calculate the new points
    newpoint = rotx * point';
    newpoint = roty * newpoint;
    newpoint = rotz * newpoint;
    
    newpoint = newpoint';
end

