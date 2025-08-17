/*
 * See also container types: https://en.cppreference.com/w/cpp/container
 *
 * The Containers library is a generic collection of class templates and
 * algorithms that allow programmers to easily implement common data structures
 * like queues, lists and stacks.
 *
 * Example: Basic Container Concept using std::vector
 *
 */

#include <iostream>
#include <vector>

int main() {
    // Create a container: a vector of integers
    std::vector<int> numbers;

    // Add (store) elements in the container
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Access elements (like an array)
    std::cout << "Accessing elements:\n";
    std::cout << "First: " << numbers[0] << "\n";
    std::cout << "Second: " << numbers[1] << "\n";

    // Iterate through the container
    std::cout << "All elements:\n";
    for (int value : numbers) {
        std::cout << value << "\n";
    }

    // Container properties
    std::cout << "Size of container: " << numbers.size() << "\n";

    return 0;
}
