#include <iostream>
#include <vector>
#include <memory>
#include <mutex>
#include <algorithm> // Include for std::remove

// Observer interface
class Observer {
public:
    virtual void update(int temperature) = 0;
    virtual ~Observer() {}
};

// Concrete Observer class
class ConcreteObserver : public Observer {
private:
    std::string name;
public:
    ConcreteObserver(const std::string& name) : name(name) {}

    void update(int temperature) override {
        std::cout << "Observer " << name << " received temperature update: " << temperature << "°C\n";
    }
};

// Subject interface
class Subject {
public:
    virtual void addObserver(std::shared_ptr<Observer> observer) = 0;
    virtual void removeObserver(std::shared_ptr<Observer> observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() {}
};

// Concrete Subject class (Weather Station) with thread safety
class WeatherStation : public Subject {
private:
    std::vector<std::shared_ptr<Observer>> observers;
    int temperature;
    std::mutex mtx; // Mutex for thread-safe operations

public:
    WeatherStation() : temperature(0) {}

    // Add observer in a thread-safe manner
    void addObserver(std::shared_ptr<Observer> observer) override {
        std::lock_guard<std::mutex> lock(mtx);
        observers.push_back(observer);
    }

    // Remove observer in a thread-safe manner
    void removeObserver(std::shared_ptr<Observer> observer) override {
        std::lock_guard<std::mutex> lock(mtx);
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    // Notify observers in a thread-safe manner
    void notifyObservers() override {
        std::lock_guard<std::mutex> lock(mtx);
        for (const auto& observer : observers) {
            observer->update(temperature);
        }
    }

    // Set new temperature and notify observers (thread-safe)
    void setTemperature(int newTemperature) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Weather station setting temperature to " << newTemperature << "°C\n";
        temperature = newTemperature;
        notifyObservers();
    }
};

int main() {
    WeatherStation weatherStation;

    std::shared_ptr<Observer> observer1 = std::make_shared<ConcreteObserver>("Observer1");
    std::shared_ptr<Observer> observer2 = std::make_shared<ConcreteObserver>("Observer2");

    weatherStation.addObserver(observer1);
    weatherStation.addObserver(observer2);

    weatherStation.setTemperature(25);
    weatherStation.setTemperature(30);

    return 0;
}
