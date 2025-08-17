# Broker pattern example in C
- Clients make service requests.
- Services provide functionality.
- Broker registers services and handles message delivery.

- Broker: Central dispatcher in broker.c
- Services: Registered via broker_register_service()
- Client: Calls broker_dispatch() with service name
- Use Cases: RPC, plugin systems, event buses, IoT routing

## Compile and run
```
gcc main.c broker.h broker.c services.c -o broker
./broker
```
