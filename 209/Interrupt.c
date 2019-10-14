#include "Interrupt.h"
volatile uint8_t t1_count = 0;
volatile uint8_t t2_count = 0;
volatile uint8_t overflow_count = 0;
volatile uint16_t Period = 0;


void init_interrupt() {
	EIMSK |= EIMSKVAL;
	EICRA |= EICVALA; 
}

ISR(INT1_vect) {
	
}

ISR(INT0_vect) {
	
}

ISR(TIMER0_OVF_vect) {

}
