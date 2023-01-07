#ifndef NW2S88_AUDIO_H
#define NW2S88_AUDIO_H


#define ENCODER_23017_ADDR0 0
#define ENCODER_23017_ADDR1 1
#define ENCODER_23017_ADDR2 2
#define ENCODER_23017_ADDR3 3
#define ENCODER_23017_ADDR4 4
#define ENCODER_23017_ADDR5 5
#define ENCODER_23017_ADDR6 6
#define ENCODER_23017_ADDR7 7


class Encoder23017
{
	public:
	
		explicit Encoder23017(arduino::MbedI2C *port, bool addr, PinName pinA, PinName pinB);
		
		uint8_t getEncoderVal(uint8_t encoder_number);

		void handleInterruptA();
		void handleInterruptB();
		
		
	private:
		
		arduino::MbedI2C *i2c_port;
		
		uint8_t address;
		
		uint8_t portA_input;
		uint8_t portB_input;		
};

#endif

