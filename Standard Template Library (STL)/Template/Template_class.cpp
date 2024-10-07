#include <iostream>
using namespace std;

// Class template to create a general-purpose stack
template <typename T>
class Stack {
private:
    T* arr;          // Pointer to array of elements
    int top;         // Index of the top element
    int capacity;    // Maximum capacity of the stack

public:
    // Constructor to initialize stack
    Stack(int size) {
        arr = new T[size];
        capacity = size;
        top = -1;
    }

    // Function to add an element to the stack
    void push(T value) {
        if (top == capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = value;  // Increment top and store the value
    }

    // Function to remove the top element from the stack
    T pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            exit(1);  // Exit with error code
        }
        return arr[top--];  // Return the value and decrement top
    }

    // Destructor to free the allocated memory
    ~Stack() {
        delete[] arr;
    }
};

int main() {
    // Create a stack of integers
    Stack<int> intStack(5);
    intStack.push(10);
    intStack.push(20);
    cout << "Popped from int stack: " << intStack.pop() << endl;  // Should pop 20

    // Create a stack of strings
    Stack<string> stringStack(3);
    stringStack.push("Hello");
    stringStack.push("World");
    cout << "Popped from string stack: " << stringStack.pop() << endl;  // Should pop "World"

    return 0;
}

/*
    Popped from int stack: 20
    Popped from string stack: World
*/