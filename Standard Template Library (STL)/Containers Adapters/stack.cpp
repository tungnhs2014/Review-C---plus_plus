#include <iostream>
#include <stack>

int main() {
    // Declare a stack of integers
    std::stack<int> myStack;

    // Push elements onto the stack
    myStack.push(1);  // Add 1 to the top of the stack
    myStack.push(2);  // Add 2 to the top of the stack
    myStack.push(3);  // Add 3 to the top of the stack

    // Print the top element of the stack
    std::cout << "Top element: " << myStack.top() << std::endl;  // Should print 3

    // Pop an element from the stack
    myStack.pop();  // Removes the top element (3)

    // Print the new top element
    std::cout << "New top element after pop: " << myStack.top() << std::endl;  // Should print 2

    // Check if the stack is empty
    if (myStack.empty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl;  // Stack still contains elements
    }

    return 0;
}

/*  
    Top element: 3
    New top element after pop: 2
    Stack is not empty.
*/