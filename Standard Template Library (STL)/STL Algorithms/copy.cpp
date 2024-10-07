#include <iostream>
#include <vector>
#include <algorithm>  // Required for copy()

int main() {
    // Initialize a source vector
    std::vector<int> source = {1, 2, 3, 4, 5};
    
    // Create a destination vector of the same size as the source
    std::vector<int> destination(source.size());

    // Copy elements from source to destination
    std::copy(source.begin(), source.end(), destination.begin());  // Copying values

    // Print copied elements
    std::cout << "Copied elements: ";
    for (int val : destination) {
        std::cout << val << " ";  // Output copied values
    }
    std::cout << std::endl;

    return 0;
}

/*
    Copied elements: 1 2 3 4 5 
*/
