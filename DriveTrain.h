#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "WPILib.h"

class DriveTrain
{
private:
	RobotDrive mainDrive;
	Gyro robotGyro;
public:
	DriveTrain();
	void DriveMecanum(float xVal, float yVal, float rotation);
	void ResetGyro();
};

#endif
