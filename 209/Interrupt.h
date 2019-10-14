#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

void init_interrupt();
volatile uint8_t t1_count;
volatile uint8_t overflow_count;
volatile uint8_t t2_count;
volatile uint16_t Period;





#endif /* INTERRUPT_H_ */