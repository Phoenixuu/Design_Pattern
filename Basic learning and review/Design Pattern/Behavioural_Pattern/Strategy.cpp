#include<iostream>
#include<string>

// Step 1: Define the interface for the attack behaviour 
class AttackBehaviour{
public:
	virtual void attack() = 0;
	virtual ~AttackBehaviour() {}
};

// Step 2: Implement concrete attack behaviour classes
class MeleeAttack : public AttackBehaviour {
public:
	void attack() override {
		//Implement attack logic
		std::cout << "Melee attack! Cach Cach Cach" << std::endl;
	}
};

class RangedAttack : public AttackBehaviour {
public:
	void attack() override {
		//Implement attack logic
		std::cout << "Ranged attack! Phut Phut Phut" << std::endl;
	}
};

class MagicAtaack : public AttackBehaviour {
public:
	void attack() override {
		// Implement attack magic
		std::cout << "Magic attack! Bla Bla Bla" << std::endl;
	}
};

// Step 3: Create a class that uses the attack behaviour 
class Enemy {
private: 
	AttackBehaviour* attackBehaviour;
public:
	Enemy(AttackBehaviour* behaviour) : attackBehaviour(behaviour){}

	void setAttackBehaviour(AttackBehaviour* behaviour) {
		attackBehaviour = behaviour;
	}

	void performAttack(){
		attackBehaviour->attack();
	}
};

//Step 4: Demonstrate the usage of the Strategy pattern
int main() {
	//Create enemy objects
	Enemy enemy1(new MeleeAttack());
	Enemy enemy2(new RangedAttack());
	Enemy enemy3(new MagicAtaack());

	//Perform attack
	enemy1.performAttack();
	enemy2.performAttack();
	enemy3.performAttack();

	//Change attack behaviour dynamically
	enemy1.setAttackBehaviour(new RangedAttack());

	enemy1.performAttack();

	return 0;
}