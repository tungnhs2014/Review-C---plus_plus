#include <iostream>
using namespace std;

// Function template to get the maximum value of two elements
template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;  // Return the greater value of a and b
}

int main() {
    // Calling the template function with different data types
    cout << "Max of 3 and 7: " << getMax(3, 7) << endl;          // Using int type
    cout << "Max of 5.5 and 2.3: " << getMax(5.5, 2.3) << endl;  // Using double type
    cout << "Max of 'a' and 'b': " << getMax('a', 'b') << endl;  // Using char type
    return 0;
}

/*
    Max of 3 and 7: 7
    Max of 5.5 and 2.3: 5.5
    Max of 'a' and 'b': b
*/
