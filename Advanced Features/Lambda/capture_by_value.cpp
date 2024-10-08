#include <iostream>

int main() {
    int x = 10;

    // Capture x by value
    auto lambda_by_value = [x]() {
        return x + 5; // Capture x's value and return x + 5
    };

    // Call the lambda and print the result
    std::cout << "Result (by value): " << lambda_by_value() << std::endl; // Output: 15
    std::cout << "Original x: " << x << std::endl; // Output: 10
    return 0; // Exit the program
}
/*
    Result (by value): 15
    Original x: 10
*/