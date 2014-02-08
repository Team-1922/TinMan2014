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
	std::map<int, RobotButton> leftButtons;
	std::map<int, RobotButton> rightButtons;
	typedef std::map<int, RobotButton>::iterator BtnIter;
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
