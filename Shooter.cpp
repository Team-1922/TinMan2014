#include "Shooter.h"

Shooter::Shooter() : catapultHigh(SOLENOID_CATAPULT_HIGH),
					 catapultLow(SOLENOID_CATAPULT_LOW),
					 kickerHigh(SOLENOID_KICKER_HIGH),
					 kickerLow(SOLENOID_KICKER_LOW),
					 downLimit(DOWN_LIMIT_CHANNEL)
{

	catapultHigh.Set(false);
	catapultLow.Set(false);
	kickerHigh.Set(false);
	kickerLow.Set(false);
}

void Shooter::Initialize()
{
	if(!downLimit.Get())
	{
		Wait(0.001);
	}
	kickerLow.Set(true);
	kickerHigh.Set(false);
	Wait(0.1);
	catapultLow.Set(true);
	catapultHigh.Set(false);
	initiated = true;
}

void Shooter::LaunchSequence()
{
	if(!initiated || !downLimit.Get())
		return;
	kickerLow.Set(false);
	kickerHigh.Set(true);
}

void Shooter::ResetSequence()
{
	if(!initiated || downLimit.Get())
		return;
	catapultLow.Set(false);
	catapultHigh.Set(true);
	while(!downLimit.Get())
	{
		Wait(0.001);
	}
	kickerLow.Set(true);
	kickerHigh.Set(false);
	Wait(0.1);
	catapultLow.Set(true);
	catapultHigh.Set(false);
}
