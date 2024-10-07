#include <iostream>

// Abstract class with a pure virtual function
class Vehicle {
public:
    virtual void startEngine() const = 0;  // Pure virtual function
};

// Derived class implementing the pure virtual function
class Car : public Vehicle {
public:
    void startEngine() const override {
        std::cout << "Car engine started" << std::endl;
    }
};

int main() {
    // Vehicle v; // Error! Cannot instantiate an abstract class
    Car myCar;  // Create a Car object
    myCar.startEngine();  // Output: Car engine started
    return 0;
}

/*
    Car engine started
*/