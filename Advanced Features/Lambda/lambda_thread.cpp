#include <iostream>
#include <thread>

int main() {
    int value = 10;

    // Create a thread with a lambda expression
    std::thread t([&value]() {
        value += 5; // Modify the captured variable
        std::cout << "Value in thread: " << value << std::endl; // Print the modified value
    });

    t.join(); // Wait for the thread to finish
    std::cout << "Value in main: " << value << std::endl; // Output: 15
    return 0; // Exit the program
}

/*
    Value in thread: 15
    Value in main: 15
*/