// loggable.h
#pragma once
#include "logger.hpp"

class Loggable {
public:
    virtual void setLogger(Logger* logger) = 0;
    virtual ~Loggable() = default;
};
