#include <iostream>
#include <vector>

int main() {
    // Initialize a vector of integers
    std::vector<int> vec = {10, 20, 30, 40, 50};

    // Use rbegin() and rend() to iterate through the vector in reverse
    std::cout << "Vector elements in reverse: ";

    // Begin the reverse iteration from the end of the vector
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << *rit << " ";  // Dereference reverse iterator to get the value
    }
    std::cout << std::endl;  // Print a new line

    return 0;
}

/*
    Vector elements in reverse: 50 40 30 20 10 
*/