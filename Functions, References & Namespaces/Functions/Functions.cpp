#include <iostream>
using namespace std;

// 1. Function with no return (void)
void printMessage() {
    // This function doesn't return anything, just prints a message
    cout << "Hello, this is a void function!" << endl;
}

// 2. Function with return type
int add(int a, int b) {
    // This function returns the sum of two integers
    return a + b;
}

// 3. Pass by value
void modifyValue(int x) {
    // The value of 'x' inside this function will not affect the original variable
    x = 100;
    cout << "Inside modifyValue, x = " << x << endl;
}

// 4. Pass by reference
void modifyReference(int &x) {
    // The value of 'x' inside this function will affect the original variable
    x = 100;
    cout << "Inside modifyReference, x = " << x << endl;
}

// 5. Function overloading
// Overloaded function for integers
int multiply(int a, int b) {
    return a * b;
}

// Overloaded function for floats
float multiply(float a, float b) {
    return a * b;
}

int main() {
    // Calling the void function
    printMessage();

    // Calling function with return value
    int sum = add(5, 10);
    cout << "Sum of 5 and 10 is: " << sum << endl;

    // Demonstrating pass by value
    int num = 50;
    cout << "Before modifyValue, num = " << num << endl;
    modifyValue(num);
    cout << "After modifyValue, num = " << num << endl;  // No change to num

    // Demonstrating pass by reference
    cout << "Before modifyReference, num = " << num << endl;
    modifyReference(num);
    cout << "After modifyReference, num = " << num << endl;  // Value of num changes

    // Demonstrating function overloading
    int resultInt = multiply(5, 6);  // Calls integer version
    float resultFloat = multiply(5.5f, 2.3f);  // Calls float version
    cout << "5 * 6 = " << resultInt << endl;
    cout << "5.5 * 2.3 = " << resultFloat << endl;

    return 0;
}

/*
    Hello, this is a void function!
    Sum of 5 and 10 is: 15
    Before modifyValue, num = 50
    Inside modifyValue, x = 100
    After modifyValue, num = 50
    Before modifyReference, num = 50
    Inside modifyReference, x = 100
    After modifyReference, num = 100
    5 * 6 = 30
    5.5 * 2.3 = 12.65

*/