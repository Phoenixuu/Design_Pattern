#include <iostream>
#include <map>
#include<memory>

//if need flexibility of having unique objects, then still create another class
// struct UniqueTree{
// 	//Extrinsic state
// 	float x,y,z;
// 	Tree(float _x, float _y, float _z) : x(_x), y(_y), z(_z){

// 	}
// 	Model m;
// };

struct Tree{
	//Extrinsic state
	float x,y,z;
	Tree(float _x, float _y, float _z) : x(_x), y(_y), z(_z){

	}
};


// Flywieght = this is what we want to share 
struct Model{
	//Instrinsic()
	// All instances are shared
	struct Mesh{
		int data[100];
	};

	Mesh m; 
	// Bark b;
	// Leaves l;

	void DrawOperator(const Tree& extrinsicState){
		std::cout 	<< extrinsicState.x << " "
					<< extrinsicState.y << " "
					<< extrinsicState.z << std::endl;
	}	
};

// 'Resource Manager', 'template' our Factory on the 'value'
struct FlyweightModelFactory{
	std::map<std::string, std::shared_ptr<Model>> mModelFlyweights;

	//Get an existing flyweight, or otherwise create a new
	//model that we can share multiple times
	std::shared_ptr<Model> GetFlyweight(std::string key){
		auto it = mModelFlyweights.find(key);
		if(it != mModelFlyweights.end()){
			std:: cout << "reusing: " << key << std::endl;
			return it->second;
		} else{
			std::cout << "Add new crypto" << std::endl;
			std::shared_ptr<Model> m = std::make_shared<Model>();
			mModelFlyweights[key] = m;
			return m;
		}
	}
};


int main(int argc, char const *argv[])
{
	Tree Cloudberry(1.0f, 2.0f, 3.0f);
	Tree Eucalyptus(4.0f, 3.5f, 5.0f);
	Tree Strawberry(1.0f, 1.0f, 4.0f);

	// Model m;

	// m.DrawOperator(Cloudberry);
	// m.DrawOperator(Eucalyptus);

	FlyweightModelFactory factory;

	factory.GetFlyweight("oak tree")->DrawOperator(Cloudberry);
	factory.GetFlyweight("Palm tree")->DrawOperator(Eucalyptus);
	factory.GetFlyweight("oak tree")->DrawOperator(Strawberry);

	return 0;
}