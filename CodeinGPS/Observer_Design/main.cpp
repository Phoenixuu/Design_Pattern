// First try
#include<string>
#include <iostream>
#include<forward_list>

//Ab stract class which we derive from 
// Base Class
class IObserver{
public: 
	virtual ~IObserver(){}
	virtual void OnNotify() = 0;
};

//Concrete implementation of our IObserver
class Watcher : public IObserver{
public: 
	explicit Watcher(const std::string& name) : mName(name){

	}

	void OnNotify() override{
		std::cout << "watcher-" << mName << std::endl;
	}

private:
	std::string mName;
};

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

class ISubject{
public:
	virtual ~ISubject(){} 
	
	virtual void AddObserver(IObserver* observer){
		mObservers.push_front(observer);
	}

	virtual void RemoveObserver(IObserver* observer){
		mObservers.remove(observer);
	}

	void NotifyAll(){
		for(auto& o: mObservers){
			o -> OnNotify();
		}
	}

private: 
	std::forward_list<IObserver*> mObservers;
};

class SomeSubject : public ISubject {
public: 
};

int main(){
	SomeSubject subject;
	Watcher watcher1("Watch");
	Watcher watcher2("Hat");
	Watcher watcher3("Pant");

	subject.AddObserver(&watcher1);
	subject.AddObserver(&watcher2);
	subject.AddObserver(&watcher3);

	subject.NotifyAll();

	subject.RemoveObserver(&watcher3);
	std::cout << std::endl;

	subject.NotifyAll();

	return 0;
}