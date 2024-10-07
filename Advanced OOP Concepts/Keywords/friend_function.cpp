#include <iostream>

class Rectangle {
private:
    double length, width;  // Private members

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Declare friend function
    friend double calculateArea(const Rectangle& r);
};

// Friend function definition
double calculateArea(const Rectangle& r) {
    // Access private members of Rectangle
    return r.length * r.width;
}

int main() {
    Rectangle rect(4.5, 2.0);  // Create a Rectangle object
    std::cout << "Area of the rectangle: " << calculateArea(rect) << std::endl;  // Output: Area of the rectangle: 9
    return 0;
}

/*
    Area of the rectangle: 9
*/