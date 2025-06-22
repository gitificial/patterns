#ifndef BROKER_H
#define BROKER_H

typedef void (*service_fn_t)(const char *payload);

void broker_register_service(const char *name, service_fn_t fn);
void broker_dispatch(const char *name, const char *payload);

#endif