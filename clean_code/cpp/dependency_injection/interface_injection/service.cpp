#include "service.hpp"

void Service::setLogger(Logger* logger) {
    this->logger = logger;
}

void Service::doSomething() {
    if (logger) {
        logger->log("Service is doing work.");
    }
}
