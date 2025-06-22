# Observer Pattern

The Observer Pattern is a behavioral design pattern where an object (the subject) maintains a list of its dependents (the observers) and notifies them of any state changes. This is useful for implementing event-driven systems.

## Example: Temperature Sensor and Display
Scenario:
A Temperature Sensor acts as the subject.
Multiple Display Units (e.g., LCD, Console) act as observers.
Whenever the temperature changes, the sensor notifies all registered displays.

## Explanation
1. Subject:

- The Subject struct maintains a list of registered observers (observers) and the current state (temperature).

* Functions:
    * subject_add_observer: Adds an observer to the list.
    * subject_remove_observer: Removes an observer from the list.
    * subject_notify_observers: Notifies all observers about a state change.
    * subject_set_temperature: Updates the temperature and triggers notifications.

2. Observer:

- The Observer struct defines an update function pointer that observers implement to handle notifications.
* Two observer implementations:
    * lcd_display_update: Simulates an LCD display.
    * console_display_update: Simulates a console display.

3. Main Loop:

- Registers two observers (LCD and Console) to the subject.
- Simulates temperature changes and notifies observers.
- Demonstrates removing an observer and observing reduced notifications.

## Enhancements
1. Dynamic Allocation:

* Use dynamic memory allocation for observers to avoid fixed-size arrays.

2. Event Types:

* Extend the subject to support different types of events (e.g., humidity changes).

3. Thread-Safe Notifications:

* Use mutexes or semaphores to make the observer list thread-safe in multi-threaded environments.