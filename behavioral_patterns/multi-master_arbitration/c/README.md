# Multi-master arbitration

## Scenario
Demonstrates how two masters might contend for an I2C-like bus:
- Two masters try to send data.
- Each bit sent is compared.
- If a master detects a discrepancy (tries to send 1 but sees 0 on the bus), it loses arbitration and stops transmitting.
- The master that successfully sends all bits first wins arbitration and continues transmission.

## UML

```mermaid
sequenceDiagram
    participant M1 as Master 1
    participant M2 as Master 2
    participant Bus

    M1->>Bus: Send bit sequence
    M2->>Bus: Send bit sequence
    Bus-->>M1: Arbitration result
    Bus-->>M2: Arbitration result

    alt M1 wins
        M1->>Bus: Continue transmission
    else M2 wins
        M2->>Bus: Continue transmission
    end
```