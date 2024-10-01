// Inheritance/GameObject.hpp
#pragma once
#include<iostream>
#include<vector>
//List of Components
struct Texture{};
struct CollisionBox{};
struct Transform{};
struct State{};
struct Input{};
struct UserInterface2D{};
struct AIBehavior{};

//Game Object Base Type
struct GameObject{
	//Constructor
protected:
	// Common Components
	Texture*		mTexture{nullptr};
	CollisionBox*	mCollision{nullptr};
	Transform*		mTransform{nullptr};
	State*			mState{nullptr};
	// Uniqie ID per Game Object

	void Update(){
		for(auto& component : mComponents){
			component -> Update();
		}
	}

	template<typename T>
	void AddComponent(T* c){
		mComponents.emplace_back(c);
	}
	template<typename T>
	T GetComponentAtIndex(size_t index){
		return static_cast<T>(mComponents[index])
	}

public:
	std::vector<Component*> mComponents;
	//std::map<ComponentType, Component*> mComponents;
};

// New Mario
struct Mario : public GameObject{
protected:
	Input*				mInput{nullptr};
	UserInterface2D*	mUserInterface{nullptr};
};

// New AI
struct AI : public GameObject{
protected:
	AIBehavior*		mAI{nullptr};
};

struct Bot : public Mario, AI {}

;

void AI(){
	if(mComponents.contains(ComponentType::AI)){
		mComponents[ComponentType::AI]->Update();
	}
}

void Update(){
	if(mComponents.contains(ComponentType::COLLISION)){
		mComponents[ComponentType::COLLISION] -> Update();
	}
}

void Render(){
	if(mComponents[ComponentType::TEXTURE] -> Update()){
		mComponents[ComponentType::TEXTURE] -> Update();
	}
}

//Artificial Intelligence 
for(int i = 0; i < numberOfEntities; ++i){
	aiComponents[i].update();
}

//Collision/Physics Simulation
for(int i = 0; i < numberOfEntities; ++i){
	ColliderComponents[i].update();
}

//Rendering
for(int i = 0; i < numberOfEntities; ++i){
	renderComponents[i].render();
}



int main(int argc, char const *argv[])
{
	GameObject* Mario = new GameObject();
	Mario->Texture = new Texture();
	texture
	Mario -> AddComponent <TextureComponent*>;

	return 0;
}