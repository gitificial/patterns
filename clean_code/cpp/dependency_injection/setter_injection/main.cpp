#include "console_logger.hpp"
#include "service.hpp"

int main() {
    ConsoleLogger logger;
    Service service;

    // Setter injection
    service.setLogger(&logger);

    service.doSomething();

    return 0;
}
