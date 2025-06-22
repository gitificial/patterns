#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OBSERVERS 5

// Observer interface
typedef struct {
    void (*update)(float temperature); // Function pointer for update
} Observer;

// Subject (Temperature Sensor)
typedef struct {
    Observer *observers[MAX_OBSERVERS];
    int observer_count;
    float temperature;
} Subject;

// Function prototypes
void subject_add_observer(Subject *subject, Observer *observer);
void subject_remove_observer(Subject *subject, Observer *observer);
void subject_notify_observers(Subject *subject);
void subject_set_temperature(Subject *subject, float temperature);

// Observer implementations
void lcd_display_update(float temperature);
void console_display_update(float temperature);

// Main function
int main(void) {
    // Create subject (Temperature Sensor)
    Subject temperature_sensor = { .observer_count = 0, .temperature = 0.0 };

    // Create observers (LCD and Console displays)
    Observer lcd_display = { .update = lcd_display_update };
    Observer console_display = { .update = console_display_update };

    // Register observers
    subject_add_observer(&temperature_sensor, &lcd_display);
    subject_add_observer(&temperature_sensor, &console_display);

    // Simulate temperature changes
    subject_set_temperature(&temperature_sensor, 25.5);
    subject_set_temperature(&temperature_sensor, 30.0);

    // Remove an observer
    subject_remove_observer(&temperature_sensor, &lcd_display);

    // Simulate another temperature change
    subject_set_temperature(&temperature_sensor, 28.0);

    return 0;
}

// Subject: Add an observer
void subject_add_observer(Subject *subject, Observer *observer) {
    if (subject->observer_count < MAX_OBSERVERS) {
        subject->observers[subject->observer_count++] = observer;
    } else {
        printf("Observer list is full!\n");
    }
}

// Subject: Remove an observer
void subject_remove_observer(Subject *subject, Observer *observer) {
    for (int i = 0; i < subject->observer_count; i++) {
        if (subject->observers[i] == observer) {
            for (int j = i; j < subject->observer_count - 1; j++) {
                subject->observers[j] = subject->observers[j + 1];
            }
            subject->observer_count--;
            break;
        }
    }
}

// Subject: Notify all observers
void subject_notify_observers(Subject *subject) {
    for (int i = 0; i < subject->observer_count; i++) {
        subject->observers[i]->update(subject->temperature);
    }
}

// Subject: Set a new temperature and notify observers
void subject_set_temperature(Subject *subject, float temperature) {
    subject->temperature = temperature;
    printf("Temperature Sensor: New temperature is %.2f°C\n", temperature);
    subject_notify_observers(subject);
}

// Observer: LCD display update
void lcd_display_update(float temperature) {
    printf("LCD Display: Temperature updated to %.2f°C\n", temperature);
}

// Observer: Console display update
void console_display_update(float temperature) {
    printf("Console Display: Temperature updated to %.2f°C\n", temperature);
}
