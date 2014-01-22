#include "Control.h"

float Control::GetX(StickSide side)
{
	switch(side)
	{
	case LEFT:
		return leftStick.GetX();
		break;
	case RIGHT:
		return rightStick.GetX();
		break;
	}
}

float Control::GetY(StickSide side)
{
	switch(side)
	{
	case LEFT:
		return leftStick.GetY();
		break;
	case RIGHT:
		return rightStick.GetY();
		break;
	}
}

float Control::GetThrottle(StickSide side)
{
	switch(side)
	{
	case LEFT:
		return leftStick.GetThrottle();
		break;
	case RIGHT:
		return rightStick.GetThrottle();
		break;
	}
}

float Control::GetTwist(StickSide side)
{
	switch(side)
	{
	case LEFT:
		return leftStick.GetTwist();
		break;
	case RIGHT:
		return rightStick.GetTwist();
		break;
	}
}

bool Control::GetButtonState(StickSide side, int btnNum)
{
	BtnIter iter;
	std::map<int, RobotButton>* buttons;
	Joystick* stick;
	switch(side)
	{
	case LEFT:
		iter = leftButtons.find(btnNum);
		buttons = &leftButtons;
		stick = &leftStick;
		break;
		
	case RIGHT:
		iter = rightButtons.find(btnNum);
		buttons = &rightButtons;
		stick = &rightStick;
		break;
	}
	if(iter == buttons->end())
	{
		buttons->insert(btnNum, RobotButton(stick, btnNum));
	}
	RobotButton button = iter->second;
	return button.GetButtonState();
}

bool Control::GetButtonSwitch(StateSide side, int btnNum)
{
	BtnIter iter;
	std::map<int, RobotButton>* buttons;
	Joystick* stick;
	switch(side)
	{
	case LEFT:
		iter = leftButtons.find(btnNum);
		buttons = &leftButtons;
		stick = &leftStick;
		break;
		
	case RIGHT:
		iter = rightButtons.find(btnNum);
		buttons = &rightButtons;
		stick = &rightStick;
		break;
	}
	if(iter == buttons->end())
	{
		buttons->insert(btnNum, RobotButton(stick, btnNum));
	}
	RobotButton button = iter->second;
	return button.GetButtonSwitched();
}
