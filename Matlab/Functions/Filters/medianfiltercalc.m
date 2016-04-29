function [ median ] = medianfiltercalc(data, degree)
%MedianFilterCalc Calculates the median
    median = [medfilt1(data(:,1), degree) medfilt1(data(:,2), degree) medfilt1(data(:,3), degree)];
end

