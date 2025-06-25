| **Test Pattern**               | **Description**                                                                |
| ------------------------------ | ------------------------------------------------------------------------------ |
| **Arrange-Act-Assert (AAA)**   | Structure test code into setup, action, and check phases                       |
| **Test Stub / Mock / Fake**    | Replace parts of the system with simplified versions for isolation             |
| **Parameterized Test**         | Run the same test logic with different inputs                                  |
| **Test Harness**               | Custom test framework to inject inputs and capture outputs in embedded systems |
| **Hardware-in-the-Loop (HIL)** | Test software with real or simulated hardware in real-time                     |
| **Golden Master**              | Capture correct output and compare future runs for regression                  |
| **Boundary Value Analysis**    | Test edge cases around input boundaries                                        |
| **Exhaustive Enumeration**     | Test all possible states or inputs (when feasible)                             |
| **State-Based Testing**        | Model system behavior as a finite state machine and test transitions           |
| **Error Injection**            | Deliberately simulate faults (e.g., corrupted sensor data, timeouts)           |
| **Watchdog Triggering**        | Simulate conditions to verify watchdog functionality                           |
| **Loopback Test**              | Send a signal/data through a system and verify it returns correctly            |
| **Back-to-Back Testing**       | Run two implementations (e.g., model vs embedded) with the same inputs         |
| **Soak/Stress Testing**        | Run for long durations to reveal memory leaks, heat buildup, or hangs          |
| **Assertion Pattern**          | Embed `assert()` or custom checks to catch invalid states at runtime           |
| **Simulated Environment**      | Use tools to simulate peripherals or real-world conditions                     |

