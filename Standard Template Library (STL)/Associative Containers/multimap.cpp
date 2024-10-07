#include <iostream>
#include <map>

int main() {
    // Declare a multimap to store key-value pairs
    std::multimap<std::string, int> myMultimap;

    // Insert key-value pairs, including duplicate keys
    myMultimap.insert({"Alice", 25});
    myMultimap.insert({"Bob", 30});
    myMultimap.insert({"Alice", 28});  // Duplicate key allowed

    // Iterate through the multimap and print key-value pairs
    std::cout << "Multimap elements:" << std::endl;
    for (const auto& pair : myMultimap) {
        std::cout << pair.first << ": " << pair.second << std::endl;  // Print key and value
    }

    return 0;
}

/*
    Multimap elements:
    Alice: 25
    Alice: 28
    Bob: 30
*/