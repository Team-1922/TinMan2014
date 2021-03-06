#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "WPILib.h"
#include "Control.h"

class DriveTrain
{
private:
	RobotDrive mainDrive;
	Gyro robotGyro;
public:
	DriveTrain();
	void DriveMecanum(float xVal, float yVal, float rotation);
	void DriveMecanum(Control* control);
	void ResetGyro();
};

#endif
