#include<iostream>
#include<memory>

class Pizza{
public:
	virtual void prepare() = 0;
};

class CheesePizza : public Pizza{
public:
	void prepare() override {
		std::cout << "Preparing Cheese Pizza ......." << std::endl;
	}
};

class PepperoniPizza : public Pizza{
public:
	void prepare() override{
		std::cout << "Preparing Pepperoni Pizza .........." << std::endl;
	}
};

class VeggiePizza : public Pizza {
public:
	void prepare() override {
		std::cout << "Preparing Veggie Pizza ........" << std::endl;
	}
};

class PizzaFactory {
public:
	std::unique_ptr<Pizza> createPizza(const std::string& type){
		if(type == "Cheese"){
			return std::make_unique<CheesePizza>();
		} else if(type == "Pepperoni") {
			return std::make_unique<PepperoniPizza>();
		} else if(type == "Veggie") {
			return std::make_unique<VeggiePizza>();
		} else {
			throw std::runtime_error("Invalid pizza type.");
		}
	}
};

int main()
{
	PizzaFactory factory;
	std::unique_ptr<Pizza> CheesePizza = factory.createPizza("Cheese");
	std::unique_ptr<Pizza> PepperoniPizza = factory.createPizza("Pepperoni");
	std::unique_ptr<Pizza> VeggiePizza = factory.createPizza("Veggie");

	CheesePizza -> prepare();
	PepperoniPizza -> prepare();
	VeggiePizza -> prepare();
	return 0;
}