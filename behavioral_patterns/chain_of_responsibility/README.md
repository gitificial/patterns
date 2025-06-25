# Chain Of Responsibility pattern

The Chain of Responsibility pattern is a behavioral design pattern that allows a request to pass through a chain of handlers until one of them handles it. It's particularly useful in embedded systems and middleware for:

- Event filtering
- Command parsing
- Message routing
- Modular exception handling

Each handler decides:
Whether to handle the request or pass it to the next handler in the chain. 