#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define DEBOUNCE_DELAY_MS 50  // Delay to filter bounces (typical: 10–50ms)

// Simulate reading a digital pin (returns 1 when "pressed")
int read_button_pin() {
    // Replace this with actual GPIO read, e.g., digitalRead(PIN)
    // For simulation: return 1 or 0 randomly or based on test sequence
    static int simulated_state = 0;
    static int count = 0;

    count++;
    if (count % 20 == 0) {
        simulated_state = !simulated_state; // Toggle every 20 calls
    }
    return simulated_state;
}

// Get milliseconds since program start (used for debounce timing)
unsigned long millis() {
    return (unsigned long)(clock() * 1000 / CLOCKS_PER_SEC);
}

bool is_button_pressed() {
    static int last_button_state = 0;
    static int debounced_state = 0;
    static unsigned long last_debounce_time = 0;

    int reading = read_button_pin();

    if (reading != last_button_state) {
        // Button state changed, reset debounce timer
        last_debounce_time = millis();
    }

    if ((millis() - last_debounce_time) > DEBOUNCE_DELAY_MS) {
        // If the button state has been stable for longer than debounce delay
        if (reading != debounced_state) {
            debounced_state = reading;

            if (debounced_state == 1) {
                // Button is pressed
                return true;
            }
        }
    }

    last_button_state = reading;
    return false;
}

int main() {
    while (1) {
        if (is_button_pressed()) {
            printf("Button press detected!\n");
        }
    }
    return 0;
}