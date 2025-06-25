#include <stdio.h>
#include <assert.h>

// Function under test
int and_gate(int a, int b) {
    return a & b;
}

// Exhaustive enumeration test
void test_and_gate() {
    printf("Testing all input combinations for 2-input AND gate...\n");

    for (int a = 0; a <= 1; ++a) {
        for (int b = 0; b <= 1; ++b) {
            int expected = a & b;
            int result = and_gate(a, b);
            printf("Input: a=%d, b=%d → result=%d\n", a, b, result);
            assert(result == expected);
        }
    }

    printf("All combinations passed.\n");
}

int main() {
    test_and_gate();
    return 0;
}
