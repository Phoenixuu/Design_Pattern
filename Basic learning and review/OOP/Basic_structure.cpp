#include<iostream>
#include<string>

class Car{
public:
	std::string brand;
	int year;

	void start(){
		std::cout << "Auto " << brand << " start running ......" << std::endl; 
	}
};

int main()
{
	Car c;
	c.brand = "Porsche Taycan 4S";
	c.year = 2024;
	c.start();
	return 0;
}
