function [ fp ] = rotypr(ip, o, y, p, r)
    %RotateYawPitchRoll Rotates point around other point
    y = y*pi/180;
    p = p*pi/180;
    r = r*pi/180;
    
    rot1 = [cos(y)*cos(p) cos(y)*sin(p)*sin(r)-sin(y)*cos(r) cos(y)*sin(p)*cos(r)+sin(y)*sin(r)];
    rot2 = [sin(y)*cos(p),sin(y)*sin(p)*sin(r)+cos(y)*cos(r),sin(y)*sin(p)*cos(r)-cos(y)*sin(r)];
    rot3 = [-sin(p),cos(p)*sin(r),cos(p)*cos(r)];
    
    rot = [rot1;rot2;rot3];
    
    ip = ip - o;
    
    fp = (rot * ip')';
    
    fp = fp + o;
end

