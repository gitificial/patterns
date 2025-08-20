#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

/*
 * A lambda constructs a closure: an unnamed function object capable of capturing variables in scope.
 *
 * A closure, also lexical closure or function closure, is a technique for implementing lexically scoped name binding
 * in a language with first-class functions. Operationally, a closure is a record storing a function[a] together with
 * an environment.The environment is a mapping associating each free variable of the function (variables that are used
 * locally, but defined in an enclosing scope) with the value or reference to which the name was bound when the closure
 * was created.Unlike a plain function, a closure allows the function to access those captured variables through the
 * closure's copies of their values or references, even when the function is invoked outside their scope.
 */

int main()
{
    std::vector<int> c = {1, 2, 3, 4, 5, 6, 7};
    int x = 5;
    c.erase(std::remove_if(c.begin(), c.end(), [x](int n) { return n < x; }), c.end());

    std::cout << "c: ";
    std::for_each(c.begin(), c.end(), [](int i){ std::cout << i << ' '; });
    std::cout << '\n';

    // the type of a closure cannot be named, but can be inferred with auto
    // since C++14, lambda could own default arguments
    auto func1 = [](int i = 6) { return i + 4; };
    std::cout << "func1: " << func1() << '\n';

    // like all callable objects, closures can be captured in std::function
    // (this may incur unnecessary overhead)
    std::function<int(int)> func2 = [](int i) { return i + 4; };
    std::cout << "func2: " << func2(6) << '\n';

    constexpr int fib_max {8};
    std::cout << "Emulate `recursive lambda` calls:\nFibonacci numbers: ";
    auto nth_fibonacci = [](int n)
    {
        std::function<int(int, int, int)> fib = [&](int n, int a, int b)
        {
            return n ? fib(n - 1, a + b, a) : b;
        };
        return fib(n, 0, 1);
    };

    for (int i{1}; i <= fib_max; ++i)
    {
        std::cout << nth_fibonacci(i) << (i < fib_max ? ", " : "\n");
    }

    std::cout << "Alternative approach to lambda recursion:\nFibonacci numbers: ";
    auto nth_fibonacci2 = [](auto self, int n, int a = 0, int b = 1) -> int
    {
        return n ? self(self, n - 1, a + b, a) : b;
    };

    for (int i{1}; i <= fib_max; ++i)
    {
        std::cout << nth_fibonacci2(nth_fibonacci2, i) << (i < fib_max ? ", " : "\n");
    }

#ifdef __cpp_explicit_this_parameter
    std::cout << "C++23 approach to lambda recursion:\n";
    auto nth_fibonacci3 = [](this auto self, int n, int a = 0, int b = 1)
    {
         return n ? self(n - 1, a + b, a) : b;
    };

    for (int i{1}; i <= fib_max; ++i)
    {
        std::cout << nth_fibonacci3(i) << (i < fib_max ? ", " : "\n");
    }
#endif
}
