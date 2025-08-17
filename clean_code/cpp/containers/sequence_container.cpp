/*
* Example: std::deque as a Sequence Container
*/

#include <iostream>
#include <deque>

int main() {
    // Create a deque of integers
    std::deque<int> sequence;

    // Add elements at both ends
    sequence.push_back(10);
    sequence.push_front(5);
    sequence.push_back(15);

    // Iterate through the sequence
    std::cout << "Sequence contents:\n";
    for (int value : sequence) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    // Access front and back
    std::cout << "Front: " << sequence.front() << "\n";
    std::cout << "Back: " << sequence.back() << "\n";

    return 0;
}
