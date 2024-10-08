#include <iostream>

// Target interface (what the client expects)
class Charger {
public:
    virtual void charge() const = 0; // Pure virtual function
    virtual ~Charger() {}
};

// Adaptee class (incompatible interface)
class EuropeanCharger {
public:
    void plugIn() const {
        std::cout << "Charging with European Charger.\n";
    }
};

// Adapter class (uses composition to adapt EuropeanCharger to Charger interface)
class EuropeanToUSAdapter : public Charger {
private:
    const EuropeanCharger& euroCharger; // The Adaptee
public:
    // Constructor initializes the Adaptee
    EuropeanToUSAdapter(const EuropeanCharger& charger) : euroCharger(charger) {}

    // Adapts the interface by calling the Adaptee's method
    void charge() const override {
        euroCharger.plugIn(); // Call the incompatible interface's method
    }
};

// Client code that expects a Charger interface
void chargeDevice(const Charger& charger) {
    charger.charge(); // Client uses the Target interface
}

int main() {
    EuropeanCharger europeanCharger; // Adaptee (incompatible interface)
    EuropeanToUSAdapter adapter(europeanCharger); // Adapter adapts the Adaptee

    // Client can now charge using a European charger through the adapter
    chargeDevice(adapter);

    return 0;
}

/*
    Charging with European Charger.
*/