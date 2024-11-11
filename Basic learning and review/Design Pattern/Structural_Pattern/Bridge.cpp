#include<iostream>

//Step 1: Define the shape classes hierarchy
class Shape{
public:
	virtual void draw() = 0;
};

class Circle : public Shape {
public:
	void draw() override {
		//Draw circle implementation
		std::cout << "Draw circle implementation" << std::endl;
	}
};

class Rectangle : public Shape {
public:
	void draw() override {
		//Draw rectangle implementation
		std::cout << "Draw Rectangle implementation" << std::endl;
	}
};

class Oval : public Shape {
public:
	void draw() override {
		//Draw oval implementation
		std::cout << "Draw Oval implementation" << std::endl;
	}
};

//Step 2: Define the rendering interface and its implementations
class Renderer {
public:
	virtual void render() = 0;
};

class RasterRenderer : public Renderer{
public:
	void render() override {
		std::cout << "Raster rendering implementation" << std::endl;
	}
};

class VectorRenderer : public Renderer {
public:
	void render() override {
		std::cout << "Vector rendering implementation" << std::endl;
	}
};

class ShapeRenderer{
protected:
	Renderer* renderer;

public:
	ShapeRenderer(Renderer* renderer) : renderer(renderer) {}

	virtual void draw() = 0;
};

class CircleRenderer : public ShapeRenderer {
public:
	CircleRenderer(Renderer* renderer) : ShapeRenderer(renderer) {}

	void draw() override {
		// Additional circle specific logic if needed
		renderer -> render();
	}
};

class RectangleRenderer : public ShapeRenderer {
public:
	RectangleRenderer(Renderer* renderer) : ShapeRenderer(renderer) {}

	void draw() override{
		// Additional rectangle specific logic if needed
		renderer -> render();
	}
};

int main(){
	// Create rendering systems
	Renderer * rasterRenderer = new RasterRenderer () ;
	Renderer * vectorRenderer = new VectorRenderer () ;

	// Create shapes with different rendering systems
	ShapeRenderer * circleRenderer = new CircleRenderer ( rasterRenderer ) ;
	ShapeRenderer * rectan gleRende rer = new ←-
	Recta ngleRend erer ( vectorRenderer ) ;

	// Draw shapes
	circleRenderer - > draw () ;
	rectangleRenderer - > draw () ;
	
	// Clean up
	delete rasterRenderer ;
	delete vectorRenderer ;
	delete circleRenderer ;
	delete rectan gleRender er ;
	
	return 0;
}


