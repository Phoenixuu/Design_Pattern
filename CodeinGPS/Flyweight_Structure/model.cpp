//model.cpp

struct GameObject{
	//Extrinsic State
	Params params;
	Position p;
	//Instrinsic State
	// - Shared object
	// - likely const
	const Model* m;
};

struct Model{
	Mesh m;
	Bark b;
	Leaves l;

	void DrawOprator(ExtrinsicState e){}
};