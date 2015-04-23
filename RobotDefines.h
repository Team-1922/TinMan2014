#ifndef ROBOTDEFINES_H
#define ROBOTDEFINES_H

// PWM channels for each motor in the drive train

#define PWM_FRONT_LEFT_MOTOR 4
#define PWM_BACK_LEFT_MOTOR 2
#define PWM_FRONT_RIGHT_MOTOR 3
#define PWM_BACK_RIGHT_MOTOR 1

#define SOLENOID_CATAPULT_HIGH 1
#define SOLENOID_CATAPULT_LOW 2

#define SOLENOID_KICKER_HIGH 3
#define SOLENOID_KICKER_LOW 4

#define SOLENOID_INTAKE_LOW 8
#define SOLENOID_INTAKE_HIGH 5

#define GYRO_CHANNEL 1

#define COMPRESSOR_SWITCH_CHANNEL 2
#define COMPRESSOR_RELAY_CHANNEL 1

#define MID_SWITCH_CHANNEL 2 //change that or not

#define PWM_INTAKE_MOTOR 5

#define ENCODER_CHANNEL_A 1
#define ENCODER_CHANNEL_B 2

//comment this out to use mechanum drive system
#define TANK_DRIVE

#endif
