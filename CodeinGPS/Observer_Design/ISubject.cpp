#include "ISubject.hpp"
#include "IObserver.hpp"

ISubject::ISubject(){}
ISubject::~ISubject() {}

//message is our 'enum' (PLAYSOUND, PHYSICSEVENT, LOG)
void ISubject::AddObserver(int message, IObserver* observer){
	//Search for 'enum'
	auto it = mObservers.find(message);
	if(it == mObservers.end()){
		mObservers[message] = ObserversList();
	}

	mObservers[message].push_front(observer);
}

void ISubject::RemoveObserver(int message, IObserver* observer){
	auto it = mObservers.find(message);
	if(it != mObservers.end()){
		// iterator through list
		ObserversList& list = mObservers[message];
		for(ObserversList::iterator li = list.begin(); li != list.end();){
			if((*li) == observer){
				list.remove(observer);
			} else{
				++li;
			}
		}
	}
}

void ISubject::NotifyAll(){
	for(ObserversMap::iterator 	it = mObservers.begin();
								it != mObservers.end();
								++it){
		for(auto& o: mObservers[it->first]){
			o->OnNotify();
		}
	}
}

void ISubject::Notify(int message){
	for(auto& o: mObservers[message]){
		o->OnNotify();
	}
}

