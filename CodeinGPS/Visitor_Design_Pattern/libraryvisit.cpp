#include<iostream>
#include<string>
#include<variant>

struct MethodActor{
public:
	MethodActor() = default;
	MethodActor(std::string name) :mName(name){}
	const std::string mName; 
};

struct ClassicalActor{
public:
	ClassicalActor() = default;
	ClassicalActor(std::string name) : mName(name){}
	const std::string mName;
};

using Actor = std::variant<MethodActor, ClassicalActor>;

struct PracticeVisitor{
	void operator()(const MethodActor& a) const{
		std::cout << a.mName << " Practicing like a Method Actor\n";
	}
	void operator()(const ClassicalActor& a) const{
		std::cout << a.mName << " Practicing like a Classical Actor\n";
	}
};

int main(){

	//Create a variant
	// the other a tagged union
	Actor a = MethodActor("Dzun");
	std::visit(PracticeVisitor{}, a);

	Actor b = ClassicalActor("zun");
	std::visit(PracticeVisitor{}, b);

	return 0;
}