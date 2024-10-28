#include<iostream>
#include<string>
#include<unordered_map>

// Lớp Enemy đóng vài trò Prototype 
class Enemy{
public:
	virtual Enemy* clone() const = 0;
	virtual void showInfo() const = 0;
	virtual ~Enemy() = default;

protected: 
	std::string type;
	int health;
	std::string weapon;
};

class Orc : public Enemy {
public:
	Orc() {
		type = "Orc";
		health = 100;
		weapon = "Axe";
	}
	
	Enemy* clone() const override {
		return new Orc(*this);
	}

	void showInfo() const override {
		std::cout << "Enemy Type: " << type << ", Health: " << health << ", Weapon: " << weapon << std::endl;
	}
};

class Goblin : public Enemy{
public:
	Goblin() {
		type = "Goblin";
		health = 75;
		weapon = "Dagger";
	}

	Enemy* clone() const override {
		return new Goblin(*this);
	}

	void showInfo() const override {
		std::cout << "Goblin Type: " << type << ", Health: " << health << ", Weapon: " << weapon << std::endl;
	}
};

class EnemyFactory {
private:
	std::unordered_map<std::string, Enemy*> prototypes; 

public: 
	EnemyFactory(){
		prototypes["Orc"] = new Orc();
		prototypes["Goblin"] = new Goblin();
	}

	Enemy* createEnemy(const std::string &type) const {
		auto it = prototypes.find(type);
		if(it != prototypes.end())
			return it -> second -> clone();
		return nullptr;
	}

	~EnemyFactory(){
		for (auto& value : prototypes){
			delete value.second;
		}
	}
};

int main(){
	EnemyFactory enemyFactory;

	// Tạo các enemy từ prototype
	Enemy* orc1 = enemyFactory.createEnemy("Orc");
	Enemy* goblin1 = enemyFactory.createEnemy("Goblin");
	Enemy* orc2 = enemyFactory.createEnemy("Orc");

	// Hiển thị thông tin kẻ thù 
	orc1 -> showInfo();
	goblin1 -> showInfo();
	orc2 -> showInfo();

	return 0;
}