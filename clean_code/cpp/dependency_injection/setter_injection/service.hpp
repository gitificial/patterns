#pragma once
#include "logger.hpp"

class Service {
public:
    void setLogger(Logger* logger);     // <-- Setter injection
    void doSomething();

private:
    Logger* logger = nullptr;
};
