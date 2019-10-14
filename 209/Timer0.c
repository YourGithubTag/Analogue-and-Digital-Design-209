#include "timer0.h"
#define F_CPU 16000000UL

void timer0_init()
{
	TCCR0A = TIMERREGA;
	TCCR0B = TIMERREGB;
	OCR0A =  OCRVAL;
}
