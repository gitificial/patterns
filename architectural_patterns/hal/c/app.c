#include "hal_gpio.h"

#define LED_PIN 5

void app_blink_led() {
    hal_gpio_init(LED_PIN);

    hal_gpio_write(LED_PIN, GPIO_HIGH);
    // delay simulation
    hal_gpio_write(LED_PIN, GPIO_LOW);
}