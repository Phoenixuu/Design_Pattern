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