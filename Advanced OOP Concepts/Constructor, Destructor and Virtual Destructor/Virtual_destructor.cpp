#include <iostream>

class Base {
public:
    // Virtual destructor
    virtual ~Base() {
        std::cout << "Base destructor called" << std::endl;
    }
};

class Derived : public Base {
public:
    // Destructor
    ~Derived() {
        std::cout << "Derived destructor called" << std::endl;
    }
};

int main() {
    Base* obj = new Derived();  // Base pointer pointing to a Derived object
    delete obj;  // Correctly calls both Derived and Base destructors
    return 0;
}

/*
    Derived destructor called
    Base destructor called
*/