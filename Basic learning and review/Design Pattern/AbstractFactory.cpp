#include<iostream>

class Car {
public :
	virtual void setEngineType() = 0;
	virtual void setTransmission() = 0;
	virtual void setColor() = 0;
};

class SedanCar : public Car {
public :
	void setEngineType () override {
		std::cout << "SedanCar EngineType ......" << std::endl;
	}
	void setTransmission () override {
		std::cout << "SedanCar Tranmission ......" << std::endl;
	}
	void setColor () override {
		std::cout << "Yelow Cars ........" << std::endl;
	}
};

class SportsCar : public Car {
public :
	void setEngineType () override {
		std::cout << "SportsCar EngineType ......." << std::endl;
	}
	void setTransmission () override {
		std::cout << "SportsCar Tranmission ......." << std::endl;
	}
	void setColor () override {
		std::cout << "Red Cars ........." << std::endl;
	}
};

class CarFactory {
public :
	virtual Car * createSedanCar () = 0;
	virtual Car * createSportsCar () = 0;
};

class LuxuryCarFactory : public CarFactory {
public:
	Car* createSedanCar () override {
		return new SedanCar () ; // Create a luxury sedan car
	}
	Car* createSportsCar () override {
		return new SportsCar () ; // Create a luxury sports car
	}
};

class EconomyCarFactory : public CarFactory {
public:
	Car* createSedanCar () override {
		return new SedanCar () ; // Create an economy sedan car
	}
	Car* createSportsCar () override {
		return new SportsCar () ; // Create an economy sports car
	}
};


int main () {
	// Create a luxury sedan car
	CarFactory* luxuryFactory = new LuxuryCarFactory() ;
	Car* luxurySedan = luxuryFactory -> createSedanCar();

	// Create an economy sports car
	CarFactory* economyFactory = new EconomyCarFactory();
	Car* economySports = economyFactory -> createSportsCar();

	return 0;
}
