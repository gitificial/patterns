#include "unity.h"
// #include "controller.c"

#include "hardware.h"
void monitor_temperature(void);

extern int last_fan_state;
extern int fan_set_state_called;
extern float test_temperature;

void setUp(void) {
    last_fan_state = -1;
    fan_set_state_called = 0;
}

void tearDown(void) {}

void test_TurnsFanOn_WhenTooHot(void) {
    test_temperature = 80.0f;
    monitor_temperature();
    TEST_ASSERT_EQUAL_INT(1, fan_set_state_called);
    TEST_ASSERT_EQUAL_INT(1, last_fan_state);
}

void test_TurnsFanOff_WhenCool(void) {
    test_temperature = 50.0f;
    monitor_temperature();
    TEST_ASSERT_EQUAL_INT(1, fan_set_state_called);
    TEST_ASSERT_EQUAL_INT(0, last_fan_state);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_TurnsFanOn_WhenTooHot);
    RUN_TEST(test_TurnsFanOff_WhenCool);
    return UNITY_END();
}
