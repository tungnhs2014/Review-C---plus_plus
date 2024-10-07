#include <iostream>

// Base class with a virtual function
class Animal {
public:
    virtual void sound() {  // Virtual function
        std::cout << "Some generic animal sound" << std::endl;
    }
};

// Derived class overriding the virtual function
class Cat : public Animal {
public:
    void sound() override {  // Override virtual function
        std::cout << "Meow! Meow!" << std::endl;
    }
};

int main() {
    Animal* animalPtr = new Cat();  // Base pointer pointing to a derived object
    animalPtr->sound();  // Output: Meow! Meow! (polymorphism using virtual keyword)
    delete animalPtr;  // Clean up memory
    return 0;
}

/*
    Meow! Meow!
*/