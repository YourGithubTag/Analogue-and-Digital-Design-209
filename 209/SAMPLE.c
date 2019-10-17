
void SampleVI() {
for (int i = 0; i < ARRAYSIZE; i++){
	//TODO channel numbers
	VoltageSamp[i] = interface_ptr->ADC_conversion_func(VoltageChannel);
	CurrentSamp[i] = interface_ptr->ADC_conversion_func(CurrentChannel);
	}
}

void timeDif() {
	TCNT0 = 0;
	while (PC0 ) {
		;
	}
	t1Count = TCNT0;
	while () {
		;
	}
	t2Count = TCNT0;
	
	
	
	
}