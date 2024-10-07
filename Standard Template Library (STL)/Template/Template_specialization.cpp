#include <iostream>
using namespace std;

// General template function
template <typename T>
void display(T value) {
    cout << "General template: " << value << endl;
}

// Specialized template function for int
template <>
void display(int value) {
    cout << "Specialized template for int: " << value << endl;
}

int main() {
    display(10);       // Calls the specialized version for int
    display(5.5);      // Calls the general version for double
    display("Hello");  // Calls the general version for string

    return 0;
}

/*
    Specialized template for int: 10
    General template: 5.5
    General template: Hello
*/