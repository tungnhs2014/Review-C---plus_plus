#include <iostream>
using namespace std;

int main() {
    // Arithmetic operators
    int a = 10, b = 3;
    cout << "Sum: " << (a + b) << endl;
    cout << "Difference: " << (a - b) << endl;
    cout << "Product: " << (a * b) << endl;
    cout << "Quotient: " << (a / b) << endl;
    cout << "Remainder: " << (a % b) << endl;

    // Relational operators
    cout << "\nIs a < b: " << (a < b) << endl;
    cout << "Is a == b: " << (a == b) << endl;

    // Logical operators
    bool x = true, y = false;
    cout << "\nLogical AND (x && y): " << (x && y) << endl;
    cout << "Logical OR (x || y): " << (x || y) << endl;
    cout << "Logical NOT (!x): " << (!x) << endl;

    // Bitwise operators
    cout << "\nBitwise AND (a & b): " << (a & b) << endl;
    cout << "Bitwise OR (a | b): " << (a | b) << endl;
    cout << "Left shift (a << 1): " << (a << 1) << endl;

    // Assignment operators
    cout << "\nAssignment operators:" << endl;
    a += 5;  // a = a + 5
    cout << "a += 5: " << a << endl;
    a -= 3;  // a = a - 3
    cout << "a -= 3: " << a << endl;

    // Conditional (ternary) operator
    int max = (a > b) ? a : b;
    cout << "\nTernary operator result: " << max << endl;

    return 0;
}

/* Run

    Sum: 13
    Difference: 7
    Product: 30
    Quotient: 3
    Remainder: 1

    Is a < b: 0
    Is a == b: 0

    Logical AND (x && y): 0
    Logical OR (x || y): 1
    Logical NOT (!x): 0

    Bitwise AND (a & b): 2
    Bitwise OR (a | b): 11
    Left shift (a << 1): 20

    Assignment operators:
    a += 5: 15
    a -= 3: 12

    Ternary operator result: 12

*/
