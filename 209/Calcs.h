float AvepowerCalc (uint16_t interVoltage, uint16_t interCurrent) 
float SIMP_AVEPowerCalc (uint16_t Vpeak, uint16_t Ipeak,double phaseAngle) 

uint16_t interleave(uint16_t toInterArray[])

float rmsCalc (uint16_t* SinosoidMax) 
float adcConvertArray (uint16_t convertArray[], uint8_t isCurrent)
float adcConvertSingle (uint16_t convertNum) 

float phaseCalc (uint16_t timeDif, uint16_t timePeriod)

float powerCalc (float Voltage[], float Current[], float interleavedVoltagef[], float interleavedCurrentf[], float powerFactor)

float averageArrayCalc (uint16_t* arrayAVE ) 

float peakCorrection (float lowerPeak)