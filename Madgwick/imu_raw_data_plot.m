raw_data = importfile('test.txt', 1, 5300);
raw_data_size = size(raw_data);
time_quant = 0.01; %100 MHz
time_x_axes = 0: 0.01: raw_data_size(1)/100-0.01;

figure(1)
subplot(3,1,1);
stackedplot(raw_data(:,1));
title('ACC X')
subplot(3,1,2);
stackedplot(raw_data(:,2));
title('ACC Y')
subplot(3,1,3);
stackedplot(raw_data(:,3));
title('ACC Z')

figure(2)
subplot(3,1,1);
stackedplot(raw_data(:,4));
title('GYRO X')
subplot(3,1,2);
stackedplot(raw_data(:,5));
title('GYRO Y')
subplot(3,1,3);
stackedplot(raw_data(:,6));
title('GYRO Z')