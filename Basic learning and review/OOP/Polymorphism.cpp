class Animal{
public:
	virtual void makeSound() const = 0;
};

class Dog : public Animal{
public:
	void makeSound() const override {
		std::cout << "Go go go ...." << std::endl;
	}
};

class Cat : public Animal{
public:
	void makeSound() const override {
		std::cout << "Meow Meow Meow ...." << std::endl;
	}
};

class Tiger : public Animal{
public: 
	void makeSound const override{
		std::cout << "Gru Gru Gru ......." << std::endl;
	}
}

