function visualize( points , speed)
%Visualize the gyrometer data
%   Detailed explanation goes here
    figure;
    
    for i = 1:size(points,1)
        
        
        scatter3(0,0,0,'red');
        hold on;
        scatter3(points(i,1),points(i,2),points(i,3), 'blue');
        
        pts = [0 0 0;points(i,1) points(i,2) points(i,3)];
        line(pts(:,1), pts(:,2), pts(:,3), 'Color', 'red');
        hold off;
        axis([-10 10 -10 10 -10 10]);
        title(strcat('Showing item ', num2str(i), ' of ', num2str(size(points,1))));
        pause(speed);
    end
end

