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
	
	/* These are the last pressed states for the left and right buttons.
	 * Our RobotButton class seems to be functioning poorly, so we'll
	 * just use the built-in JoystickButton class and do store the button
	 * states here.
	 */
	std::map<int, bool> leftButtonState;
	std::map<int, bool> rightButtonState;
	
	typedef std::map<int, bool>::iterator BtnIter;
	typedef std::pair<int, bool> MapPair;
	
	// We need a map to store every button so we can detect change in state.
	// We have two of them - one for each joystick
	//std::map<int, JoystickButton> leftButtons;
	//std::map<int, JoystickButton> rightButtons;
	// We typedef the iterator to make it easier to type
	//typedef std::map<int, JoystickButton>::iterator BtnIter;
	// We do the same thing with pair
	//typedef std::pair<int, JoystickButton> MapPair;
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
