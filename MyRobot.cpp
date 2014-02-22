#include "WPILib.h"
#include "DriveTrain.h"
#include "Control.h"
#include "Shooter.h"
#include "RobotDefines.h"
#include "Intake.h"

class RobotDemo : public SimpleRobot
{	
	Compressor robotCompressor;
	DriveTrain robotDrive; // Class that handles the drivetrain for us
	Control robotControl; // Class that gives us functions for getting stuff from joysticks
	Shooter robotShooter;
	Jaguar intakeMotor;
	Intake robotIntake;
	Task launcherResetTask;
	ReentrantSemaphore mutex;
	Encoder roboEncoder;
	bool launcherResetting;
public:
	void LauncherReset(void)
	{
		Synchronized sync(mutex);
		robotShooter.ResetSequence();
		launcherResetting = false;
	}
	
	RobotDemo() : robotCompressor(COMPRESSOR_SWITCH_CHANNEL, COMPRESSOR_RELAY_CHANNEL),
			robotDrive(), robotControl(), robotShooter(),intakeMotor(PWM_INTAKE_MOTOR),
			robotIntake(), launcherResetTask("LauncherTask", (FUNCPTR)LauncherReset),
			roboEncoder(ENCODER_CHANNEL_A, ENCODER_CHANNEL_B)
	{
		launcherResetting = false;
	}
	
	void RobotInit(){
		robotCompressor.Start();
		robotShooter.Initialize();
		robotIntake.Initialize();
		roboEncoder.SetDistancePerPulse(1);
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous()
	{
		robotCompressor.Start();
		robotShooter.Initialize();
		robotIntake.Initialize();
		/*do
		{
			robotDrive.DriveMecanum(0, 0.75f, 0);
		} while(roboEncoder.GetDistance() < 10);*/
		robotDrive.DriveMecanum(0, 0.75f, 0);
		Wait(1.5);
		robotDrive.DriveMecanum(0, 0, 0);
		robotShooter.LaunchSequence();
		Wait(1.5);
		if(!launcherResetting)
		{
			if(launcherResetTask.Restart())
			{
				launcherResetting = true;
			}
		}
		
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
		robotShooter.Initialize();
		robotIntake.Initialize();
		
		while (IsOperatorControl())
		{
			//testSolenoid.Set(robotControl.GetButtonState(RIGHT, 1));
			// Just pass the control variable to the class
			robotDrive.DriveMecanum(&robotControl);
			
			if(robotControl.GetButtonSwitch(LEFT, 1))
			{
				SmartDashboard::PutString("didTrigger","hell yeah");
				robotShooter.LaunchSequence();
				//Wait(1.5);
				//robotShooter.ResetSequence();
			}
			else
			{
				SmartDashboard::PutString("didTrigger","npe");
			}
			
			if(robotControl.GetButtonSwitch(LEFT,3))
			{
				SmartDashboard::PutString("didUntrigger","hell yeah");
				//robotShooter.ResetSequence();
				if(!launcherResetting)
				{
					if(launcherResetTask.Restart())
					{
						launcherResetting = true;
					}
				}
			}
			else
			{
				SmartDashboard::PutString("didUntrigger","npe");
			}
			
			if(robotControl.GetButtonState(LEFT,5)){
				intakeMotor.Set(-0.8);
			}
			else if(robotControl.GetButtonState(LEFT,4))
			{
				intakeMotor.Set(0.8);
			}	
			else
			{
				intakeMotor.Set(-0);
			}
			
			if(robotControl.GetButtonSwitch(LEFT,7))
			{
				robotIntake.Retract();
			}
			else if(robotControl.GetButtonSwitch(LEFT,6))
			{
				robotIntake.Extend();
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
