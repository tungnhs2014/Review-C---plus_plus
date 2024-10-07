#include <iostream>
using namespace std;

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to add three integers
int add(int a, int b, int c) {
    return a + b + c;
}

// Function to add two floating-point numbers
float add(float a, float b) {
    return a + b;
}

int main() {
    // Calling overloaded functions
    cout << "Sum of 3 and 4: " << add(3, 4) << endl;            // Calls add(int, int)
    cout << "Sum of 1, 2, and 3: " << add(1, 2, 3) << endl;      // Calls add(int, int, int)
    cout << "Sum of 2.5 and 4.3: " << add(2.5f, 4.3f) << endl;   // Calls add(float, float)
    return 0;
}

/*
    Sum of 3 and 4: 7
    Sum of 1, 2, and 3: 6
    Sum of 2.5 and 4.3: 6.8

*/