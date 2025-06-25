#include <utility>
#include <iostream>

/*
 * Converts any type T to a reference type, making it possible to use member functions in decltype expressions
 * without the need to go through constructors.
 * declval is commonly used in templates where acceptable template parameters may have no constructor in common, but have the same member function whose return type is needed.
 *
 * Note that declval can only be used in unevaluated contexts and is not required to be defined; it is an error to evaluate an expression that contains this function.
 * Formally, the program is ill-formed if this function is odr-used.
 *
 */

struct Default { int foo() const { return 1; } };

struct NonDefault
{
    NonDefault() = delete;
    int foo() const { return 1; }
};

int main()
{
    decltype(Default().foo()) n1 = 1;                   // type of n1 is int
//  decltype(NonDefault().foo()) n2 = n1;               // error: no default constructor
    decltype(std::declval<NonDefault>().foo()) n2 = n1; // type of n2 is int
    std::cout << "n1 = " << n1 << '\n'
              << "n2 = " << n2 << '\n';
}
