#include <stdio.h>
#include <stdbool.h>

// Enum for traffic light states
typedef enum {
    STATE_RED,
    STATE_GREEN,
    STATE_YELLOW
} TrafficLightState;

// Function prototypes for state actions
void red_state_action(void);
void green_state_action(void);
void yellow_state_action(void);

// Main function
int main(void) {
    TrafficLightState current_state = STATE_RED; // Initial state
    bool running = true;

    while (running) {
        // Perform action based on the current state
        switch (current_state) {
            case STATE_RED:
                red_state_action();
                current_state = STATE_GREEN; // Transition to GREEN
                break;

            case STATE_GREEN:
                green_state_action();
                current_state = STATE_YELLOW; // Transition to YELLOW
                break;

            case STATE_YELLOW:
                yellow_state_action();
                current_state = STATE_RED; // Transition to RED
                break;

            default:
                printf("Invalid state!\n");
                running = false; // Exit the loop on error
                break;
        }

        // Simulate delay (e.g., waiting for a timer)
        printf("Waiting...\n\n");
    }

    return 0;
}

// Action for RED state
void red_state_action(void) {
    printf("State: RED - Cars must STOP.\n");
}

// Action for GREEN state
void green_state_action(void) {
    printf("State: GREEN - Cars can GO.\n");
}

// Action for YELLOW state
void yellow_state_action(void) {
    printf("State: YELLOW - Cars should PREPARE TO STOP.\n");
}
