#include <iostream>

class MyClass {
private:
    int* data;

public:
    // Parameterized constructor
    MyClass(int size) {
        data = new int[size];
        std::cout << "Parameterized constructor called" << std::endl;
    }

    // Move constructor
    MyClass(MyClass&& other) noexcept {
        data = other.data;
        other.data = nullptr;
        std::cout << "Move constructor called" << std::endl;
    }

    // Destructor
    ~MyClass() {
        delete[] data;
        std::cout << "Destructor called" << std::endl;
    }
};

int main() {
    MyClass obj1(10);        // Calls parameterized constructor
    MyClass obj2 = std::move(obj1);  // Calls move constructor
    return 0;
}



/*
    Parameterized constructor called
    Move constructor called
    Destructor called
*/