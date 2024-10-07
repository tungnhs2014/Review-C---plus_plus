#include <iostream>

int main() {
    // Allocate memory for an integer using 'new'
    int* ptr = new int;

    // Assign a value to the allocated memory
    *ptr = 10;

    // Print the value
    std::cout << "Value: " << *ptr << std::endl;

    // Free the allocated memory using 'delete'
    delete ptr;

    // After deleting, set the pointer to nullptr to avoid dangling pointer
    ptr = nullptr;

    return 0;
}


/*
    Value: 10
*/