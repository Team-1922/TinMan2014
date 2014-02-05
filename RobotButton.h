#ifndef ROBOTBUTTON_H
#define ROBOTBUTTON_H

#include "WPILib.h"

class RobotButton
{
private:
	bool lastState; // Last state of the button
	int btnNum; // Button number being tracked
	Joystick* stick; // Joystick button is being tracked on
public:
	RobotButton(Joystick* stick, int btnNum); // Constructor
	bool GetButtonState(); // Get the current button state
	bool GetButtonSwitched(); // Get whether the button has changed from off to on
};

#endif ROBOTBUTTON_H
