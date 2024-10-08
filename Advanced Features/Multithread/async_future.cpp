#include <iostream>
#include <future>
#include <chrono>
#include <thread>

// Function to be executed asynchronously
int find_answer() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate a long computation
    return 42; // Return the answer
}

int main() {
    std::future<int> result = std::async(find_answer); // Start the asynchronous task
    std::cout << "Waiting for the answer..." << std::endl;

    // Get the result from the asynchronous task
    std::cout << "The answer is: " << result.get() << std::endl; // Blocks until the result is ready

    return 0; // Exit the program
}

/*
    Waiting for the answer...
    The answer is: 42
*/ 

