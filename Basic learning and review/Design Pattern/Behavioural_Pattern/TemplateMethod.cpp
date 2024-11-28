#include<iostream>
#include<string>

class Level {
public:
	// Template method defining the level structure
	void play() {
		initialize();
		gameplay();
		finalize();
	}

	// Abstract methods to be implemented by concrete levels
	virtual void initialize() = 0;
	virtual void gameplay() = 0;
	virtual void finalize() = 0;
};

class EasyLevel : public Level {
public:
	void initialize() override {
		// Initialize the easy level
	}

	void gameplay() override {
		// Implement gameplay logic for the easy level
	}

	void finalize() override {
		// Finalize the easy level
	}
}

class MediumLevel : public Level {
public:
	void initialize() override {
		// Initialize the medium level
	}

	void gameplay() override {
		// Implement gameplay logic for the medium level
	}

	void finalize() override {
		//Finalrize the medium level
	}
}

int main()
{
	// Create instances of the concrete level classes
	Level* easylevel = new EasyLevel();
	Level* mediumlevel = new MediumLevel();

	// Play the levels 
	easylevel -> play();
	mediumlevel -> play();

	// Clean up
	delete easylevel;
	delete mediumlevel;

	return 0;
}