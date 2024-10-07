#include <iostream>

// Base class with virtual functions
class Animal {
public:
    // Virtual function
    virtual void makeSound() const {
        std::cout << "Some generic animal sound" << std::endl;
    }

    // Virtual destructor to ensure proper cleanup
    virtual ~Animal() {
        std::cout << "Animal destructor called" << std::endl;
    }
};

// Derived class Dog that overrides makeSound
class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }

    // Destructor for Dog
    ~Dog() {
        std::cout << "Dog destructor called" << std::endl;
    }
};

// Derived class Cat that overrides makeSound
class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow! Meow!" << std::endl;
    }

    // Destructor for Cat
    ~Cat() {
        std::cout << "Cat destructor called" << std::endl;
    }
};

// Function that demonstrates polymorphism
void makeAnimalSound(const Animal& animal) {
    animal.makeSound();  // Calls the correct version of makeSound using v-table
}

int main() {
    // Create a Dog and Cat object using Animal pointers
    Animal* animal1 = new Dog();  // Base pointer pointing to Derived (Dog) object
    Animal* animal2 = new Cat();  // Base pointer pointing to Derived (Cat) object

    // Call makeSound on both objects through base pointers
    animal1->makeSound();  // Expected to call Dog's makeSound
    animal2->makeSound();  // Expected to call Cat's makeSound

    // Use function to demonstrate polymorphism via references
    makeAnimalSound(*animal1);  // Calls Dog's makeSound
    makeAnimalSound(*animal2);  // Calls Cat's makeSound

    // Delete objects and see if correct destructors are called
    delete animal1;  // Expected to call Dog's destructor first, then Animal's
    delete animal2;  // Expected to call Cat's destructor first, then Animal's

    return 0;
}

/*
    Woof! Woof!
    Meow! Meow!
    Woof! Woof!
    Meow! Meow!
    Dog destructor called
    Animal destructor called
    Cat destructor called
    Animal destructor called
*/