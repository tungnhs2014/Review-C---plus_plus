#include <iostream>
#include <vector>

int main() {
    // Initialize a vector of integers
    std::vector<int> vec = {10, 20, 30, 40, 50};

    // Use begin() and end() to iterate through the vector
    std::cout << "Vector elements: ";
    
    // Begin the iteration from the start of the vector
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";  // Dereference iterator to get the value
    }
    std::cout << std::endl;  // Print a new line

    return 0;
}
/*
    Vector elements: 10 20 30 40 50 
*/