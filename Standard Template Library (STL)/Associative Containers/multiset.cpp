#include <iostream>
#include <set>

int main() {
    // Declare a multiset of integers
    std::multiset<int> myMultiset;

    // Insert elements, including duplicates
    myMultiset.insert(10);
    myMultiset.insert(20);
    myMultiset.insert(10);  // Duplicate allowed

    // Iterate through the multiset and print elements
    std::cout << "Multiset elements: ";
    for (int val : myMultiset) {
        std::cout << val << " ";  // Elements are stored in sorted order, duplicates allowed
    }
    std::cout << std::endl;

    return 0;
}

/*
    Multiset elements: 10 10 20 
*/