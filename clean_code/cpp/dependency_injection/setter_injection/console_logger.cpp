#include "console_logger.hpp"
#include <iostream>

void ConsoleLogger::log(const std::string& message) {
    std::cout << "[Console] " << message << std::endl;
}
