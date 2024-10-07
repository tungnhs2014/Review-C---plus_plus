#include <iostream>
#include <vector>

int main() {
    // Initialize a vector of integers
    std::vector<int> vec = {10, 20, 30, 40, 50};

    // Forward iteration using begin() and end()
    std::cout << "Forward iteration: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";  // Dereference iterator to get the value
    }
    std::cout << std::endl;  // Print a new line

    // Reverse iteration using rbegin() and rend()
    std::cout << "Reverse iteration: ";
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << *rit << " ";  // Dereference reverse iterator to get the value
    }
    std::cout << std::endl;  // Print a new line

    return 0;
}

/*
    Forward iteration: 10 20 30 40 50 
    Reverse iteration: 50 40 30 20 10 

*/