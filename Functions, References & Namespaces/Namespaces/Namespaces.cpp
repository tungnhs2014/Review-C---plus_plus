#include <iostream>

// 1. Define a namespace called Outer
namespace Outer {
    // 2. Define a nested namespace called Inner
    namespace Inner {
        // 3. Function within the Inner namespace
        void myFunction() {
            std::cout << "Hello from Inner namespace!" << std::endl; // Print message
        }
    }

    // 4. Another function within the Outer namespace
    void outerFunction() {
        std::cout << "Hello from Outer namespace!" << std::endl; // Print message
    }
}

int main() {
    // 5. Using the function from the Inner namespace with fully qualified name
    Outer::Inner::myFunction(); // Calls the function in Inner namespace

    // 6. Using the function from the Outer namespace
    Outer::outerFunction(); // Calls the function in Outer namespace

    // 7. Using the 'using' directive to simplify access to the Inner namespace
    using namespace Outer::Inner;

    // 8. Now we can call myFunction without the namespace prefix
    myFunction(); // Calls the function in Inner namespace

    // 9. Using 'using' for individual function to avoid namespace conflicts
    using Outer::outerFunction;

    // 10. Calling outerFunction without specifying the namespace again
    outerFunction(); // Calls the function in Outer namespace

    return 0; // End of the program
}
