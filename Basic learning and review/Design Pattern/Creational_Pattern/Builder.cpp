#include<iostream>
#include<string>

class Character {
public:
	void setName(std::string name) { mName = name; }
	void setGender(std::string gender) { mGender = gender; }
	void setRace(std::string race) { mRace = race; }
	void setClass(std::string characterClass) { mClass = characterClass; }
	void setEquipment(std::string equipment) { mEquipment = equipment; }

    void printCharacter() const {
    std::cout << "Name: " << mName << std::endl;
    std::cout << "Gender: " << mGender << std::endl;
    std::cout << "Race: " << mRace << std::endl;
    std::cout << "Class: " << mClass << std::endl;
    std::cout << "Equipment: " << mEquipment << std::endl;
    }

private:
	std::string mName;
	std::string mGender;
	std::string mRace;
	std::string mClass;
	std::string mEquipment;
};

class CharacterBuilder{
public:
	virtual ~CharacterBuilder() {}
	virtual void buildName() = 0;
	virtual void buildGender() = 0;
	virtual void buildRace() = 0;
	virtual void buildClass() = 0;
	virtual void buildEquipment() = 0;
	virtual Character* getCharacter() = 0;
};

class HumanCharacterBuilder : public CharacterBuilder {
public:
	virtual void buildName() override { mCharacter -> setName("Ryze"); }
	virtual void buildGender() override { mCharacter -> setGender("Male"); }
	virtual void buildRace() override { mCharacter -> setRace("Mid"); }
	virtual void buildClass() override { mCharacter -> setClass("Magic"); }
	virtual void buildEquipment() override { mCharacter -> setEquipment("Book"); }
	virtual Character* getCharacter() override { return mCharacter; }
private:
	Character* mCharacter = new Character();
};

class CharacterDirector {
public:
	void setBuilder(CharacterBuilder* builder ) { mBuilder = builder; }
	void constructCharacter() {
		mBuilder -> buildName();
		mBuilder -> buildGender();
		mBuilder -> buildRace();
		mBuilder -> buildClass();
		mBuilder -> buildEquipment();
	}
private:
	CharacterBuilder* mBuilder;
};

int main() {
    // Create builder and director
    HumanCharacterBuilder* humanBuilder = new HumanCharacterBuilder();
    CharacterDirector director;

    // Set the builder in the director
    director.setBuilder(humanBuilder);

    // Construct the character
    director.constructCharacter();

    // Get the constructed character
    Character* humanCharacter = humanBuilder->getCharacter();

    // Print out the character details
    humanCharacter->printCharacter();

    // Clean up
    delete humanBuilder;
    delete humanCharacter;

    return 0;
}