#ifndef INTAKE_H
#define INTAKE_H

#include "WPILib.h"
#include "RobotDefines.h"

class Intake{
private:
	Solenoid leftHigh;
	Solenoid leftLow;
	Solenoid rightHigh;
	Solenoid rightLow;
	DigitalInput midSwitch;
	
	bool initialized;
public:
	Intake();
	void Initialize();
	void Extend();
	void Retract();
	void MoveMid();
	
};

#endif
