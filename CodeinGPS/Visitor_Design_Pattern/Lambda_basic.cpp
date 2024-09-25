#include<iostream>
#include<string>
#include<functional>

// struct Actor{
// public:
// 	Actor(std::string name) : mName(name){}
// 	const std::string mName;
// };

// // Higher order function
// void Agenda(std::function<void(const Actor&)> f, const Actor& a){
// 	//Call function with the actor argument
// 	f(a);
// }

// int main(){
// 	//Define a lambda function (Implement as a functor)
// 	auto practice = [](const Actor& s){
// 		std::cout << s.mName << " ::practice()\n";
// 	};
// 	auto dance = [](const Actor& s){
// 		std::cout << s.mName << " ::dance()\n";
// 	};

// 	//Instantiate date
// 	Actor a = Actor("Phoe");

// 	// Pass function as a parameter
// 	Agenda(practice, a);
// 	Agenda(dance, a);

// 	return 0;
// }

struct MyRoom{
public:
	MyRoom(std::string name) : mName(name){}
	const std::string mName;
};

void TimKiem(std::function<void(const MyRoom&)> F, const MyRoom& s){
	F(s);
}

int main(){
	auto Freakconomic = [](const MyRoom& b){
		std::cout << b.mName << " Finding kinh te hoc hai huoc ngan so 3\n";
	};
	auto Psychology_of_money = [](const MyRoom& b){
		std::cout << b.mName << " founded Psychology_of_money in the bookself in 5 floors\n";
	};

	MyRoom s = MyRoom("Dzung");

	TimKiem(Freakconomic, s);
	TimKiem(Psychology_of_money, s);

	return 0;
}