#include <iostream>
#include <set>

int main() {
    // Declare a set of integers
    std::set<int> mySet;

    // Insert elements into the set
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(10);  // Duplicate element, ignored automatically

    // Iterate through the set and print elements
    std::cout << "Set elements: ";
    for (int val : mySet) {
        std::cout << val << " ";  // Elements are stored in sorted order
    }
    std::cout << std::endl;

    // Find an element in the set
    if (mySet.find(20) != mySet.end()) {
        std::cout << "20 is found in the set." << std::endl;
    }

    return 0;
}

/*
    Set elements: 10 20 
    20 is found in the set.
*/