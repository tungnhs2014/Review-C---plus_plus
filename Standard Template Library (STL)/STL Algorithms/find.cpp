#include <iostream>
#include <vector>
#include <algorithm>  // Required for find()

int main() {
    // Initialize a vector of integers
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Find the element 3 in the vector
    auto it = std::find(vec.begin(), vec.end(), 3);  // Search for the value 3

    // Check if the element was found
    if (it != vec.end()) {
        std::cout << "Element " << *it << " found in the vector." << std::endl;  // Dereference iterator to get the value
    } else {
        std::cout << "Element not found." << std::endl;  // Element was not found
    }

    return 0;
}

/*
    Element 3 found in the vector.
*/