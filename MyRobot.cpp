#include "WPILib.h"
#include "DriveTrain.h"
#include "Control.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */ 
class RobotDemo : public SimpleRobot
{	
	DriveTrain robotDrive; // Class that handles the drivetrain for us
	Control robotControl; // Class that gives us functions for getting stuff from joysticks

public:
	RobotDemo() : robotDrive(), robotControl()
	{
		// We don't really have to do anything here yet
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous()
	{
		// Not doing anything yet - will add in later
	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl()
	{
		while (IsOperatorControl())
		{
			// Get the three values from the right joystick for Mecanum drive
			float xVal = robotControl.GetX(RIGHT);
			float yVal = robotControl.GetY(RIGHT);
			float twistVal = robotControl.GetTwist(RIGHT);
			// Just pass the values into the DriveMecanum function
			robotDrive.DriveMecanum(xVal, yVal, twistVal);
			Wait(0.005);				// wait for a motor update time
		}
	}
	
	/**
	 * Runs during test mode
	 */
	void Test() {

	}
};

START_ROBOT_CLASS(RobotDemo);


