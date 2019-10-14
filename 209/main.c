/*
 * 209.c
 *
 * Created: 13/10/2019 8:00:22 am
 * Author : nickk
 */ 

#include <avr/io.h>
#include "adc.h"
#include "timer.h"
#include "uart.h"


#include "fsm_msd/state_machine.h"

#include "configuration.h"

int main(void)
{
	adc_init();
	timer0_init();
	uart_initialise(baud_rate);

	// Create the interface needed by the MSD state machine
	struct msd_interface interface = {
		.convert_channel_func = ADC_conversion,
		.millivolt_con_func = millivolt_conversion,
		.uart_format_func = uart_format,
		.uart_transmit_func = uart_transmit
	};
	
	fsm_init(&interface);
	
    /* Replace with your application code */
    while (1) 
    {
		fsm_tick();
    }
}

