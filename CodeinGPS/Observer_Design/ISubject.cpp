#include "ISubject.hpp"
#include "IObserver.hpp"

ISubject::ISubject(){}
ISubject::~ISubject() {}

void ISubject::AddObserver(IObserver* observer){
	mObservers.push_front(observer);
}

void ISubject::RemoveObserver(IObserver* observer){
	mObservers.remove(observer);
}

void ISubject::NotifyAll(){
	for(auto& o: mObservers){
		o->OnNotify();
	}
}