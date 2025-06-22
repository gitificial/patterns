#include "broker.h"
#include <stdio.h>
#include <string.h>

#define MAX_SERVICES 10

typedef struct {
    const char *name;
    service_fn_t fn;
} service_entry_t;

static service_entry_t registry[MAX_SERVICES];
static int service_count = 0;

void broker_register_service(const char *name, service_fn_t fn) {
    if (service_count < MAX_SERVICES) {
        registry[service_count].name = name;
        registry[service_count].fn = fn;
        service_count++;
        printf("[Broker] Registered service: %s\n", name);
    } else {
        printf("[Broker] Service registry full!\n");
    }
}

void broker_dispatch(const char *name, const char *payload) {
    for (int i = 0; i < service_count; i++) {
        if (strcmp(registry[i].name, name) == 0) {
            printf("[Broker] Dispatching to service: %s\n", name);
            registry[i].fn(payload);
            return;
        }
    }
    printf("[Broker] No service found for: %s\n", name);
}