#include "Intake.h"


Intake::Intake():leftHigh(SOLENOID_INTAKE_LEFT_HIGH),
				leftLow(SOLENOID_INTAKE_LEFT_LOW),
				rightHigh(SOLENOID_INTAKE_RIGHT_HIGH),
				rightLow(SOLENOID_INTAKE_RIGHT_LOW),
				midSwitch(MID_SWITCH_CHANNEL)
{
	
	

}

void Intake::Initialize(){
	leftHigh.Set(true);
	leftLow.Set(false);
	rightHigh.Set(true);
	rightLow.Set(false);
	
	
}

void Intake::Extend(){
	
	leftHigh.Set(false);
	leftLow.Set(true);
	rightHigh.Set(false);
	rightLow.Set(true);
	

}

void Intake::Retract(){
	
	leftHigh.Set(true);
	leftLow.Set(false);
	rightHigh.Set(true);
	rightLow.Set(false);
		
}

void Intake::MoveMid(){
	
	
	
}
