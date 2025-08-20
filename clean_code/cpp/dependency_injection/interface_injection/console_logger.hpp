// console_logger.h
#pragma once
#include "logger.hpp"
#include <iostream>

class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) override {
        std::cout << "[Console] " << message << std::endl;
    }
};
