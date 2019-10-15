uint16_t rev = 360;


uint16_t powerCalc (uint16_t Voltage, uint16_t Current) {
	
	
	
}

uint16_t rmsCalc (uint16_t SinosoidMax) {
	
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