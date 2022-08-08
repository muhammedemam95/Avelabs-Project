/*
 * UART.h
 *
 *  Created on: Jan 17, 2019
 *      Author: hd1
 */

#ifndef UART_H_
#define UART_H_

#include "microConfiguration.h"
#include "commanMacros.h"
#include "standardTypes.h"


void UART_init (void);
void UART_sendByte (uint8 data);
uint8 UART_receiveByte (void);
void UART_sendString (uint8 str[30]);
void UART_receiveString(uint8 *str);

#endif /* UART_H_ */
