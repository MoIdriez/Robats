function [ points ] = acctopoints(acc)
    %AccToPoints Get's the Acc data and generates 3D points

    % preallocating memory
    msize = size(acc,1);
    nsize = size(acc,2);
    velocities = zeros(msize,nsize);
    displacements = zeros(msize,nsize);
    points = zeros(msize,nsize);
    
    % now let's calculate the velocities
    for i=1:size(acc,1)
        % get current acceleration
        a = acc(i,:);

        % get current time
        t = 0.1;

        % get previous velocity
        if (i == 1) 
            Vprev = [0 0 0];
        else
            Vprev = velocities(i-1,:);
        end

        % calculate new velocity
        Vnew = velocity(Vprev, a, t);

        % calculate the displacement
        displacements(i,:) = displacement(Vprev, Vnew, t);

        % let's add the new velocity to the list
        velocities(i,:) = Vnew;    
    end

    for i=1:size(displacements,1)
        % let's get current displacement
        d = displacements(i,:);

        % get previous position
        if (i == 1) 
            Pprev = [0 0 0];
        else
            Pprev = points(i-1,:);
        end

        points(i,:) = Pprev + d;    
    end
end