#include "Intake.h"


Intake::Intake():intakeHigh(SOLENOID_INTAKE_HIGH),
				intakeLow(SOLENOID_INTAKE_LOW)
				
{
	initialized = false;
}

void Intake::Initialize(){
	intakeHigh.Set(false);
	intakeLow.Set(true);
	initialized = true;
}

void Intake::Extend(){
	intakeHigh.Set(true);
	intakeLow.Set(false);
}

void Intake::Retract(){
	intakeHigh.Set(false);
	intakeLow.Set(true);
}
