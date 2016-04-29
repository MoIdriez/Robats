function medianfilterplot(data, degree)
%MedianFilterPlot Generate and plot median filter

% calculating the median
median = medianfiltercalc(data, degree);

figure;
subplot(3,1,1); 
plot([data(:,1) median(:,1)]);
legend('data','median')
title(strcat(num2str(degree), ': Accelerometer X values'));

subplot(3,1,2);
plot([data(:,1) median(:,1)]);
legend('data','median')
title(strcat(num2str(degree), ': Accelerometer Y values'));

subplot(3,1,3);
plot([data(:,1) median(:,1)]);
legend('data','median')
title(strcat(num2str(degree), ': Accelerometer Z values'));

end

