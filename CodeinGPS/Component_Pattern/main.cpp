#include <iostream>
#include <map>

enum class ComponentType{TEXTURE, COLLISION, POSSITION};

//Interface
struct IComponent{
	virtual void Update() = 0; // Must be implemented 
	virtual ComponentType GetType() = 0;
};

struct TextureComponent : public IComponent{
	void Update(){ std::cout << "TextureComponent::Update\n";}
	ComponentType GetType(){ return ComponentType::TEXTURE;}
};

struct CollisionComponent : public IComponent{
	void Update(){std::cout << "CollisonComponent::Update\n";}
	ComponentType GetType(){ return ComponentType::COLLISION;}
};

struct PositionComponent : public IComponent{
	void Update(){std::cout << "PositionComponent::Update\n";}
	ComponentType GetType(){ return ComponentType::POSSITION;}
};

struct GameObject{

	void Update(){
		for(auto& [key,value] : mComponents){
			mComponents[key]->Update();
		}
	}
	//using unique_ptr for components
	void AddComponent(IComponent* c){
		mComponents[c->GetType()] = c;
	}

	IComponent* GetComponent(ComponentType type){
		auto found = mComponents.find(type);
		if(found != mComponents.end()){
			return found->second;
		}
		return nullptr;
	}

	std::map<ComponentType, IComponent*> mComponents;
};

int main(int argc, char const *argv[])
{
	GameObject mario;
	TextureComponent tc;
	PositionComponent pc;
	CollisionComponent cc;

	mario.AddComponent(&cc);
	mario.AddComponent(&pc);
	mario.AddComponent(&tc);

	auto retrieveComponent = mario.GetComponent(ComponentType::TEXTURE);
	retrieveComponent->Update();

	mario.Update();
	
	return 0;
}