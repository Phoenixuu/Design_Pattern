//gameobject.cpp
struct GameObject{
	std::string name;
	Mesh		m; // 3D data
	Texture		t; // texture
	Position 	p: // Position
	Transform 	t: // rotation
	Behavior 	b; // Function ptr

	GameObject() {}
	~GameObject() {}

}

///Game Object Base Type
struct GameObject{
	void Update(){
		//Retrieve key and value
		for(auto& [key,value] : mComponents){
			mComponents[key] -> Update();
		}
	}

	template<typename T>
	void AddComponent(T* c) {
		// Insert or update the component
		mComponents[c -> GetType()] = c;
	}

	template<typename T>
	T GetComponent(ComponentType type){
		auto found = mComponents.find(type);
		if(found != mComponents.end()){
			return static_cast<T>(found->second);
		}

		return nullptr;
	}
}

std::map<ComponentType Compoent*> mComponents;

int main(){
Game GameObject* obj1 = new GameObject();

obj -> Update = 

	return 0
}