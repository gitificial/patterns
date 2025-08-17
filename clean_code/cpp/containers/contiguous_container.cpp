/*
*   Example: std::vector as a Contiguous Container 
*/

#include <iostream>
#include <vector>

int main() {
    // Create a vector with some elements
    std::vector<int> data = {1, 2, 3, 4, 5};

    // Print using index access (fast because memory is contiguous)
    std::cout << "Index-based access:\n";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << "data[" << i << "] = " << data[i] << "\n";
    }

    // Show that underlying memory is contiguous
    std::cout << "\nMemory addresses:\n";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << "&data[" << i << "] = " << &data[i] << "\n";
    }

    return 0;
}
