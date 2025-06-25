#include "handshake.h"

// Simulated UART send
void uart_send(uint8_t data) {
    printf("Sending: 0x%02X\n", data);
}

// Simulated UART receive (stub/fake)
// Replace with real UART receive in embedded
uint8_t uart_receive(void) {
    // Simulate ACK response from slave
    return ACK;
}

int send_command_with_ack(uint8_t command) {
    uart_send(command);

    uint8_t response = uart_receive();
    if (response == ACK) {
        printf("ACK received\n");
        return 0;  // success
    } else if (response == NACK) {
        printf("NACK received\n");
        return -1; // failure
    } else {
        printf("Unknown response: 0x%02X\n", response);
        return -2; // invalid
    }
}
