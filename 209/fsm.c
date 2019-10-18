#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "fsm.h"

enum state {
	STATE_INIT,
	STATE_SAMPLE,
	STATE_CALC,
	STATE_DISPLAY,
};

struct msd_interface* interface_ptr;

void fsm_init(struct msd_interface* interface_in_ptr)
{
	interface_ptr = interface_in_ptr;
}

void fsm_tick(void)
{
	static enum state current_state = STATE_SAMPLE;
	
	switch (current_state) {
		case STATE_SAMPLE:
		cli();
		for (int i = 0; i < ARRAYSIZE; i++){
			//TODO channel numbers
			VoltageSamp[i] = interface_ptr->ADC_conversion_func(VOLTAGECHANNEL);
			CurrentSamp[i] = interface_ptr->ADC_conversion_func(CURRENTCHANNEL);
		}
		sei();
		
		while (Period && time_dif) {
			;
		}
		
		peakVoltage = interface_ptr->ADC_conversion_func(PEAKVOLTAGECHANNEL);
		
		current_state = STATE_CALC;
		break;
		
		case STATE_CALC:
		Voltage = interface_ptr->ADC_convert_func(VoltageSamp, 0);
		Current = interface_ptr->ADC_convert_func(CurrentSamp,1);
		interleavedVoltagef = interface_ptr->interleave_func(Voltage);
		interleavedCurrentf = interface_ptr->interleave_func(Current);
		
		peakVoltage = interface_ptr->adc_convertsing_func(peakVoltage);
		
		phaseAngle = interface_ptr->phaseCalc_func(timeDif);
		powerFactorVAL = interface_ptr->powerFactor_func(phaseAngle);
		
		Power = interface_ptr->powerCalc_func(Voltage, Current, interleavedVoltagef, interleavedCurrentf, powerFactor);
		
		current_state = STATE_DISPLAY;
		break;
		
		case STATE_DISPLAY:
		
		formatArray = interface_ptr->uart_format_func(peakVoltage, 'V');
		interface_ptr->uart_transmit_func(formatArray);
		
		current_state = STATE_SAMPLE;
		break;
		
		default:
		current_state = STATE_SAMPLE;
		break;
	}
}