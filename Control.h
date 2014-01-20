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
	Joystick leftStick = Joystick(1);
	Joystick rightStick = Joystick(2);
	std::map<int, RobotButton> leftButtons;
	std::map<int, RobotButton> rightButtons;
	typedef std::map<int, RobotButton>::iterator BtnIter;
public:
	Control();
	static float GetX(StickSide side);
	static float GetY(StickSide side);
	static float GetThrottle(StickSide side);
	static float GetTwist(StickSide side);
	static bool GetButtonState(StickSide side, int btnNum);
	static bool GetButtonSwitch(StickSide side, int btnNum);
};

#endif
