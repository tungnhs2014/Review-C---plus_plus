#include <iostream>
#include <vector>

int main() {
    // Declare a vector of integers
    std::vector<int> vec = {1, 2, 3};

    // Add an element to the end
    vec.push_back(4);

    // Access elements using indexing
    std::cout << "Vector elements: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";  // Random access using index
    }
    std::cout << std::endl;

    // Remove the last element
    vec.pop_back();

    std::cout << "After pop_back, vector elements: ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
    Vector elements: 1 2 3 4 
    After pop_back, vector elements: 1 2 3 
*/