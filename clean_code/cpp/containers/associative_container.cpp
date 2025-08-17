/*
* Example: std::map as an Associative Container
*/

#include <iostream>
#include <map>
#include <string>

int main() {
    // Create a map from string to int
    std::map<std::string, int> fruitInventory;

    // Insert some key-value pairs
    fruitInventory["apples"] = 5;
    fruitInventory["bananas"] = 3;
    fruitInventory["oranges"] = 8;

    // Update value
    fruitInventory["apples"] += 2; // now 7

    // Access and print values
    std::cout << "Inventory:\n";
    for (const auto& pair : fruitInventory) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }

    // Lookup
    std::string search = "bananas";
    if (fruitInventory.find(search) != fruitInventory.end()) {
        std::cout << search << " are in stock: "
                  << fruitInventory[search] << '\n';
    } else {
        std::cout << search << " not found.\n";
    }

    return 0;
}
