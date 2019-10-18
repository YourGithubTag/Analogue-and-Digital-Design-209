#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

void init_interrupt();
volatile uint8_t t1_count;
volatile uint8_t t2_count;
volatile uint8_t t2p_count;
volatile uint8_t overflow_counttimedif;
volatile uint8_t overflow_countperiod;
volatile uint16_t Period;
volatile uint16_t time_dif;




#endif /* INTERRUPT_H_ */