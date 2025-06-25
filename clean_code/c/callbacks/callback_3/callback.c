#include <stdio.h>

// addFuncPtr_t is a pointer to a function that:
// - returns int
// - takes two int arguments
typedef int ( *addFuncPtr_t )( int, int );

int add(int x, int y) {
    return (x + y);
}

void passptr(addFuncPtr_t fp, int a, int b) {
    int result = fp(a, b);
    printf("%d \n", result);
}

int main() {
    add(3, 5);

    // note that the function is passed separately from
    // the arguments - add(3,5) would *call* the function
    // instead of passing the address of the function
    passptr( add, 3, 5 );
    return 0;
}
