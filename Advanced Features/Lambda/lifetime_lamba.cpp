#include <iostream>

int main() {
    int x = 10;

    // Capture x by reference
    auto lambda = [&x]() {
        // x is captured by reference
        std::cout << "Value of x inside lambda: " << x << std::endl; // Access x
    };

    lambda(); // Call the lambda
    x = 20; // Modify x
    lambda(); // Call the lambda again
    return 0; // Exit the program
}

/*
    Value of x inside lambda: 10
    Value of x inside lambda: 20
*/