#include <iostream>
using namespace std;

// Abstract base class Shape
class Shape {
public:
    // Pure virtual function - this makes Shape an abstract class
    virtual double area() = 0; // Function to calculate area, no implementation here

    // Virtual function to display the area of the shape
    virtual void displayArea() {
        cout << "The area is: " << area() << endl; // Calls the area() function of the derived class
    }
};

// Derived class Circle inherits from Shape
class Circle : public Shape {
private:
    double radius; // Attribute to store the radius of the circle

public:
    // Constructor to initialize the radius
    Circle(double r) : radius(r) {}

    // Implementation of the pure virtual function area()
    double area() override {
        return 3.14159 * radius * radius; // Area of a circle = π * r^2
    }
};

// Derived class Rectangle inherits from Shape
class Rectangle : public Shape {
private:
    double length; // Attribute to store the length of the rectangle
    double width;  // Attribute to store the width of the rectangle

public:
    // Constructor to initialize length and width
    Rectangle(double l, double w) : length(l), width(w) {}

    // Implementation of the pure virtual function area()
    double area() override {
        return length * width; // Area of a rectangle = length * width
    }
};

int main() {
    // Create a pointer of type Shape that points to an object of Circle
    Shape* shape1 = new Circle(5.0); // A Circle object with radius 5.0
    shape1->displayArea(); // Output: The area is: 78.5398 (approximate)

    // Create a pointer of type Shape that points to an object of Rectangle
    Shape* shape2 = new Rectangle(4.0, 6.0); // A Rectangle object with length 4.0 and width 6.0
    shape2->displayArea(); // Output: The area is: 24

    // Clean up memory by deleting the allocated objects
    delete shape1;
    delete shape2;

    return 0;
}

/*

    The area is: 78.5398
    The area is: 24

*/