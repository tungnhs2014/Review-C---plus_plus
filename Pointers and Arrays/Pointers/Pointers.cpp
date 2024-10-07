#include <iostream>

using namespace std;

// Function using function pointers
void greet() {
    cout << "Hello from greet!" << endl;
}

void farewell() {
    cout << "Goodbye from farewell!" << endl;
}

void execute(void (*func)()) {
    func(); // Call function through function pointer
}

// Linked list structure using pointers
struct Node {
    int data;
    Node* next;
};

class MyClass {
public:
    void display() {
        cout << "This is the object address: " << this << endl;
    }
};

int main() {
    // 1. Basic pointer
    int value = 10;
    int* ptr = &value;
    cout << "Value: " << *ptr << " (accessed via pointer)" << endl;

    // 2. Dynamic memory management
    int* dynamicPtr = new int(20);
    cout << "Dynamically allocated value: " << *dynamicPtr << endl;
    delete dynamicPtr;

    // 3. nullptr
    int* nullPtr = nullptr;
    if (nullPtr == nullptr) {
        cout << "nullPtr does not point to any memory." << endl;
    }

    // 4. Passing pointer to function to modify value
    modify(&value);
    cout << "Modified value: " << value << endl;

    // 5. Function pointer
    void (*funcPtr)() = greet;
    funcPtr(); // Call greet function through function pointer
    execute(farewell); // Pass farewell function to execute function

    // 6. Constant pointer (pointer to const)
    const int constValue = 50;
    const int* constPtr = &constValue; // Pointer to const
    cout << "Const pointer points to value: " << *constPtr << endl;

    // 7. Constant pointer (const pointer)
    int anotherValue = 30;
    int* const constantPtr = &anotherValue; // Const pointer
    *constantPtr = 40; // Can change value
    cout << "Modified value via constant pointer: " << anotherValue << endl;

    // 8. Pointer to pointer
    int** ptrToPtr = &ptr;
    cout << "Value accessed via pointer to pointer: " << **ptrToPtr << endl;

    // 9. Void pointer
    int num = 100;
    void* voidPtr = &num;
    cout << "Value accessed via void pointer: " << *(static_cast<int*>(voidPtr)) << endl;

    // 10. This pointer in class
    MyClass myObject;
    myObject.display();

    // 11. Array traversal using pointer
    int arr[] = {1, 2, 3, 4, 5};
    int* arrPtr = arr;
    cout << "Array elements: ";
    for (int i = 0; i < 5; ++i) {
        cout << *(arrPtr + i) << " "; // Access each element
    }
    cout << endl;

    // 12. Linked list (Linked structures)
    Node* head = new Node();
    head->data = 10;
    head->next = new Node();
    head->next->data = 20;
    head->next->next = nullptr;

    Node* current = head;
    cout << "Linked list elements: ";
    while (current != nullptr) {
        cout << current->data << " "; // Traverse linked list
        current = current->next;
    }
    cout << endl;

    // 13. Two-dimensional array and pointers
    int rows = 2, cols = 3;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // Assign values and print the 2D array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = (i + 1) * (j + 1);
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Free dynamically allocated memory
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

// Function to modify value via pointer
void modify(int* ptr) {
    *ptr = 100; // Modify value of the variable the pointer points to
}

/*
    Value: 10 (accessed via pointer)
    Dynamically allocated value: 20
    nullPtr does not point to any memory.
    Modified value: 100
    Hello from greet!
    Goodbye from farewell!
    Const pointer points to value: 50
    Modified value via constant pointer: 40
    Value accessed via pointer to pointer: 100
    Value accessed via void pointer: 100
    This is the object address: 0x7ffee1e98d78
    Array elements: 1 2 3 4 5 
    Linked list elements: 10 20 
    1 2 3 
    2 4 6 

*/