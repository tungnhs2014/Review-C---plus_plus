#include <iostream>
using namespace std;

int main() {
    int number;

    // Using if, else if, else to check the value of the variable 'number'
    cout << "Enter a number between 1 and 10: ";
    cin >> number;

    if (number > 10) {
        // If the number is greater than 10
        cout << "The number is greater than 10." << endl;
    } else if (number >= 1 && number <= 10) {
        // If the number is between 1 and 10 (inclusive)
        cout << "The number is between 1 and 10." << endl;
    } else {
        // If the number is less than 1
        cout << "The number is less than 1." << endl;
    }

    // Using switch to display messages based on the value of 'number'
    switch (number) {
        case 1:
            // If number is 1
            cout << "You entered one." << endl;
            break;
        case 2:
            // If number is 2
            cout << "You entered two." << endl;
            break;
        case 3:
            // If number is 3
            cout << "You entered three." << endl;
            break;
        default:
            // If number is not 1, 2, or 3
            cout << "You entered a number that is not between 1 and 3." << endl;
    }

    // Using for loop to iterate from 1 to 5
    cout << "\nFor loop from 1 to 5:" << endl;
    for (int i = 1; i <= 5; i++) {
        // Print the value of i for each iteration
        cout << i << " ";
    }
    cout << endl;

    // Using while loop to count down from 'number' until it reaches 0
    cout << "\nWhile loop: Counting down from number until 0:" << endl;
    while (number > 0) {
        // Print the current value of 'number' and decrease it by 1
        cout << number << " ";
        number--;
    }
    cout << endl;

    // Using do-while loop to ensure the code runs at least once
    int count = 0;
    cout << "\nDo-while loop: Counting at least once:" << endl;
    do {
        // Print the current value of 'count' and increase it by 1
        cout << count << " ";
        count++;
    } while (count < 3);
    cout << endl;

    return 0;
}

/* Run

    Enter a number between 1 and 10: 5

    The number is between 1 and 10.
    You entered a number that is not between 1 and 3.

    For loop from 1 to 5:
    1 2 3 4 5 

    While loop: Counting down from number until 0:
    5 4 3 2 1 

    Do-while loop: Counting at least once:
    0 1 2 

*/
