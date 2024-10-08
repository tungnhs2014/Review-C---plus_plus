#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // Declare a mutex for synchronization

// Function that will be executed in each thread
void print_thread(int id) {
    std::lock_guard<std::mutex> guard(mtx);  // Automatically locks the mutex
    std::cout << "Thread ID: " << id << std::endl;  // Print the ID of the current thread
    // The mutex will be automatically unlocked when 'guard' goes out of scope
}

int main() {
    std::thread threads[10];  // Array to hold 10 threads

    // Create 10 threads
    for (int i = 0; i < 10; ++i) {
        threads[i] = std::thread(print_thread, i);
    }

    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }

    return 0; // Exit the program
}

/*
    Thread ID: 5
    Thread ID: 4
    Thread ID: 3
    Thread ID: 1
    Thread ID: 2
    Thread ID: 6
    Thread ID: 7
    Thread ID: 0
    Thread ID: 8
    Thread ID: 9
*/