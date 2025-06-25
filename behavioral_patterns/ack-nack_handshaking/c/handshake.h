#ifndef HANDSHAKE_H
#define HANDSHAKE_H

#include <stdio.h>
#include <stdint.h>

#define ACK  0x06  // ASCII ACK
#define NACK 0x15  // ASCII NAK

int send_command_with_ack(uint8_t command);
void uart_send(uint8_t data);
uint8_t uart_receive(void);

#endif
