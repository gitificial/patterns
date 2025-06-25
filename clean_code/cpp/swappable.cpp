#include <iostream>
#include <vector>

/*
 *
 * Any lvalue or rvalue of this type can be swapped with any lvalue or rvalue
 * of some other type, using unqualified function call swap() in the context
 * where both std::swap and the user-defined swap()s are visible.
 *
 */

struct IntVector {
    std::vector<int> v;
    IntVector& operator=(IntVector) = delete; // not assignable
    void swap(IntVector& other) {
        v.swap(other.v);
    }
    void operator()(auto rem, char term = ' ') {
        for(std::cout << rem << " { "; int e: v) { std::cout << e << ' '; }
        std::cout << "}" << term;
    }
};
void swap(IntVector& v1, IntVector& v2) {
    v1.swap(v2);
}

int main()
{
    IntVector v1{ {1,1,1,1,1} }, v2{ {2222,2222} };
    auto prn = [&]{ v1("v1"), v2("v2", '\n'); };

//  std::swap(v1, v2); // compiler error! std::swap requires MoveAssignable
    prn();
    std::iter_swap(&v1, &v2); // OK: library calls unqualified swap()
    prn();
    std::ranges::swap(v1, v2); // OK: library calls unqualified swap()
    prn();
}
