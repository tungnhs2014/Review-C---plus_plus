#include <iostream>

// Lazy Initialization Singleton
class LazySingleton {
private:
    static LazySingleton* instance;

    // Private constructor and destructor
    LazySingleton() {
        std::cout << "LazySingleton instance created." << std::endl;
    }

    ~LazySingleton() {
        std::cout << "LazySingleton instance destroyed." << std::endl;
    }

public:
    // Static method to get the single instance
    static LazySingleton* getInstance() {
        if (instance == nullptr) {
            instance = new LazySingleton(); // Create instance on first use
        }
        return instance;
    }

    // Method to explicitly destroy the Singleton instance
    static void destroyInstance() {
        if (instance != nullptr) {
            delete instance;
            instance = nullptr;
        }
    }

    void doSomething() {
        std::cout << "Doing something in LazySingleton." << std::endl;
    }
};

// Initialize the static instance to nullptr
LazySingleton* LazySingleton::instance = nullptr;

int main() {
    // Access the Singleton instance
    LazySingleton* singleton = LazySingleton::getInstance();
    singleton->doSomething();

    // Destroy the Singleton instance when no longer needed
    LazySingleton::destroyInstance();

    return 0;
}

/*
    LazySingleton instance created.
    Doing something in LazySingleton.
    LazySingleton instance destroyed.
*/