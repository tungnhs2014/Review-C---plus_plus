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

// Adapter class (inherits from both Charger and EuropeanCharger)
class EuropeanToUSClassAdapter : public Charger, private EuropeanCharger {
public:
    // Adapter calls the Adaptee's method through inheritance
    void charge() const override {
        plugIn(); // Call the Adaptee's method (EuropeanCharger::plugIn)
    }
};

// Client code that expects a Charger interface
void chargeDevice(const Charger& charger) {
    charger.charge(); // Client uses the Target interface
}

int main() {
    EuropeanToUSClassAdapter adapter; // Class adapter

    // Client can now charge using a European charger through the adapter
    chargeDevice(adapter);

    return 0;
}

/*
    Charging with European Charger.
*/