#include <iostream>
#include <vector>
#include <memory>
#include <algorithm> // Include for std::remove

// Observer interface
class Observer {
public:
    // Virtual function to be implemented by concrete observers
    virtual void update(float temperature, float humidity) = 0;
    virtual ~Observer() {}
};

// Concrete Observer class
class ConcreteObserver : public Observer {
private:
    std::string name;
public:
    ConcreteObserver(const std::string& name) : name(name) {}

    // Observer receives both temperature and humidity updates
    void update(float temperature, float humidity) override {
        std::cout << "Observer " << name << " received update: Temperature = "
                  << temperature << "°C, Humidity = " << humidity << "%\n";
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

// Concrete Subject class (Weather Station with multiple states)
class WeatherStation : public Subject {
private:
    std::vector<std::shared_ptr<Observer>> observers;
    float temperature;
    float humidity;

public:
    WeatherStation() : temperature(0.0), humidity(0.0) {}

    // Add observer to the list
    void addObserver(std::shared_ptr<Observer> observer) override {
        observers.push_back(observer);
    }

    // Remove observer from the list
    void removeObserver(std::shared_ptr<Observer> observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    // Notify all observers with both temperature and humidity changes
    void notifyObservers() override {
        for (const auto& observer : observers) {
            observer->update(temperature, humidity);
        }
    }

    // Set new temperature and humidity, and notify observers
    void setWeatherData(float newTemperature, float newHumidity) {
        std::cout << "Weather station setting: Temperature = " << newTemperature
                  << "°C, Humidity = " << newHumidity << "%\n";
        temperature = newTemperature;
        humidity = newHumidity;
        notifyObservers(); // Notify all observers after data change
    }
};

int main() {
    WeatherStation weatherStation;

    std::shared_ptr<Observer> observer1 = std::make_shared<ConcreteObserver>("Observer1");
    std::shared_ptr<Observer> observer2 = std::make_shared<ConcreteObserver>("Observer2");

    // Add observers
    weatherStation.addObserver(observer1);
    weatherStation.addObserver(observer2);

    // Set weather data, which notifies all observers
    weatherStation.setWeatherData(22.5, 65.0);
    weatherStation.setWeatherData(28.0, 70.0);

    return 0;
}

/*
    Weather station setting: Temperature = 22.5┬░C, Humidity = 65%
    Observer Observer1 received update: Temperature = 22.5┬░C, Humidity = 65%
    Observer Observer2 received update: Temperature = 22.5┬░C, Humidity = 65%
    Weather station setting: Temperature = 28┬░C, Humidity = 70%
    Observer Observer1 received update: Temperature = 28┬░C, Humidity = 70%
    Observer Observer2 received update: Temperature = 28┬░C, Humidity = 70%
*/