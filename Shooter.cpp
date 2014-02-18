#include "Shooter.h"

Shooter::Shooter() : catapultHigh(SOLENOID_CATAPULT_HIGH),
					 catapultLow(SOLENOID_CATAPULT_LOW),
					 kickerHigh(SOLENOID_KICKER_HIGH),
					 kickerLow(SOLENOID_KICKER_LOW),
					 downLimit(DOWN_LIMIT_CHANNEL)
{
}

void Shooter::Initialize()
{
	kickerHigh.Set(true);
	kickerLow.Set(false);
	Wait(0.5);
	catapultHigh.Set(true);
	catapultLow.Set(false);
		
}

void Shooter::LaunchSequence()
{
	if(!initiated /*|| downLimit.Get()*/)
		return;
	kickerHigh.Set(false);
	kickerLow.Set(true);
	
}

void Shooter::ResetSequence()
{
	if(!initiated /*|| !downLimit.Get()*/) 
		return;
	catapultHigh.Set(false);
	catapultLow.Set(true);
	/*while(downLimit.Get()){
		Wait(0.001);
	}*/
	Wait(3.3); //remove if lim reenabled
	kickerHigh.Set(true);
	kickerLow.Set(false);
	
	Wait(0.5);
	
	catapultHigh.Set(true);
	catapultLow.Set(false);
}
