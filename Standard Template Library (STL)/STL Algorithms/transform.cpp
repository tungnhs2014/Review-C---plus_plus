#include <iostream>
#include <vector>
#include <algorithm>  // Required for transform

// Function to double an integer
int doubleValue(int value) {
    return value * 2;  // Return double of the input value
}

int main() {
    // Initialize a vector of integers
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // Create a vector to hold transformed values of the same size
    std::vector<int> transformed(vec.size());

    // Apply doubleValue function to each element in vec and store in transformed
    std::transform(vec.begin(), vec.end(), transformed.begin(), doubleValue);  // Applies the transformation

    // Print transformed elements
    std::cout << "Transformed elements: ";
    for (int val : transformed) {
        std::cout << val << " ";  // Output each transformed value
    }
    std::cout << std::endl;

    return 0;
}

/*
    Transformed elements: 2 4 6 8 10 
*/