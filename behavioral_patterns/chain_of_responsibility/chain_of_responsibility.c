#include <stdio.h>
#include <string.h>

typedef enum {
    LEVEL_INFO,
    LEVEL_WARNING,
    LEVEL_ERROR
} LogLevel;

typedef struct Handler {
    LogLevel level;
    void (*handle)(const char* msg);
    struct Handler* next;
} Handler;

// Handler function for INFO
void handle_info(const char* msg) {
    printf("[INFO] %s\n", msg);
}

// Handler function for WARNING
void handle_warning(const char* msg) {
    printf("[WARNING] %s\n", msg);
}

// Handler function for ERROR
void handle_error(const char* msg) {
    printf("[ERROR] %s\n", msg);
}

// Dispatch function: traverse chain
void log_message(Handler* chain, LogLevel level, const char* msg) {
    Handler* current = chain;
    while (current != NULL) {
        if (current->level == level) {
            current->handle(msg);
            return;  // handled
        }
        current = current->next;
    }
    printf("No handler for level %d\n", level);
}
