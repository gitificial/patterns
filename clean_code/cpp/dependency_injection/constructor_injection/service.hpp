/*
*  service.hpp
*/ 
#pragma once
#include "logger.hpp"

class Service {
public:
    explicit Service(Logger& logger);
    void doSomething();

private:
    Logger& logger;
};

