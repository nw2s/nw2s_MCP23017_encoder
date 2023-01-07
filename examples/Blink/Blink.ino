
#include "Wire.h"

#include "nw2s_MCP23017_encoder.h"


void setup()
{
	Encoder23017 *encoder = new Encoder23017(&Wire2, ENCODER_23017_ADDR0, PA_8, PC_6);
}



void loop()
{
}
