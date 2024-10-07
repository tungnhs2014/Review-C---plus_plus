#include <iostream>
#include <memory>  // Include for smart pointers

int main() {
    // Create a unique_ptr to an integer with value 30
    std::unique_ptr<int> up1 = std::make_unique<int>(30);

    std::cout << "Unique_ptr value: " << *up1 << std::endl;  // Output: 30

    // Transfer ownership to another unique_ptr using std::move
    std::unique_ptr<int> up2 = std::move(up1);

    // After moving, up1 no longer owns the resource (it's set to nullptr)
    if (!up1) {
        std::cout << "up1 is now null after moving ownership." << std::endl;  // Output
    }

    // up2 now owns the resource
    std::cout << "Unique_ptr 2 value: " << *up2 << std::endl;  // Output: 30

    return 0;
}

/*
    Unique_ptr value: 30
    up1 is now null after moving ownership.
    Unique_ptr 2 value: 30

*/