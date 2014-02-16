#include "WPILib.h"
#include "DriveTrain.h"
#include "Control.h"
#include "Shooter.h"
#include "RobotDefines.h"

class RobotDemo : public SimpleRobot
{	
	Compressor robotCompressor;
	DriveTrain robotDrive; // Class that handles the drivetrain for us
	Control robotControl; // Class that gives us functions for getting stuff from joysticks
	Shooter robotShooter;
	//Solenoid testSolenoid;
	
public:
	RobotDemo() : robotCompressor(COMPRESSOR_SWITCH_CHANNEL, COMPRESSOR_RELAY_CHANNEL),
			robotDrive(), robotControl(), robotShooter()
	{
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous()
	{
		robotCompressor.Start();
		/*Wait(0.5);
		robotDrive.DriveMecanum(0.0f, 0.75f, 0.0f);
		Wait(1);
		robotDrive.DriveMecanum(0.0f, 0.0f, 0.0f);*/
	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void OperatorControl()
	{
		robotCompressor.Start();
		while (IsOperatorControl())
		{
			//testSolenoid.Set(robotControl.GetButtonState(RIGHT, 1));
			// Just pass the control variable to the class
			robotDrive.DriveMecanum(&robotControl);
			
			if(robotControl.GetButtonSwitch(RIGHT, 1))
			{
				robotShooter.LaunchSequence();
				Wait(1.5);
				robotShooter.ResetSequence();
			}
			
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
