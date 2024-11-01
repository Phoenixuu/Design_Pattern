#include<iostream>

class LegacyLibrary {
public:
	void readDataFromLegacyFormat(const std::string& fileName);
	void writeDataToLegacyFormat(const std::string& fileName);
};

class ModernInterface {
public:
	virtual void readData(const std::string& fileName) = 0;
	virtual void writeData(const std::string& fileName) = 0;
	virtual ~ModernInterface() = default;
};

class LegacyAdapter : public ModernInterface{
public:
	void readData(const std::string& fileName) override{
		legacyLibrary.readDataFromLegacyFormat(fileName);
	}

	void writeData(const std::string& fileName) override{
		legacyLibrary.writeDataToLegacyFormat(fileName);
	}

private:
	LegacyLibrary legacyLibrary;
};

void someFunction(ModernInterface& adapter){
	adapter.readData("data.txt");
	adapter.writeData("output.txt");
}

int main(){
	LegacyAdapter adapter;
	someFunction(adapter);
	return 0;
}

