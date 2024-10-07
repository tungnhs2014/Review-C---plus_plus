#include <iostream>
#include <string>
using namespace std;

// 4. User-defined data type (Struct)
struct Person {
    string name;
    int age;
    float height;
};

// 4. User-defined data type (Enum)
enum Weekday { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

// Void function (does not return any value)
void greet() {
    cout << "Hello! This is an example of data types in C++." << endl;
}

// Function to calculate the sum of two integers
int sum(int a, int b) {
    return a + b;
}

int main() {
    // 1. Basic data types
    int num1 = 10;          // Integer type int (4 bytes)
    short num2 = 5;         // Smaller integer type short (2 bytes)
    long num3 = 1000000;    // Larger integer type long (4 or 8 bytes)
    float num4 = 3.14f;     // Floating-point type float (4 bytes)
    double num5 = 3.14159;  // Floating-point type double (8 bytes)
    char initial = 'A';     // Character type char (1 byte)
    bool isAdult = true;    // Boolean type (1 byte)
    
    // 1.5 Wide character type (Unicode)
    wchar_t wideChar = L'Đ'; // Wide character type (2 or 4 bytes)

    // 2. Modifiers for basic data types
    unsigned int positiveNum = 100;   // unsigned int to store only positive numbers
    signed int negativeNum = -100;    // signed int to store both positive and negative numbers

    // 3. Array
    int numbers[5] = {1, 2, 3, 4, 5}; // Array of 5 integers
    
    // 3. Pointer
    int* ptr = &num1; // Pointer storing the address of variable num1
    
    // 3. Reference
    int& refNum1 = num1; // refNum1 is a reference to variable num1

    // 4. Using struct
    Person person1;
    person1.name = "Tung";
    person1.age = 25;
    person1.height = 1.70;

    // 4. Using enum
    Weekday today = Wednesday;

    // Call void function
    greet();

    // Call sum function
    int result = sum(5, 7);

    // Print values to the console
    cout << "Integer (int): " << num1 << endl;
    cout << "Short integer (short): " << num2 << endl;
    cout << "Long integer (long): " << num3 << endl;
    cout << "Floating-point (float): " << num4 << endl;
    cout << "Double floating-point (double): " << num5 << endl;
    cout << "Character: " << initial << endl;
    cout << "Wide character: " << wideChar << endl;
    cout << "Positive number (unsigned int): " << positiveNum << endl;
    cout << "Negative number (signed int): " << negativeNum << endl;
    cout << "First element of the array: " << numbers[0] << endl;
    cout << "Address of num1 (through pointer): " << ptr << endl;
    cout << "Reference to num1: " << refNum1 << endl;
    
    // Print information of struct Person
    cout << "Name: " << person1.name << endl;
    cout << "Age: " << person1.age << endl;
    cout << "Height: " << person1.height << " m" << endl;

    // Print day of the week (enum)
    cout << "Today is day: " << today << endl;

    // Print result of sum function
    cout << "Sum of 5 and 7: " << result << endl;

    return 0;
}

/* Run:

    Hello! This is an example of data types in C++.
    Integer (int): 10
    Short integer (short): 5
    Long integer (long): 1000000
    Floating-point (float): 3.14
    Double floating-point (double): 3.14159
    Character: A
    Wide character: Đ
    Positive number (unsigned int): 100
    Negative number (signed int): -100
    First element of the array: 1
    Address of num1 (through pointer): 0x7ffeefbff4b4
    Reference to num1: 10
    Name: Kien
    Age: 30
    Height: 1.75 m
    Today is day: 2
    Sum of 5 and 7: 12
    
*/