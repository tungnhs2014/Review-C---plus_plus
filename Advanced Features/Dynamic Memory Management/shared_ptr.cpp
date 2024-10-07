#include <iostream>
#include <memory>  // Include for smart pointers

void use_shared_ptr(std::shared_ptr<int> sp) {
    // Function to use shared_ptr
    std::cout << "Inside function, value: " << *sp << std::endl;
}

int main() {
    // Create a shared_ptr to an integer with value 20
    std::shared_ptr<int> sp1 = std::make_shared<int>(20);

    // Create another shared_ptr that shares ownership of the same resource
    std::shared_ptr<int> sp2 = sp1;

    std::cout << "Shared_ptr 1 value: " << *sp1 << std::endl;
    std::cout << "Shared_ptr 2 value: " << *sp2 << std::endl;

    // Pass shared_ptr to a function
    use_shared_ptr(sp2);

    // Shared pointers automatically release the memory when all owners are out of scope

    return 0;
}

/*
    Shared_ptr 1 value: 20
    Shared_ptr 2 value: 20
    Inside function, value: 20

*/