#include <iostream>
#include <memory>

// Interface for the product
class Product {
public:
    virtual void display() const = 0; // Pure virtual method to display product info
    virtual ~Product() {} // Virtual destructor for proper cleanup
};

// ConcreteProductA - Specific product A
class ConcreteProductA : public Product {
public:
    void display() const override {
        std::cout << "ConcreteProductA created.\n";
    }
};

// ConcreteProductB - Specific product B
class ConcreteProductB : public Product {
public:
    void display() const override {
        std::cout << "ConcreteProductB created.\n";
    }
};

// Abstract Factory Method class
class Factory {
public:
    virtual std::unique_ptr<Product> createProduct() const = 0; // Pure virtual method for creating products
    virtual ~Factory() {}
};

// Concrete Factory for creating Product A
class ConcreteFactoryA : public Factory {
public:
    std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ConcreteProductA>(); // Create and return Product A
    }
};

// Concrete Factory for creating Product B
class ConcreteFactoryB : public Factory {
public:
    std::unique_ptr<Product> createProduct() const override {
        return std::make_unique<ConcreteProductB>(); // Create and return Product B
    }
};

int main() {
    std::unique_ptr<Factory> factoryA = std::make_unique<ConcreteFactoryA>(); // Create factory for Product A
    auto productA = factoryA->createProduct(); // Create Product A using the factory
    productA->display(); // Display Product A

    std::unique_ptr<Factory> factoryB = std::make_unique<ConcreteFactoryB>(); // Create factory for Product B
    auto productB = factoryB->createProduct(); // Create Product B using the factory
    productB->display(); // Display Product B

    return 0;
}

/*
    ConcreteProductA created.
    ConcreteProductB created.
*/