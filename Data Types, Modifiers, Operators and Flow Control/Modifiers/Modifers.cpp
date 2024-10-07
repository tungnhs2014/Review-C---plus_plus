#include <iostream>
using namespace std;

// Example function demonstrating the use of const
void displayConst(const int MAX_COUNT) {
    // MAX_COUNT is a constant and its value cannot be modified
    cout << "Value of MAX_COUNT (const): " << MAX_COUNT << endl;
}

// Assume this is a variable that could be changed by external factors (e.g., hardware)
volatile int externalFlag = 0;

void checkFlag() {
    if (externalFlag == 1) {
        cout << "Flag has been changed by hardware or another thread." << endl;
    } else {
        cout << "Flag has not been changed." << endl;
    }
}

int main() {
    // 1. signed modifier
    signed int signedNumber = -50;  // Signed integer can hold both negative and positive values
    cout << "Signed integer: " << signedNumber << endl;

    // 2. unsigned modifier
    unsigned int positiveNumber = 100;  // Unsigned integer can only hold non-negative values
    cout << "Unsigned integer: " << positiveNumber << endl;

    // 3. const modifier
    const int MAX_LIMIT = 500;  // MAX_LIMIT is a constant value
    displayConst(MAX_LIMIT);

    // 4. volatile modifier
    cout << "Current value of externalFlag (volatile): " << externalFlag << endl;
    externalFlag = 1;  // Assume this value is changed by some external event
    checkFlag();

    return 0;
}

/* Run:

    Signed integer: -50
    Unsigned integer: 100
    Value of MAX_COUNT (const): 500
    Current value of externalFlag (volatile): 0
    Flag has been changed by hardware or another thread.

*/