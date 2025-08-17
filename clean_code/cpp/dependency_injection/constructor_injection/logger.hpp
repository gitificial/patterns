/*
* logger.hpp
*/
#pragma once
#include <string>

class Logger {
public:
    virtual void log(const std::string& message) = 0;
    virtual ~Logger() = default;
};
