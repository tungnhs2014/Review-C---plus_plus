#include <iostream>

class MyClass {
private:
    int value;

public:
    // Parameterized constructor
    MyClass(int v) : value(v) {
        std::cout << "Parameterized constructor called with value: " << value << std::endl;
    }
};

int main() {
    MyClass obj(10);  // Calls parameterized constructor with value 10
    return 0;
}

/*
    Parameterized constructor called with value: 10
*/