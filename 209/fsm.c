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
			for (int i =0; i < ARRAYSIZE; i++){
				//TODO channel numbers
				VoltageSamp[i] = interface_ptr->ADC_conversion_func(1);
				CurrentSamp[i] = interface_ptr->ADC_conversion_func(2);
			}
			 interface_ptr->timeDif();
			 
			 
		current_state = STATE_CALC;
		break;
		
		case STATE_CALC:
		interleavedVolatage = interface_ptr->interleave(Voltage);
		interleavedCurrent = interface_ptr->interleave(Current);
		
		AvePower = interface_ptr->powerCalc(interleavedVolatage,interleavedCurrent);
		
		phaseAngle = interface_ptr->phaseCalc(timeDef);
		powerFactor = interface_ptr->powerFactor(phaseAngle);
		
		current_state = STATE_DISPLAY;
		break;
		
		case STATE_DISPLAY:
		
		formattedPeakVol = interface_ptr->uart_format_func(sample, letter);
		interface_ptr->uart_transmit_func(formattedPeakVol);
		
		current_state = STATE_SAMPLE;
		break;
		
		default:
		current_state = STATE_SAMPLE;
		break;
	}
}