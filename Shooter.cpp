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
	catapultLow.Set(true);
		catapultHigh.Set(false);
		/*while(!downLimit.Get())
		{
			Wait(0.001);
		}
		*/
		Wait(3.3);
		kickerLow.Set(false);
		kickerHigh.Set(true);
		Wait(0.1);
		catapultLow.Set(false);
		catapultHigh.Set(true);
}

void Shooter::LaunchSequence()
{
	if(!initiated || !downLimit.Get())
		return;
	kickerLow.Set(true);
	kickerHigh.Set(false);
}

void Shooter::ResetSequence()
{
	if(!initiated) //add limswitch later
		return;
	catapultLow.Set(true);
	catapultHigh.Set(false);
	/*while(!downLimit.Get())
	{
		Wait(0.001);
	}
	*/
	Wait(3.3);
	kickerLow.Set(false);
	kickerHigh.Set(true);
	Wait(0.1);
	catapultLow.Set(false);
	catapultHigh.Set(true);
}
