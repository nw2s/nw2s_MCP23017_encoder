
#include "Wire.h"
#include "nw2s_MCP23017_encoder.h"

/* Keep track of how many instances have been created. Up to 8 are supported */
uint8_t num_chips = 0;
Encoder23017 *encoders[8] = {0,0,0,0,0,0,0,0};

/* Interrupt handlers can't really be dynamic, so here we are just        */
/* creating a list of methods to easily handle each possible interrupt    */
/* without having to poll each bank every time someone fires an interrupt */
/* Really, it's easier to just have 16 callbacks to support up to 8       */
/* devices to route the callbacks properly. Total 8*2*8=128 encoders.     */
/* speed is critical as well as the encoder is only in its "changing"     */
/* state for a short time. Check an o-scope if you havent' seen it before */
void handle0A();
void handle0B();
void handle1A();
void handle1B();
void handle2A();
void handle2B();
void handle3A();
void handle3B();
void handle4A();
void handle4B();
void handle5A();
void handle5B();
void handle6A();
void handle6B();
void handle7A();
void handle7B();

Encoder23017::Encoder23017(arduino::MbedI2C *port, bool addr, PinName pinA, PinName pinB)
{
	this->i2c_port = port;
	this->address = addr;

	/* Constructor is not thread-safe! */
	/* If someone tries to make 9 of these things, just ignore it */
	if (num_chips < 7)
	{
		encoders[num_chips] = this;
		
		//TODO: Configure chip!
		
		switch(num_chips)
		{
			case 0:
		
				attachInterrupt(digitalPinToInterrupt(pinA), handle0A, FALLING);
				attachInterrupt(digitalPinToInterrupt(pinB), handle0B, FALLING);
				break;
	
			case 1:
	
				attachInterrupt(digitalPinToInterrupt(pinA), handle1A, FALLING);
				attachInterrupt(digitalPinToInterrupt(pinB), handle1B, FALLING);
				break;

			case 2:

				attachInterrupt(digitalPinToInterrupt(pinA), handle2A, FALLING);
				attachInterrupt(digitalPinToInterrupt(pinB), handle2B, FALLING);
				break;

			case 3:

				attachInterrupt(digitalPinToInterrupt(pinA), handle3A, FALLING);
				attachInterrupt(digitalPinToInterrupt(pinB), handle3B, FALLING);
				break;

			case 4:

				attachInterrupt(digitalPinToInterrupt(pinA), handle4A, FALLING);
				attachInterrupt(digitalPinToInterrupt(pinB), handle4B, FALLING);
				break;

			case 5:

				attachInterrupt(digitalPinToInterrupt(pinA), handle5A, FALLING);
				attachInterrupt(digitalPinToInterrupt(pinB), handle5B, FALLING);
				break;

			case 6:

				attachInterrupt(digitalPinToInterrupt(pinA), handle6A, FALLING);
				attachInterrupt(digitalPinToInterrupt(pinB), handle6B, FALLING);
				break;

			case 7:

				attachInterrupt(digitalPinToInterrupt(pinA), handle7A, FALLING);
				attachInterrupt(digitalPinToInterrupt(pinB), handle7B, FALLING);
				break;
		}
		
		num_chips++;
	}
}

void Encoder23017::handleInterruptA()
{
	/* BI Tech encoder detents on both pins high. You have to catch the rising edge */
	/* to know which direction it's moving. If B leads A, it's CW. If B lags A, it's CCW */
	
	
	// disable interrupts
	// remove this interrupt
	// enable interrupts
	// which pin changed?
	// we only care about encoder A pin (even #s)
	
	// if A pin triggered rising interrupt 
	// and  B pin is high, then B leads A (CW)  +1
	// else B pin is low,  then A leads B (CCW) -1
	
	// re-add this interrupt
}

void Encoder23017::handleInterruptB()
{
	// handle
}


void handle0A()
{
	encoders[0]->handleInterruptA();
}

void handle0B()
{
	encoders[0]->handleInterruptB();
}

void handle1A()
{
	encoders[1]->handleInterruptA();
}

void handle1B()
{
	encoders[1]->handleInterruptB();
}

void handle2A()
{
	encoders[2]->handleInterruptA();
}

void handle2B()
{
	encoders[2]->handleInterruptB();
}

void handle3A()
{
	encoders[3]->handleInterruptA();
}

void handle3B()
{
	encoders[3]->handleInterruptB();
}

void handle4A()
{
	encoders[4]->handleInterruptA();
}

void handle4B()
{
	encoders[4]->handleInterruptB();
}

void handle5A()
{
	encoders[5]->handleInterruptA();
}

void handle5B()
{
	encoders[5]->handleInterruptB();
}

void handle6A()
{
	encoders[6]->handleInterruptA();
}

void handle6B()
{
	encoders[6]->handleInterruptB();
}

void handle7A()
{
	encoders[7]->handleInterruptA();
}

void handle7B()
{
	encoders[7]->handleInterruptB();
}

