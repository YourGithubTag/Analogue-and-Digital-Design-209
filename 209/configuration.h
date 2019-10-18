#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

//SOFTWARE
#define BAUD_RATE				9600
#define PI						3.141
#define ARRAYSIZE				30
#define POWERSAMPLETIME			0.0002 //ADC SAMPLING VALUE

//DRIVER
#define EIMSKVAL				1
#define EICVALA					0b00001100
#define TIMERREGA				0x00
#define TIMERREGB				0x04
#define UARTREGA				0x00
#define UARTREGB				0x08
#define UARTREGC				0x06
#define ADMUXVAL				0b01000000
#define ADCVALA					0b10000110
#define ADCVALB					0x00


//Integer stuff
#define VREF					5.0
#define RESOLUTION				10
#define ADCFACTOR				VREF/(2^RESOLUTION)

//HARDWARE
#define OFFSET					1.8
#define SHUNTVAL				0.75
#define	RESISTOR1				2.2
#define	RESISTOR2				27
#define CURRENTGAIN				2.7
#define VOLTAGECHANNEL			3
#define CURRENTCHANNEL			5
#define PEAKVOLTAGECHANNEL		2

#endif /* CONFIGURATION_H_ */