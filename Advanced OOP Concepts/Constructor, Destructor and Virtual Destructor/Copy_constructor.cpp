#include <iostream>

class MyClass {
private:
    int value;

public:
    // Parameterized constructor
    MyClass(int v) : value(v) {}

    // Copy constructor
    MyClass(const MyClass& other) {
        value = other.value;
        std::cout << "Copy constructor called" << std::endl;
    }

    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    MyClass obj1(20);       // Calls parameterized constructor
    MyClass obj2 = obj1;    // Calls copy constructor
    obj2.display();         // Output: Value: 20
    return 0;
}

/*
    Copy constructor called
    Value: 20
*/
