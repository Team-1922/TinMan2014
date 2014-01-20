#ifndef ROBOTBUTTON_H
#define ROBOTBUTTON_H

#include "WPILib.h"

class RobotButton
{
private:
	bool lastState;
	int btnNum;
	Joystick* stick;
public:
	RobotButton(Joystick* stick, int btnNum);
	bool GetButtonState();
	bool GetButtonSwitched();
};

#endif ROBOTBUTTON_H
