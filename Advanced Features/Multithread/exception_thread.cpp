#include <iostream>
#include <thread>
#include <stdexcept>

// Function that throws an exception
void thread_function() {
    throw std::runtime_error("Exception in thread"); // Throw an exception
}

int main() {
    try {
        std::thread t(thread_function); // Create a new thread
        t.join(); // Wait for the thread to finish
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl; // Handle the exception
    }

    return 0; // Exit the program
}


/*
    terminate called after throwing an instance of 'std::runtime_error'
    what():  Exception in thread
*/