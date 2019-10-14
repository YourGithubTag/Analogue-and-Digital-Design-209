#include <avr/io.h>
void adc_init();
uint16_t ADC_conversion(uint8_t channel);
uint32_t millivolt_conversion(uint8_t adc_count);