#include <iostream>

int main() {
    // Allocate memory for an array of 5 integers using 'new'
    int* arr = new int[5];

    // Assign values to the array
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;  // Assign values from 1 to 5
    }

    // Print the array elements
    for (int i = 0; i < 5; i++) {
        std::cout << "Element " << i << ": " << arr[i] << std::endl;
    }

    // Free the allocated memory using 'delete[]'
    delete[] arr;

    // Set pointer to nullptr after deletion
    arr = nullptr;

    return 0;
}

/*
    Element 0: 1
    Element 1: 2
    Element 2: 3
    Element 3: 4
    Element 4: 5

*/