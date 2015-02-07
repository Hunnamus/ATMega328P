/* Programs ATMega328P microcontroller to say "Hello World" every 5 seconds. 
 * The string can be read from the serial USB -port (USART) 
 * (for example using putty).
 *
 * Created: 6.2.2015 23:27:57
 *  Author: Henna Andelin
 */
#include <asf.h>
#include <avr/io.h>
#include <util/delay.h>
#include "usart.h"


int main (void)
{
	board_init();
	USART_init(MYUBRR);
	// String we want to send to serial port for reading.
	char String[]="Hello World!! \n\r";
	
	while (1) {
		USART_putstring(String);
		_delay_ms(5000);
	}
	
}
