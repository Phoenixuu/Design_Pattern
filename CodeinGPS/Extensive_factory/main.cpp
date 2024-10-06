#include <vector>
#include <memory>
#include <fstream>
#include <string>

#include "Factory.hpp"
#include "GameObjects.hpp"

class Ant : public IGameObject{
public:
	Ant(int x, int y){
		ObjectsCreated++;
	}
	void ObjectPlayDefaultAnimation() { /* ... */}
	void ObjectMoveInGame() {/* ... */}
	void Update() { /* ... */}
	void Render() { /* ... */}
	static IGameObject* Create() {
		return new Ant(0,0);
	}
private:
	static int ObjectsCreated;
};

int Ant::ObjectsCreated = 0;

int main() {
	MyGameObjectFactory::RegisterObject("plane", Plane::Create);
	MyGameObjectFactory::RegisterObject("boat", Boat::Create);
	MyGameObjectFactory::RegisterObject("ant", Ant::Create);

	std::vector<IGameObject*> gameObjectCollection;
	std::string line;
	std::ifstream myFile("Level1.txt");
	if(myFile.is_open()){
		while(std::getline(myFile,line)){
			IGameObject* object = MyGameObjectFactory::CreateSingleObject(line);
			gameObjectCollection.push_back(object);
		}
	}
	// Run our game ...
	while(true){
		for(auto& e: gameObjectCollection){
			e -> Update();
			e -> Render();
		}
	}

	return 0;
}
