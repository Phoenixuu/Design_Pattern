#include<iostream>
#include<vector>

//Base Class
struct Monster{
	virtual ~Monster(){} 
	virtual void run() = 0;
};

struct Orc : public Monster{
	Orc(){
		std::cout << "Created a new Orc::Orc()\n";
	}
	void run(){
		std::cout << "Orc::run()\n";
	}
};

struct Goblin : public Monster{
	Goblin(){
		std::cout << "Created a new Goblin::Goblin()\n";
	}
	void run(){
		std::cout << "Goblin::run()\n";
	}
};

int main(){
	std::vector<Monster*> BlueMonsters;
	BlueMonsters.emplace_back(new Orc);
	BlueMonsters.emplace_back(new Goblin);

	for(const auto& m: BlueMonsters){
		m->run();
	}

	return 0;
}