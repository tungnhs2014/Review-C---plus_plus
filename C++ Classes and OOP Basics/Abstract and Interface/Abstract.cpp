#include <iostream>

// Abstract class with one pure virtual function
class AbstractAnimal {
public:
    // Pure virtual function - must be implemented by derived classes
    virtual void makeSound() const = 0;

    // Regular member function
    void breathe() const {
        std::cout << "Animal is breathing..." << std::endl;
    }

    // Virtual destructor
    virtual ~AbstractAnimal() {}
};

// Derived class from AbstractAnimal, implementing the pure virtual function
class Dog : public AbstractAnimal {
public:
    // Overriding the pure virtual function from AbstractAnimal
    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

int main() {
    // AbstractAnimal animal; // Error! Cannot instantiate an abstract class

    // Create an instance of the derived class
    Dog myDog;
    myDog.makeSound();  // Output: Woof! Woof!
    myDog.breathe();    // Output: Animal is breathing...

    // Using polymorphism with a pointer to the abstract class
    AbstractAnimal* animalPtr = &myDog;
    animalPtr->makeSound(); // Output: Woof! Woof!

    return 0;
}

/*
    Woof! Woof!
    Animal is breathing...
    Woof! Woof!
*/