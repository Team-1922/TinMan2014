#include "Control.h"

Control::Control() : leftStick(1), rightStick(2)
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
		break;
	case RIGHT:
		return rightStick.GetX();
		break;
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
		break;
	case RIGHT:
		return rightStick.GetY();
		break;
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
		break;
	case RIGHT:
		return rightStick.GetThrottle();
		break;
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
		break;
	case RIGHT:
		return rightStick.GetTwist();
		break;
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
	default:
		stick = &leftStick;
		break;
	}
	JoystickButton* button = new JoystickButton(stick, btnNum);
	return button->Get();
}

bool Control::GetButtonSwitch(StickSide side, int btnNum)
{
	BtnIter stateIter;
	JoystickButton* button;
	bool currentState;
	std::map<int, bool> *buttonMap;
	switch(side)
	{
	case LEFT:
		button = new JoystickButton(&leftStick, btnNum);
		buttonMap = &leftButtonState;
		break;
	case RIGHT:
		button = new JoystickButton(&rightStick, btnNum);
		buttonMap = &rightButtonState;
		break;
	default:
		button = new JoystickButton(&leftStick, btnNum);
		buttonMap = &leftButtonState;
		break;
	}
	currentState = button->Get();
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
