/*
    Example: Since virtual constructors do not exist in C++, a Factory Pattern is used to create derived class objects.
*/

#include <iostream>

// Abstract base class
class Animal {
public:
    virtual void makeSound() const = 0;
    virtual ~Animal() {}
};

// Derived class Dog
class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow! Meow!" << std::endl;
    }
};

// Factory function to create Animal objects
Animal* createAnimal(const std::string& type) {
    if (type == "Dog") {
        return new Dog();
    } else if (type == "Cat") {
        return new Cat();
    } else {
        return nullptr;
    }
}

int main() {
    Animal* myAnimal = createAnimal("Dog");
    if (myAnimal) {
        myAnimal->makeSound();  // Output: Woof! Woof!
        delete myAnimal;  // Clean up
    }

    myAnimal = createAnimal("Cat");
    if (myAnimal) {
        myAnimal->makeSound();  // Output: Meow! Meow!
        delete myAnimal;  // Clean up
    }

    return 0;
}

/*
    Woof! Woof!
    Meow! Meow!
*/