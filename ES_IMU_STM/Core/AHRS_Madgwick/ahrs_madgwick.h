#ifndef AHRS_MADGWICK_H_
#define AHRS_MADGWICK_H_

#define PI 3.14159265

typedef struct {
	float yaw;
	float pitch;
	float roll;
} euler_ang_t;

void MadgwickAHRSupdate(float, float, float, float, float, float, float, float, float);

void MadgwickAHRSupdateIMU(float, float, float, float, float, float);

void ToEulerAngles(euler_ang_t *);

#endif /* AHRS_MADGWICK_H_ */
