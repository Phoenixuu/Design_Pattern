#include<iostream>
#include<vector>

struct Orc;
struct Goblin;
// Our visitor 'base class' which tells us, which type of
// of Jects that we can extent
struct MonsterVisitor{
	virtual ~MonsterVisitor() = default;
	virtual void visit(const Orc& orc) const = 0;
	virtual void visit(const Goblin& goblin) const = 0;
};

struct DrawMonsterVisitor : public MonsterVisitor{
	void visit(const Orc& orc) const override{
		std::cout << "Drawing orc from MonsterVisitor\n";
	}
	void visit(const Goblin& goblin) const override{
		std::cout << "Drawing globin from MonsterVisitor\n";
	}
};

//Base Class
struct Monster{
	virtual ~Monster(){} 
	virtual void accept(const MonsterVisitor& visitor) = 0;
};

struct Orc : public Monster{
	Orc(){
		std::cout << "Created a new Orc::Orc()\n";
	}
	void accept(const MonsterVisitor& visitor) override{
		std::cout << "Orc::accept\n";
		visitor.visit(*this);
	}
};

struct Goblin : public Monster{
	Goblin(){
		std::cout << "Created a new Goblin::Goblin()\n";
	}
	void accept(const MonsterVisitor& visitor) override{
		std::cout << "Goblin::accept\n";
		visitor.visit(*this);
	}
};

void drawAllMonsters(const std::vector<Monster*>& monsters){
	for(auto const& m:monsters){
		m -> accept(DrawMonsterVisitor{});
	}
}

int main(){
	std::vector<Monster*> BlueMonsters;
	BlueMonsters.emplace_back(new Orc);
	BlueMonsters.emplace_back(new Goblin);

	std::cout << std::endl;;

	drawAllMonsters(BlueMonsters);
	std::cout << "\n\n";

	Monster* myMonster = new Orc;
	DrawMonsterVisitor dmv;
	myMonster->accept(dmv);

	return 0;
}