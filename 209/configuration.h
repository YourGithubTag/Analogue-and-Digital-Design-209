#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#define BAUD_RATE				9600
#define PI						3.141
#define ARRAYSIZE				100
#define DIODEDROP				0.25
#define VOLTAGECHANNEL			0.25
#define CURRENTCHANNEL			0.25

#define VREF					5.0
#define RESOLUTION				10

#define ADCFACTOR				VREF/(2^RESOLUTION)

#define OFFSET					1.8
#endif /* CONFIGURATION_H_ */