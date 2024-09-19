#ifndef FACTORY_HPP
#define FACTORY_HPP

#include<memory>
#include<map>
#include <string>

//Declare our one interface type
class IGameObject;

// ONe change is that I have removed our 'enum class' 
// This is because during run-time I want to be able to 
// create different types
class MyGameObjectFactory{
	//Callback function for creating an object
	typedef IGameObject *()
}