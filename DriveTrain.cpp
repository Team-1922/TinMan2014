#include "DriveTrain.h"
#include "RobotDefines.h"

DriveTrain::DriveTrain() : mainDrive(PWM_FRONT_LEFT_MOTOR,
									 PWM_BACK_LEFT_MOTOR,
									 PWM_FRONT_RIGHT_MOTOR,
									 PWM_BACK_RIGHT_MOTOR)/*,
						   robotGyro(GYRO_CHANNEL)*/
{
	// #yoloswagforlifeveryday
}

void DriveTrain::DriveMecanum(float xVal, float yVal, float rotation)
{
	// For now, we have no manipulation to do of the variables.
	// We'll just pass the values to the mainDrive Mecanum function.
	mainDrive.MecanumDrive_Cartesian(xVal, yVal, 0);
	/* We use Cartesian instead of Polar because Cartesian lets us 
	 * use the gyro without doing the manipulation ourselves.
	 * The description in the WPILib reference also makes sense, whereas
	 * their Polar description doesn't help me know which arguments are
	 * which.
	 */
}

void DriveTrain::DriveMecanum(Control* control)
{
	// Get the values from the control class
	float xVal = control->GetX(RIGHT);
	float yVal = control->GetY(RIGHT);
	float twistVal = control->GetTwist(RIGHT);
	// Pass those values to our normal drive function
	DriveMecanum(xVal, -yVal, twistVal);
}

void DriveTrain::ResetGyro()
{
	//robotGyro.Reset();
}
