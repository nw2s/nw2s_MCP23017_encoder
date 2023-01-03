
#include "Wire.h"
#include "nw2s_portenta_PCA6416.h"

arduino::MbedI2C *i2c_port;


void pca6416_initialize(arduino::MbedI2C *port)
{
	i2c_port = port;
}


// enum PCA6408A_Registers_t
// {
// 	PCA6408A_Registers_InputPort = 0,
// 	PCA6408A_Registers_OutputPort = 1,
// 	PCA6408A_Registers_PolarityInversion = 2,
// 	PCA6408A_Registers_Configuration = 3
// };
//
// void PCA6408A_SetDeviceAddress(struct PCA6408A_t* instance, bool addrPinHigh)
// {
// 	const uint8_t fixedpartofaddress = 0b01000000; //defined by the device manufacturer
// 	instance->I2C_Address = addrPinHigh ? (fixedpartofaddress | 2) : fixedpartofaddress;
// }
//
// bool PCA6408A_WritePort(struct PCA6408A_t* instance, uint8_t data)
// {
// 	uint8_t buffer[2] = { PCA6408A_Registers_OutputPort, data };
// 	return instance->I2C_WriteMethodPtr(instance->I2C_Address, &buffer[0], 2);
// }
//
// bool PCA6408A_ReadPort(struct PCA6408A_t* instance, uint8_t* data)
// {
// 	uint8_t buffer = { PCA6408A_Registers_InputPort };
// 	bool success = instance->I2C_WriteMethodPtr(instance->I2C_Address, &buffer, 1);
// 	if (!success)
// 	{ return false; }
// 	return instance->I2C_ReadMethodPtr(instance->I2C_Address, data, 1);
// }
//
// bool PCA6408A_ConfigurePort(struct PCA6408A_t* instance, uint8_t config)
// {
// 	uint8_t buffer[2] = { PCA6408A_Registers_Configuration, config };
// 	return instance->I2C_WriteMethodPtr(instance->I2C_Address, &buffer[0], 2);
// }
//
// bool PCA6408A_ConfigurePortPolarity(struct PCA6408A_t* instance, uint8_t polarityConfig)
// {
// 	uint8_t buffer[2] = { PCA6408A_Registers_PolarityInversion, polarityConfig };
// 	return instance->I2C_WriteMethodPtr(instance->I2C_Address, &buffer[0], 2);
// }