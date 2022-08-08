/*
 * UART.c
 *
 *  Created on: Jan 17, 2019
 *      Author: hd1
 */

#include "UART.h"


/* hna ana bazbt el frame bta3y bta3 el data elly hab3t-ha fl init */
void UART_init (void)
{
	UCSRA = (1<<U2X);  // 3chan yshtghl m3 Asynchronous bouble speed mode
	UCSRB = (1<<TXEN) | (1<<RXEN);  // 3chan ashghl el uart as transmitter we receiver
	UCSRC = (1<<UCSZ1) | (1<<UCSZ0); // 3chan ha2olo el data elly hattb3t 8-bits
	UBRRH = 0;
	UBRRL = 12; // 3chan 3aiz ashtghl 3la baud rate = 9600 kbs
}

void UART_sendByte (uint8 data)
{
	UDR = data;
	while(BIT_IS_CLEAR(UCSRA,TXC)); // polling 3chan at2kd 2ne el data etb3tt
	SET_BIT(UCSRA,TXC); // lazm ams7 el flag tany 3n tare2 2ne a7ot feh 1
}

uint8 UART_receiveByte (void)
{
	while(BIT_IS_CLEAR(UCSRA,RXC));
	return UDR;
}

void UART_sendString (uint8 *str)
{
	while(*str != '\0')
	{
		UART_sendByte(*str);
		str++;
	}
}

void UART_receiveString (uint8 *str)
{
	uint8 i = 0;
	str[i] = UART_receiveByte();
	while(str[i] != '#')
	{
		i++;
		str[i] = UART_receiveByte();
	}
	str[i] = '\0';
}
