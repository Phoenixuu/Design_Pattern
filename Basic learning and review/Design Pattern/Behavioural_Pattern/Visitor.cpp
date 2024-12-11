#include<iostream>
#include<string>
#include<vector>
#include<memory>

class Lion;
class Elephent; 
class Monkey;

//Visitor interface 
class AnimalVisitor {
public:
	virtual void visitLion(Lion* lion) = 0;
	virtual void visitElephent(Elephent* elephant) = 0;
	virtual void visitMonkey(Monkey* monkey) = 0;
	virtual ~AnimalVisitor() = default;
};

class Animal {
public:
	virtual void accept(AnimalVisitor* visitor) = 0;
	virtual ~Animal() = default;
};

class Lion : public Animal {
public:
	void accept(AnimalVisitor* visitor) override {
		visitor->visitLion(this);
	}
};

class Elephent : public Animal{
public:
	void accept(AnimalVisitor* visitor) override {
		visitor->visitElephent(this);
	}
};

class Monkey : public Animal {
public:
	void accept(AnimalVisitor* visitor) override {
		visitor->visitMonkey(this);
	}
};

class Feedingvisitor : public AnimalVisitor {
public:
	void visitLion(Lion* lion) override {
		std::cout << "Feed the lion with meat." << std::endl;
	}
	void visitElephent(Elephent* elephant) override {
		std::cout << "Feed the elephent with fruits." << std::endl;
	}
	void visitMonkey(Monkey* monkey) override {
		std::cout << "Feed the monkey with bananas." << std::endl;
	}
};

class HealthCheckVisitor : public AnimalVisitor{
public:
	void visitLion(Lion* lion) override {
		std::cout << "Checking the lion's heath !" << std::endl;
	}
	void visitElephent(Elephent* elephant) override {
		std::cout << "Checking the elephent's heath" << std::endl;
	}
	void visitMonkey(Monkey* monkey) override {
		std::cout << "Checking the monkey's health" <<std::endl;
	}
};

int main(){
	//Create animals
	std::vector<std::unique_ptr<Animal>> animals;
	animals.emplace_back(std::make_unique<Lion>());
	animals.emplace_back(std::make_unique<Elephent>());
	animals.emplace_back(std::make_unique<Monkey>());

	//Create visitors
	Feedingvisitor feedingvisitor;
	HealthCheckVisitor healthcheckvision;

	//Apply visitors to animals 
	std::cout << "Feeding animals:" << std::endl;
	for(const auto& animal : animals) {
		animal->accept(&feedingvisitor);
	}
	std::cout << "Health check for animals:" << std::endl;
	for(const auto& animal : animals) {
		animal->accept(&healthcheckvision);
	}

	return 0;
}