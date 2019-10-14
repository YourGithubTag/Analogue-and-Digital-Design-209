#include <avr/io.h>
// This header file contains the macros for accessing the UART registers
void uart_initialise(uint32_t baud_rate);
void uart_format(uint16_t number, char letter);
void uart_transmit(uint8_t* byte_array);