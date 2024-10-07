#include <iostream>
using namespace std;

// Declare the Car class
class Car {
private:
    // Attributes (member variables) to store information about the car
    string brand; // Brand of the car
    string color; // Color of the car
    int year;     // Year of manufacture

public:
    // Constructor - initializes the attributes when an object is created
    Car(string b, string c, int y) {
        brand = b;   // Assign the parameter 'b' to the 'brand' attribute
        color = c;   // Assign the parameter 'c' to the 'color' attribute
        year = y;    // Assign the parameter 'y' to the 'year' attribute
    }

    // Method to display information about the car
    void displayInfo() {
        cout << "Brand: " << brand << ", Color: " << color << ", Year: " << year << endl;
        // Print out the brand, color, and year of the car
    }

    // Method to change the color of the car
    void repaint(string newColor) {
        color = newColor; // Assign the new color to the 'color' attribute
        cout << "The car has been repainted to: " << color << endl;
        // Print a message indicating the car has been repainted
    }
};

int main() {
    // Create an object of the Car class with brand "Toyota", color "Red", and year 2021
    Car car1("Toyota", "Red", 2021);

    // Call the displayInfo() method to display car1's information
    car1.displayInfo(); // Output: Brand: Toyota, Color: Red, Year: 2021

    // Change the color of car1 by calling the repaint() method
    car1.repaint("Black"); // Output: The car has been repainted to: Black

    // Display car1's information again after repainting
    car1.displayInfo(); // Output: Brand: Toyota, Color: Black, Year: 2021

    return 0; // End of the program, the destructor will be called automatically to release resources
}

/*
    Constructor called for Toyota
    Brand: Toyota, Color: Red, Year: 2021
    The car has been repainted to: Black
    Brand: Toyota, Color: Black, Year: 2021
    Destructor called for Toyota

*/