#include <iostream>
using namespace std;

// Base class Animal with a virtual function
class Animal {
public:
    // Virtual function to make a sound
    virtual void makeSound() {
        cout << "Some generic animal sound" << endl;
    }
};

// Derived class Dog inherits from Animal
class Dog : public Animal {
public:
    // Override the makeSound function for Dog
    void makeSound() override {
        cout << "Woof woof!" << endl;
    }
};

// Derived class Cat inherits from Animal
class Cat : public Animal {
public:
    // Override the makeSound function for Cat
    void makeSound() override {
        cout << "Meow meow!" << endl;
    }
};

int main() {
    // Create pointers of type Animal pointing to Dog and Cat objects
    Animal* animalPtr1 = new Dog(); // Pointer of type Animal pointing to Dog object
    Animal* animalPtr2 = new Cat(); // Pointer of type Animal pointing to Cat object

    // Call the makeSound() function using the Animal pointers
    animalPtr1->makeSound(); // Output: Woof woof! (calls Dog's makeSound)
    animalPtr2->makeSound(); // Output: Meow meow! (calls Cat's makeSound)

    // Clean up memory
    delete animalPtr1;
    delete animalPtr2;

    return 0;
}

/*
    Woof woof!
    Meow meow!
*/