#include <stdio.h>
#include "sensor.h"

// Stub implementation
float test_temp = 25.0;

float read_temperature(void) {
    return test_temp;  // Controlled by test
}

// Include code under test
#include "controller.c"

void run_test(const char* label, float temp, int expected) {
    test_temp = temp;
    int result = check_overheat();
    printf("%s: Temp = %.1f → %s\n", label, temp,
           (result == expected ? "PASS" : "FAIL"));
}

int main() {
    run_test("Normal", 60.0, 0);         // Should not overheat
    run_test("High", 75.0, 1);           // Edge case
    run_test("Critical", 90.0, 1);       // Should overheat

    return 0;
}
