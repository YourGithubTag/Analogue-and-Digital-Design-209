uint16_t rev = 360;


uint16_t AvepowerCalc (uint16_t interVoltage, uint16_t interCurrent) {
	uint32_t runningTotal = 0;
	uint16_t rmsVal =0;
	for (int i = 0; i < (ARRAYSIZE -1); i++) {
		runningTotal += (interVoltage[i] * interCurrent[i] )
	}
	rmsVal = (runningTotal) / (ARRAYSIZE -1);
	return rmsVal;
}

uint16_t interleave(uint16_t* toInterArray){
	uint16_t interleaveArray[ARRAYSIZE - 1];
	for (int i= 1; i < (ARRAYSIZE - 1); i++) {
		interleaveArray[i] = (toInterArray[i-1] + toInterArray[i+1]) /2;
	}
	return interleaveArray;
}



uint16_t rmsCalc (uint16_t* SinosoidMax) {
	uint32_t runningTotal = 0; 
	uint16_t rmsVal =0; 
	for (int i = 0; i < SinosoidMax->length(); i++) {
		runningTotal += (SinosoidMax[i] * SinosoidMax[i] )
	}
	rmsVal = (runningTotal) / (SinosoidMax->length() );
	return rmsVal;
}

uint16_t phaseCalc (uint8_t timeDif) {
	phaseangle = (float)360 * (float)(timeDif / timePeriod ) ;
	return phaseangle;
	
}

uint16_t peakCalc (uint16_t PeakVal) {
	
}

uint16_t averageCalc (uint16_t* arrayAVE ) {
	uint16_t sum;
	for (int i = 0; i < arrayAVE->length(); i++) {
		sum += arrayAVE[i];
	}
	return (sum / arrayAVE->length());
}