#pragma once 
#include <forward_list>

class IObserver;

class ISubject{
public:
	ISubject();
	virtual ~ISubject(); 
	
	virtual void AddObserver(IObserver* observer);

	virtual void RemoveObserver(IObserver* observer);

	void NotifyAll();

private: 
	std::forward_list<IObserver*> mObservers;
};

class SomeSubject : public ISubject {
public: 
};