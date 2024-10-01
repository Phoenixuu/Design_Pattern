/*
You are develping a video game that features different types of enemies. Each enemy has a uique
behavior when it comes to attacking the player. However, you want to implement a flexible and 
extensible system that allows you to easily add new enemy types and their corresponding attack
behaviors without modifying the existing code
*/

#include<iostream>

// Step 1: Define the interface for attack behavior
class AttackBehaviour {
public:
	virtual void attack() = 0;
	virtual ~AttackBehaviour() {}
};

// Step 2: Implement concrete attack behaviour classes
class MeleeAttack : public AttackBehaviour{
public:
	void attack() override{
	// Implement melee attack logic
		std::cout << "Performing MeleeAttack !" << std::endl;
	}
};

class RangedAttack : public AttackBehaviour{
public:
	void attack() override{
		//Implement ranged attack logic
		std::cout << "Performing RangedAttack !" << std::endl;
	}
};

class MagicAttack : public AttackBehaviour{
public:
	void attack() override{
		//Implement magic attack logic
		std::cout << "Performing MagicAttack !" << std::endl;
	}
};

// Step 3: Create a class that uses the attack behaviour
class Enemy{
private: 
	AttackBehaviour* attackbehaviour;
public:
	Enemy(AttackBehaviour* behaviour) : attackbehaviour(behaviour){}

	void setAttackBehaviour(AttackBehaviour* behaviour){
		attackbehaviour = behaviour;
	}

	void performAttack(){
		attackbehaviour -> attack();
	}
};

// Step 4: Demonstrate the usage of the Strategy pattern
int main(){
	std::cout << "Create enemy objects\n" << std::endl;

	//Create enemy objects
	Enemy enemy1(new MeleeAttack());
	Enemy enemy2(new RangedAttack());
	Enemy enemy3(new MagicAttack());

	//Perform attack
	enemy1.performAttack();
	enemy2.performAttack();
	enemy3.performAttack();

	std::cout << "\nChange attack behaviour: \n" << std::endl;

	//Change attack behaviour dynamically
	enemy1.setAttackBehaviour(new RangedAttack());
	enemy1.performAttack();

	return 0;
}