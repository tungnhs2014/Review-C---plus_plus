#include <iostream>
#include <string>

// Component interface (Coffee)
class Coffee {
public:
    virtual std::string getDescription() const = 0; // Pure virtual function for coffee description
    virtual double cost() const = 0;                // Pure virtual function for coffee cost
    virtual ~Coffee() {}
};

// ConcreteComponent (SimpleCoffee)
class SimpleCoffee : public Coffee {
public:
    std::string getDescription() const override {
        return "Simple Coffee";
    }

    double cost() const override {
        return 2.00; // Base price of simple coffee
    }
};

// Decorator class (base class for coffee decorators)
class CoffeeDecorator : public Coffee {
protected:
    const Coffee& coffeeComponent; // Composition: stores a reference to the wrapped coffee
public:
    CoffeeDecorator(const Coffee& coffee) : coffeeComponent(coffee) {}

    // Delegate to the wrapped coffee for description
    std::string getDescription() const override {
        return coffeeComponent.getDescription();
    }

    // Delegate to the wrapped coffee for cost
    double cost() const override {
        return coffeeComponent.cost();
    }
};

// ConcreteDecorator (MilkDecorator) adds milk
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(const Coffee& coffee) : CoffeeDecorator(coffee) {}

    // Add milk description and update the price
    std::string getDescription() const override {
        return coffeeComponent.getDescription() + ", Milk";
    }

    double cost() const override {
        return coffeeComponent.cost() + 0.50; // Milk adds $0.50
    }
};

// ConcreteDecorator (SugarDecorator) adds sugar
class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(const Coffee& coffee) : CoffeeDecorator(coffee) {}

    // Add sugar description and update the price
    std::string getDescription() const override {
        return coffeeComponent.getDescription() + ", Sugar";
    }

    double cost() const override {
        return coffeeComponent.cost() + 0.20; // Sugar adds $0.20
    }
};

int main() {
    SimpleCoffee coffee; // Base component (simple coffee)

    // Add milk to the coffee
    MilkDecorator milkCoffee(coffee);
    std::cout << milkCoffee.getDescription() << " - Cost: $" << milkCoffee.cost() << std::endl;

    // Add sugar to the coffee with milk
    SugarDecorator milkSugarCoffee(milkCoffee);
    std::cout << milkSugarCoffee.getDescription() << " - Cost: $" << milkSugarCoffee.cost() << std::endl;

    return 0;
}

/*
    Simple Coffee, Milk - Cost: $2.50
    Simple Coffee, Milk, Sugar - Cost: $2.70
*/