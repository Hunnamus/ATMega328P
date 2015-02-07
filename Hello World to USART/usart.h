/*
 * usart.h
 * Basic usart functions needed for setting up usart, sending data,
 * receiving data.
 * 
 * Created: 6.2.2015 23:27:57
 *  Author: Henna Andelin
 */ 


#ifndef USART_H_
#define USART_H_
// Defining clock speed and baud rate
#define FOSC 16000000 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

void USART_init(unsigned int ubrr);
void USART_transmit(unsigned char data);
unsigned char USART_receive(void);
void USART_putstring(char *StringPtr);



#endif /* USART_H_ */