#include "Control.h"

Control::Control() : leftStick(1), driverStick2(2), rightStick(3)
{
	// We don't have much to do here.
}

float Control::GetX(StickSide side)
{
	// Test which joystick we're using and return value from that side.
	switch(side)
	{
	case LEFT:
		return leftStick.GetX();
	case RIGHT:
		return rightStick.GetX();
	case DRIVER2:
		return driverStick2.GetX();
	default:
		return 0;
	}
	return 0;
}

float Control::GetY(StickSide side)
{
	// Test which joystick we're using and return value from that side.
	switch(side)
	{
	case LEFT:
		return leftStick.GetY();
	case RIGHT:
		return rightStick.GetY();
	case DRIVER2:
		return driverStick2.GetY();
	default:
		return 0;
	}
	return 0;
}

float Control::GetThrottle(StickSide side)
{
	// Test which joystick we're using and return value from that side.
	switch(side)
	{
	case LEFT:
		return leftStick.GetThrottle();
	case RIGHT:
		return rightStick.GetThrottle();
	case DRIVER2:
		return driverStick2.GetThrottle();
	default:
		return 0;
	}
	return 0;
}

float Control::GetTwist(StickSide side)
{
	// Test which joystick we're using and return value from that side.
	switch(side)
	{
	case LEFT:
		return leftStick.GetTwist();
	case RIGHT:
		return rightStick.GetTwist();
	case DRIVER2:
		return driverStick2.GetTwist();
	default:
		return 0;
	}
	return 0;
}

bool Control::GetButtonState(StickSide side, int btnNum)
{
	Joystick* stick;
	switch(side)
	{
	case LEFT:
		stick = &leftStick;
		break;
	case RIGHT:
		stick = &rightStick;
		break;
	case DRIVER2:
		stick = &driverStick2;
		break;
	default:
		stick = &leftStick;
		break;
	}
	return stick->GetRawButton(btnNum);
}

bool Control::GetButtonSwitch(StickSide side, int btnNum)
{
	BtnIter stateIter;
	// JoystickButton* button;
	Joystick* stick;
	bool currentState;
	std::map<int, bool> *buttonMap;
	switch(side)
	{
	case LEFT:
		//button = new JoystickButton(&leftStick, btnNum);
		stick = &leftStick;
		buttonMap = &leftButtonState;
		break;
	case RIGHT:
		//button = new JoystickButton(&rightStick, btnNum);
		stick = &rightStick;
		buttonMap = &rightButtonState;
		break;
	case DRIVER2:
		return false;//just because no point in having this feature on this joystick
	default:
		//button = new JoystickButton(&leftStick, btnNum);
		stick = &leftStick;
		buttonMap = &leftButtonState;
		break;
	}
	//currentState = button->Get();
	currentState = stick->GetRawButton(btnNum);
	stateIter = buttonMap->find(btnNum);
	if(stateIter == buttonMap->end())
	{
		buttonMap->insert(MapPair(btnNum, currentState));
		stateIter = buttonMap->find(btnNum);
	}
	bool lastState = stateIter->second;
	stateIter->second = currentState;
	if(currentState && !lastState)
	{
		return true;
	}
	return false;
}
