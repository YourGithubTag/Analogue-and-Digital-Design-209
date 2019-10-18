#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#define BAUD_RATE				9600
#define PI						3.141
#define ARRAYSIZE				100
#define DIODEDROP				0.25
#define VOLTAGECHANNEL			1
#define CURRENTCHANNEL			2
#define PEAKVOLTAGECHANNEL		3

#define VREF					5.0
#define RESOLUTION				10

#define ADCFACTOR				VREF/(2^RESOLUTION)

#define OFFSET					1.8
#define SHUNTVAL				0.75
#endif /* CONFIGURATION_H_ */