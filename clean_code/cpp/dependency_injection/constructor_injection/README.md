# Constructor Injection

| Feature        | Benefit                                         |
| -------------- | ----------------------------------------------- |
| Testability    | You can inject mocks or fakes                   |
| Loose coupling | Class depends on interface, not concrete        |
| Explicitness   | Required dependencies are clear at construction |
| Immutability   | No reassignment after construction              |


## UML

### Class diagram
```mermaid
classDiagram
    class Logger {
        <<interface>>
        +log(message: std::string)
    }

    class ConsoleLogger {
        +log(message: std::string)
    }

    class Service {
        -logger: Logger&
        +Service(logger: Logger&)
        +doSomething()
    }

    class Main {
    }

    Logger <|.. ConsoleLogger
    Logger <.. Service : depends on
    Main --> Service
    Main --> ConsoleLogger
```

### Sequence diagram
```mermaid
sequenceDiagram
    participant Main
    participant ConsoleLogger
    participant Service

    Main->>ConsoleLogger: create ConsoleLogger
    Main->>Service: inject ConsoleLogger via constructor
    Service->>ConsoleLogger: log("Service is doing work.")
```