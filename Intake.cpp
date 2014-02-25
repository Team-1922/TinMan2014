#include "Intake.h"


Intake::Intake():intakeHigh(SOLENOID_INTAKE_HIGH),
				intakeLow(SOLENOID_INTAKE_LOW)
				
{
	
	

}

void Intake::Initialize(){
	intakeHigh.Set(true);
	intakeLow.Set(false);
	
}

void Intake::Extend(){
	intakeHigh.Set(true);
	intakeLow.Set(false);
	
	

}

void Intake::Retract(){
	intakeHigh.Set(false);
	intakeLow.Set(true);
	
}
