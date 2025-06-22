#include "hal_gpio.h"
#include <stdio.h>

// Simulate GPIO state (for demonstration)
static gpio_state_t gpio_pins[32] = { GPIO_LOW };

void hal_gpio_init(int pin) {
    printf("Initializing GPIO pin %d\n", pin);
    gpio_pins[pin] = GPIO_LOW;
}

void hal_gpio_write(int pin, gpio_state_t state) {
    printf("Writing %s to GPIO pin %d\n", state == GPIO_HIGH ? "HIGH" : "LOW", pin);
    gpio_pins[pin] = state;
}

gpio_state_t hal_gpio_read(int pin) {
    printf("Reading GPIO pin %d: %s\n", pin, gpio_pins[pin] == GPIO_HIGH ? "HIGH" : "LOW");
    return gpio_pins[pin];
}