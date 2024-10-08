#include <iostream>
#include <memory>

// Abstract product family for ProductA
class AbstractProductA {
public:
    virtual void displayA() const = 0;
    virtual ~AbstractProductA() {}
};

// Abstract product family for ProductB
class AbstractProductB {
public:
    virtual void displayB() const = 0;
    virtual ~AbstractProductB() {}
};

// Concrete Product A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void displayA() const override {
        std::cout << "ConcreteProductA1 created.\n";
    }
};

// Concrete Product A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void displayA() const override {
        std::cout << "ConcreteProductA2 created.\n";
    }
};

// Concrete Product B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void displayB() const override {
        std::cout << "ConcreteProductB1 created.\n";
    }
};

// Concrete Product B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void displayB() const override {
        std::cout << "ConcreteProductB2 created.\n";
    }
};

// Abstract Factory Interface
class AbstractFactory {
public:
    virtual std::unique_ptr<AbstractProductA> createProductA() const = 0;
    virtual std::unique_ptr<AbstractProductB> createProductB() const = 0;
    virtual ~AbstractFactory() {}
};

// Concrete Factory for creating ProductA1 and ProductB1
class ConcreteFactory1 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA1>();
    }
    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ConcreteProductB1>();
    }
};

// Concrete Factory for creating ProductA2 and ProductB2
class ConcreteFactory2 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA2>();
    }
    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ConcreteProductB2>();
    }
};

int main() {
    std::unique_ptr<AbstractFactory> factory1 = std::make_unique<ConcreteFactory1>();
    auto productA1 = factory1->createProductA(); // Create ProductA1
    auto productB1 = factory1->createProductB(); // Create ProductB1
    productA1->displayA(); // Display ProductA1
    productB1->displayB(); // Display ProductB1

    std::unique_ptr<AbstractFactory> factory2 = std::make_unique<ConcreteFactory2>();
    auto productA2 = factory2->createProductA(); // Create ProductA2
    auto productB2 = factory2->createProductB(); // Create ProductB2
    productA2->displayA(); // Display ProductA2
    productB2->displayB(); // Display ProductB2

    return 0;
}

/*
    ConcreteProductA1 created.
    ConcreteProductB1 created.
    ConcreteProductA2 created.
    ConcreteProductB2 created.
*/