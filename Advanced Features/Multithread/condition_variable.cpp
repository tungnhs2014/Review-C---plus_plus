#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

std::mutex mtx;                     // Declare a mutex for synchronization
std::condition_variable cv;         // Condition variable for thread synchronization
bool ready = false;                 // Shared variable to signal readiness

// Function to be executed by threads
void print_thread(int id) {
    std::unique_lock<std::mutex> lock(mtx); // Lock the mutex
    cv.wait(lock, [] { return ready; });     // Wait until 'ready' becomes true
    std::cout << "Thread ID: " << id << std::endl; // Print the ID of the current thread
}

void set_ready() {
    std::unique_lock<std::mutex> lock(mtx); // Lock the mutex
    ready = true;                            // Set the ready flag to true
    cv.notify_all();                        // Notify all waiting threads
}

int main() {
    std::thread threads[10];  // Array to hold 10 threads

    // Create 10 threads
    for (int i = 0; i < 10; ++i) {
        threads[i] = std::thread(print_thread, i);
    }

    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work being done in main
    set_ready(); // Signal that the threads can proceed

    // Wait for all threads to complete
    for (auto& t : threads) {
        t.join();
    }

    return 0; // Exit the program
}

/*

    Thread ID: 9
    Thread ID: 1
    Thread ID: 2
    Thread ID: 5
    Thread ID: 4
    Thread ID: 6
    Thread ID: 7
    Thread ID: 8
    Thread ID: 3
    Thread ID: 0

*/