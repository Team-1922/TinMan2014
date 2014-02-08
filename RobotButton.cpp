#include "RobotButton.h"

RobotButton::RobotButton(Joystick* stick, int btnNum)
{
	this->btnNum = btnNum; // Set the button number to the button you're tracking
	this->stick = stick; // Set the stick to the stick being tracked
	this->lastState = false; // Set the last state to false initially
}

bool RobotButton::GetButtonState()
{
	// Just return the current button state.
	// The Joystick class does this easily for us, so we pass it the button number.
	return stick->GetRawButton(btnNum);
}

bool RobotButton::GetButtonSwitched()
{
	// 
	bool currentState = stick->GetRawButton(btnNum);
	if((currentState) && (!lastState))
	{
		lastState = currentState;
		return true;
	}
	lastState = currentState;
	return false;
}
