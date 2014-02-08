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
	BtnIter iter;
	// Create some pointers to the button maps and joysticks
	std::map<int, RobotButton>* buttons;
	Joystick* stick;
	/*
	 * We assign to these pointers the correct map and joystick
	 * based on which side we want to get from.
	 */
	switch(side)
	{
	case LEFT:
		buttons = &leftButtons;
		stick = &leftStick;
		break;
		
	case RIGHT:
		buttons = &rightButtons;
		stick = &rightStick;
		break;
	}
	// Iter points to the button we want in the map
	iter = buttons->find(btnNum);
	if(iter == buttons->end())
	{
		// If the button isn't in the map, we create an entry for it
		buttons->insert(MapPair(btnNum, RobotButton(stick, btnNum)));
	}
	// Get the value from the button
	RobotButton button = iter->second;
	// Then return it
	return button.GetButtonState();
}

bool Control::GetButtonSwitch(StickSide side, int btnNum)
{
	BtnIter iter;
	// Create some pointers to the button maps and joysticks
	std::map<int, RobotButton>* buttons;
	Joystick* stick;
	/*
	* We assign to these pointers the correct map and joystick
	* based on which side we want to get from.
	*/
	switch(side)
	{
		buttons = &leftButtons;
		stick = &leftStick;
		break;
		
	case RIGHT:
		buttons = &rightButtons;
		stick = &rightStick;
		break;
	}
	// Iter points to the button we want in the map
	iter = buttons->find(btnNum);
	if(iter == buttons->end())
	{
		// If the button isn't in the map, we create an entry for it
		buttons->insert(MapPair(btnNum, RobotButton(stick, btnNum)));
	}
	// Get the value from the button
	RobotButton button = iter->second;
	// Then return it
	return button.GetButtonSwitched();
}
