# Setter Injection

## When to use

- You want to create an object without immediately providing all dependencies.
- Some dependencies are optional or can change at runtime.

## UML

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
        -logger: Logger*
        +setLogger(logger: Logger*)
        +doSomething()
    }

    class Main

    Logger <|.. ConsoleLogger
    Service --> Logger : uses
    Main --> ConsoleLogger : creates
    Main --> Service : injects logger via setter
```

## Compile and Run

```
g++ main.cpp console_logger.cpp service.cpp -o app
```