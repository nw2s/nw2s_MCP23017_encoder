#ifndef NW2S88_AUDIO_H
#define NW2S88_AUDIO_H

#define PINMODE_6416_INPUT (0)
#define PINMODE_6416_OUTPUT (1)
#define POLARITY_6416_NORMAL (0)
#define POLARITY_6416_INVERTED (1)

class Expander6416
{
	public:
	
		explicit Expander6416(arduino::MbedI2C *port, bool addr, PinName pin);
		
		void configurePin(uint8_t pin, bool mode, void (*callback)(bool));
		void configureEncoder(uint8_t pin_a, uint8_t pin_b, uint8_t range, uint8_t *val, void (*callback)(void));
		void digitalRead(uint8_t pin);
		bool digitalWrite(uint8_t pin, bool value);
		void configurePolarity(uint8_t pin, bool mode);
		
	private:
		
		arduino::MbedI2C *i2c_port;
		
		uint8_t address;
		
		uint8_t port0_configuration;
		uint8_t port1_configuration;
		uint8_t port0_inversion;
		uint8_t port1_inversion;
		uint8_t port0_output;
		uint8_t port1_output;
		uint8_t port0_input;
		uint8_t port1_input;
}

#endif

