#include <iostream>

int main() {
    // Define a lambda expression with no parameters
    auto greet = []() {
        std::cout << "Hello, World!" << std::endl; // Print greeting message
    };

    // Call the lambda
    greet(); // Output: Hello, World!
    return 0; // Exit the program
}

/*
    Hello, World!
*/