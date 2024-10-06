#include <iostream>
#include <memory>

struct ICombat{
	virtual ~ICombat(){}
	virtual void Execute() = 0;
};

struct Nocombat : public ICombat {
	void Execute(){
		std::cout << "Nocombat::Execute()\n";
	}
};

struct MeleeCombat : public ICombat {
	void Execute(){
		std::cout << "MeleeMelee::Execute()\n";
	}
};

struct Orc{

	Orc() {
		mCombatStrategy = std::make_unique<Nocombat>();
	}

	void DoActions()
	{
		mCombatStrategy->Execute();
	}

	void SetCombatStrategy(std::unique_ptr<ICombat>&& c){
		mCombatStrategy = std::move(c);
	}

private:
	std::unique_ptr<ICombat> mCombatStrategy;
};

int main(){

	Orc orc;
	orc.DoActions();
	orc.SetCombatStrategy(std::make_unique<MeleeCombat>());
	orc.DoActions();

	return 0;
}