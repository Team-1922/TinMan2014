#include "WPILib.h"
#include "DriveTrain.h"
#include "Control.h"
#include "Shooter.h"
#include "Pneumatics.h"

class RobotDemo : public SimpleRobot
{	
	DriveTrain robotDrive; // Class that handles the drivetrain for us
	Control robotControl; // Class that gives us functions for getting stuff from joysticks
	Shooter robotShooter;
	//Solenoid testSolenoid;
	
public:
	RobotDemo() : robotDrive(), robotControl(), robotShooter()
	{
		if(!Pneumatics::InitCompressor())
		{
			// Whoops we broke it
			// Do something about it at some point
		}
		robotShooter.Initialize();
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous()
	{
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
		while (IsOperatorControl())
		{
			//testSolenoid.Set(robotControl.GetButtonState(RIGHT, 1));
			// Just pass the control variable to the class
			robotDrive.DriveMecanum(&robotControl);
			
			if(robotControl.GetButtonSwitch(RIGHT, 1))
			{
				robotShooter.LaunchSequence();
				Wait(0.005);
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
