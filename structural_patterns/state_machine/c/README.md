# State Machine

A state machine is a programming model where the system is in one state at a time and transitions between states are triggered by events or conditions. Below is a simple example of a state machine implemented in C, simulating a traffic light controller.

Traffic Light State Machine Example
States:
1. RED: Cars must stop.
2. GREEN: Cars can go.
3. YELLOW: Cars should prepare to stop.
Transitions:
* RED → GREEN
* GREEN → YELLOW
* YELLOW → RED

## Explanation
1. State Definition:

* The TrafficLightState enum defines the possible states of the traffic light.

2. State Actions:

* Each state has an associated action function (red_state_action, green_state_action, etc.) to handle what happens in that state.

3. State Transitions:

* The switch statement in the while loop handles transitions between states. For example:
    * STATE_RED transitions to STATE_GREEN.
    * STATE_GREEN transitions to STATE_YELLOW.

4. Main Loop:

* The loop keeps the state machine running, simulating a traffic light that cycles through its states.

5. Output:

* The program prints the current state and simulates waiting before transitioning to the next state.

## Enhancements
1. Add Timers:

* Use a real-time clock or delay function to simulate actual timings for each state (e.g., 5 seconds for GREEN, 2 seconds for YELLOW).

2. Add Events:

* Introduce external events (e.g., pedestrian crossing button press) to trigger state transitions.

3. Use a Struct:

* Encapsulate state information and actions in a struct for more complex state machines.