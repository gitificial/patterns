#include "handshake.h"
#include <stdint.h>

int main(void) {
    uint8_t command = 0xA5;

    int result = send_command_with_ack(command);
    if (result == 0) {
        // Proceed normally
    } else {
        // Retry or report error
    }

    return 0;
}
