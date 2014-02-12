#ifndef ROBOTCONTROL_H
#define ROBOTCONTROL_H

#include "RobotButton.h"
#include "WPILib.h"
#include <map>

enum StickSide
{
	LEFT,
	RIGHT
};

class Control
{
private:
	Joystick leftStick;
	Joystick rightStick;
	// We need a map to store every button so we can detect change in state.
	// We have two of them - one for each joystick
	std::map<int, RobotButton> leftButtons;
	std::map<int, RobotButton> rightButtons;
	// We typedef the iterator to make it easier to type
	typedef std::map<int, RobotButton>::iterator BtnIter;
	// We do the same thing with pair
	typedef std::pair<int, RobotButton> MapPair;
public:
	Control();
	float GetX(StickSide side);
	float GetY(StickSide side);
	float GetThrottle(StickSide side);
	float GetTwist(StickSide side);
	bool GetButtonState(StickSide side, int btnNum);
	bool GetButtonSwitch(StickSide side, int btnNum);
};

#endif
