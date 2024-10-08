#include <iostream>

int main() {
    int y = 20;

    // Capture y by reference
    auto lambda_by_reference = [&y]() {
        y += 5; // Modify the original variable y
    };

    lambda_by_reference(); // Call the lambda
    std::cout << "y after increment (by reference): " << y << std::endl; // Output: 25
    return 0; // Exit the program
}

/* 
    y after increment (by reference): 25
*/