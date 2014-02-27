#include "WPILib.h"
#include "DriveTrain.h"
#include "Control.h"
#include "Shooter.h"
#include "RobotDefines.h"
#include "Intake.h"

class RobotDemo : public SimpleRobot
{
protected:
	Compressor robotCompressor;
	DriveTrain robotDrive; // Class that handles the drivetrain for us
	Control robotControl; // Class that gives us functions for getting stuff from joysticks
	Shooter robotShooter;
	Jaguar intakeMotor;
	Intake robotIntake;
	Task launcherResetTask;
	// ReentrantSemaphore mutex;
	Encoder roboEncoder;
	bool launcherShooting;
public:
	void LauncherShoot(void)
	{
		if(launcherShooting) return;
		launcherShooting = true;
		SmartDashboard::PutString("Launcher shooting?", "Launcher shooting");
		robotShooter.LaunchSequence();
		Wait(1.3);
		SmartDashboard::PutString("Launcher shooting?", "Launcher resetting");
		robotShooter.ResetSequence();
		launcherShooting = false;
		SmartDashboard::PutString("Launcher resetting?", "Launcher done everything");
	}
	
	bool IsLauncherShooting()
	{
		return launcherShooting;
	}
	
	static void LauncherTask(RobotDemo* robo)
	{
		RobotDemo& robot = *robo;
		SmartDashboard::PutString("Task go?", "Task go");
		if(robot.IsLauncherShooting())
		{
			SmartDashboard::PutString("Task go?", "Task exit");
			return;
		}
		robot.LauncherShoot();
		SmartDashboard::PutString("Task go?", "Task done");
	}
	
	RobotDemo() : robotCompressor(COMPRESSOR_SWITCH_CHANNEL, COMPRESSOR_RELAY_CHANNEL),
			robotDrive(), robotControl(), robotShooter(), intakeMotor(PWM_INTAKE_MOTOR),
			robotIntake(), launcherResetTask("LauncherTask", (FUNCPTR)LauncherTask),
			roboEncoder(ENCODER_CHANNEL_A, ENCODER_CHANNEL_B)
	{
		launcherShooting = false;
		//robotShooter = new Shooter();
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
		robotIntake.Retract();
		robotIntake.Extend();
		double intakeTime = 0;
		while(intakeTime < 1.0)
		{
			intakeMotor.Set(-0.8);
			Wait(0.001);
			intakeTime += 0.001;
		}
		/*do
		{
			robotDrive.DriveMecanum(0, 0.75f, 0);
		} while(roboEncoder.GetDistance() < 10);*/
		double driveTime = 0;
		while(driveTime < 1.5)
		{
			robotDrive.DriveMecanum(0, 0.75f, 0);
			Wait(0.001);
			driveTime += 0.001;
		}
		robotDrive.DriveMecanum(0, 0, 0);
		//robotShooter.LaunchSequence();
		Wait(1.5);
		if(!launcherShooting)
		{
			if(launcherResetTask.Start((UINT32)this))
			{
				//launcherResetting = true;
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
			SmartDashboard::PutBoolean("LauncherResettingVar", launcherShooting);
			//testSolenoid.Set(robotControl.GetButtonState(RIGHT, 1));
			// Just pass the control variable to the class
			robotDrive.DriveMecanum(&robotControl);
			
			if(robotControl.GetButtonSwitch(LEFT, 1))
			{
				SmartDashboard::PutString("didTrigger","hell yeah");
				//robotShooter.LaunchSequence();
				if(!launcherShooting)
				{
					launcherResetTask.Restart();
					launcherResetTask.Start((UINT32)this);
				}
				//Wait(1.5);
				//robotShooter.ResetSequence();
			}
			else
			{
				SmartDashboard::PutString("didTrigger","npe");
			}
			
			/*if(robotControl.GetButtonSwitch(LEFT,3))
			{
				SmartDashboard::PutString("didUntrigger","hell yeah");
				//robotShooter.ResetSequence();
				if(!launcherResetting)
				{
					launcherResetTask.Restart();
					launcherResetTask.Start((UINT32)this);*/
					/*if(launcherResetTask.Restart())
					{
						launcherResetTask.Start((UINT32)this);
						//launcherResetting = true;
					}*/
				/*}
			}*/
			/*else
			{
				SmartDashboard::PutString("didUntrigger","npe");
			}*/
			
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
