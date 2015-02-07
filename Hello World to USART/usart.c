/*
 * USART
 * Basic usart functions needed for setting up usart, sending data,
 * receiving data.
 * 
 *
 * Created: 6.2.2015 23:11:22
 *  Author: Henna
 */ 


#include <avr/io.h>
#include "usart.h"


void USART_init(unsigned int ubrr);
void USART_transmit(unsigned char data);
unsigned char USART_receive(void);
void USART_putstring(char *StringPtr);

// Init USART. Baud rate has been defined in other settings.
void USART_init(unsigned int ubrr) {
	// Set baud rate
	UBRR0H = (unsigned char)(ubrr>>8); // Four most significant bits of USART baud rate
	UBRR0L = (unsigned char)ubrr;	// 8 least significant bits of USART baud rate
	// Enable receiver and transmitter
	UCSR0B = (1<<RXEN0) | (1<<TXEN0);
	// Set frame format
	UCSR0C = (1<<USBS0) | (3<<UCSZ00);
}


/* Transmit function based on polling of the Data Register
*  Empty (UDREn) Flag.
*/
void USART_transmit(unsigned char data) {
	// Wait for empty transmit buffer. 8 bits data, 2 stop bits.
	while ( !( UCSR0A & (1<<UDRE0) ) );
	UDR0 = data;
		
}

/* Wait data to be present in the receive buffer (Check RXC -flag)
* before reading the buffer and returning the value
*/
unsigned char USART_receive(void) {
	while ( !(UCSR0A & (1<<RXC0)) );
	return UDR0;
	
}

/* Sends wanted string to serial port */
void USART_putstring(char *StringPtr) {
	/* String is terminated by null character. */
	while(*StringPtr != 0x00) {
		USART_transmit(*StringPtr);
		StringPtr++;
	}
	
}