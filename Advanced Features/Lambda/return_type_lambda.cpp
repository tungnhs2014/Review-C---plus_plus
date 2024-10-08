#include <iostream>

int main() {
    // Define a lambda expression with a specified return type
    auto multiply = [](int a, int b) -> int {
        return a * b; // Return the product of a and b
    };

    // Call the lambda and print the result
    std::cout << "Product: " << multiply(3, 4) << std::endl; // Output: 12
    return 0; // Exit the program
}

/*  
    Product: 12
*/