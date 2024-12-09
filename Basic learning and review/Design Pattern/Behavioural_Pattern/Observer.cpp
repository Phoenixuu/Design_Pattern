#include<iostream>
#include<vector>
#include<string>

// Step 1: Define the Observer interface
class Observer{
public:
	virtual void update(int temperature, int humidity) = 0;
	virtual ~Observer() = default;
};

// Step 2: Define the Subject interface and its implementations
class Subject {
protected:
	std::vector<Observer*> observers;
public:
	virtual void attach(Observer* observer) = 0;
	virtual void detach(Observer* observer) = 0;
	virtual void notify() = 0;
};

class WeatherStation : public Subject {
private:
	int temperature;
	int humidity;
public:
	void setWeatherConditions(int temperature, int humidity){
		this->temperature = temperature;
		this->humidity = humidity;
		notify();
	}

	void attach(Observer* observer) override {
		observers.push_back(observer);
	}

	void detach(Observer* observer) override {
		// Find and remove the observer
		for(auto it = observers.begin(); it != observers.end(); ++it){
			if(*it == observer) {
				observers.erase(it);
				break;
			}
		}
	}
	void notify() override {
		for(auto observer : observers) {
			observer->update(temperature, humidity);
		}
	}
};

class DisplayDevice : public Observer {
public:
	void update(int temperature, int humidity) override {
		std::cout << "Displaying weather conditions. Temperature: " << temperature << "C, Humidnity: " << humidity << "%" << std::endl;
	}
};

int main(){
	//Create weather station and display devices
	WeatherStation weatherstation;
	DisplayDevice displayDevice1;
	DisplayDevice displayDevice2;

	// Attach display devices to the weather station
	weatherstation.attach(&displayDevice1);
	weatherstation.attach(&displayDevice2);

	// Set weather conditions
	weatherstation.setWeatherConditions(15,75);

	// Detach displayDevice1
	weatherstation.detach(&displayDevice1);

	// Set new weather conditions
	weatherstation.setWeatherConditions(25,80);

	weatherstation.detach(&displayDevice2);

	return 0;
}