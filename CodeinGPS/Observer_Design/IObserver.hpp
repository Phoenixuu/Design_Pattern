#pragma once
#include "ISubject.hpp"
#include <string>

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
	// Automatically register Watcher to subject
	explicit Watcher(ISubject& subject, int message, const std::string& name);

	// Automatically remove Watcher from ISubject 
	~Watcher();

	void OnNotify();

private:
	ISubject& mSubject;
	std::string mName;
	int mMessage;
};