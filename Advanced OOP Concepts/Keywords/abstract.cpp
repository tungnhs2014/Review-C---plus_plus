#include <iostream>

// Abstract class defining a common interface
class Appliance {
public:
    virtual void turnOn() const = 0;  // Pure virtual function
};

// Derived class implementing the pure virtual function
class Fan : public Appliance {
public:
    void turnOn() const override {
        std::cout << "Fan is turning on" << std::endl;
    }
};

int main() {
    Fan myFan;  // Create an instance of Fan
    myFan.turnOn();  // Output: Fan is turning on
    return 0;
}


/*
    Fan is turning on
*/