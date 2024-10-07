#include <iostream>
using namespace std;

// Class template with two parameters T and U
template <typename T, typename U>
class Pair {
private:
    T first;  // First element of type T
    U second; // Second element of type U

public:
    // Constructor to initialize both elements
    Pair(T a, U b) : first(a), second(b) {}

    // Function to display the pair
    void display() {
        cout << "First: " << first << ", Second: " << second << endl;
    }
};

int main() {
    // Create a pair of int and double
    Pair<int, double> p1(10, 20.5);
    p1.display();  // Should display: First: 10, Second: 20.5

    // Create a pair of string and char
    Pair<string, char> p2("Hello", 'A');
    p2.display();  // Should display: First: Hello, Second: A

    return 0;
}

/*
    First: 10, Second: 20.5
    First: Hello, Second: A
*/