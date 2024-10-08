#include <iostream>
#include <vector>
#include <algorithm> // For std::for_each

int main() {
    // Initialize a vector with integers
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Use for_each to print elements in the vector
    std::for_each(vec.begin(), vec.end(), [](int n) {
        std::cout << n << " "; // Print each element
    });
    std::cout << std::endl; // New line

    return 0; // Exit the program
}

/*
    1 2 3 4 5 
*/