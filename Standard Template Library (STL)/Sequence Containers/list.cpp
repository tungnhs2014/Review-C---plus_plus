#include <iostream>
#include <list>

int main() {
    // Declare a list of integers
    std::list<int> lst = {1, 2, 3};

    // Add elements to both ends
    lst.push_back(4);   // Add to the back
    lst.push_front(0);  // Add to the front

    // Iterate through the list
    std::cout << "List elements: ";
    for (int val : lst) {
        std::cout << val << " ";  // Access elements in order
    }
    std::cout << std::endl;

    // Remove an element from the front and back
    lst.pop_front();  // Remove element from front
    lst.pop_back();   // Remove element from back

    std::cout << "List after popping front and back: ";
    for (int val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
    List elements: 0 1 2 3 4 
    List after popping front and back: 1 2 3 
*/