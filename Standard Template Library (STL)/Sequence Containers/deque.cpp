#include <iostream>
#include <deque>

int main() {
    // Declare a deque of integers
    std::deque<int> dq;

    // Add elements to both ends
    dq.push_back(10);   // Add 10 to the back
    dq.push_front(20);  // Add 20 to the front

    // Iterate through the deque
    std::cout << "Deque elements: ";
    for (int val : dq) {
        std::cout << val << " ";  // Access elements from front to back
    }
    std::cout << std::endl;

    // Remove elements from both ends
    dq.pop_front();  // Remove element from front
    dq.pop_back();   // Remove element from back

    std::cout << "Deque after popping both ends: ";
    if (dq.empty()) {
        std::cout << "Empty";
    }
    std::cout << std::endl;

    return 0;
}

/*
    Deque elements: 20 10 
    Deque after popping both ends: Empty
*/