#include <iostream>
#include <vector>
#include <algorithm>  // Required for sort()

int main() {
    // Initialize a vector of integers
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};

    // Sort the vector in ascending order
    std::sort(vec.begin(), vec.end());  // Uses the default comparison (operator <)

    // Print sorted elements
    std::cout << "Sorted elements: ";
    for (int val : vec) {
        std::cout << val << " ";  // Output sorted values
    }
    std::cout << std::endl;

    return 0;
}

/*
    Sorted elements: 1 2 5 5 6 9 
*/