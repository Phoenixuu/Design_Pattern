#include<iostream>
#include<string>

class Character{
public:
	void setName(std::string name) {mName = name;}
	void setGender(std::string gender) {mGender = gender;}
	void setRace(std::string race) {mRace = race;}
	void setAttribute(std::string attribute) {mAtrribute = attribute;}
	void setWeapon(std::string weapon) {mWeapon = weapon;}

	void printCharacter() const{
		std::cout << "Name: " << mName << std::endl;
		std::cout << "Gender: " << mGender << std::endl;
		std::cout << "Race: " << mRace << std::endl;
		std::cout << "Attribute: " << mAtrribute << std::endl;
		std::cout << "Weapon: " << mWeapon << std::endl;
	}

private:
	std::string mName;
	std::string mGender;
	std::string mRace;
	std::string mAtrribute;
	std::string mWeapon;
};

class CharacterBuilder{
public:
	virtual ~CharacterBuilder() {}
	virtual void buildName() = 0;
	virtual void buildGender() = 0;
	virtual void buildRace() = 0;
	virtual void buildAttribute() = 0;
	virtual void buildWeapon() = 0;
	virtual Character* getCharacter() = 0; 
};

class HumanCharacterBuilder : public CharacterBuilder{
public:
	virtual void buildName() override {mCharacter -> setName("Yasuo");}
	virtual void buildGender() override {mCharacter -> setGender("Male");}
	virtual void buildRace() override {mCharacter -> setRace("Mid");}
	virtual void buildAttribute() override {mCharacter -> setAttribute("Physical");}
	virtual void buildWeapon() override {mCharacter -> setWeapon("Sword");}
	virtual Character* getCharacter() override {return mCharacter;}
private:
	Character* mCharacter = new Character();
};

class CharacterDirector {
public:
	void setBuilder(CharacterBuilder* builder) {mBuilder = builder;}
	void constructCharacter(){
		mBuilder -> buildName();
		mBuilder -> buildGender();
		mBuilder -> buildRace();
		mBuilder -> buildAttribute();
		mBuilder -> buildWeapon();
	}
private:
	CharacterBuilder* mBuilder;
};

int main(){
	//Create builder and director
	HumanCharacterBuilder* playerBuilder = new HumanCharacterBuilder();
	CharacterDirector director;

	// Set the builder in the director
	director.setBuilder(playerBuilder);

	//Construct the character
	director.constructCharacter();

	//Get the constructed character
	Character* playerCharacter = playerBuilder -> getCharacter();

	// print out the character details
	playerCharacter -> printCharacter();

	// Clean up
	delete playerBuilder;
	delete playerCharacter;

	return 0;
}