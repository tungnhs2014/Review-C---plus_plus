#include <iostream>

int main() {
    int a = 5, b = 10;

    // Capture all variables by value
    auto lambda_all_by_value = [=]() {
        return a + b; // Both a and b are captured by value
    };

    // Capture all variables by reference
    auto lambda_all_by_reference = [&]() {
        a += 1; // Modify a
        b += 1; // Modify b
    };

    std::cout << "Sum (by value): " << lambda_all_by_value() << std::endl; // Output: 15
    lambda_all_by_reference(); // Modify a and b
    std::cout << "a: " << a << ", b: " << b << std::endl; // Output: a: 6, b: 11
    return 0; // Exit the program
}

/*
    Sum (by value): 15
    a: 6, b: 11
*/