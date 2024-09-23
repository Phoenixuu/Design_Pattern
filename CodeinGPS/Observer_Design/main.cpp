// First try
#include <iostream>
#include "IObserver.hpp"
#include "ISubject.hpp"

// class Observer{
// public:
// 	Observer(std::string name): mName(name){
// 	}

// 	void OnNotify(){
// 		std::cout << mName << " Pip pip pip !!!\n";
// 	}

// private:
// 	std::string mName;
// };



int main(){
	SomeSubject subject;
	Watcher watcher1(subject,"Watch");
	Watcher watcher2(subject,"Hat");
	Watcher watcher3(subject,"Pant");

	// subject.AddObserver(&watcher1);
	// subject.AddObserver(&watcher2);
	// subject.AddObserver(&watcher3);

	subject.NotifyAll();

	// subject.RemoveObserver(&watcher3);
	std::cout << std::endl;

	subject.NotifyAll();

	return 0;
}