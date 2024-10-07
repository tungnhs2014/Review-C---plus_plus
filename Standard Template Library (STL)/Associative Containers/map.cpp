#include <iostream>
#include <map>

int main() {
    // Declare a map to store key-value pairs (name and age)
    std::map<std::string, int> myMap;

    // Insert key-value pairs
    myMap["Alice"] = 25;
    myMap["Bob"] = 30;
    myMap["Charlie"] = 28;

    // Iterate through the map and print key-value pairs
    std::cout << "Map elements:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;  // Print key and value
    }

    // Access value by key
    std::cout << "Age of Alice: " << myMap["Alice"] << std::endl;

    return 0;
}

/*
    Map elements:
    Alice: 25
    Bob: 30
    Charlie: 28
    Age of Alice: 25
*/