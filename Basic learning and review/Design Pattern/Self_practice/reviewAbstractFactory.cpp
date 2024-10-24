#include<iostream>

class Rapper {
public:
	virtual void Type() = 0;
	virtual void Appearance() = 0;
	virtual void Song() = 0;
};

class VietnameseRapper : public Rapper{
public:
	void Type() override {
		std::cout << "Linh ta linh tinh, trash, waste, money" << std::endl;
	}
	void Appearance() override {
		std::cout << "Normal, small, a bit high and handsome will famous" << std::endl;
	}
	void Song() override {
		std::cout << "Lazy, not too much music, just showbiz and make money" << std::endl;
	}
};

class USRapper : public Rapper{
public:
	void Type() override {
		std::cout << "Catchy, Storytelling, Strong, Real Rap, Rap diss" << std::endl;
	}
	void Appearance() override {
		std::cout << "Almost black and live under the line" << std::endl;
	}
	void Song() override {
		std::cout << "Not like that, Rap God, Annaconda, BlingBling" << std::endl;
	}
};

class Show {
public:
	virtual Rapper* inviteVietnamese() = 0;
	virtual Rapper* inviteUS() = 0;
};

class ExpensiveRapper : public Show {
public:
	Rapper* inviteUS() override {
		std::cout << "Eminem, Kayne West, Kendrick Lamar, Nicky Minaj" << std::endl;
		return new USRapper();
	}
	Rapper* inviteVietnamese() override {
		std::cout << "Rhymatic, Karik, Suboi, Justatee, Binz, Bray" << std::endl;
		return new VietnameseRapper();
	}
};

class CheapRapper : public Show {
public:
	Rapper* inviteUS() override{
		std::cout << "Tyga, Drake, Anonymous" << std::endl;
		return new USRapper();
	}
	Rapper* inviteVietnamese() override{
		std::cout << "Sidie, Yuno, Tage, Gonzo, Type" << std::endl;
		return new VietnameseRapper();
	}
};


int main()
{
	Show* BigShow = new ExpensiveRapper();
	Rapper* Rapperbigfan = BigShow -> inviteUS();

	Show* TrashShow = new CheapRapper();
	Rapper* Rapperlor = TrashShow -> inviteVietnamese();   
	return 0;
}