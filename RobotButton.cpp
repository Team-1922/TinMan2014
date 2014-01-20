#include "RobotButton.h"

RobotButton::RobotButton(Jostick* stick, int btnNum)
{
	this->btnNum = btnNum;
	this->stick = stick;
	this->lastState = false;
}

bool RobotButton::GetButtonState()
{
	return stick->GetButton(btnNum);
}

bool RobotButton::GetButtonSwitched()
{
	bool currentState = stick->GetButton(btnNum);
	if((currentState) && (!lastState))
	{
		lastState = currentState;
		return true;
	}
	lastState = currentState;
	return false;
}
