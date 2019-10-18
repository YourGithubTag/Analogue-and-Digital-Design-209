/*
 * 209.c
 *
 * Created: 13/10/2019 8:00:22 am
 * Author : nickk
 */ 

#include <avr/io.h>
#include "adc.h"
#include "timer0.h"
#include "UART.h"
#include "Interrupt.h"
#include "Calcs.h"
#include "Interrupt.h"
#include "fsm.h"

#include "configuration.h"


uint16_t VoltageSamp[ARRAYSIZE];
uint16_t CurrentSamp[ARRAYSIZE];
uint8_t formatArray[7];
float peakVoltage;
float Voltage[ARRAYSIZE];
float Current[ARRAYSIZE];
float interleavedVoltagef[ARRAYSIZE-1];
float interleavedCurrentf[ARRAYSIZE-1];
float phaseAngle;
float powerFactorVAL;
float Power;

int main(void)
{
	adc_init();
	timer0_init();
	uart_initialise(BAUD_RATE);

	// Create the interface needed by the MSD state machine
	struct msd_interface interface = {
		.ADC_conversion_func = ADC_conversion,
		.uart_format_func = uart_format,
		.uart_transmit_func = uart_transmit,
		.ADC_convert_func = adcConvertArray,
		.interleave_func =interleave,
		.adc_convertsing_func = adcConvertSingle,
		.phaseCalc_func = phaseCalc,
		.powerFactor_func = powerFactor,
		.powerCalc_func = powerCalc
	};
	
	fsm_init(&interface);
	
    /* Replace with your application code */
    while (1) 
    {
		fsm_tick();
    }
}

