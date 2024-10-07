#include <iostream>

class MyClass {
public:
    // Destructor
    ~MyClass() {
        std::cout << "Destructor called" << std::endl;
    }
};

int main() {
    {
        MyClass obj;  // Object `obj` is created in this scope
    }  // Object `obj` goes out of scope here and destructor is called
    return 0;
}

/*
    Destructor called
*/