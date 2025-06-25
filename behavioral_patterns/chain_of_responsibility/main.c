#include "chain_of_responsibility.c"

int main() {
    Handler errorHandler = { LEVEL_ERROR, handle_error, NULL };
    Handler warningHandler = { LEVEL_WARNING, handle_warning, &errorHandler };
    Handler infoHandler = { LEVEL_INFO, handle_info, &warningHandler };

    Handler* logger_chain = &infoHandler;

    log_message(logger_chain, LEVEL_INFO, "System boot successful.");
    log_message(logger_chain, LEVEL_WARNING, "Low battery detected.");
    log_message(logger_chain, LEVEL_ERROR, "Sensor failure!");
    log_message(logger_chain, 99, "Unknown severity.");

    return 0;
}
