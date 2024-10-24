#include<iostream>
#include<memory>

class Tea{
public:
	virtual void order() = 0;
};

class Avocado : public Tea{
public:
	void order() override {
		std::cout << "We are preparing Avocado, please wait ......." << std::endl;
	}
};

class Mango : public Tea{
public:
	void order() override {
		std::cout << "Preparing Mango Tea, please wait ........." << std::endl;
	}
};

class GreenBean : public Tea{
public:
	void order() override {
		std::cout << "Preparing Green Bean Tea, please wait ....." << std::endl;
	}
};

class CoconutJelly : public Tea{
public:
	void order() override {
		std::cout << "Preparing CoconutJelly Tea, please wait ....." << std::endl;
	}
};

class GrapeFruit : public Tea{
public:
	void order() override {
		std::cout << "Preparing GrapeFruit Tea, please wait ......." << std::endl;
	}
};

class Lotus : public Tea {
public:
	void order() override {
		std::cout << "Preparing Lotus Tea, please wait ......." << std::endl;
	}
};

class TeaFactory{
public:
	std::unique_ptr<Tea> createTea(const std::string &type){
		if(type == "Avocado") {
			return std::make_unique<Avocado>();
		} else if (type == "Mango") {
			return std::make_unique<Mango>();
		} else if (type == "GreenBean") {
			return std::make_unique<GreenBean>();
		} else if (type == "CoconutJelly") {
			return std::make_unique<CoconutJelly>();
		} else if (type == "GrapeFruit") {
			return std::make_unique<GrapeFruit>();
		} else if (type == "Lotus") {
			return std::make_unique<Lotus>();
		} else{
			throw std::runtime_error("Invalid kind of Tea here !!!");
		}
	}
};

int main(int argc, char const *argv[])
{
	TeaFactory Koi;
	std::unique_ptr<Tea> Avocado = Koi.createTea("Avocado");
	std::unique_ptr<Tea> Mango = Koi.createTea("Mango");
	std::unique_ptr<Tea> GreenBean = Koi.createTea("GreenBean");
	std::unique_ptr<Tea> CoconutJelly = Koi.createTea("CoconutJelly");
	std::unique_ptr<Tea> GrapeFruit = Koi.createTea("GrapeFruit");
	std::unique_ptr<Tea> Lotus = Koi.createTea("Lotus");

	Avocado ->  order();
	Mango -> order();
	CoconutJelly -> order();
	Lotus -> order();

	return 0;
}