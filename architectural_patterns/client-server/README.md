# Client-Server pattern
- The Server provides services or data.
- The Client requests those services.

## Common Use Cases
- Web servers & web browsers
- Database clients
- IoT devices communicating with a central server

## UML

```mermaid 
classDiagram
    class Client {
        + send_request()
        + receive_response()
    }
    class Server {
        + receive_request()
        + process_request()
        + send_response()
    }
    class Request {
        - data
    }
    class Response {
        - data
    }

    Client --> Request : creates
    Client --> Server : sends request
    Server --> Request : receives
    Server --> Response : creates
    Server --> Client : sends response
    Client --> Response : receives
```
