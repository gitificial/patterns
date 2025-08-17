#include "service.hpp"

Service::Service(Logger& logger) : logger(logger) {}

void Service::doSomething() {
    logger.log("Service is doing work.");
}
