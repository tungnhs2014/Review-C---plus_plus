#include <iostream>

// Singleton class
class Singleton {
private:
    // Static pointer to the single instance of the class
    static Singleton* instance;

    // Private constructor to prevent instantiation from outside the class
    Singleton() {
        std::cout << "Singleton instance created." << std::endl;
    }

public:
    // Static method to access the single instance of the class
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton(); // Create the instance if it doesn't exist
        }
        return instance; // Return the existing instance
    }

    // Example method in the Singleton class
    void displayMessage() {
        std::cout << "Singleton instance in use!" << std::endl;
    }
};

// Initialize the static member variable
Singleton* Singleton::instance = nullptr;

int main() {
    // Get the Singleton instance and use it
    Singleton* singleton1 = Singleton::getInstance();
    singleton1->displayMessage();

    // Get the Singleton instance again (no new instance is created)
    Singleton* singleton2 = Singleton::getInstance();
    singleton2->displayMessage();

    // Both singleton1 and singleton2 point to the same instance
    std::cout << "Are both instances the same? "
              << (singleton1 == singleton2 ? "Yes" : "No") << std::endl;

    return 0;
}

/*
    Singleton instance created.
    Singleton instance in use!
    Singleton instance in use!
    Are both instances the same? Yes
*/