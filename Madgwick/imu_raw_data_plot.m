raw_data = importfile('pomiary2.txt',[123000 inf]);
raw_data_size = size(raw_data);
time_quant = 0.01; %100 MHz
time_x_axes = 0: 0.01: raw_data_size(1)/100-0.01;
%%
figure(1)
subplot(3,1,1);
stackedplot(raw_data.AccX);
title('ACC X')
subplot(3,1,2);
stackedplot(raw_data.AccY);
title('ACC Y')
subplot(3,1,3);
stackedplot(raw_data.AccZ);
title('ACC Z')
%%
figure(2)
subplot(3,1,1);
stackedplot(raw_data.GyroX);
title('GYRO X')
subplot(3,1,2);
stackedplot(raw_data.GyroY);
title('GYRO Y')
subplot(3,1,3);
stackedplot(raw_data.GyroZ);
title('GYRO Z')
%%
figure(3)
stackedplot(raw_data)
%%
AccX(:,1) = time_x_axes;
AccX(:,2) = raw_data.AccX;
AccY(:,1) = time_x_axes;
AccY(:,2) = raw_data.AccY;
AccZ(:,1) = time_x_axes;
AccZ(:,2) = raw_data.AccZ;

GyroX(:,1) = time_x_axes;
GyroX(:,2) = raw_data.GyroX;
GyroY(:,1) = time_x_axes;
GyroY(:,2) = raw_data.GyroY;
GyroZ(:,1) = time_x_axes;
GyroZ(:,2) = raw_data.GyroZ;

save IMU.mat AccX AccY AccZ GyroX GyroY GyroZ