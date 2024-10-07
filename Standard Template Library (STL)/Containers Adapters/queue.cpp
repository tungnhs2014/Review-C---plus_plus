#include <iostream>
#include <queue>

int main() {
    // Declare a queue of integers
    std::queue<int> myQueue;

    // Push elements into the queue
    myQueue.push(1);  // Add 1 to the back of the queue
    myQueue.push(2);  // Add 2 to the back of the queue
    myQueue.push(3);  // Add 3 to the back of the queue

    // Print the front element of the queue
    std::cout << "Front element: " << myQueue.front() << std::endl;  // Should print 1

    // Pop an element from the queue
    myQueue.pop();  // Removes the front element (1)

    // Print the new front element
    std::cout << "New front element after pop: " << myQueue.front() << std::endl;  // Should print 2

    // Check if the queue is empty
    if (myQueue.empty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;  // Queue still contains elements
    }

    return 0;
}

/*
    Front element: 1
    New front element after pop: 2
    Queue is not empty.
*/