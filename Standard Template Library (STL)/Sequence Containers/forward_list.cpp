#include <iostream>
#include <forward_list>

int main() {
    // Declare a forward_list of integers
    std::forward_list<int> fl = {1, 2, 3};

    // Insert an element at the front
    fl.push_front(0);  // Add 0 to the front

    // Iterate through the forward list
    std::cout << "Forward list elements: ";
    for (int val : fl) {
        std::cout << val << " ";  // Access elements in a single direction
    }
    std::cout << std::endl;

    return 0;
}

/*
    Forward list elements: 0 1 2 3 
*/