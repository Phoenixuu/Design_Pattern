#include<iostream>
#include<string>
#include<vector>

class Colleague;

// Step 1: Define the Mediator class
class Mediator{
public:
	virtual void sendMessage(const std::string& message, Colleague* sender, Colleague* recipient) = 0;
	virtual ~Mediator() = default;
};

// Step 1: Define the Colleague class
class Colleague {
protected:
	Mediator* mediator;
	std::string name;

public:
	Colleague(const std::string& name, Mediator* mediator) : name(name), mediator(mediator){}
	virtual void send(const std::string& message, Colleague* recipient) = 0;
	virtual void receive(const std::string& message) = 0;

	const std::string& getName() const {
		return name;
	}
};

// Step 2: Implement the Concrete Mediator class 
class Chatroom : public Mediator {
private:
	std::vector<Colleague*> colleagues;
public:
	void addColleague(Colleague* colleague){
		colleagues.push_back(colleague);
	}

	void sendMessage(const std::string& message, Colleague* sender, Colleague* recipient) override {
		for(Colleague* colleague : colleagues){
			if(colleague == recipient)
				colleague -> receive(message);
		}
	}
};

// Step 3: Implement the Concrete Colleague class
class User : public Colleague{
public:
	User(const std::string& name, Mediator* mediator) : Colleague(name, mediator){}

	void send (const std::string& message , Colleague* recipient) override {
		mediator -> sendMessage(message ,this ,recipient ) ;
	}

	void receive(const std::string& message) override {
		std::cout << "Received message: " << message << " (User: " << name << ")" << std::endl;
	}
};

int main() {
	Chatroom* chatroom = new Chatroom();

	Colleague* user1 = new User("Mark", chatroom);
	Colleague* user2 = new User("Bill", chatroom);
	Colleague* user3 = new User("Steve", chatroom);

	chatroom->addColleague(user1);
	chatroom->addColleague(user2);
	chatroom->addColleague(user3);

	user1->send("Hello, Bill", user2);
	user2->send("Hello, Mark", user1);
	user3->send("Hey, guys", user3);

	delete chatroom;
	delete user1;
	delete user2;
	delete user3;

	return 0;
}

