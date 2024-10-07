#include <iostream>
#include <queue>

int main() {
    // Declare a priority queue of integers
    std::priority_queue<int> myPQ;

    // Push elements into the priority queue
    myPQ.push(10);  // Higher priority
    myPQ.push(20);  // Highest priority
    myPQ.push(15);  // Medium priority

    // Print the top element (highest priority)
    std::cout << "Top element (highest priority): " << myPQ.top() << std::endl;  // Should print 20

    // Pop the top element
    myPQ.pop();  // Removes the highest priority element (20)

    // Print the new top element
    std::cout << "New top element after pop: " << myPQ.top() << std::endl;  // Should print 15

    // Check if the priority queue is empty
    if (myPQ.empty()) {
        std::cout << "Priority queue is empty." << std::endl;
    } else {
        std::cout << "Priority queue is not empty." << std::endl;  // Priority queue still contains elements
    }

    return 0;
}

/*
    Top element (highest priority): 20
    New top element after pop: 15
    Priority queue is not empty.
*/