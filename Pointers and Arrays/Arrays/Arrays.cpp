#include <iostream>
#include <array> // Required for using std::array

using namespace std;

int main() {
    // 1. C-Style Array
    // Declaring a C-style array with fixed size of 5
    int cArray[5] = {1, 2, 3, 4, 5};

    // Accessing and printing each element of the C-style array using index
    cout << "C-Style Array elements: ";
    for (int i = 0; i < 5; ++i) {
        cout << cArray[i] << " "; // Direct access using index
    }
    cout << endl; // Output: 1 2 3 4 5

    // 2. std::array (C++11 and later)
    // Declaring a std::array with fixed size of 5
    array<int, 5> stdArray = {10, 20, 30, 40, 50};

    // Accessing and printing each element of the std::array using index
    cout << "std::array elements using index: ";
    for (int i = 0; i < stdArray.size(); ++i) {
        cout << stdArray[i] << " "; // Accessing elements using index
    }
    cout << endl; // Output: 10 20 30 40 50

    // Accessing elements safely using the .at() method
    cout << "Accessing std::array using .at() method: ";
    for (int i = 0; i < stdArray.size(); ++i) {
        cout << stdArray.at(i) << " "; // Safe access with bounds checking
    }
    cout << endl; // Output: 10 20 30 40 50

    // Using range-based for loop to access elements of std::array
    cout << "std::array elements using range-based for loop: ";
    for (int value : stdArray) {
        cout << value << " "; // Using a range-based loop to access each element
    }
    cout << endl; // Output: 10 20 30 40 50

    // 3. Address of each element in C-Style Array
    // Printing the memory address of each element in the C-style array
    cout << "Memory addresses of C-Style Array elements: " << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Address of cArray[" << i << "]: " << &cArray[i] << endl;
    }

    // 4. Address of each element in std::array
    // Printing the memory address of each element in std::array
    cout << "Memory addresses of std::array elements: " << endl;
    for (int i = 0; i < stdArray.size(); ++i) {
        cout << "Address of stdArray[" << i << "]: " << &stdArray[i] << endl;
    }

    return 0;
}

/*
    C-Style Array elements: 1 2 3 4 5 
    std::array elements using index: 10 20 30 40 50 
    Accessing std::array using .at() method: 10 20 30 40 50 
    std::array elements using range-based for loop: 10 20 30 40 50 
    Memory addresses of C-Style Array elements: 
    Address of cArray[0]: 0x7ffeef2b8a80
    Address of cArray[1]: 0x7ffeef2b8a84
    Address of cArray[2]: 0x7ffeef2b8a88
    Address of cArray[3]: 0x7ffeef2b8a8c
    Address of cArray[4]: 0x7ffeef2b8a90
    Memory addresses of std::array elements: 
    Address of stdArray[0]: 0x7ffeef2b8aa0
    Address of stdArray[1]: 0x7ffeef2b8aa4
    Address of stdArray[2]: 0x7ffeef2b8aa8
    Address of stdArray[3]: 0x7ffeef2b8aac
    Address of stdArray[4]: 0x7ffeef2b8ab0

*/