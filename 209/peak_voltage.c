

void peak_voltage_sense(uint16_t* voltage_array) {
	uint16_t average = 0;
	uint16_t sum = 0;
	uint16_t peak_voltage_array[1];
	
	for (int i = 0; i < Max_array_value;i++) {
		sum += voltage_array[i];
	}
	average = sum / Max_array_value;
	
	peak_voltage_array[0] = average;
	uint32_t array_length = 1;
}