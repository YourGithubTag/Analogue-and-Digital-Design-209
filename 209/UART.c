#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"

uint8_t uart_format(float number, char letter ) {
	uint8_t tens = (number / 10) % 10) + 48;
	uint8_t thousand = (number / 1000) + 48;
	uint8_t hundreds = ((number / 100) % 10) + 48;
	if (tens == 0 && thousand == 0 && hundreds == 0) {
		number *= 1000;
			uint8_t work = uint8_t(letter);
			uint8_t equal = 0x3D;
			thousand = (number / 1000) + 48;
			hundreds = ((number / 100) % 10) + 48;
			tens = (number / 10) % 10) + 48;
			uint8_t ones = (number % 10) + 48;
			uint8_t UARTFrames[8] = {work, equal, thousand, 46 ,hundreds, tens, ones, 10};
			return UARTFrames;
	}
	else {
		uint8_t work = uint8_t(letter);
		uint8_t equal = 0x3D;
		thousand = (number / 1000) + 48;
		hundreds = ((number / 100) % 10) + 48;
		tens = (number / 10) % 10) + 48;
		uint8_t ones = (number % 10) + 48;
		uint8_t UARTFrame[7] = {work, equal, thousand, hundreds, tens, ones, 10};
		return UARTFrame;
	}
}

void uart_initialise(uint32_t baud_rate)
{
	UCSR0A = UARTREGA;
	UCSR0B = UARTREGB;
	UCSR0C = UARTREGC;
	UBRR0 = 16000000 / (16 * baud_rate) - 1;
}

// This function transmits an array of bytes via the UART
void uart_transmit(uint8_t* byte_array)
{
	for (int i = 0; i < byte_array->length(); i++) {
		// Wait for the UART data register empty flag
		while ((UCSR0A && 0x20) == 0) {
			;
		}
		// Put the byte to be sent into the data register once the register is empty.
		UDR0 = byte_array[i];
	}
}
