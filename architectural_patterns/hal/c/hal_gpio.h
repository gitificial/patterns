#ifndef HAL_GPIO_H
#define HAL_GPIO_H

typedef enum {
    GPIO_LOW = 0,
    GPIO_HIGH = 1
} gpio_state_t;

void hal_gpio_init(int pin);
void hal_gpio_write(int pin, gpio_state_t state);
gpio_state_t hal_gpio_read(int pin);

#endif