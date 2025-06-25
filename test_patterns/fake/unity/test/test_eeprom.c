#include "unity.h"
#include "eeprom.h"

void setUp(void) {}
void tearDown(void) {}

void test_eeprom_write_and_read(void) {
    eeprom_write(10, 42);
    int val = eeprom_read(10);
    TEST_ASSERT_EQUAL_INT(42, val);
}

void test_invalid_address_returns_error(void) {
    int result = eeprom_read(999);  // out of bounds
    TEST_ASSERT_EQUAL_INT(-1, result);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_eeprom_write_and_read);
    RUN_TEST(test_invalid_address_returns_error);
    return UNITY_END();
}
