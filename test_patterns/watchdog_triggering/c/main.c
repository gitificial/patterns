#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h> // For sleep()

#define WATCHDOG_TIMEOUT_SEC 3

// Watchdog state
time_t last_kick_time;

void watchdog_init() {
    last_kick_time = time(NULL);
    printf("[Watchdog] Initialized. Timeout = %d seconds\n", WATCHDOG_TIMEOUT_SEC);
}

void watchdog_kick() {
    last_kick_time = time(NULL);
    printf("[Watchdog] Kicked at %ld\n", last_kick_time);
}

void watchdog_check() {
    time_t now = time(NULL);
    if (difftime(now, last_kick_time) > WATCHDOG_TIMEOUT_SEC) {
        printf("[Watchdog] Timeout! System reset triggered.\n");
        exit(EXIT_FAILURE); // Simulate system reset
    }
}

// Simulated main loop
void application_loop(bool simulate_hang) {
    watchdog_init();

    for (int i = 0; i < 10; ++i) {
        printf("Main loop iteration %d\n", i);

        if (simulate_hang && i == 5) {
            printf("[App] Simulating hang... (no kick)\n");
            // Skip kicking to trigger watchdog
        } else {
            watchdog_kick();
        }

        sleep(1);         // Simulate work
        watchdog_check(); // Run watchdog logic
    }

    printf("[App] Completed without watchdog reset.\n");
}

int main() {
    // Run with simulate_hang = true to test watchdog trigger
    application_loop(true);

    return 0;
}
