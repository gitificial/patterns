// main.cpp
#include "console_logger.hpp"
#include "service.hpp"

int main() {
    ConsoleLogger consoleLogger;
    Service service;

    // Interface injection via method call
    service.setLogger(&consoleLogger);

    service.doSomething();

    return 0;
}
