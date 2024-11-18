#include<iostream>
#include<string>

// Step 1: Define the base component interface
class Coffee {
public: 
	virtual std::string getDescription() const = 0;
	virtual double getCost() const = 0;
};

// Step 2: Implement the concrete component class
class SimpleCoffee: public Coffee{
public:
	std::string getDescription() const override {
		return "Simple Coffee";
	}

	double getCost() const override {
		return 2.0;
	}
};

// Step 3: Define the decorator class hierarchy
class CoffeeDecorator : public Coffee {
protected:
	Coffee* decoratedCoffee;
public:
	CoffeeDecorator(Coffee* coffee) : decoratedCoffee(coffee){}

	std::string getDescription() const override {
		return decoratedCoffee -> getDescription();
	}
	double getCost() const override {
		return decoratedCoffee -> getCost();
	}
};

class MilkDecorator : public CoffeeDecorator {
public:
	MilkDecorator(Coffee* coffee) : CoffeeDecorator(coffee){}

	std::string getDescription() const override {
		return CoffeeDecorator::getDescription() + ", Milk";
	}
	double getCost() const override {
		return CoffeeDecorator::getCost() + 0.3;
	}
};

class SugarDecorator : public CoffeeDecorator {
public:
	SugarDecorator(Coffee* coffee) : CoffeeDecorator(coffee){}

	std::string getDescription() const override {
		return CoffeeDecorator::getDescription() + ", Sugar";
	}
	double getCost() const override {
		return CoffeeDecorator::getCost() + 0.2;
	}
};	

int main() {
	//Create a simple coffee
	Coffee* simpleCoffee = new SimpleCoffee();
	std::cout << "Description: " << simpleCoffee -> getDescription() << std::endl;
	std::cout << "Cost: $" << simpleCoffee->getCost() << std::endl;

	Coffee* coffeeWithMilk = new MilkDecorator(simpleCoffee);
	std::cout << "Description: " << coffeeWithMilk -> getDescription() << std::endl;
	std::cout << "Cost: $" <<  coffeeWithMilk->getCost() << std::endl;

	Coffee* coffeeWithMilkSugar = new SugarDecorator(coffeeWithMilk);
	std::cout << "Description: " << coffeeWithMilkSugar -> getDescription() << std::endl;
	std::cout << "Cost: $" << coffeeWithMilkSugar->getCost() << std::endl;

	delete simpleCoffee;
	delete coffeeWithMilk;
	delete coffeeWithMilkSugar;

	return 0;
}	
