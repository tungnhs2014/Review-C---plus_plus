#include <iostream>
using namespace std;

// Base class Vehicle
class Vehicle {
public:
    // Public method to display a generic message
    void honk() {
        cout << "Beep beep!" << endl; // All vehicles can honk
    }

    // Method to display type of vehicle
    void displayType() {
        cout << "This is a generic vehicle." << endl;
    }
};

// Derived class Car inherits from Vehicle
class Car : public Vehicle {
private:
    int numberOfDoors; // Attribute specific to Car

public:
    // Constructor to initialize the number of doors
    Car(int doors) : numberOfDoors(doors) {}

    // Method specific to Car to display the number of doors
    void displayDetails() {
        cout << "This car has " << numberOfDoors << " doors." << endl;
    }

    // Overriding the displayType() method
    void displayType() {
        cout << "This is a car." << endl;
    }
};

// Derived class Bike inherits from Vehicle
class Bike : public Vehicle {
private:
    bool hasCarrier; // Attribute specific to Bike

public:
    // Constructor to initialize hasCarrier
    Bike(bool carrier) : hasCarrier(carrier) {}

    // Method specific to Bike to display carrier information
    void displayDetails() {
        if (hasCarrier) {
            cout << "This bike has a carrier." << endl;
        } else {
            cout << "This bike does not have a carrier." << endl;
        }
    }

    // Overriding the displayType() method
    void displayType() {
        cout << "This is a bike." << endl;
    }
};

int main() {
    // Create an object of Car
    Car myCar(4);
    myCar.honk();             // Output: Beep beep! (inherited from Vehicle)
    myCar.displayType();      // Output: This is a car. (overridden from Vehicle)
    myCar.displayDetails();   // Output: This car has 4 doors.

    // Create an object of Bike
    Bike myBike(true);
    myBike.honk();            // Output: Beep beep! (inherited from Vehicle)
    myBike.displayType();     // Output: This is a bike. (overridden from Vehicle)
    myBike.displayDetails();  // Output: This bike has a carrier.

    return 0;
}

/*
    Beep beep!
    This is a car.
    This car has 4 doors.
    Beep beep!
    This is a bike.
    This bike has a carrier.

*/