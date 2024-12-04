#include<iostream>
#include<string>
#include<vector>

// Step 1: Define the Iterator interface and its implementation
class Iterator {
public:
	virtual bool hasNext() const = 0;
	virtual std::string next() = 0;
};

class BookIterator : public Iterator {
private:
	std::vector<std::string> books;
	int current = 0;
public:
	BookIterator(const std::vector<std::string> books) : books(books) {}

	bool hasNext() const override {
		return current < books.size();
	}

	std::string next() override {
		if(!hasNext()){
			throw std::out_of_range("No more book in the collection.");
		}
		return books[current++];
	}
};

// Step 2: Define the collection class and its methods
class BookCollection {
private:
	std::vector<std::string> books;
public:
	void addBook(const std::string& book) {
		books.push_back(book);
	}

	Iterator* createIterator() const {
		return new BookIterator(books);
	}
};

int main(){
	BookCollection collection;
	collection.addBook("Harry Potter");
	collection.addBook("Game of Thornes");
	collection.addBook("The lord of conjuring");
	Iterator* iterator = collection.createIterator();

	while(iterator->hasNext()) {
		std::string book = iterator -> next();
		std::cout << "Book: " << book << std::endl;
	}

	delete iterator;

	return 0;
}