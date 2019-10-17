
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

float interleave(uint16_t* toInterArray){
	uint16_t interleaveArray[ARRAYSIZE - 1];
	for (int i= 1; i < (ARRAYSIZE - 1); i++) {
		interleaveArray[i] = (toInterArray[i-1] + toInterArray[i+1]) /2;
	}
	return interleaveArray;
}

float rmsCalc (uint16_t* SinosoidMax) {
	uint32_t runningTotal = 0; 
	uint16_t rmsVal =0; 
	for (int i = 0; i < SinosoidMax->length(); i++) {
		runningTotal += (SinosoidMax[i] * SinosoidMax[i] )
	}
	rmsVal = (runningTotal) / (SinosoidMax->length() );
	return rmsVal;
}

float phaseCalc (uint16_t timeDif) {
	phaseangle = (float)2* PI * (float)timeDif / timePeriod ;
	return phaseangle;
	
}

uint16_t peakCalc (uint16_t PeakVal) {
	
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