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
		sample = interface_ptr->ADC_conversion_func(channel);
		current_state = STATE_CALC;
		break;
		
		case STATE_CALC:
		interface_ptr->
		current_state = STATE_DISPLAY;
		break;
		
		case STATE_DISPLAY:
		
		formatted = interface_ptr->uart_format_func(sample, letter);
		interface_ptr->uart_transmit_func(formatted);
		
		current_state = STATE_SAMPLE;
		break;
		
		default:
		current_state = STATE_SAMPLE;
		break;
	}
}