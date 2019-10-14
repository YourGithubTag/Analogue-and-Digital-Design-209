#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

#include <stdbool.h>
#include <stdint.h>

typedef uint16_t (*ADC_conversion_t)(uint8_t channel);
typedef uint32_t (*millivolt_conversion_t)(uint8_t adc_count);
typedef uint8_t  (*uart_format_t)(uint16_t number, char letter);
typedef void (*uart_transmit_t)(uint8_t* byte_array);

struct msd_interface {
	ADC_conversion_t ADC_conversion_func;
	millivolt_conversion_t millivolt_con_func;
	uart_format_t uart_format_func;
	uart_transmit_t uart_transmit_func;
};

void FSM_initialise(struct msd_interface* interface_ptr);
void FSM_tick(void);

#endif /* STATE_MACHINE_H_ */