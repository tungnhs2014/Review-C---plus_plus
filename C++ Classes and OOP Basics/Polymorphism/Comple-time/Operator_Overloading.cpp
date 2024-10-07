#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Constructor to initialize real and imaginary parts
    Complex(float r = 0.0, float i = 0.0) : real(r), imag(i) {}

    // Overloading the '+' operator for adding two complex numbers
    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // Function to display complex number
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.5, 2.5);

    // Add two complex numbers using overloaded '+' operator
    Complex c3 = c1 + c2;

    // Display the result
    cout << "Result of addition: ";
    c3.display();  // Output: 4.5 + 6.5i

    return 0;
}

/*
    Result of addition: 4.5 + 6.5i

*/