#include <iostream>
#include <string>

// Component interface (Pizza)
class Pizza {
public:
    virtual std::string getDescription() const = 0; // Pure virtual function for pizza description
    virtual double getCost() const = 0;             // Pure virtual function for pizza cost
    virtual ~Pizza() {}
};

// ConcreteComponent (PlainPizza)
class PlainPizza : public Pizza {
public:
    // Returns the description of the plain pizza
    std::string getDescription() const override {
        return "Plain Pizza";
    }

    // Returns the cost of the plain pizza
    double getCost() const override {
        return 5.00; // Base price of plain pizza
    }
};

// Decorator class (base class for pizza decorators)
class PizzaDecorator : public Pizza {
protected:
    const Pizza& pizzaComponent; // Composition: stores a reference to the wrapped pizza
public:
    PizzaDecorator(const Pizza& pizza) : pizzaComponent(pizza) {}

    // Delegate to the wrapped pizza for description
    std::string getDescription() const override {
        return pizzaComponent.getDescription();
    }

    // Delegate to the wrapped pizza for cost
    double getCost() const override {
        return pizzaComponent.getCost();
    }
};

// ConcreteDecorator (CheeseDecorator) adds cheese
class CheeseDecorator : public PizzaDecorator {
public:
    CheeseDecorator(const Pizza& pizza) : PizzaDecorator(pizza) {}

    // Add cheese description and update the price
    std::string getDescription() const override {
        return pizzaComponent.getDescription() + ", Cheese";
    }

    double getCost() const override {
        return pizzaComponent.getCost() + 1.50; // Cheese adds $1.50
    }
};

// ConcreteDecorator (PepperoniDecorator) adds pepperoni
class PepperoniDecorator : public PizzaDecorator {
public:
    PepperoniDecorator(const Pizza& pizza) : PizzaDecorator(pizza) {}

    // Add pepperoni description and update the price
    std::string getDescription() const override {
        return pizzaComponent.getDescription() + ", Pepperoni";
    }

    double getCost() const override {
        return pizzaComponent.getCost() + 2.00; // Pepperoni adds $2.00
    }
};

int main() {
    PlainPizza pizza; // Base component (plain pizza)

    // Add cheese topping
    CheeseDecorator cheesePizza(pizza);
    std::cout << cheesePizza.getDescription() << " - Cost: $" << cheesePizza.getCost() << std::endl;

    // Add pepperoni topping on top of cheese
    PepperoniDecorator pepperoniCheesePizza(cheesePizza);
    std::cout << pepperoniCheesePizza.getDescription() << " - Cost: $" << pepperoniCheesePizza.getCost() << std::endl;

    return 0;
}

/*
    Plain Pizza, Cheese - Cost: $6.50
    Plain Pizza, Cheese, Pepperoni - Cost: $8.50

*/
