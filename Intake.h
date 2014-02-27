#ifndef INTAKE_H
#define INTAKE_H

#include "WPILib.h"
#include "RobotDefines.h"

class Intake{
private:
	Solenoid intakeHigh;
	Solenoid intakeLow;
		
	bool initialized;
public:
	Intake();
	void Initialize();
	void Extend();
	void Retract();
};

#endif
