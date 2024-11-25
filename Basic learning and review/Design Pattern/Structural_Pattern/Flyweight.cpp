#include<iostream>
#include<map>
#include<string>

class Character {
public :
	virtual void draw(const std :: string &font) const = 0;
};

class ConcreteCharacter : public Character {
private:
	char symbol ;
public:
	ConcreteCharacter (char symbol) : symbol ( symbol ) {}
	void draw(const std::string &font) const override {
		std::cout << "Character: " << symbol << ", Font: " << font << std::endl ;
	}
};
class CharacterFactory {
private:
	std::map <char,Character* > characters ;
public:
	Character* getCharacter (char symbol) {
		if(characters.find(symbol) == characters.end()) {
			characters[symbol] = new ConcreteCharacter (symbol) ;
		}
		return characters [symbol];
	}
};

int main () {
	CharacterFactory characterFactory ;

	Character* characterA = characterFactory . getCharacter ( 'A') ;
	Character* characterB = characterFactory . getCharacter ( 'B') ;
	Character* characterA2 = characterFactory . getCharacter ( 'A') ;
	
	characterA -> draw("Arial");
	characterB -> draw("Times New Roman");
	characterA2 -> draw("Arial");
	
	return 0;
}
