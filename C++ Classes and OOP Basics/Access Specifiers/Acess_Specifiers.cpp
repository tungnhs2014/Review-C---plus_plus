#include <iostream>
using namespace std;

// Define the Vehicle class to demonstrate access specifiers
class Vehicle {
private:
    // Private attribute: cannot be accessed outside of this class
    int privateSpeed;

protected:
    // Protected attribute: can be accessed in this class and derived classes
    string brand;

public:
    // Public attribute: can be accessed anywhere in the program
    int wheels;

    // Constructor to initialize the attributes
    Vehicle(string b, int w) {
        brand = b;            // Initialize the protected attribute
        wheels = w;           // Initialize the public attribute
        privateSpeed = 0;     // Initialize the private attribute
    }

    // Public method to set the private speed attribute
    void setSpeed(int speed) {
        if (speed >= 0) {
            privateSpeed = speed;
        }
    }

    // Public method to display the speed
    void displaySpeed() {
        cout << "Speed: " << privateSpeed << " km/h" << endl;  // Accessing private attribute from within the class
    }

    // Public method to display the brand
    void displayBrand() {
        cout << "Brand: " << brand << endl; // Accessing protected attribute from within the class
    }
};

// Derived class Car that inherits from Vehicle
class Car : public Vehicle {
public:
    // Constructor for Car, calling the Vehicle constructor
    Car(string b, int w) : Vehicle(b, w) {}

    // Public method to access protected attribute (brand) from derived class
    void showDetails() {
        cout << "Car brand: " << brand << ", Wheels: " << wheels << endl;
    }
};

int main() {
    // Create an object of the Vehicle class
    Vehicle vehicle("Generic", 4);
    vehicle.displayBrand();       // Output: Brand: Generic
    vehicle.setSpeed(60);         // Set the private speed through a public method
    vehicle.displaySpeed();       // Output: Speed: 60 km/h

    // Create an object of the Car class
    Car car("Toyota", 4);
    car.showDetails();            // Output: Car brand: Toyota, Wheels: 4

    // Accessing public attribute directly
    car.wheels = 6;               // Changing the number of wheels
    car.showDetails();            // Output: Car brand: Toyota, Wheels: 6

    // The following lines would cause an error because private or protected members cannot be accessed directly:
    // vehicle.privateSpeed = 100;  // Error: 'privateSpeed' is private
    // car.brand = "Honda";         // Error: 'brand' is protected

    return 0;
}

/*
    Brand: Generic
    Speed: 60 km/h
    Car brand: Toyota, Wheels: 4
    Car brand: Toyota, Wheels: 6

*/