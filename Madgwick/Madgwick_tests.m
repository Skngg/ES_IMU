%%
% [accelReadings,gyroReadings] = IMU(acc,angVel,orientation) Syntax for
% generating data from IMU sensor using accelerometer and gyro

close all
clear all

snr = 15; %signal to noise ratio
bias = 1;

% gyro meas error in rad/s (mean std of noise for gyro = 0.0124)
beta = sqrt(3/4) * 0.0124;
%beta is the divergence rate of ^S_E q_ω 
%expressed as the magnitude of a quaternion derivative corresponding
%to the gyroscope measurement error

fs = 100;
%dt = 1/fs;
dt = 0.011;
firstLoopNumSamples = fs*8;
secondLoopNumSamples = fs*4;
totalNumSamples = firstLoopNumSamples + secondLoopNumSamples;
%%
traj = kinematicTrajectory('SampleRate',fs);

accBody = zeros(totalNumSamples,3);
accBody(1:firstLoopNumSamples,1) = 9.81;
accBody(firstLoopNumSamples+1:end,2) = -9.81;
angVelBody = zeros(totalNumSamples,3);
angVelBody(1:firstLoopNumSamples,3) = (2*pi)/4;
angVelBody(firstLoopNumSamples+1:end,3) = (2*pi)/2;

[~,orientationNED,~,accNED,angVelNED] = traj(accBody,angVelBody);

IMU = imuSensor('accel-gyro','SampleRate',fs); % Creating IMU model object

[accelReadings,gyroReadings] = IMU(accNED,angVelNED);%,orientationNED);


accelReadings_noised = awgn(accelReadings, snr);
gyroReadings_noised = awgn(gyroReadings, snr);

accelReadings_noised = accelReadings_noised + bias;
gyroReadings_noised = gyroReadings_noised + bias;
%%
figure(1)
t = (0:(totalNumSamples-1))/fs;
subplot(2,2,1)
plot(t,accelReadings)
legend('X-axis','Y-axis','Z-axis')
ylabel('Acceleration (m/s^2)')
title('Accelerometer Readings')

subplot(2,2,3)
plot(t,gyroReadings)
legend('X-axis','Y-axis','Z-axis')
title('Gyroscope Readings')
ylabel('Angular Velocity (rad/s)')
xlabel('Time (s)')

subplot(2,2,2)
plot(t, accBody)
title('Acceleration')

subplot(2,2,4)
plot(t, angVelBody)
xlabel('Time (s)')
title('Angle Velocity')
%%
figure(2)
subplot(2,2,1)
plot(t,accelReadings_noised)
legend('X-axis','Y-axis','Z-axis')
ylabel('Acceleration (m/s^2)')
title('Accelerometer readings with noise and bias')

subplot(2,2,3)
plot(t,gyroReadings_noised)
legend('X-axis','Y-axis','Z-axis')
title('Gyroscope readings with noise and bias')
ylabel('Angular Velocity (rad/s)')
xlabel('Time (s)')

subplot(2,2,2)
plot(t, accBody)
title('Acceleration')

subplot(2,2,4)
plot(t, angVelBody)
xlabel('Time (s)')
title('Angle Velocity')
%%
AccX(:,1) = t;
AccX(:,2) = accelReadings_noised(:,1);
AccY(:,1) = t;
AccY(:,2) = accelReadings_noised(:,2);
AccZ(:,1) = t;
AccZ(:,2) = accelReadings_noised(:,3);

GyroX(:,1) = t;
GyroX(:,2) = gyroReadings_noised(:,1);
GyroY(:,1) = t;
GyroY(:,2) = gyroReadings_noised(:,2);
GyroZ(:,1) = t;
GyroZ(:,2) = gyroReadings_noised(:,3);

out = sim('Madgwick_embedded');

Eul(:,1) = out.EulXYZ.Data(1,1,:);
Eul(:,2) = out.EulXYZ.Data(2,1,:);
Eul(:,3) = out.EulXYZ.Data(3,1,:);

%%
figure(3)
subplot(2,1,1)
plot(t,eulerd(orientationNED,'XYZ','frame'))
legend('X-axis','Y-axis','Z-axis')
title('True IMU position')
ylabel('Euler angle pos')

subplot(2,1,2)
plot(out.EulXYZ.Time,Eul)
legend('X-axis','Y-axis','Z-axis')
title('Estimated IMU position')
ylabel('Euler angle pos')
xlabel('Time (s)')

%%
clear AccX AccY AccZ GyroX GyroY GyroZ

load IMU_offset.mat

out = sim('Madgwick_embedded');

Eul_data(:,1) = out.EulXYZ.Data(1,1,:);
Eul_data(:,2) = out.EulXYZ.Data(2,1,:);
Eul_data(:,3) = out.EulXYZ.Data(3,1,:);

%%
figure(4)

plot(out.EulXYZ.Time,Eul_data)
legend('X-axis','Y-axis','Z-axis')
title('Estimated IMU position')
ylabel('Euler angle pos')
xlabel('Time (s)')
