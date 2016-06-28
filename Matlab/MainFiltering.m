m = csvread('Data/CrazyFlie/slaPressure.txt');
asl = m(4249:size(m, 1),1);
%msize = size(asl,1);
%nsize = size(asl,2);
%filtered = zeros(msize,nsize);

%for i = 1:size(asl, 1)
%    if (i == 1) 
%        filtered(i,:) = asl(i,:);
%    else
%       p = filtered(i-1,:);
%       filtered(i,:) = p * 0.3 + asl(i,:) * 0.7; 
%    end    
%end

%ss = 10;
%for i = 1:fix(size(asl, 1)/ss)
%    section = asl(i*ss-9:i*ss, :);
%    newvalue = sum(section) / ss;
%    for j =i*ss-9:i*ss
%        mf(j, :) = newvalue;
%    end
%end

filtered = runaverage(asl, 20000);

figure;
plot(asl, 'r');
hold on;
plot(filtered, 'g');