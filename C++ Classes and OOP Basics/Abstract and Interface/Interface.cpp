#include <iostream>

// Interface - a class with all pure virtual functions
class IShape {
public:
    // Pure virtual function for drawing the shape
    virtual void draw() const = 0;

    // Pure virtual function for calculating area
    virtual double area() const = 0;

    // Virtual destructor
    virtual ~IShape() {}
};

// Derived class implementing the interface
class Circle : public IShape {
private:
    double radius;

public:
    // Constructor to initialize radius
    Circle(double r) : radius(r) {}

    // Implementing the draw function
    void draw() const override {
        std::cout << "Drawing a circle with radius " << radius << std::endl;
    }

    // Implementing the area function
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

// Another class implementing the interface
class Rectangle : public IShape {
private:
    double width, height;

public:
    // Constructor to initialize width and height
    Rectangle(double w, double h) : width(w), height(h) {}

    // Implementing the draw function
    void draw() const override {
        std::cout << "Drawing a rectangle of width " << width << " and height " << height << std::endl;
    }

    // Implementing the area function
    double area() const override {
        return width * height;
    }
};

int main() {
    // Create instances of Circle and Rectangle
    Circle myCircle(5.0);
    Rectangle myRectangle(4.0, 6.0);

    // Use polymorphism to handle different shapes
    IShape* shape1 = &myCircle;
    IShape* shape2 = &myRectangle;

    // Drawing and calculating area for both shapes
    shape1->draw();            // Output: Drawing a circle with radius 5
    std::cout << "Area: " << shape1->area() << std::endl;  // Output: Area: 78.53975

    shape2->draw();            // Output: Drawing a rectangle of width 4 and height 6
    std::cout << "Area: " << shape2->area() << std::endl;  // Output: Area: 24

    return 0;
}

/*
    Drawing a circle with radius 5
    Area: 78.53975
    Drawing a rectangle of width 4 and height 6
    Area: 24
*/