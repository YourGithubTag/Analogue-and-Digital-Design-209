#ifndef TIMER0_H_
#define TIMER0_H_
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
volatile uint8_t count;
void timer0_init();
#endif