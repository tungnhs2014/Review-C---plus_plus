#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> // For std::remove

// Observer interface
class Observer {
public:
    // Virtual function to be implemented by concrete observers
    virtual void update(int temperature) = 0;
    virtual ~Observer() {}
};

// Concrete Observer class
class ConcreteObserver : public Observer {
private:
    std::string name; // Observer name for identification
public:
    // Constructor to initialize observer name
    ConcreteObserver(const std::string& name) : name(name) {}

    // Update method to handle temperature change
    void update(int temperature) override {
        std::cout << "Observer " << name << " received temperature update: " << temperature << "°C\n";
    }
};

// Subject interface
class Subject {
public:
    // Add an observer to the list
    virtual void addObserver(std::shared_ptr<Observer> observer) = 0;

    // Remove an observer from the list
    virtual void removeObserver(std::shared_ptr<Observer> observer) = 0;

    // Notify all observers about the state change
    virtual void notifyObservers() = 0;

    virtual ~Subject() {}
};

// Concrete Subject class (Weather Station)
class WeatherStation : public Subject {
private:
    std::vector<std::shared_ptr<Observer>> observers; // List of observers
    int temperature; // State that observers are interested in

public:
    WeatherStation() : temperature(0) {}

    // Add observer to the list
    void addObserver(std::shared_ptr<Observer> observer) override {
        observers.push_back(observer);
    }

    // Remove observer from the list
    void removeObserver(std::shared_ptr<Observer> observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    // Notify all observers of the temperature change
    void notifyObservers() override {
        for (const auto& observer : observers) {
            observer->update(temperature); // Call update on each observer
        }
    }

    // Set new temperature and notify observers
    void setTemperature(int newTemperature) {
        std::cout << "Weather station setting temperature to " << newTemperature << "°C\n";
        temperature = newTemperature;
        notifyObservers(); // Notify all observers after temperature change
    }
};

int main() {
    WeatherStation weatherStation; // Create weather station (subject)

    // Create observers
    std::shared_ptr<Observer> observer1 = std::make_shared<ConcreteObserver>("Observer1");
    std::shared_ptr<Observer> observer2 = std::make_shared<ConcreteObserver>("Observer2");

    // Add observers to the weather station
    weatherStation.addObserver(observer1);
    weatherStation.addObserver(observer2);

    // Change temperature, which notifies all observers
    weatherStation.setTemperature(25);
    weatherStation.setTemperature(30);

    // Remove observer1 and change temperature again
    weatherStation.removeObserver(observer1);
    weatherStation.setTemperature(35);

    return 0;
}

/*
    Weather station setting temperature to 25┬░C
    Observer Observer1 received temperature update: 25┬░C
    Observer Observer2 received temperature update: 25┬░C
    Weather station setting temperature to 30┬░C
    Observer Observer1 received temperature update: 30┬░C
    Observer Observer2 received temperature update: 30┬░C
    Weather station setting temperature to 35┬░C
    Observer Observer2 received temperature update: 35┬░C
*/