#include "console_logger.hpp"
#include "service.hpp"

int main() {
    ConsoleLogger logger;
    Service service(logger);
    service.doSomething();
    return 0;
}
