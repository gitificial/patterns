#include <stdio.h>
#include "broker.h"

void log_service(const char *payload) {
    printf("[Log Service] %s\n", payload);
}

void alert_service(const char *payload) {
    printf("[Alert Service] !! %s !!\n", payload);
}

void register_services() {
    broker_register_service("log", log_service);
    broker_register_service("alert", alert_service);
}