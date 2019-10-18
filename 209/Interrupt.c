#include "Interrupt.h"
volatile uint8_t t1_count = 0;
volatile uint8_t t2_count = 0;
volatile uint8_t t2p_count = 0;
volatile uint8_t overflow_counttimedif = 0;
volatile uint8_t overflow_countperiod = 0;
volatile uint16_t Period = 0;
volatile uint16_t time_dif = 0;

void init_interrupt() {
	//EIMSK |= EIMSKVAL;
	EICRA |= EICVALA; 
	
	EIMSK |= (1 << INT1);
	EIMSK |= (1 << INT0);
}

ISR(INT1_vect) {
	// Detecting rising edge.
	if (EICRA == 0b00001100) {
		// Storing the timer value. 
		t1_count = TCNT0; 
		overflow_count = 0;
		// setting interrupt to trigger on falling edge.
		EICRA &= 0x00;
		EICRA |= 0b00001000; 
	} 
	
	else { // Detecting falling edge
		if (overflow_countperiod > 0) {
			t2p_count = TCNT0;
			overflow_countperiod -= 1;
			Period = 256 - t1_count;
			Period += t2_count;
			} else {
			Period = t2_count - t1_count;
		}
		
		Period += overflow_countperiod * 256;
		Period *= 2;
		EICRA &= 0x00;
		EICRA |= 0b00001100;
	}	
}

ISR(INT0_vect) {
	t2_count = TCNT0;
	if (overflow_counttimedif > 0) {
		t2_count = TCNT0;
		overflow_counttimedif -= 1;
		time_dif = 256 - t1_count;
		time_dif += t2_count;
	}
	else {
		time_dif = t2_count - t1_count;
	}
	time_dif += overflow_counttimedif * 256 
	
}

ISR(TIMER0_OVF_vect) {
	overflow_counttimedif++;
	overflow_countperiod++;
}
