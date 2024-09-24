#pragma once 
#include <forward_list>
#include <map>

class IObserver;

class ISubject{
public:
	ISubject();
	virtual ~ISubject(); 
	
	virtual void AddObserver(int message, IObserver* observer);

	virtual void RemoveObserver(int message, IObserver* observer);

	void NotifyAll();

	void Notify(int message);

private: 
	typedef std::forward_list<IObserver*> ObserversList;
	typedef std::map<int, ObserversList> ObserversMap;
	// Key - Value Pair
	// Key: int, value: std::forwardlist our observers
	ObserversMap mObservers;
};

// SomeSubject.hpp
class SomeSubject : public ISubject {
public: 
	enum MessageTypes{PLAYSOUND, HANDLEPHYSICS, LOG};
};