#ifndef ROBOTSHOOTER_H
#define ROBOTSHOOTER_H

#include "RobotDefines.h"
#include "WPILib.h"

class Shooter
{
private:
	Solenoid catapultHigh;
	Solenoid catapultLow;
	Solenoid kickerHigh;
	Solenoid kickerLow;
	bool initiated;
	//DigitalInput downLimit;
	static const int DOWN_LIMIT_CHANNEL = 4;
public:
	Shooter();
	void Initialize();
	void LaunchSequence();
	void ResetSequence();
};

#endif
