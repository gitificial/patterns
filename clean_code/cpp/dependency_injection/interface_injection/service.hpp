#pragma once
#include "loggable.hpp"

class Service : public Loggable {
public:
    void setLogger(Logger* logger) override;
    void doSomething();

private:
    Logger* logger = nullptr;
};

