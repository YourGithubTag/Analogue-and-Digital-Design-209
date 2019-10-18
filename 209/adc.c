#include "adc.h"
#include <util/delay.h>

void adc_init() {
	ADMUX |= ADMUXVAL;
	ADCSRA = ADCVALA;
	ADCSRB = ADCVALB;
}

uint16_t ADC_conversion(uint8_t channel) {
	ADMUX  |= channel;
	ADCSRA |= (1 << ADSC); // Starting the conversion.
	
	while((ADCSRA & (1<<ADIF))==0) { // Waiting for the conversion to complete.
		;
	}
	
	uint16_t adc_count = (ADCL<<0)|(ADCH<<8);
	uint32_t millivolts = millivolt_conversion(adc_count);
	return(uint16_t)millivolts;
}
