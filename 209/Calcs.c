
float AvepowerCalc (uint16_t interVoltage, uint16_t interCurrent) {
	uint32_t runningTotal = 0;
	uint16_t rmsVal =0;
	for (int i = 0; i < (ARRAYSIZE -1); i++) {
		runningTotal += (interVoltage[i] * interCurrent[i] )
	}
	rmsVal = (runningTotal) / (ARRAYSIZE -1);
	return rmsVal;
}
float SIMP_AVEPowerCalc (uint16_t Vpeak, uint16_t Ipeak,double phaseAngle) {
	AvePower = SIMP_RMS(Vpeak) * SIMP_RMS(Ipeak) * cos (phaseAngle);
	return AvePower;
}

float interleave(float toInterArray[]){
	uint16_t interleaveArray[ARRAYSIZE - 1];
	for (int i= 0; i < (ARRAYSIZE - 1); i++) {
		interleaveArray[i] = (toInterArray[i] + toInterArray[i+1]) /2;
	}
	return interleaveArray;
}

float rmsCalc (float Sinosoid[]) {
	float runningTotal = 0; 
	float rmsVal =0; 
	for (int i = 0; i < sizeof(SinosoidMax); i++) {
		runningTotal += (SinosoidMax[i] * SinosoidMax[i] )
	}
	rmsVal = (runningTotal) / (sizeof(SinosoidMax));
	return rmsVal;
}

float adcConvertArray (uint16_t convertArray[], uint8_t isCurrent) {
	float converted[sizeof(convertArray)];
	if (isCurrent == 1) {
		
	for (int i=0; i<sizeof(convertArray); i++){
		 converted[i] = ( (float)convertArray[i] / (2^RESOLUTION) )*VREF;
		 converted[i] -= OFFSET;
		 converted[i] /= CURRENTGAIN;
		 converted[i] /= SHUNTVAL;
	}
	return converted;
	} else {
	for (int i=0; i<sizeof(convertArray); i++){
		converted[i] = ( (float)convertArray[i] / (2^RESOLUTION) )*VREF;
		converted[i] -= OFFSET;
		converted[i] /= ((float)RESISTOR2 / (RESISTOR1 + RESISTOR2));
	}	
	return converted;
	}
}
float adcConvertSingle (uint16_t convertNum) {
	float converted;
		converted = ( (float)convertNum / (2^RESOLUTION) )*VREF;
		converted -= OFFSET;
		converted /= ((float)RESISTOR2 / (RESISTOR1 + RESISTOR2));
	return converted;
}

float phaseCalc (uint16_t timeDif, uint16_t timePeriod) {
	phaseangle = (float)2* PI * (float)timeDif / timePeriod ;
	return phaseangle;
	
}

float powerCalc (float Voltage[], float Current[], float interleavedVoltagef[], float interleavedCurrentf[], float powerFactor){
	float powerArray[(ARRAYSIZE-1) * 2];
	int j;
	float area =0;
	for (int i = 0; i < ARRAYSIZE-1; i++) {
		 j=2*i;
		powerArray[j] = Voltage[i] * interleavedCurrentf[i];
		powerArray[j+1] = Current[i] * interleavedVoltagef[i];
	}
	for (int k = 0; k < (ARRAYSIZE-1) * 2; k++){
		area += ( powerArray[k] * POWERSAMPLETIME );
	}
	return (area * powerFactor);
	
}

float averageArrayCalc (uint16_t* arrayAVE ) {
	uint16_t sum;
	for (int i = 0; i < arrayAVE->length(); i++) {
		sum += arrayAVE[i];
	}
	return (sum / arrayAVE->length());
}

float peakCorrection (float lowerPeak) {
	return lowerPeak + DIODEDROP;
}