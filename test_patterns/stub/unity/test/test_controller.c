#include "unity.h"
#include "controller.c"          // Include code under test
#include "test_sensor_stub.h"    // Include stub control header

extern float test_temperature;   // Stub control

void setUp(void) {}
void tearDown(void) {}

void test_TemperatureBelowThreshold(void) {
    test_temperature = 60.0f;
    TEST_ASSERT_FALSE(check_overheat());
}

void test_TemperatureAtThreshold(void) {
    test_temperature = 75.0f;
    TEST_ASSERT_TRUE(check_overheat());
}

void test_TemperatureAboveThreshold(void) {
    test_temperature = 80.0f;
    TEST_ASSERT_TRUE(check_overheat());
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_TemperatureBelowThreshold);
    RUN_TEST(test_TemperatureAtThreshold);
    RUN_TEST(test_TemperatureAboveThreshold);
    return UNITY_END();
}