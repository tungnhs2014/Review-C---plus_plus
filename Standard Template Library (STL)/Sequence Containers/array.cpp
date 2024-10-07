#include <iostream>
#include <array>

int main() {
    // Declare an array of fixed size 5
    std::array<int, 5> arr = {10, 20, 30, 40, 50};

    // Access elements using range-based for loop
    std::cout << "Array elements: ";
    for (int num : arr) {
        std::cout << num << " ";  // Access each element in the array
    }
    std::cout << std::endl;

    // Access specific elements using at() method
    std::cout << "Element at index 2: " << arr.at(2) << std::endl;

    return 0;
}

/*
    Array elements: 10 20 30 40 50 
    Element at index 2: 30
*/