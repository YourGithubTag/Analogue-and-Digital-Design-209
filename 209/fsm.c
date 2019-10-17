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
		while (fulfilled == 0) {
			;
		}
		current_state = STATE_CALC;
		break;
		
		case STATE_CALC:
		
		float interleavedVolatage = interface_ptr->interleave(Voltage);
		float interleavedCurrent = interface_ptr->interleave(Current);
		
		float AvePower = interface_ptr->powerCalc(interleavedVolatage,interleavedCurrent);
		
		phaseAngle = interface_ptr->phaseCalc(timeDef);
		powerFactor = interface_ptr->powerFactor(phaseAngle);
		
		current_state = STATE_DISPLAY;
		break;
		
		case STATE_DISPLAY:
		
		formattedPeakVol = interface_ptr->uart_format_func(peakVol, letter);
		interface_ptr->uart_transmit_func(formattedPeakVol);
		
		current_state = STATE_SAMPLE;
		break;
		
		default:
		current_state = STATE_SAMPLE;
		break;
	}
}