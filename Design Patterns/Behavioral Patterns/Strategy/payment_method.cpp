#include <iostream>
#include <memory>
#include <string>

// Strategy interface for payment methods
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0; // Pure virtual function for making a payment
    virtual ~PaymentStrategy() {}
};

// Concrete strategy for Credit Card payment
class CreditCardPayment : public PaymentStrategy {
private:
    std::string cardNumber;
    std::string cardHolder;
public:
    // Constructor to initialize card details
    CreditCardPayment(const std::string& number, const std::string& holder)
        : cardNumber(number), cardHolder(holder) {}

    void pay(int amount) override {
        std::cout << "Paid " << amount << " using Credit Card. Card Holder: " 
                  << cardHolder << ", Card Number: " << cardNumber << "\n";
    }
};

// Concrete strategy for PayPal payment
class PayPalPayment : public PaymentStrategy {
private:
    std::string email;
public:
    PayPalPayment(const std::string& email) : email(email) {}

    void pay(int amount) override {
        std::cout << "Paid " << amount << " using PayPal. Account Email: " 
                  << email << "\n";
    }
};

// Concrete strategy for Bitcoin payment
class BitcoinPayment : public PaymentStrategy {
private:
    std::string walletAddress;
public:
    BitcoinPayment(const std::string& address) : walletAddress(address) {}

    void pay(int amount) override {
        std::cout << "Paid " << amount << " using Bitcoin. Wallet Address: " 
                  << walletAddress << "\n";
    }
};

// Context class (Shopping Cart) that uses a payment strategy
class ShoppingCart {
private:
    std::shared_ptr<PaymentStrategy> paymentStrategy; // Holds the payment strategy
public:
    // Set the payment strategy at runtime
    void setPaymentStrategy(std::shared_ptr<PaymentStrategy> strategy) {
        paymentStrategy = strategy;
    }

    // Process the payment using the selected strategy
    void checkout(int amount) {
        if (paymentStrategy) {
            paymentStrategy->pay(amount);
        } else {
            std::cout << "No payment strategy selected.\n";
        }
    }
};

int main() {
    ShoppingCart cart; // Create a shopping cart

    // Create and set Credit Card payment strategy
    std::shared_ptr<PaymentStrategy> creditCard = 
        std::make_shared<CreditCardPayment>("1234-5678-9012-3456", "John Doe");
    cart.setPaymentStrategy(creditCard);
    cart.checkout(250); // Pay 250 using Credit Card

    // Create and set PayPal payment strategy
    std::shared_ptr<PaymentStrategy> payPal = 
        std::make_shared<PayPalPayment>("john.doe@example.com");
    cart.setPaymentStrategy(payPal);
    cart.checkout(350); // Pay 350 using PayPal

    // Create and set Bitcoin payment strategy
    std::shared_ptr<PaymentStrategy> bitcoin = 
        std::make_shared<BitcoinPayment>("1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa");
    cart.setPaymentStrategy(bitcoin);
    cart.checkout(500); // Pay 500 using Bitcoin

    return 0;
}

/*
    Paid 250 using Credit Card. Card Holder: John Doe, Card Number: 1234-5678-9012-3456
    Paid 350 using PayPal. Account Email: john.doe@example.com
    Paid 500 using Bitcoin. Wallet Address: 1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa
*/