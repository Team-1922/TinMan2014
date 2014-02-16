#ifndef ROBOT_PNEUMATICS
#define ROBOT_PNEUMATICS

#include "WPILib.h"

class Pneumatics
{
private:
	static const int COMPRESSOR_CHANNEL;
	static const int RELAY_CHANNEL;
	static Compressor robotCompressor;
	//Solenoid piston;
public:
	Pneumatics(int pistonChannel);
	
	static bool InitCompressor();
	
	//void Set(bool state);
};

#endif
