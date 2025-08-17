/*
* A reversible container in C++ is one that supports bidirectional iteration, meaning you can traverse it forwards and backwards using standard iterators.
*
* Example: std::vector with Reverse Iteration
*
* rbegin() returns a reverse iterator to the last element.
* rend() is the reverse version of begin(), stopping before the first element.
* This is part of the bidirectional iterator support in STL.
*
*/

#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50};

    std::cout << "Forward iteration:\n";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "Reverse iteration:\n";
    for (auto rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << "\n";

    return 0;
}
