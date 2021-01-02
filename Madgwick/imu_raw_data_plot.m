%raw_data = importfile('pomiary2.txt',[123000 inf]);
close all
clear all
raw_data = importfile1('capture.txt',[100 800000]);
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
%%
Temp(:,1) = time_x_axes;
Temp(:,2) = raw_data.Temp;

Temp_offset = mean(raw_data.Temp);
Temp(:,2) = Temp(:,2) - Temp_offset;

AccX_offset = mean(AccX(:,2));
AccY_offset = mean(AccY(:,2));
AccZ_offset = mean(AccZ(:,2)) - 9.81;

GyroX_offset = mean(GyroX(:,2));
GyroY_offset = mean(GyroY(:,2));
GyroZ_offset = mean(GyroZ(:,2));

AccX(:,2) = AccX(:,2) - AccX_offset;
AccY(:,2) = AccY(:,2) - AccY_offset;
AccZ(:,2) = AccZ(:,2) - AccZ_offset;

GyroX(:,2) = GyroX(:,2) - GyroX_offset;
GyroY(:,2) = GyroY(:,2) - GyroY_offset;
GyroZ(:,2) = GyroZ(:,2) - GyroZ_offset;

%%
figure()
subplot(3,1,1)
plot(Temp(:,1),Temp(:,2))
legend('Temp')
ylabel('Degree')
title('Temperature readings')
xlabel('Time (s)')

subplot(3,1,2)
plot(AccX(:,1),AccX(:,2),AccY(:,1),AccY(:,2),AccZ(:,1),AccZ(:,2))
legend('X-axis','Y-axis','Z-axis')
ylabel('Acceleration (m/s^2)')
title('Accelerometer Readings')
xlabel('Time (s)')

subplot(3,1,3)
plot(GyroX(:,1),GyroX(:,2),GyroY(:,1),GyroY(:,2),GyroZ(:,1),GyroZ(:,2))
legend('X-axis','Y-axis','Z-axis')
title('Gyroscope Readings')
ylabel('Angular Velocity (rad/s)')
xlabel('Time (s)')
%%
GyroX_temp_mult = GyroX(1,2)/Temp(1,2);
GyroY_temp_mult = GyroY(1,2)/Temp(1,2);
GyroZ_temp_mult = GyroZ(1,2)/Temp(1,2);

%%

GyroX(:,2) = GyroX(:,2) - Temp(:,2)*GyroX_temp_mult;
GyroY(:,2) = GyroY(:,2) - Temp(:,2)*GyroY_temp_mult;
GyroZ(:,2) = GyroZ(:,2) - Temp(:,2)*GyroZ_temp_mult;

%%

figure()
subplot(3,1,1)
plot(Temp(:,1),Temp(:,2))
legend('Temp')
ylabel('Degree')
title('Temperature readings')
xlabel('Time (s)')

subplot(3,1,2)
plot(AccX(:,1),AccX(:,2),AccY(:,1),AccY(:,2),AccZ(:,1),AccZ(:,2))
legend('X-axis','Y-axis','Z-axis')
ylabel('Acceleration (m/s^2)')
title('Accelerometer Readings')
xlabel('Time (s)')

subplot(3,1,3)
plot(GyroX(:,1),GyroX(:,2),GyroY(:,1),GyroY(:,2),GyroZ(:,1),GyroZ(:,2))
legend('X-axis','Y-axis','Z-axis')
title('Gyroscope Readings')
ylabel('Angular Velocity (rad/s)')
xlabel('Time (s)')

%%

save IMU_offset.mat Temp AccX AccY AccZ GyroX GyroY GyroZ