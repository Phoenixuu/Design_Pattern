// Inheritance/GameObject.hpp
#pragma once
#include<iostream>
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

int main(int argc, char const *argv[])
{
	GameObject* Mario = new GameObject();
	Mario->Texture = new Texture()
	
	return 0;
}