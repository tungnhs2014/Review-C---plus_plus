#include <iostream>
#include <mutex>

// Thread-safe Singleton class
class ThreadSafeSingleton {
private:
    static ThreadSafeSingleton* instance; // Static instance of the class
    static std::mutex mutex_;             // Mutex to ensure thread-safety

    // Private constructor to prevent instantiation from outside the class
    ThreadSafeSingleton() {
        std::cout << "Thread-safe Singleton instance created." << std::endl;
    }

public:
    // Static method to get the single instance, with thread-safety
    static ThreadSafeSingleton* getInstance() {
        std::lock_guard<std::mutex> lock(mutex_); // Lock the mutex during this block
        if (instance == nullptr) {
            instance = new ThreadSafeSingleton(); // Create instance if it doesn't exist
        }
        return instance; // Return the existing instance
    }

    // Example method in the Singleton class
    void show() {
        std::cout << "Thread-safe Singleton instance in use!" << std::endl;
    }
};

// Initialize the static member variables
ThreadSafeSingleton* ThreadSafeSingleton::instance = nullptr;
std::mutex ThreadSafeSingleton::mutex_;

int main() {
    // Get the Singleton instance in a thread-safe manner
    ThreadSafeSingleton* singleton = ThreadSafeSingleton::getInstance();
    singleton->show();

    return 0;
}

/*
    Thread-safe Singleton instance created.
    Thread-safe Singleton instance in use!
*/