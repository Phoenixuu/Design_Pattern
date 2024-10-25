// First try
#include <iostream>
#include "IObserver.hpp"
#include "ISubject.hpp"

int main(){
	SomeSubject subject;
	Watcher watcher1(subject,SomeSubject::PLAYSOUND,"Mountain");
	Watcher watcher2(subject,SomeSubject::PLAYSOUND,"Fire");
	Watcher watcher3(subject,SomeSubject::LOG,"Water");

	// subject.AddObserver(&watcher1);
	// subject.AddObserver(&watcher2);
	// subject.AddObserver(&watcher3);

	subject.NotifyAll();

	// subject.RemoveObserver(SomeSubject::PLAYSOUND, &watcher1);
	std::cout << std::endl;

	subject.Notify(SomeSubject::LOG);

	std::cout << std::endl;
	subject.Notify(SomeSubject::PLAYSOUND);

	return 0;
}