function [ output ] = baselineacc( input )
    %BaseLine Baseline's an array to get negative and positive movements

    baseline = round(sum(input(1:60,:)) / 60);
    base = repmat(baseline, size(input,1), 1);

    % let's get the based data
    output = input - base;
end

