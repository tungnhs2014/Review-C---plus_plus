#include <iostream>

int main() {
    // Define a lambda expression that adds two numbers
    auto add = [](int a, int b) {
        return a + b; // Return the sum of a and b
    };

    // Call the lambda and print the result
    std::cout << "Sum: " << add(3, 5) << std::endl; // Output: Sum: 8
    return 0; // Exit the program
}

/*
    Sum: 8
*/