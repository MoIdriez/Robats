function visualizeimu( accpoints, gyrpoints, speed)
%VisualizeIMU Simple Method to display the IMU information

    figure;
    for i=1:size(accpoints,1)

        % let's plot initially the acc point
        scatter3(accpoints(i,1), accpoints(i,2), accpoints(i,3), 'red');
        hold on;

        % let's plot the gyro point 
        scatter3(gyrpoints(i,1), gyrpoints(i,2), gyrpoints(i,3), 'blue');

        % now let's link it with a line
        pts = [accpoints(i,:);gyrpoints(i,:)];
        line(pts(:,1), pts(:,2), pts(:,3), 'Color', 'red');
        hold off;
        axis([-450 450 -450 450 -450 450]);
        title(strcat('Showing item ', num2str(i), ' of ', num2str(size(accpoints,1))));
        pause(speed);
    end

end

