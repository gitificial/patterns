#include <stdio.h>

#include "broker.h"

// Declare external function to register services
void register_services();

int main() {
    register_services();

    // Simulate clients sending messages
    broker_dispatch("log", "System started");
    broker_dispatch("alert", "High temperature detected");
    broker_dispatch("unknown", "This should fail");

    return 0;
}