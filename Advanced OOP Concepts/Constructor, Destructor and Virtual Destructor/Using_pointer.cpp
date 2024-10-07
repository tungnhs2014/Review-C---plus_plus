#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base constructor called" << std::endl;
    }
    virtual ~Base() {
        std::cout << "Base destructor called" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived constructor called" << std::endl;
    }
    ~Derived() {
        std::cout << "Derived destructor called" << std::endl;
    }
};

int main() {
    Base* b = new Derived();  // Base pointer pointing to a Derived object
    delete b;  // Correctly calls both destructors thanks to the virtual destructor
    return 0;
}


/*
    Base constructor called
    Derived constructor called
    Derived destructor called
    Base destructor called
*/