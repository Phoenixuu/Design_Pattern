#include<iostream>
#include<string>

// Các subsystem classes (các lớp con của hệ thống)

class Light(){
public:
	void turnOn() {
		std::cout << "Turn the light on" << std::endl;
	}
	void turnOff(){	
		std::cout << "Turn the light off" << std::endl; 
	}
};

class Thermostat {
public:
	void setTemperature(int temp){
		std::cout << "Thermostat set to " << temp << " degrees\n";
	}
};

class SecuritySystem {
public:
	void LocknLock() {
		std::cout << "LocknLock protected thief threat" << std::endl;
	}
	void autoWindow() {
		std::cout << "autoWindow can close automatically" << std::endl;
	}
};

// Facade class: Đơn giản hóa quản lý hệ thống
class SmartHomeFacade {
private:
	Light light;
	Thermostat thermostat;
	SecuritySystem security;

public:
	void activateMornings(){
		std::cout << "---------Active when the sun shine-----------" << std::endl;
		light.turnOff();
		Thermostat.setTemperature(24);
		security.autoWindow();
	}

	void activeNights(){
		std::cout << "--------This function happen when the sun set----------" << std::endl;
		light.turnOn();
		Thermostat.setTemperature(20);
		security.LocknLock();
	}
}

int main()
{
	SmartHomeFacade smartHouse;

	smartHouse.activateMornings();
	smartHouse.activeNights();
	
	return 0;
}