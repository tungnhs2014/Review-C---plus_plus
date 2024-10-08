#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

int main() {
    // Initialize a vector with unsorted integers
    std::vector<int> vec = {5, 3, 8, 1, 2};

    // Sort the vector using a lambda expression
    std::sort(vec.begin(), vec.end(), [](int a, int b) {
        return a < b; // Sort in ascending order
    });

    // Print the sorted vector
    std::cout << "Sorted vector: ";
    for (const auto& num : vec) {
        std::cout << num << " "; // Print each element
    }
    std::cout << std::endl; // New line
    return 0; // Exit the program
}

/*
    Sorted vector: 1 2 3 5 8 
*/