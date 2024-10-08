#include <iostream>
#include <memory>

// Interface for the product
class Product {
public:
    virtual void display() const = 0; // Pure virtual function to be overridden by subclasses
    virtual ~Product() {} // Virtual destructor for proper cleanup
};

// ConcreteProductA - A specific implementation of the product
class ConcreteProductA : public Product {
public:
    void display() const override {
        std::cout << "ConcreteProductA created.\n";
    }
};

// ConcreteProductB - Another specific implementation of the product
class ConcreteProductB : public Product {
public:
    void display() const override {
        std::cout << "ConcreteProductB created.\n";
    }
};

// Simple Factory - Responsible for creating the product objects
class SimpleFactory {
public:
    // Method to create product based on type
    std::unique_ptr<Product> createProduct(char type) {
        if (type == 'A') {
            return std::make_unique<ConcreteProductA>(); // Create ConcreteProductA
        } else if (type == 'B') {
            return std::make_unique<ConcreteProductB>(); // Create ConcreteProductB
        }
        return nullptr; // Return null if no valid type
    }
};

int main() {
    SimpleFactory factory; // Create a factory instance

    auto productA = factory.createProduct('A'); // Create product A
    productA->display(); // Display product A

    auto productB = factory.createProduct('B'); // Create product B
    productB->display(); // Display product B

    return 0;
}

/*
    ConcreteProductA created.
    ConcreteProductB created.
*/
