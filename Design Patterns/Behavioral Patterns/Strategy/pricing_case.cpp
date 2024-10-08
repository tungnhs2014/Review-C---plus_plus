#include <iostream>
#include <memory>

// Strategy interface for pricing
class PricingStrategy {
public:
    virtual int calculatePrice(int basePrice) = 0; // Pure virtual function
    virtual ~PricingStrategy() {}
};

// Concrete strategy for percentage discount
class PercentageDiscountStrategy : public PricingStrategy {
private:
    int percent;
public:
    PercentageDiscountStrategy(int discountPercent) : percent(discountPercent) {}

    int calculatePrice(int basePrice) override {
        return basePrice - (basePrice * percent / 100);
    }
};

// Concrete strategy for fixed amount discount
class FixedDiscountStrategy : public PricingStrategy {
private:
    int discountAmount;
public:
    FixedDiscountStrategy(int amount) : discountAmount(amount) {}

    int calculatePrice(int basePrice) override {
        return basePrice - discountAmount;
    }
};

// Concrete strategy for no discount
class NoDiscountStrategy : public PricingStrategy {
public:
    int calculatePrice(int basePrice) override {
        return basePrice; // No discount applied
    }
};

// Context class (Product) that uses a pricing strategy
class Product {
private:
    std::shared_ptr<PricingStrategy> pricingStrategy; // Holds the pricing strategy
    int basePrice;
public:
    Product(int price) : basePrice(price) {}

    // Set the pricing strategy at runtime
    void setPricingStrategy(std::shared_ptr<PricingStrategy> strategy) {
        pricingStrategy = strategy;
    }

    // Get the final price using the selected pricing strategy
    void getPrice() {
        if (pricingStrategy) {
            int finalPrice = pricingStrategy->calculatePrice(basePrice);
            std::cout << "Final price: " << finalPrice << "\n";
        } else {
            std::cout << "No pricing strategy selected.\n";
        }
    }
};

int main() {
    Product product(1000); // Create a product with base price 1000

    // Use percentage discount
    product.setPricingStrategy(std::make_shared<PercentageDiscountStrategy>(10));
    product.getPrice(); // 10% discount applied

    // Use fixed amount discount
    product.setPricingStrategy(std::make_shared<FixedDiscountStrategy>(200));
    product.getPrice(); // 200 units discount applied

    // Use no discount
    product.setPricingStrategy(std::make_shared<NoDiscountStrategy>());
    product.getPrice(); // No discount applied

    return 0;
}

/*
    Final price: 900
    Final price: 800
    Final price: 1000
*/