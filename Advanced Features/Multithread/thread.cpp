#include <iostream>
#include <thread>

// Function that will be executed in the thread
void myFunction() {
    std::cout << "Thread is running!" << std::endl; // Print a message indicating the thread is active
}

int main() {
    // Create a thread object and execute the myFunction
    std::thread t(myFunction);

    // Wait for the thread 't' to finish before continuing
    t.join();  

    std::cout << "Thread has finished." << std::endl; // Print a message after the thread finishes
    return 0; // Exit the program
}


/*
    Thread is running!
    Thread has finished.
*/