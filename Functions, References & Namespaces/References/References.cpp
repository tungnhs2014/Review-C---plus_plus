#include <iostream>
using namespace std;

// Function that modifies a variable using pass by reference
void modifyValue(int &x) {
    // This function changes the original variable
    x = 50;
}

// Function using constant reference (does not allow modification)
void displayValue(const int &x) {
    // This function only displays the value without modifying it
    cout << "The value is: " << x << endl;
}

// Function that swaps two variables using references
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function demonstrating reference with arrays
void modifyArray(int (&arr)[5]) {
    // Modifying elements of the original array
    for (int i = 0; i < 5; ++i) {
        arr[i] *= 2;  // Double each element
    }
}

int main() {
    // Example 1: Pass by reference
    int num = 10;
    cout << "Before modifyValue, num = " << num << endl;
    modifyValue(num);
    cout << "After modifyValue, num = " << num << endl;

    // Example 2: Constant reference
    displayValue(num);  // Prints the value of num but doesn't modify it

    // Example 3: Swap two values using references
    int a = 5, b = 10;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    // Example 4: Reference with arrays
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Array before modification: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    modifyArray(arr);  // Pass the array by reference
    cout << "Array after modification: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*Run

    Before modifyValue, num = 10
    After modifyValue, num = 50
    The value is: 50
    Before swap: a = 5, b = 10
    After swap: a = 10, b = 5
    Array before modification: 1 2 3 4 5 
    Array after modification: 2 4 6 8 10 


*/