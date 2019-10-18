#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

#include <stdbool.h>
#include <stdint.h>

typedef uint16_t (*ADC_conversion_t)(uint8_t channel);
typedef uint8_t  (*uart_format_t)(uint16_t number, char letter);
typedef void (*uart_transmit_t)(uint8_t* byte_array);
typedef float (*adcConvertArray_t)(uint16_t convertArray[], uint8_t isCurrent);
typedef float (*interleave_t)(uint16_t toInterArray[]);
typedef float (*phaseCalc_t)(uint16_t timeDif, uint16_t timePeriod);
typedef float (*powerFactor_t)(float phaseAngle);
typedef float (*powerCalc_t)(float Voltage[], float Current[], float interleavedVoltagef[], float interleavedCurrentf[], float powerFactor);
typedef float (*adcConvertSingle_t)(uint16_t convertNum);

struct msd_interface {
	ADC_conversion_t ADC_conversion_func;
	uart_format_t uart_format_func;
	uart_transmit_t uart_transmit_func;
	adcConvertArray_t ADC_convert_func;
	interleave_t	interleave_func;
	adcConvertSingle_t  adc_convertsing_func;
	phaseCalc_t		phaseCalc_func;
	powerFactor_t	powerFactor_func;
	powerCalc_t		powerCalc_func;
};

void FSM_initialise(struct msd_interface* interface_ptr);
void FSM_tick(void);

#endif /* STATE_MACHINE_H_ */