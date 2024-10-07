#include <iostream>
#include <vector>
#include <algorithm>  // Required for for_each

// Function to print an integer
void print(int value) {
    std::cout << value << " ";  // Output each value
}

int main() {
    // Initialize a vector of integers
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Apply print function to each element in the vector
    std::cout << "Elements: ";
    std::for_each(vec.begin(), vec.end(), print);  // Applies the print function to each element
    std::cout << std::endl;

    return 0;
}

/*
    Elements: 1 2 3 4 5 
*/