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
	switch(side)
	{
	case LEFT:
		BtnIter iter = leftButtons.find(btnNum);
		
		break;
		
	case RIGHT:
		BtnIter iter = rightButtons.find(btnNum);
		break;
	}
}
