#include "Pneumatics.h"

const int Pneumatics::COMPRESSOR_CHANNEL = 126;
const int Pneumatics::RELAY_CHANNEL = 127;
Compressor Pneumatics::robotCompressor(COMPRESSOR_CHANNEL, RELAY_CHANNEL);

Pneumatics::Pneumatics(int pistonChannel) : 
		piston(pistonChannel)
{
	piston.Set(false);
}

bool Pneumatics::InitCompressor()
{
	robotCompressor.Start();
	return robotCompressor.Enabled();
}

void Pneumatics::Set(bool state)
{
	piston.Set(state);
}
