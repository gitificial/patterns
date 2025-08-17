/*
* console_logger.cpp
*/ 
#pragma once
#include "logger.hpp"

class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) override;
};
