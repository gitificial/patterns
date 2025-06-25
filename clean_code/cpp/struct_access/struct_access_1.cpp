#include <iostream>
#include <string>

#include <stdio.h>
#include <typeinfo>
#include <mutex>
#include "config.h"

struct X { int i[2]{1, 5}; }; // definition of X
X x;                 // OK: the definition of X is reachable

int main(int argc, char **argv)
{
	X* xp;

    xp = &x;         // OK: type is "pointer to X"
    // xp++;            // OK: X is complete

    std::cout << x.i[1] << std::endl;
    std::cout << xp->i[0] << std::endl;
    // std::cout << xp++->i << std::endl;

    x.i[0]++;
    std::cout << x.i[0] << std::endl;

    return 0;
}
