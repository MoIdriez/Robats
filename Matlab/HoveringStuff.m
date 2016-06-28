% static = csvread('Data/CrazyFlie/Acc/Static.txt');
% staticLong = csvread('Data/CrazyFlie/Acc/StaticLong.txt');
% staticThrust = csvread('Data/CrazyFlie/Acc/StaticThrust.txt');
 up = csvread('Data/CrazyFlie/Acc/Up.txt');
% upLong = csvread('Data/CrazyFlie/Acc/UpLong.txt');
% upThrust = csvread('Data/CrazyFlie/Acc/UpThrust.txt');
% p = acctopoints(m);

figure;
%% Up With Running Average
upRun1 = runaverage(up(:,3), 10);
upPid1 = pid(upRun1, upRun1(1), 1);
upRun10 = runaverage(up(:,3), 100);
upPid10 = pid(upRun10, upRun10(1), 1);
%upRun100 = runaverage(up(:,3), 1000);
%upRun1000 = runaverage(up(:,3), 10000);

subplot(3,2,[1,2]); plot(up(:,3)); title('up');
subplot(3,2,3); plot(upRun1); title('upRun 1');
subplot(3,2,4); plot(upPid1); title('PID 1');
subplot(3,2,5); plot(upRun10); title('upRun 10');
subplot(3,2,6); plot(upPid10); title('PID 10');


%subplot(3,2,5); plot(upRun100); title('upRun 100');
%subplot(3,2,6); plot(upRun1000); title('upRun 1000');


%scatter3(p1(:,1),p1(:,2),p1(:,3), 'red');
%hold on;
%scatter3(p2(:,1),p2(:,2),p2(:,3), 'green');
%scatter3(p3(:,1),p3(:,2),p3(:,3), 'blue');
%visualize(p, 0.0000003);

%% Static
% subplot(3, 3, 1);
% plot(static(:,1));
% title('Static X')
% 
% subplot(3, 3, 2);
% plot(static(:,2));
% title('Static Y')
% 
% subplot(3, 3, 3);
% plot(static(:,3));
% title('Static Z')
% 
% %% Static Long
% subplot(3, 3, 4);
% plot(staticLong(:,1));
% title('Static Long X')
% 
% subplot(3, 3, 5);
% plot(staticLong(:,2));
% title('Static Long Y')
% 
% subplot(3, 3, 6);
% plot(staticLong(:,3));
% title('Static Long Z')
% 
% %% Static Thrust
% subplot(3, 3, 7);
% plot(staticThrust(:,1));
% title('Static Thurst X')
% 
% subplot(3, 3, 8);
% plot(staticThrust(:,2));
% title('Static Thurst Y')
% 
% subplot(3, 3, 9);
% plot(staticThrust(:,3));
% title('Static Thrust Z')

% figure;
%scatter3(p1(:,1),p1(:,2),p1(:,3), 'red');
%hold on;
%scatter3(p2(:,1),p2(:,2),p2(:,3), 'green');
%scatter3(p3(:,1),p3(:,2),p3(:,3), 'blue');
%visualize(p, 0.0000003);

% %% up
% subplot(3, 3, 1);
% plot(up(:,1));
% title('up X')
% 
% subplot(3, 3, 2);
% plot(up(:,2));
% title('up Y')
% 
% subplot(3, 3, 3);
% plot(up(:,3));
% title('up Z')
% 
% %% upLong
% subplot(3, 3, 4);
% plot(upLong(:,1));
% title('upLong X')
% 
% subplot(3, 3, 5);
% plot(upLong(:,2));
% title('upLong Y')
% 
% subplot(3, 3, 6);
% plot(upLong(:,3));
% title('upLong Z')
% 
% %% upThrust
% subplot(3, 3, 7);
% plot(upThrust(:,1));
% title('upThrust X')
% 
% subplot(3, 3, 8);
% plot(upThrust(:,2));
% title('upThrust Y')
% 
% subplot(3, 3, 9);
% plot(upThrust(:,3));
% title('upThrust Z')