#include <iostream>
#include "IObserver.hpp"

Watcher::Watcher(ISubject& subject, int message, const std::string& name) : mSubject(subject), mMessage(message), mName(name){
	mSubject.AddObserver(mMessage, this);
}

Watcher::~Watcher(){
	mSubject.RemoveObserver(mMessage, this);
}

void Watcher::OnNotify(){
	std::cout << "watcher-" << mName << std::endl;
}