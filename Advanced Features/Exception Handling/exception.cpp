#include <iostream>
#include <stdexcept>  // Include necessary library for standard exceptions
using namespace std;

// Custom exception class inheriting from std::exception
class MyCustomException : public exception {
public:
    const char* what() const noexcept override {
        return "Custom Exception: Something went wrong!";
    }
};

// Function to perform division and demonstrate standard exception handling
double divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("Standard Exception: Division by zero error!");  // Throw standard runtime error
    }
    return a / b;
}

int main() {
    // Handling Standard Exceptions
    try {
        cout << "Attempting to divide 20 by 0 (Standard Exception)..." << endl;
        double result = divide(20, 0);  // This will throw a runtime_error exception
        cout << "Result: " << result << endl;  // This line will not be executed
    } catch (const runtime_error& e) {
        // Catch and handle the runtime error
        cerr << "Caught a standard exception: " << e.what() << endl;  // Output the error message
    }

    cout << "Program continues running normally after handling the standard exception." << endl;

    // Handling Custom Exceptions
    try {
        cout << "\nAttempting to throw a custom exception..." << endl;
        throw MyCustomException();  // Throw a custom exception
    } catch (const MyCustomException& e) {
        // Catch and handle the custom exception
        cerr << "Caught a custom exception: " << e.what() << endl;  // Output the custom error message
    }

    cout << "Program continues running normally after handling the custom exception." << endl;

    // Successful Division Case
    try {
        cout << "\nAttempting to divide 20 by 4 (No Exception Expected)..." << endl;
        double result = divide(20, 4);  // This should succeed without exceptions
        cout << "Result: " << result << endl;  // Output the successful result
    } catch (const runtime_error& e) {
        // Catch any unexpected runtime error
        cerr << "Caught an exception: " << e.what() << endl;
    }

    return 0;
}

/*
    Attempting to divide 20 by 0 (Standard Exception)...
    Caught a standard exception: Standard Exception: Division by zero error!
    Program continues running normally after handling the standard exception.

    Attempting to throw a custom exception...
    Caught a custom exception: Custom Exception: Something went wrong!
    Program continues running normally after handling the custom exception.

    Attempting to divide 20 by 4 (No Exception Expected)...
    Result: 5

*/